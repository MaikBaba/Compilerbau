/*
 * CodeGen.C
 *
 *  Created on: Jun 28, 2016
 *      Author: MB
 */
#include "CodeGen.H"

CodeGen::CodeGen(void) :
		builder(llvm::getGlobalContext()),
		context(llvm::getGlobalContext()),
		TheModule("mycode", llvm::getGlobalContext()) {
	val = nullptr;
}

llvm::Value* CodeGen::codegen(Visitable* v) {
	v->accept(this);
	return val;
}

llvm::Type* CodeGen::typegen(Visitable* v) {
	v->accept(this);
	return type;
}

void CodeGen::visitProgram(Program* t) {
} //abstract class
void CodeGen::visitDef(Def* t) {
} //abstract class
void CodeGen::visitArg(Arg* t) {
} //abstract class
void CodeGen::visitStm(Stm* t) {
} //abstract class
void CodeGen::visitExp(Exp* t) {
} //abstract class
void CodeGen::visitType(Type* t) {
} //abstract class

void CodeGen::visitPDefs(PDefs *pdefs) {
	/* Code For PDefs Goes Here */

	codegen(pdefs->listdef_);

}
/*************************************************************************
 * 						 	  FUNKTIONEN ETC.							 *
 /*************************************************************************/

/* Funktionsprototyp besuchen */
void CodeGen::visitListDef(ListDef* listdef) {

	std::cout << indent << "Enter visitListDef" << std::endl;
	indent.push_back('\t');

	for (ListDef::iterator proto_it = listdef->begin();
			proto_it != listdef->end(); proto_it++) {
		DFun* proto = (DFun*) *proto_it;
		val=codegen(proto);
	}

	indent.pop_back();
	std::cout << indent << "Leave visitListDef" << std::endl;

}

/* Funktionsdefinition besuchen*/
void CodeGen::visitDFun(DFun *dfun) {
	std::cout << indent << "Enter visitDFun: " << dfun->id_ << std::endl;
	std::cout << indent << "---------------- " << dfun->id_ << std::endl;
	indent.push_back('\t');

	// Überspringen, wenn für diese Funktion schon Code generiert wurde
	// TODO Polymorphe Funktionen
	llvm::Function *TheFunction = TheModule.getFunction(dfun->id_);
	if (TheFunction != nullptr) {
		indent.pop_back();
		std::cout << indent << "Leave visitDFun" << std::endl;
		return;
	}
	// Baue llvm Funktionstyp auf
	// Hole dazu die richtigen Argumenttypen via typegen
	vector<llvm::Type*> protoArgs;

	for (ListArg::iterator arg_it = dfun->listarg_->begin(); arg_it != dfun->listarg_->end(); arg_it++) {
		ADecl* adecl = (ADecl*) *arg_it;
		std::cout << indent << "Signatur: " << dfun->id_ << std::endl;
		indent.push_back('\t');
		protoArgs.push_back(typegen(adecl->type_));
	}
	llvm::FunctionType* llvm_funType = llvm::FunctionType::get(typegen(dfun->type_), protoArgs, false);
	indent.pop_back();

	// Generiere Funktion unter dem vom Prototypen gegebenen Namen im Modul
	llvm::Function* llvm_fun = llvm::Function::Create(llvm_funType, llvm::Function::ExternalLinkage, dfun->id_, &TheModule);

	// Zwecks besserer Lesbarkeit des IR dumps Namen der Argumente setzen
	ListArg::iterator listarg = dfun->listarg_->begin();
	for (auto &arg : llvm_fun->args()) {
		arg.setName(((ADecl*) *listarg)->id_);
		listarg++;
	}

	/* generiere einen einzigen entry block
	 * Branching statements müssen selbst Blöcke generieren
	 * und den insert point ändern */
	llvm::BasicBlock* entryBlock = llvm::BasicBlock::Create(context, "entry",
			TheFunction);
	builder.SetInsertPoint(entryBlock);

	// Füge Funktionsargumente in env_/NamedValues ein
	// TODO Könnte man das auch weiter rekursiv machen?
	//      dfun->listarg_->accept(this); und dann in visitListArg eintragen

	// generiere Code für die Statements im Body
	std::cout << indent << "Body:" << std::endl;
	indent.push_back('\t');
	val = codegen(dfun->liststm_);
	indent.pop_back();

	// Note: Return statement wird auch rekursiv generiert


	// Validieren
	llvm::verifyFunction(*TheFunction);

	// fertige Funktion als "Rückgabewert" speichern
	val = TheFunction;

	indent.pop_back();
	std::cout << indent << "Leave visitDFun" << std::endl;
}
/* Funktionsaufruf besuchen */
void CodeGen::visitEApp(EApp *eapp) {
	std::cout << indent << "Enter visitEApp" << std::endl;
	indent.push_back('\t');

	llvm::Function *calleeF = TheModule.getFunction(eapp->id_);

	//Auch hier: Angenommen, es gibt keine überladenen Funktionen
	if (!calleeF)
		// TODO Error: Unbekannte Funktion
		if (calleeF->arg_size() != eapp->listexp_->size()) {
			// TODO Error: Anzahl der übergebenen Argumente stimmt nicht mit Deklaration überein
		}

	std::vector<llvm::Value*> llvm_call_args;
	for (ListExp::iterator it = eapp->listexp_->begin();
			it != eapp->listexp_->end(); ++it) {
		llvm_call_args.push_back(codegen(*it));
	}
	val = builder.CreateCall(calleeF, llvm_call_args, "callMeMaybe");

	indent.pop_back();
	std::cout << indent << "Leave visitEApp" << std::endl;
}

void CodeGen::visitADecl(ADecl *adecl) {
	/* Code For ADecl Goes Here */
	std::cout << indent << "Enter visitADecl" << std::endl;
	indent.push_back('\t');

	val = codegen(adecl->type_);
	visitId(adecl->id_);

	indent.pop_back();
	std::cout << indent << "Leave visitADecl" << std::endl;
}

void CodeGen::visitSExp(SExp *sexp) {
	/* Code For SExp Goes Here */
	std::cout << indent << "Enter visitSExp" << std::endl;
	indent.push_back('\t');

	sexp->exp_->accept(this);

	indent.pop_back();
	std::cout << indent << "Leave visitSExp" << std::endl;
}

void CodeGen::visitSDecls(SDecls *sdecls) {
	/* Code For SDecls Goes Here */
	std::cout << indent << "Enter visitSDecl" << std::endl;


	sdecls->type_->accept(this);
	sdecls->listid_->accept(this);

	std::cout << indent << "Leave visitSDecl" << std::endl;
}

void CodeGen::visitSInit(SInit *sinit) {
	/* Code For SInit Goes Here */
	std::cout << indent << "Enter visitSInit" << std::endl;

	sinit->type_->accept(this);
	visitId(sinit->id_);
	sinit->exp_->accept(this);

	std::cout << indent << "Leave visitSInit" << std::endl;
}


void CodeGen::visitSReturn(SReturn *sreturn)
{
	/* Code For SReturn Goes Here */
	std::cout << indent << "Enter visitSReturn" << std::endl;

	// Füge non-void return statement ein
	// wichtig: darf Insertpoint nicht verändern!
	val = builder.CreateRet(val);

	std::cout << indent << "Leave visitSReturn" << std::endl;
}

void CodeGen::visitSReturnVoid(SReturnVoid *sreturnvoid) {
	std::cout << indent << "Enter visitSReturnVoid" << std::endl;
	val = builder.CreateRetVoid();

	std::cout << indent << "Leave visitSReturnVoid" << std::endl;
}

void CodeGen::visitSWhile(SWhile *swhile) {
	/* Code For SWhile Goes Here */
	std::cout << indent << "Enter visitSWhile" << std::endl;

	swhile->exp_->accept(this);
	swhile->stm_->accept(this);

	std::cout << indent << "Leave visitSWhile" << std::endl;
}

void CodeGen::visitSBlock(SBlock *sblock) {
	/* Code For SBlock Goes Here */
	std::cout << indent << "Enter visitSBlock" << std::endl;

	sblock->liststm_->accept(this);

	std::cout << indent << "Leave visitSBlock" << std::endl;
}

void CodeGen::visitSIfElse(SIfElse *sifelse) {

	std::cout << indent << "Enter visitSIfElse" << std::endl;

	// Hole die Funktion, für die wir gerade Code generieren
	llvm::Function* currentFun = builder.GetInsertBlock()->getParent();

	// Basic Blocks für then, else, merge in der aktuellen Funktion anlegen und einfügen
	llvm::BasicBlock *thenBB = llvm::BasicBlock::Create(context, "thenBlock",
			currentFun);
	llvm::BasicBlock *elseBB = llvm::BasicBlock::Create(context, "elsefBlock",
			currentFun);
	llvm::BasicBlock *mergeBB = llvm::BasicBlock::Create(context, "mergeBlock",
			currentFun);
	/*** Einzelteile generieren ***/

	// Condition-Expression (gehört noch zu entry block)
	Exp* tmp = sifelse->exp_;
	codegen(sifelse->exp_);
	llvm::Value *condExprVal = val;
	if (val == nullptr)
		cout << "Value in Conditional Expression war leer..." << endl;
	condExprVal = builder.CreateFCmpONE(condExprVal,
			llvm::ConstantFP::get(context, llvm::APFloat(0.0)), "ifcond"); // vergleiche mit 0.0
	// Entry block mit Conditional-Branch abschließen
	builder.CreateCondBr(condExprVal, thenBB, elseBB);

	// Then-Statement
	builder.SetInsertPoint(thenBB);
	sifelse->stm_1->accept(this);
	llvm::Value *thenVal = val; // generierten Value für Phi merken
	builder.CreateBr(mergeBB); //then-Block mit Sprung in merge-Block abschließen

	// Else-Statement
	builder.SetInsertPoint(elseBB);
	sifelse->stm_2->accept(this);
	llvm::Value *elseVal = val; // generierten Value für Phi merken
	builder.CreateBr(mergeBB); // else-Block ebenfalls mit Sprung in merge-Block abschließen

	// merge-Block
	builder.SetInsertPoint(mergeBB);
	llvm::PHINode *phiStatement = builder.CreatePHI(
			llvm::Type::getDoubleTy(context), 2, "merge");
	phiStatement->addIncoming(thenVal, thenBB); //wenn wir aus then-Block kommen, übernimm thenValue
	phiStatement->addIncoming(elseVal, elseBB); //wenn wir aus else-Block kommen, übernimm elseValue

	indent.push_back('\t');
	std::cout << indent << "Leave visitSIfElse" << std::endl;
}

void CodeGen::visitETrue(ETrue *etrue) {
	/* Code For ETrue Goes Here */
	std::cout << indent << "Enter visitETrue" << std::endl;
	indent.push_back('\t');
	indent.pop_back();
	std::cout << indent << "Leave visitETrue" << std::endl;
}

void CodeGen::visitEFalse(EFalse *efalse) {
	/* Code For EFalse Goes Here */
	std::cout << indent << "Enter visitEFalse" << std::endl;
	indent.push_back('\t');
	indent.pop_back();
	std::cout << indent << "Leave visitEFalse" << std::endl;
}

void CodeGen::visitEInt(EInt *eint) {
	/* Code For EInt Goes Here */
	std::cout << indent << "Enter visitEInt" << std::endl;
	indent.push_back('\t');

	visitInteger(eint->integer_);

	indent.pop_back();
	std::cout << indent << "Leave visitEInt" << std::endl;
}

void CodeGen::visitEDouble(EDouble *edouble) {
	/* Code For EDouble Goes Here */
	std::cout << indent << "Enter visitEDouble" << std::endl;
	indent.push_back('\t');

	visitDouble(edouble->double_);

	indent.pop_back();
	std::cout << indent << "Leave visitEDouble" << std::endl;
}

void CodeGen::visitEString(EString *estring) {
	/* Code For EString Goes Here */
	std::cout << indent << "Enter visitEString" << std::endl;
	indent.push_back('\t');

	visitString(estring->string_);

	indent.pop_back();
	std::cout << indent << "Leave visitEString" << std::endl;
}

void CodeGen::visitEId(EId *eid) {
	/* Code For EId Goes Here */
	std::cout << indent << "Enter visitEId" << std::endl;
	indent.push_back('\t');

	visitId(eid->id_);

	indent.pop_back();
	std::cout << indent << "Leave visitEId" << std::endl;
}

void CodeGen::visitEPIncr(EPIncr *epincr) {
	/* Code For EPIncr Goes Here */
	std::cout << indent << "Enter visitEPIncr" << std::endl;
	indent.push_back('\t');

	epincr->exp_->accept(this);

	indent.pop_back();
	std::cout << indent << "Leave visitEPIncr" << std::endl;
}

void CodeGen::visitEPDecr(EPDecr *epdecr) {
	/* Code For EPDecr Goes Here */
	std::cout << indent << "Enter visitEPDecr" << std::endl;
	indent.push_back('\t');
	epdecr->exp_->accept(this);
	indent.pop_back();
	std::cout << indent << "Leave visitEPDecr" << std::endl;
}

void CodeGen::visitEIncr(EIncr *eincr) {
	/* Code For EIncr Goes Here */
	std::cout << indent << "Enter visitEIncr" << std::endl;
	indent.push_back('\t');

	llvm::Value *L = codegen(eincr->exp_);
	llvm::Value *One = llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 1);

	val = builder.CreateAdd(L, One, "multmp");
	indent.pop_back();
	std::cout << indent << "Leave visitEIncr" << std::endl;
}

void CodeGen::visitEDecr(EDecr *edecr) {
	/* Code For EDecr Goes Here */
	std::cout << indent << "Enter visitEDecr" << std::endl;
	indent.push_back('\t');

	llvm::Value *L = codegen(edecr->exp_);
	llvm::Value *One = llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 1);

	val = builder.CreateSub(L, One, "multmp");

	indent.pop_back();
	std::cout << "Leave visitEDecr" << std::endl;
}

void CodeGen::visitETimes(ETimes *etimes) {
	/* Code For ETimes Goes Here */
	std::cout << indent << "Enter visitETimes" << std::endl;

	llvm::Value *L = codegen(etimes->exp_1);
	llvm::Value *R = codegen(etimes->exp_2);

	val = builder.CreateMul(L, R, "multmp");

	std::cout << indent << "Leave visitETimes" << std::endl;
}

void CodeGen::visitEDiv(EDiv *ediv) {
	/* Code For EDiv Goes Here */
	std::cout << indent << "Enter visitEDiv" << std::endl;

	llvm::Value *L = codegen(ediv->exp_1);
	llvm::Value *R = codegen(ediv->exp_2);

	val = builder.CreateExactUDiv(L, R, "divtmp");

	std::cout << indent << "Leave visitEDiv" << std::endl;
}

void CodeGen::visitEPlus(EPlus *eplus) {
	/* Code For EPlus Goes Here */
	std::cout << indent << "Enter visitEPlus" << std::endl;

	llvm::Value *L = codegen(eplus->exp_1);
	llvm::Value *R = codegen(eplus->exp_2);

	val = builder.CreateAdd(L, R, "addtmp");

	std::cout << indent << "Leave visitEPlus" << std::endl;
}

void CodeGen::visitEMinus(EMinus *eminus) {
	/* Code For EMinus Goes Here */
	std::cout << indent << "Enter visitEMinus" << std::endl;

	llvm::Value *L = codegen(eminus->exp_1);
	llvm::Value *R = codegen(eminus->exp_2);

	val = builder.CreateSub(L, R, "subtmp");

	std::cout << indent << "Leave visitEMinus" << std::endl;
}

void CodeGen::printGeneratedIR() {
	TheModule.dump();
}

void CodeGen::visitELt(ELt *elt) {
	/* Code For ELt Goes Here */
	std::cout << indent << "Enter visitELt" << std::endl;

	llvm::Value *L = codegen(elt->exp_1);
	llvm::Value *R = codegen(elt->exp_2);

	val = builder.CreateFCmpULT(L, R, "cmptmp");

	std::cout << indent << "Leave visitELt" << std::endl;
}

void CodeGen::visitEGt(EGt *egt) {
	/* Code For EGt Goes Here */
	std::cout << indent << "Enter visitEGt" << std::endl;

	llvm::Value *L = codegen(egt->exp_1);
	llvm::Value *R = codegen(egt->exp_2);

	val = builder.CreateFCmpULT(L, R, "cmptmp");

	std::cout << indent << "Leave visitEGt" << std::endl;
}

void CodeGen::visitELtEq(ELtEq *elteq) {
	/* Code For ELtEq Goes Here */
	std::cout << indent << "Enter visitELtEq" << std::endl;

	llvm::Value *L = codegen(elteq->exp_1);
	llvm::Value *R = codegen(elteq->exp_2);

	val = builder.CreateFCmpULE(L, R, "cmptmp");

	std::cout << indent << "Leave visitELtEq" << std::endl;
}

void CodeGen::visitEGtEq(EGtEq *egteq) {
	/* Code For EGtEq Goes Here */
	std::cout << indent << "Enter visitEGtEq" << std::endl;

	llvm::Value *L = codegen(egteq->exp_1);
	llvm::Value *R = codegen(egteq->exp_2);

	val = builder.CreateFCmpUGE(L, R, "cmptmp");

	std::cout << indent << "Leave visitEGtEq" << std::endl;
}

void CodeGen::visitEEq(EEq *eeq) {
	/* Code For EEq Goes Here */
	std::cout << indent << "Enter visitEEq" << std::endl;

	llvm::Value *L = codegen(eeq->exp_1);
	llvm::Value *R = codegen(eeq->exp_2);

	val = builder.CreateFCmpUEQ(L, R, "cmptmp");

	std::cout << indent << "Leave visitEEq" << std::endl;
}

void CodeGen::visitENEq(ENEq *eneq) {
	/* Code For ENEq Goes Here */
	std::cout << indent << "Enter visitENEq" << std::endl;

	llvm::Value *L = codegen(eneq->exp_1);
	llvm::Value *R = codegen(eneq->exp_2);

	val = builder.CreateFCmpUNE(L, R, "cmptmp");

	std::cout << indent << "Leave visitENEq" << std::endl;
}

void CodeGen::visitEAnd(EAnd *eand) {
	/* Code For EAnd Goes Here */
	std::cout << indent << "Enter visitEAnd" << std::endl;

	llvm::Value *L = codegen(eand->exp_1);
	llvm::Value *R = codegen(eand->exp_2);

	val = builder.CreateAnd(L, R, "and");

	std::cout << indent << "Leave visitEAnd" << std::endl;
}

void CodeGen::visitEOr(EOr *eor) {
	/* Code For EOr Goes Here */
	std::cout << indent << "Enter visitEOr" << std::endl;

	llvm::Value *L = codegen(eor->exp_1);
	llvm::Value *R = codegen(eor->exp_2);

	val = builder.CreateOr(L, R, "or");

	std::cout << indent << "Leave visitEOr" << std::endl;
}

void CodeGen::visitEAss(EAss *eass) {
	/* Code For EAss Goes Here */
	std::cout << indent << "Enter visitEAss" << std::endl;

	eass->exp_1->accept(this);
	eass->exp_2->accept(this);

	std::cout << indent << "Leave visitEAss" << std::endl;
}

void CodeGen::visitETyped(ETyped *etyped) {
	/* Code For ETyped Goes Here */
	std::cout << indent << "Enter visitETyped" << std::endl;

	etyped->exp_->accept(this);
	etyped->type_->accept(this);

	std::cout << indent << "Leave visitETyped" << std::endl;
}

void CodeGen::visitType_bool(Type_bool *type_bool) {
	/* Code For Type_bool Goes Here */
	std::cout << indent << "Enter visitType_bool" << std::endl;
	type = llvm::Type::getInt1Ty(context);
	std::cout << indent << "Leave visitType_bool" << std::endl;

}

void CodeGen::visitType_int(Type_int *type_int) {
	/* Code For Type_int Goes Here */
	std::cout << indent << "Enter visitType_int" << std::endl;
	type = llvm::Type::getInt32Ty(context);
	std::cout << indent << "Leave visitType_int" << std::endl;
}

void CodeGen::visitType_double(Type_double *type_double) {
	/* Code For Type_double Goes Here */
	std::cout << indent << "Enter visitType_double" << std::endl;
	type = llvm::Type::getDoubleTy(context);
	std::cout << indent << "Leave visitType_double" << std::endl;
}

void CodeGen::visitType_void(Type_void *type_void) {
	/* Code For Type_void Goes Here */
	std::cout << indent << "Enter visitType_void" << std::endl;
	type = llvm::Type::getVoidTy(context);
	std::cout << indent << "Leave visitType_void" << std::endl;
}

void CodeGen::visitType_string(Type_string *type_string) {
	/* Code For Type_string Goes Here */
	std::cout << indent << "Enter visitType_string" << std::endl;
	std::cout << indent << "Error no String Support" << std::endl; //TODO
	std::cout << indent << "Leave visitType_string" << std::endl;
}

void CodeGen::visitListArg(ListArg* listarg) {
	std::cout << indent << "Enter visitListArg" << std::endl;
//	for (ListArg::iterator i = listarg->begin() ; i != listarg->end() ; ++i)
//	{
//		(*i)->accept(this);
//	}

	// TODO Funktionsargumente in NamedValues eintragen?

	std::cout << indent << "Leave visitListArg" << std::endl;
}

void CodeGen::visitListStm(ListStm* liststm)
{
	std::cout << indent << "Enter visitListStm" << std::endl;
	indent.push_back('\t');
	for (ListStm::iterator i = liststm->begin() ; i != liststm->end() ; ++i)
	{
		(*i)->accept(this);
	}
	indent.pop_back();
	std::cout << indent << "Leave visitListStm" << std::endl;
}

void CodeGen::visitListExp(ListExp* listexp)
{
	std::cout << indent << "Enter visitListExp" << std::endl;

	for (ListExp::iterator i = listexp->begin() ; i != listexp->end() ; ++i)
	{
		(*i)->accept(this);
	}

	std::cout << indent << "Leave visitListExp" << std::endl;
}

void CodeGen::visitListId(ListId* listid)
{
	std::cout << indent << "Enter visitListId" << std::endl;

	for (ListId::iterator i = listid->begin() ; i != listid->end() ; ++i)
	{
		visitId(*i) ;
	}

	std::cout << indent << "Leave visitListId" << std::endl;
}

void CodeGen::visitId(Id x) {
	/* Code for Id Goes Here */
	std::cout << indent << "Enter visitId" << std::endl;
	val = // TODO lookup in named values
	std::cout << indent << "Leave visitId" << std::endl;
}

void CodeGen::visitInteger(Integer x) {
	/* Code for Integer Goes Here */
	std::cout << indent << "Enter visitInteger" << std::endl;
	indent.push_back('\t');
	cout << indent << "leaf (" << x <<")" << endl;
	val = llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), x);
	indent.pop_back();
	std::cout << indent << "Leave visitInteger" << std::endl;
}

void CodeGen::visitChar(Char x) {
	/* Code for Char Goes Here */
	std::cout << indent << "Enter visitChar" << std::endl;
	indent.push_back('\t');

	indent.pop_back();
	std::cout << indent << "Leave visitChar" << std::endl;
}

void CodeGen::visitDouble(Double x) {
	/* Code for Double Goes Here */
	std::cout << indent << "Enter visitDouble" << std::endl;
	indent.push_back('\t');

	indent.pop_back();
	std::cout << indent << "Leave visitDouble" << std::endl;
}

void CodeGen::visitString(String x) {
	/* Code for String Goes Here */
	std::cout << indent << "Enter visitString" << std::endl;
	indent.push_back('\t');

	indent.pop_back();
	std::cout << indent << "Leave visitString" << std::endl;
}

void CodeGen::visitIdent(Ident x) {
	/* Code for Ident Goes Here */
	std::cout << indent << "Enter visitIdent" << std::endl;
	indent.push_back('\t');

	indent.pop_back();
	std::cout << indent << "Leave visitIdent" << std::endl;
}
