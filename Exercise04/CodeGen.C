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

		string temp=proto->id_;
		llvm::Function *f = TheModule.getFunction(proto->id_);
		// Übersringe, falls f schon in Modul vorhanden (angenommen keine Überladung)
		if (f != nullptr) {
				continue;
		}
		// Baue llvm Funktionstyp auf
		// Alle Typen sind llvm doubles
		vector<llvm::Type*> protoArgs;

		for (ListArg::iterator arg_it = proto->listarg_->begin(); arg_it != proto->listarg_->end(); arg_it++) {
			ADecl* adecl = (ADecl*) *arg_it;
			protoArgs.push_back(typegen(adecl->type_));
		}

		llvm::FunctionType* llvm_funType = llvm::FunctionType::get(typegen(proto->type_), protoArgs, false);

		// Generiere Funktion unter dem vom Prototypen gegebenen Namen im Modul
		llvm::Function* llvm_fun = llvm::Function::Create(llvm_funType, llvm::Function::ExternalLinkage, proto->id_, &TheModule);

		// Zwecks besserer Lesbarkeit des IR dumps Namen der Argumente setzen
		ListArg::iterator listarg = proto->listarg_->begin();
		for (auto &arg : llvm_fun->args()) {
			arg.setName(((ADecl*) *listarg)->id_);
			listarg++;
		}

		//val=codegen(proto);
	}
	llvm::BasicBlock *BB = llvm::BasicBlock::Create(context, "entry", f);
	builder.SetInsertPoint(BB);

	//codegen(proto->liststm_);
	indent.pop_back();
	std::cout << indent << "Leave visitListDef" << std::endl;

}

/* Funktionsdefinition besuchen*/
void CodeGen::visitDFun(DFun *dfun) {

	std::cout << indent << "Enter visitDFun: " << dfun->id_ << std::endl;
	indent.push_back('\t');

	// Überspringen, wenn für diese Funktion schon Code generiert wurde
	// TODO Polymorphe Funktionen
	llvm::Function *TheFunction = TheModule.getFunction(dfun->id_);
	if (TheFunction != nullptr) {
		indent.pop_back();
		std::cout << indent << "Leave visitDFun" << std::endl;
		return;
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
	val = codegen(dfun->liststm_);

	// rekursiver Aufruf kann den Builder Insert Point verschieben
	// => auf aktuellen Block setzen
	builder.SetInsertPoint(entryBlock);

	// generiere return statement
	// Falls der Insertpoint bei rekursivem Aufruf auf einen anderen Block gesetzt wurde,
	// wird das return statement in jenem Block generiert
	codegen(dfun->type_);

	// Validieren
	llvm::verifyFunction(*TheFunction);

	// fertige Funktion als "Rückgabewert" speichern
	val = TheFunction;

	indent.pop_back();
	std::cout << "Leave visitDFun" << std::endl;
}
/* Funktionsaufruf besuchen */
void CodeGen::visitEApp(EApp *eapp) {
	std::cout << "Enter visitEApp" << std::endl;
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

	std::cout << "Leave visitEApp" << std::endl;
}

void CodeGen::visitADecl(ADecl *adecl) {
	/* Code For ADecl Goes Here */
	std::cout << "Enter visitADecl" << std::endl;


	val = codegen(adecl->type_);
	visitId(adecl->id_);

	std::cout << "Leave visitADecl" << std::endl;
}

void CodeGen::visitSExp(SExp *sexp) {
	/* Code For SExp Goes Here */
	std::cout << "Enter visitSExp" << std::endl;

	sexp->exp_->accept(this);

	std::cout << "Leave visitSExp" << std::endl;
}

void CodeGen::visitSDecls(SDecls *sdecls) {
	/* Code For SDecls Goes Here */
	std::cout << "Enter visitSDecl" << std::endl;


	sdecls->type_->accept(this);
	sdecls->listid_->accept(this);

	std::cout << "Leave visitSDecl" << std::endl;
}

void CodeGen::visitSInit(SInit *sinit) {
	/* Code For SInit Goes Here */
	std::cout << "Enter visitSInit" << std::endl;

	sinit->type_->accept(this);
	visitId(sinit->id_);
	sinit->exp_->accept(this);

	std::cout << "Leave visitSInit" << std::endl;
}


void CodeGen::visitSReturn(SReturn *sreturn)
{
	/* Code For SReturn Goes Here */
	std::cout << "Enter visitSReturn" << std::endl;

	// Füge non-void return statement ein
	// wichtig: darf Insertpoint nicht verändern!
	val = builder.CreateRet(val);

	std::cout << "Leave visitSReturn" << std::endl;
}

void CodeGen::visitSReturnVoid(SReturnVoid *sreturnvoid) {
	std::cout << "Enter visitSReturnVoid" << std::endl;
	val = builder.CreateRetVoid();

	std::cout << "Leave visitSReturnVoid" << std::endl;
}

void CodeGen::visitSWhile(SWhile *swhile) {
	/* Code For SWhile Goes Here */
	std::cout << "Enter visitSWhile" << std::endl;

	swhile->exp_->accept(this);
	swhile->stm_->accept(this);

	std::cout << "Leave visitSWhile" << std::endl;
}

void CodeGen::visitSBlock(SBlock *sblock) {
	/* Code For SBlock Goes Here */
	std::cout << "Enter visitSBlock" << std::endl;

	sblock->liststm_->accept(this);

	std::cout << "Leave visitSBlock" << std::endl;
}

void CodeGen::visitSIfElse(SIfElse *sifelse) {

	std::cout << "Enter visitSIfElse" << std::endl;

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
	sifelse->exp_->accept(this);
	llvm::Value *condExprVal = val;
	// TODO if (!val) ?
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

	std::cout << "Leave visitSIfElse" << std::endl;
}

void CodeGen::visitETrue(ETrue *etrue) {
	/* Code For ETrue Goes Here */
	std::cout << "Enter visitETrue" << std::endl;
	std::cout << "Leave visitETrue" << std::endl;
}

void CodeGen::visitEFalse(EFalse *efalse) {
	/* Code For EFalse Goes Here */
	std::cout << "Enter visitEFalse" << std::endl;
	std::cout << "Leave visitEFalse" << std::endl;
}

void CodeGen::visitEInt(EInt *eint) {
	/* Code For EInt Goes Here */
	std::cout << "Enter visitEInt" << std::endl;

	visitInteger(eint->integer_);

	std::cout << "Leave visitEInt" << std::endl;
}

void CodeGen::visitEDouble(EDouble *edouble) {
	/* Code For EDouble Goes Here */
	std::cout << "Enter visitEDouble" << std::endl;

	visitDouble(edouble->double_);

	std::cout << "Leave visitEDouble" << std::endl;
}

void CodeGen::visitEString(EString *estring) {
	/* Code For EString Goes Here */
	std::cout << "Enter visitEString" << std::endl;

	visitString(estring->string_);

	std::cout << "Leave visitEString" << std::endl;
}

void CodeGen::visitEId(EId *eid) {
	/* Code For EId Goes Here */
	std::cout << "Enter visitEId" << std::endl;

	visitId(eid->id_);

	std::cout << "Leave visitEId" << std::endl;
}

void CodeGen::visitEPIncr(EPIncr *epincr) {
	/* Code For EPIncr Goes Here */
	std::cout << "Enter visitEPIncr" << std::endl;

	epincr->exp_->accept(this);

	std::cout << "Leave visitEPIncr" << std::endl;
}

void CodeGen::visitEPDecr(EPDecr *epdecr) {
	/* Code For EPDecr Goes Here */
	std::cout << "Enter visitEPDecr" << std::endl;

	epdecr->exp_->accept(this);

	std::cout << "Leave visitEPDecr" << std::endl;
}

void CodeGen::visitEIncr(EIncr *eincr) {
	/* Code For EIncr Goes Here */
	std::cout << "Enter visitEIncr" << std::endl;

	eincr->exp_->accept(this);

	std::cout << "Leave visitEIncr" << std::endl;
}

void CodeGen::visitEDecr(EDecr *edecr) {
	/* Code For EDecr Goes Here */
	std::cout << "Enter visitsEDecr" << std::endl;

	edecr->exp_->accept(this);

	std::cout << "Leave visitsEDecr" << std::endl;
}

void CodeGen::visitETimes(ETimes *etimes) {
	/* Code For ETimes Goes Here */
	std::cout << "Enter visitETimes" << std::endl;

	etimes->exp_1->accept(this);
	etimes->exp_2->accept(this);

	std::cout << "Leave visitETimes" << std::endl;
}

void CodeGen::visitEDiv(EDiv *ediv) {
	/* Code For EDiv Goes Here */
	std::cout << "Enter visitEDiv" << std::endl;

	ediv->exp_1->accept(this);
	ediv->exp_2->accept(this);

	std::cout << "Leave visitEDiv" << std::endl;
}

void CodeGen::visitEPlus(EPlus *eplus) {
	/* Code For EPlus Goes Here */
	std::cout << "Enter visitEPlus" << std::endl;

	eplus->exp_1->accept(this);
	eplus->exp_2->accept(this);

	std::cout << "Leave visitEPlus" << std::endl;
}

void CodeGen::visitEMinus(EMinus *eminus) {
	/* Code For EMinus Goes Here */
	std::cout << "Enter visitEMinus" << std::endl;

	eminus->exp_1->accept(this);
	eminus->exp_2->accept(this);

	std::cout << "Leave visitEMinus" << std::endl;
}

void CodeGen::printGeneratedIR() {
	TheModule.dump();
}

void CodeGen::visitELt(ELt *elt) {
	/* Code For ELt Goes Here */
	std::cout << "Enter visitELt" << std::endl;

	elt->exp_1->accept(this);
	elt->exp_2->accept(this);

	std::cout << "Leave visitELt" << std::endl;
}

void CodeGen::visitEGt(EGt *egt) {
	/* Code For EGt Goes Here */
	std::cout << "Enter visitEGt" << std::endl;

	egt->exp_1->accept(this);
	egt->exp_2->accept(this);

	std::cout << "Leave visitEGt" << std::endl;
}

void CodeGen::visitELtEq(ELtEq *elteq) {
	/* Code For ELtEq Goes Here */
	std::cout << "Enter visitELtEq" << std::endl;

	elteq->exp_1->accept(this);
	elteq->exp_2->accept(this);

	std::cout << "Leave visitELtEq" << std::endl;
}

void CodeGen::visitEGtEq(EGtEq *egteq) {
	/* Code For EGtEq Goes Here */
	std::cout << "Enter visitEGtEq" << std::endl;

	egteq->exp_1->accept(this);
	egteq->exp_2->accept(this);

	std::cout << "Leave visitEGtEq" << std::endl;
}

void CodeGen::visitEEq(EEq *eeq) {
	/* Code For EEq Goes Here */
	std::cout << "Enter visitEEq" << std::endl;

	eeq->exp_1->accept(this);
	eeq->exp_2->accept(this);

	std::cout << "Leave visitEEq" << std::endl;
}

void CodeGen::visitENEq(ENEq *eneq) {
	/* Code For ENEq Goes Here */
	std::cout << "Enter visitENEq" << std::endl;

	eneq->exp_1->accept(this);
	eneq->exp_2->accept(this);

	std::cout << "Leave visitENEq" << std::endl;
}

void CodeGen::visitEAnd(EAnd *eand) {
	/* Code For EAnd Goes Here */
	std::cout << "Enter visitEAnd" << std::endl;

	eand->exp_1->accept(this);
	eand->exp_2->accept(this);

	std::cout << "Leave visitEAnd" << std::endl;
}

void CodeGen::visitEOr(EOr *eor) {
	/* Code For EOr Goes Here */
	std::cout << "Enter visitEOr" << std::endl;

	eor->exp_1->accept(this);
	eor->exp_2->accept(this);

	std::cout << "Leave visitEOr" << std::endl;
}

void CodeGen::visitEAss(EAss *eass) {
	/* Code For EAss Goes Here */
	std::cout << "Enter visitEAss" << std::endl;

	eass->exp_1->accept(this);
	eass->exp_2->accept(this);

	std::cout << "Leave visitEAss" << std::endl;
}

void CodeGen::visitETyped(ETyped *etyped) {
	/* Code For ETyped Goes Here */
	std::cout << "Enter visitETyped" << std::endl;

	etyped->exp_->accept(this);
	etyped->type_->accept(this);

	std::cout << "Leave visitETyped" << std::endl;
}

void CodeGen::visitType_bool(Type_bool *type_bool) {
	/* Code For Type_bool Goes Here */
	std::cout << "Enter visitType_bool" << std::endl;
	type = llvm::Type::getInt1Ty(context);
	std::cout << "Leave visitType_bool" << std::endl;

}

void CodeGen::visitType_int(Type_int *type_int) {
	/* Code For Type_int Goes Here */
	std::cout << "Enter visitType_int" << std::endl;
	type = llvm::Type::getInt32Ty(context);
	std::cout << "Leave visitType_int" << std::endl;
}

void CodeGen::visitType_double(Type_double *type_double) {
	/* Code For Type_double Goes Here */
	std::cout << "Enter visitType_double" << std::endl;
	type = llvm::Type::getDoubleTy(context);
	std::cout << "Leave visitType_double" << std::endl;
}

void CodeGen::visitType_void(Type_void *type_void) {
	/* Code For Type_void Goes Here */
	std::cout << "Enter visitType_void" << std::endl;
	type = llvm::Type::getVoidTy(context);
	std::cout << "Leave visitType_void" << std::endl;
}

void CodeGen::visitType_string(Type_string *type_string) {
	/* Code For Type_string Goes Here */
	std::cout << "Enter visitType_string" << std::endl;
	std::cout << "Error no String Support" << std::endl; //TODO
	std::cout << "Leave visitType_string" << std::endl;
}

void CodeGen::visitListArg(ListArg* listarg) {
	std::cout << "Enter visitListArg" << std::endl;
//	for (ListArg::iterator i = listarg->begin() ; i != listarg->end() ; ++i)
//	{
//		(*i)->accept(this);
//	}

	// TODO Funktionsargumente in NamedValues eintragen?

	std::cout << "Leave visitListArg" << std::endl;
}

void CodeGen::visitListStm(ListStm* liststm)
{
	std::cout << "Enter visitListStm" << std::endl;
	for (ListStm::iterator i = liststm->begin() ; i != liststm->end() ; ++i)
	{
		(*i)->accept(this);
	}
	std::cout << "Leave visitListStm" << std::endl;
}

void CodeGen::visitListExp(ListExp* listexp)
{
	std::cout << "Enter visitListExp" << std::endl;

	for (ListExp::iterator i = listexp->begin() ; i != listexp->end() ; ++i)
	{
		(*i)->accept(this);
	}

	std::cout << "Leave visitListExp" << std::endl;
}

void CodeGen::visitListId(ListId* listid)
{
	std::cout << "Enter visitListId" << std::endl;

	for (ListId::iterator i = listid->begin() ; i != listid->end() ; ++i)
	{
		visitId(*i) ;
	}

	std::cout << "Leave visitListId" << std::endl;
}

void CodeGen::visitId(Id x) {
	/* Code for Id Goes Here */
	std::cout << "Enter visitId" << std::endl;
	std::cout << "Leave visitId" << std::endl;
}

void CodeGen::visitInteger(Integer x) {
	/* Code for Integer Goes Here */
	std::cout << "Enter visitInteger" << std::endl;
	std::cout << "Leave visitInteger" << std::endl;
}

void CodeGen::visitChar(Char x) {
	/* Code for Char Goes Here */
	std::cout << "Enter visitChar" << std::endl;
	std::cout << "Leave visitChar" << std::endl;
}

void CodeGen::visitDouble(Double x) {
	/* Code for Double Goes Here */
	std::cout << "Enter visitDouble" << std::endl;
	std::cout << "Leave visitDouble" << std::endl;
}

void CodeGen::visitString(String x) {
	/* Code for String Goes Here */
	std::cout << "Enter visitString" << std::endl;
	std::cout << "Leave visitString" << std::endl;
}

void CodeGen::visitIdent(Ident x) {
	/* Code for Ident Goes Here */
	std::cout << "Enter visitIdent" << std::endl;
	std::cout << "Leave visitIdent" << std::endl;
}
