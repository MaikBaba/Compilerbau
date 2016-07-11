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
	indent.push_back('\t');
	std::cout << indent << "---------------- " << std::endl;
	


	// Überspringen, wenn für diese Funktion schon Code generiert wurde
	// TODO Polymorphe Funktionen
	llvm::Function *TheFunction = TheModule.getFunction(dfun->id_);
	if (TheFunction != nullptr) {
		

		indent.pop_back();
		std::cout << indent << "Leave visitDFun (redecl)" << std::endl;
		return;
	}
	// Baue llvm Funktionstyp auf
	// Hole dazu die richtigen Argumenttypen via typegen
	// Für jedes Argument Speicher allokieren und in NamedValues eintragen
	std::cout << indent << "Signatur: " << dfun->id_ << std::endl;
	vector<llvm::Type*> protoArgs;
	for (ListArg::iterator arg_it = dfun->listarg_->begin(); arg_it != dfun->listarg_->end(); arg_it++) {
		ADecl* adecl = (ADecl*) *arg_it;
		llvm::Type* argType = typegen(adecl->type_);
		protoArgs.push_back(argType);
	}

	llvm::Type* llvm_ret_type = typegen(dfun->type_);
	llvm::FunctionType* llvm_funType = llvm::FunctionType::get(llvm_ret_type, protoArgs, false);
	
	// Generiere Funktion unter dem vom Prototypen gegebenen Namen im Modul
	TheFunction = llvm::Function::Create(llvm_funType, llvm::Function::ExternalLinkage, dfun->id_, &TheModule);

	/* generiere einen einzigen entry block
	 * Branching statements müssen selbst Blöcke generieren
	 * und den insert point ändern */
	llvm::BasicBlock* entryBlock = llvm::BasicBlock::Create(context, "entry",
			TheFunction);
	builder.SetInsertPoint(entryBlock);

	// Namen der Argumente setzen
	// Lokale Kopie erstellen und Name der Kopie eintragen
	ListArg::iterator listarg = dfun->listarg_->begin();
	NamedValues.clear();
	for (auto &arg : TheFunction->args()) {
		string argName = ((ADecl*) *listarg)->id_;
		arg.setName(argName);
		allocateStoreName(argName, arg.getType(), &arg);
		listarg++;
	}

	// generiere Code für die Statements im Body
	std::cout << indent << "Body:" << std::endl;
	val = codegen(dfun->liststm_);
	
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
	// TODO
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
indent.push_back('\t');


	sdecls->type_->accept(this);
	sdecls->listid_->accept(this);

	indent.pop_back();
	std::cout << indent << "Leave visitSDecl" << std::endl;
}

void CodeGen::visitSInit(SInit *sinit) {
	/* Code For SInit Goes Here */
	std::cout << indent << "Enter visitSInit" << std::endl;
indent.push_back('\t');

	// TODO welche Variablen brauchen wir nicht?
	llvm::Value* expr = codegen(sinit->exp_);
	llvm::Type*  type = typegen(sinit->type_);
	val = allocateStoreName(sinit->id_,type, expr);
	indent.pop_back();
	std::cout << indent << "Leave visitSInit" << std::endl;
}


void CodeGen::visitSReturn(SReturn *sreturn)
{
	/* Code For SReturn Goes Here */
	std::cout << indent << "Enter visitSReturn" << std::endl;
	indent.push_back('\t');

	// Füge non-void return statement ein
	// wichtig: darf Insertpoint nicht verändern!
	val = builder.CreateRet(val);

	indent.pop_back();
	std::cout << indent << "Leave visitSReturn" << std::endl;
}

void CodeGen::visitSReturnVoid(SReturnVoid *sreturnvoid) {
	std::cout << indent << "Enter visitSReturnVoid" << std::endl;
	indent.push_back('\t');
	val = builder.CreateRetVoid();

	indent.pop_back();
	std::cout << indent << "Leave visitSReturnVoid" << std::endl;
}

void CodeGen::visitSWhile(SWhile *swhile) {
	/* Code For SWhile Goes Here */
	std::cout << indent << "Enter visitSWhile" << std::endl;
	indent.push_back('\t');

	// Hole die Funktion, für die wir gerade Code generieren
	llvm::Function* currentFun = builder.GetInsertBlock()->getParent();

	llvm::BasicBlock *checkBB = llvm::BasicBlock::Create(context);
	llvm::BasicBlock *whileBB = llvm::BasicBlock::Create(context);
	llvm::BasicBlock *endBB = llvm::BasicBlock::Create(context);

	currentFun->getBasicBlockList().push_back(checkBB);
	builder.SetInsertPoint(checkBB);
	llvm::Value *con = codegen(swhile->exp_);
	builder.CreateCondBr(con, whileBB, endBB);
	checkBB = builder.GetInsertBlock();

	currentFun->getBasicBlockList().push_back(whileBB);
	builder.SetInsertPoint(whileBB);
	llvm::Value* stm = codegen(swhile->stm_);
	builder.CreateBr(checkBB);
	whileBB = builder.GetInsertBlock();

	currentFun->getBasicBlockList().push_back(endBB);
	builder.SetInsertPoint(endBB);
	endBB = builder.GetInsertBlock();

	indent.pop_back();
	std::cout << indent << "Leave visitSWhile" << std::endl;
}

void CodeGen::visitSBlock(SBlock *sblock) {
	/* Code For SBlock Goes Here */
	std::cout << indent << "Enter visitSBlock" << std::endl;
indent.push_back('\t');

	sblock->liststm_->accept(this);

	indent.pop_back();
	std::cout << indent << "Leave visitSBlock" << std::endl;
}

void CodeGen::visitSIfElse(SIfElse *sifelse) {

	std::cout << indent << "Enter visitSIfElse" << std::endl;
	indent.push_back('\t');

	// Hole die Funktion, für die wir gerade Code generieren
	llvm::Function* currentFun = builder.GetInsertBlock()->getParent();

	// TODO je nach Typ richtigen 0 holen
	llvm::Value *condExprVal = codegen(sifelse->exp_);
	llvm::Type* condExprType = typegen(sifelse->exp_);
	printGeneratedIR();
	llvm::Type* llvm_IntType = llvm::Type::getInt32Ty(context);
	llvm::Type* llvm_FloatType = llvm::Type::getFloatTy(context);
	llvm::Type* llvm_DoubleType = llvm::Type::getDoubleTy(context);

	// Compare wird immer mit Double erstellt. Nötigenfalls konvertieren oder Fehler schmeißen
	if(condExprType != llvm_DoubleType) {
		if(condExprType == llvm_FloatType) {
			//convert float to double
			condExprVal = builder.CreateFPExt(condExprVal, llvm_DoubleType, "castFloatToDouble");
		}
		else if (condExprType == llvm_IntType) {
			// convert int to double
			condExprVal = builder.CreateIntCast(condExprVal, llvm_DoubleType, true, "castIntToDouble");
		}
		else {
			throw new CodeGenException("In Condition: Expression must evaluate to Float or Int32");
		}
	}

	cout << "HALLOOOOOOOOO " << endl;
	llvm::Constant::getNullValue(llvm::Type::getDoubleTy(context))->dump();
	condExprVal->getType()->dump();
	condExprVal->dump();

	llvm::ConstantFP::get(llvm_DoubleType, 0)->dump();
	condExprVal = builder.CreateFCmpONE(
			condExprVal,
			//llvm::ConstantFP::get(context, llvm::APFloat(0.0)), // compare to 0.0
			llvm::ConstantFP::get(llvm::Type::getDoubleTy(context), 0.0),
			"ifcond");

//get(llvm::Type::getInt32Ty(context)
	// Basic Blocks für then, else, merge erstellen (noch nicht einfügen)
	llvm::BasicBlock *thenBB = llvm::BasicBlock::Create(context, "thenBlock",
			currentFun);
	llvm::BasicBlock *elseBB = llvm::BasicBlock::Create(context, "elseBlock");
	llvm::BasicBlock *mergeBB = llvm::BasicBlock::Create(context, "mergeBlock");

	// Entry block mit Conditional-Branch abschließen
	builder.CreateCondBr(condExprVal, thenBB, elseBB);

	/*** Einzelteile generieren ***/

	// Then-Statement
	builder.SetInsertPoint(thenBB);
	llvm::Value *thenVal = codegen(sifelse->stm_1); // generierten Value für Phi merken
	builder.CreateBr(mergeBB); //then-Block mit Sprung in merge-Block abschließen
	thenBB = builder.GetInsertBlock();

	// Else-Statement
	currentFun->getBasicBlockList().push_back(elseBB);
	builder.SetInsertPoint(elseBB);
	llvm::Value *elseVal = codegen(sifelse->stm_2); // generierten Value für Phi merken
	builder.CreateBr(mergeBB); // else-Block ebenfalls mit Sprung in merge-Block abschließen
	elseBB = builder.GetInsertBlock();

	printGeneratedIR();

	// merge-Block
	currentFun->getBasicBlockList().push_back(mergeBB);
	printGeneratedIR();
	builder.SetInsertPoint(mergeBB);
	llvm::PHINode *phiStatement = builder.CreatePHI(
			//llvm::Type::getDoubleTy(context), 2, "merge");
			llvm::Type::getInt32Ty(context), 2, "merge");
	phiStatement->addIncoming(thenVal, thenBB); //wenn wir aus then-Block kommen, übernimm thenValue
	phiStatement->addIncoming(elseVal, elseBB); //wenn wir aus else-Block kommen, übernimm elseValue

	

	indent.pop_back();
	std::cout << indent << "Leave visitSIfElse" << std::endl;
}

void CodeGen::visitETrue(ETrue *etrue) {
	/* Code For ETrue Goes Here */
	std::cout << indent << "Enter visitETrue" << std::endl;
	indent.push_back('\t');
	// TODO true zu 1 evaluieren -> create constant int 1

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

	


	llvm::Value *expr = codegen(epincr->exp_);
	std::cout << "This point is reached1" << std::endl;
	llvm::Value *One = llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 1);
	std::cout << "This point is reached2" << std::endl;
	llvm::Value *Trial = llvm::ConstantFP::get(llvm::Type::getDoubleTy(context), 1);
	std::cout << "This point is reached3" << std::endl;

	printType(expr->getType()->getTypeID());
	printType(One->getType()->getTypeID());
	printType(Trial->getType()->getTypeID());

	//llvm::Value* tmp = builder.CreateAdd(expr, One, "Incr");
	llvm::Value* tmp2 = builder.CreateFAdd(expr, Trial, "IncrFP");
	std::cout << "This point is reached4" << std::endl;
	printType(tmp2->getType()->getTypeID());
	val = builder.CreateStore(expr, tmp2);

	

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

	val = builder.CreateAdd(L, One, "Incr");
	// TODO store111

	indent.pop_back();
	std::cout << indent << "Leave visitEIncr" << std::endl;
}

void CodeGen::visitEDecr(EDecr *edecr) {
	/* Code For EDecr Goes Here */
	std::cout << indent << "Enter visitEDecr" << std::endl;
	indent.push_back('\t');

	llvm::Value *L = codegen(edecr->exp_);
	llvm::Value *One = llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 1);

	val = builder.CreateSub(L, One, "Decr");

	std::cout << "Leave visitEDecr" << std::endl;
}

void CodeGen::visitETimes(ETimes *etimes) {
	/* Code For ETimes Goes Here */
	std::cout << indent << "Enter visitETimes" << std::endl;
	indent.push_back('\t');

	llvm::Value *L = codegen(etimes->exp_1);
	llvm::Value *R = codegen(etimes->exp_2);

	val = builder.CreateFMul(L, R);

	indent.pop_back();
	std::cout << indent << "Leave visitETimes" << std::endl;
}

void CodeGen::visitEDiv(EDiv *ediv) {
	/* Code For EDiv Goes Here */
	std::cout << indent << "Enter visitEDiv" << std::endl;
	indent.push_back('\t');

	llvm::Value *L = codegen(ediv->exp_1);
	llvm::Value *R = codegen(ediv->exp_2);

	val = builder.CreateExactSDiv(L, R);

	indent.pop_back();
	std::cout << indent << "Leave visitEDiv" << std::endl;
}

void CodeGen::visitEPlus(EPlus *eplus) {
	/* Code For EPlus Goes Here */
	std::cout << indent << "Enter visitEPlus" << std::endl;
	indent.push_back('\t');

	llvm::Value *L = codegen(eplus->exp_1);
	llvm::Value *R = codegen(eplus->exp_2);

	val = builder.CreateFAdd(L, R);

	indent.pop_back();
	std::cout << indent << "Leave visitEPlus" << std::endl;
}

void CodeGen::visitEMinus(EMinus *eminus) {
	/* Code For EMinus Goes Here */
	std::cout << indent << "Enter visitEMinus" << std::endl;
	indent.push_back('\t');

	llvm::Value *L = codegen(eminus->exp_1);
	llvm::Value *R = codegen(eminus->exp_2);

	val = builder.CreateFSub(L, R);

	indent.pop_back();
	std::cout << indent << "Leave visitEMinus" << std::endl;
}

void CodeGen::printGeneratedIR() {
	cout << "------------------ Module Dump ------------------------------------" << endl;
	TheModule.dump();
	cout << "----------------- End Module Dump ---------------------------------" << endl << endl;

	cout << "---------------- Named Value Dump----------------------------------" << endl;
	for (auto entry : NamedValues) {
		cout << "NamedValues[" << entry.first << "] : " << flush;
		entry.second->dump();
	}
	cout << endl;
	cout << "--------------- End NamedValue Dump -------------------------------" << endl << endl;
}

void CodeGen::visitELt(ELt *elt) {
	/* Code For ELt Goes Here */
	std::cout << indent << "Enter visitELt" << std::endl;
	indent.push_back('\t');

	llvm::Value *L = codegen(elt->exp_1);
	llvm::Value *R = codegen(elt->exp_2);

	val = builder.CreateFCmp(llvm::CmpInst::Predicate::FCMP_OLT, L, R);

	indent.pop_back();
	std::cout << indent << "Leave visitELt" << std::endl;
}

void CodeGen::visitEGt(EGt *egt) {
	/* Code For EGt Goes Here */
	std::cout << indent << "Enter visitEGt" << std::endl;
	indent.push_back('\t');

	llvm::Value *L = codegen(egt->exp_1);
	llvm::Value *R = codegen(egt->exp_2);

	val = builder.CreateFCmp(llvm::CmpInst::Predicate::FCMP_OGT, L, R);

	indent.pop_back();
	std::cout << indent << "Leave visitEGt" << std::endl;
}

void CodeGen::visitELtEq(ELtEq *elteq) {
	/* Code For ELtEq Goes Here */
	std::cout << indent << "Enter visitELtEq" << std::endl;
	indent.push_back('\t');

	llvm::Value *L = codegen(elteq->exp_1);
	llvm::Value *R = codegen(elteq->exp_2);

	val = builder.CreateFCmp(llvm::CmpInst::Predicate::FCMP_OLE, L, R);

	indent.pop_back();
	std::cout << indent << "Leave visitELtEq" << std::endl;
}

void CodeGen::visitEGtEq(EGtEq *egteq) {
	/* Code For EGtEq Goes Here */
	std::cout << indent << "Enter visitEGtEq" << std::endl;
	indent.push_back('\t');

	llvm::Value *L = codegen(egteq->exp_1);
	llvm::Value *R = codegen(egteq->exp_2);

	val = builder.CreateFCmp(llvm::CmpInst::Predicate::FCMP_OGE, L, R);

	indent.pop_back();
	std::cout << indent << "Leave visitEGtEq" << std::endl;
}

void CodeGen::visitEEq(EEq *eeq) {
	/* Code For EEq Goes Here */
	std::cout << indent << "Enter visitEEq" << std::endl;
	indent.push_back('\t');

	llvm::Value *L = codegen(eeq->exp_1);
	llvm::Value *R = codegen(eeq->exp_2);

	printType(L->getType()->getTypeID());
	printType(R->getType()->getTypeID());
	if(L->getType()->getTypeID() == llvm::Type::TypeID::DoubleTyID && R->getType()->getTypeID() ==llvm::Type::TypeID::DoubleTyID) {
		val = builder.CreateFCmp(llvm::CmpInst::Predicate::FCMP_OEQ, L, R);
	} else if(L->getType()->getTypeID() == llvm::Type::TypeID::IntegerTyID && R->getType()->getTypeID() ==llvm::Type::TypeID::IntegerTyID) {
		val = builder.CreateICmp(llvm::CmpInst::Predicate::ICMP_EQ, L, R);
	} else if(L->getType()->getTypeID() == llvm::Type::TypeID::DoubleTyID) {
		llvm::CastInst* float_conv = new llvm::SIToFPInst(R, llvm::Type::getDoubleTy(context));
		val = builder.CreateFCmp(llvm::CmpInst::Predicate::FCMP_OEQ, L, float_conv);
	} else if(R->getType()->getTypeID() == llvm::Type::TypeID::DoubleTyID) {
		llvm::CastInst* float_conv = new llvm::SIToFPInst(L, llvm::Type::getDoubleTy(context));
		val = builder.CreateFCmp(llvm::CmpInst::Predicate::FCMP_OEQ, R, float_conv);
	} else {

	}

	indent.pop_back();
	std::cout << indent << "Leave visitEEq" << std::endl;
}

void CodeGen::visitENEq(ENEq *eneq) {
	/* Code For ENEq Goes Here */
	std::cout << indent << "Enter visitENEq" << std::endl;
	indent.push_back('\t');

	llvm::Value *L = codegen(eneq->exp_1);
	llvm::Value *R = codegen(eneq->exp_2);

	val = builder.CreateFCmp(llvm::CmpInst::Predicate::FCMP_ONE, L, R);

	indent.pop_back();
	std::cout << indent << "Leave visitENEq" << std::endl;
}

void CodeGen::visitEAnd(EAnd *eand) {
	/* Code For EAnd Goes Here */
	std::cout << indent << "Enter visitEAnd" << std::endl;
	indent.push_back('\t');

	llvm::Value *L = codegen(eand->exp_1);
	llvm::Value *R = codegen(eand->exp_2);

	val = builder.CreateAnd(L, R);

	indent.pop_back();
	std::cout << indent << "Leave visitEAnd" << std::endl;
}

void CodeGen::visitEOr(EOr *eor) {
	/* Code For EOr Goes Here */
	std::cout << indent << "Enter visitEOr" << std::endl;
	indent.push_back('\t');

	llvm::Value *L = codegen(eor->exp_1);
	llvm::Value *R = codegen(eor->exp_2);

	val = builder.CreateOr(L, R);

	indent.pop_back();
	std::cout << indent << "Leave visitEOr" << std::endl;
}

void CodeGen::visitEAss(EAss *eass) {
	/* Code For EAss Goes Here */
	std::cout << indent << "Enter visitEAss" << std::endl;
	indent.push_back('\t');

	llvm::Value* var = codegen(eass->exp_1);
	llvm::Value* expr = codegen(eass->exp_2);
	builder.CreateStore(expr, var);

	indent.pop_back();
	std::cout << indent << "Leave visitEAss" << std::endl;
}

void CodeGen::visitETyped(ETyped *etyped) {
	/* Code For ETyped Goes Here */
	std::cout << indent << "Enter visitETyped" << std::endl;
indent.push_back('\t');

	etyped->exp_->accept(this);
	etyped->type_->accept(this);

	indent.pop_back();
	std::cout << indent << "Leave visitETyped" << std::endl;
}

void CodeGen::visitType_bool(Type_bool *type_bool) {
	/* Code For Type_bool Goes Here */
	std::cout << indent << "Enter visitType_bool" << std::endl;
	indent.push_back('\t');



	type = llvm::Type::getInt1Ty(context);
	indent.pop_back();
	std::cout << indent << "Leave visitType_bool" << std::endl;

}

void CodeGen::visitType_int(Type_int *type_int) {
	/* Code For Type_int Goes Here */
	std::cout << indent << "Enter visitType_int" << std::endl;
	indent.push_back('\t');



	type = llvm::Type::getInt32Ty(context);
	indent.pop_back();
	std::cout << indent << "Leave visitType_int" << std::endl;
}

void CodeGen::visitType_double(Type_double *type_double) {
	/* Code For Type_double Goes Here */
	std::cout << indent << "Enter visitType_double" << std::endl;
	indent.push_back('\t');
	type = llvm::Type::getDoubleTy(context);
	indent.pop_back();
	std::cout << indent << "Leave visitType_double" << std::endl;
}

void CodeGen::visitType_void(Type_void *type_void) {
	/* Code For Type_void Goes Here */
	std::cout << indent << "Enter visitType_void" << std::endl;
	indent.push_back('\t');


	type = llvm::Type::getVoidTy(context);

	

	indent.pop_back();
	std::cout << indent << "Leave visitType_void" << std::endl;
}

void CodeGen::visitType_string(Type_string *type_string) {
	/* Code For Type_string Goes Here */
	std::cout << indent << "Enter visitType_string" << std::endl;
	indent.push_back('\t');



	std::cout << indent << "Error no String Support" << std::endl; //TODO
	indent.pop_back();
	std::cout << indent << "Leave visitType_string" << std::endl;
}

void CodeGen::visitListArg(ListArg* listarg) {
	std::cout << indent << "Enter visitListArg" << std::endl;
	indent.push_back('\t');

	// wird von DFun übernommen

	indent.pop_back();
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
	indent.push_back('\t');



	for (ListExp::iterator i = listexp->begin() ; i != listexp->end() ; ++i)
	{
		(*i)->accept(this);
	}

	indent.pop_back();
	std::cout << indent << "Leave visitListExp" << std::endl;
}

void CodeGen::visitListId(ListId* listid)
{
	std::cout << indent << "Enter visitListId" << std::endl;
indent.push_back('\t');

	for (ListId::iterator i = listid->begin() ; i != listid->end() ; ++i)
	{
		visitId(*i) ;
	}

	indent.pop_back();
	std::cout << indent << "Leave visitListId" << std::endl;
}

void CodeGen::visitId(Id x) {
	/* Code for Id Goes Here */
	std::cout << indent << "Enter visitId" << std::endl;
	indent.push_back('\t');
	//val = NamedValues[x]; //benutze llvm name uniquing
	val = builder.CreateLoad(NamedValues[x], x); //benutze llvm name uniquing
	std::cout << indent << "Found " << x << ": " << val << std::endl;
	

	indent.pop_back();
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

	// TODO visitchar
	
	std::cout << indent << "Leave visitChar" << std::endl;
}

void CodeGen::visitDouble(Double x) {
	/* Code for Double Goes Here */
	std::cout << indent << "Enter visitDouble" << std::endl;
	indent.push_back('\t');
	
	val = llvm::ConstantFP::get(llvm::Type::getDoubleTy(context), x);

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

// Falls zwar Speicher allokiert, aber kein Wert gespeichert werden soll -> Nullptr übergeben
llvm::AllocaInst* CodeGen::allocateStoreName(const string argName, llvm::Type* argType, llvm::Value* value) {
	llvm::AllocaInst* alloc = builder.CreateAlloca(argType,0, argName);
	NamedValues[argName] = alloc;
	if (value != nullptr)
		llvm::Value* store = builder.CreateStore(value, alloc);
	return alloc;
}

void CodeGen::printType(llvm::Type::TypeID type) {
	switch(type){
	case llvm::Type::TypeID::ArrayTyID:
		std::cout << "Array" << std::endl;
		break;
	case llvm::Type::TypeID::DoubleTyID:
		std::cout << "Double" << std::endl;
		break;
	case llvm::Type::TypeID::FP128TyID:
		std::cout << "FB128" << std::endl;
		break;
	case llvm::Type::TypeID::FloatTyID:
		std::cout << "Float" << std::endl;
		break;
	case llvm::Type::TypeID::FunctionTyID:
		std::cout << "Function" << std::endl;
		break;
	case llvm::Type::TypeID::HalfTyID:
		std::cout << "Half" << std::endl;
		break;
	case llvm::Type::TypeID::IntegerTyID:
		std::cout << "Integer" << std::endl;
		break;
	case llvm::Type::TypeID::LabelTyID:
		std::cout << "Lable" << std::endl;
		break;
	case llvm::Type::TypeID::MetadataTyID:
		std::cout << "Metadata" << std::endl;
		break;
	case llvm::Type::TypeID::PPC_FP128TyID:
		std::cout << "PPC_FP128" << std::endl;
		break;
	case llvm::Type::TypeID::PointerTyID:
		std::cout << "Pointer" << std::endl;
		break;
	case llvm::Type::TypeID::StructTyID:
		std::cout << "Struct" << std::endl;
		break;
	case llvm::Type::TypeID::TokenTyID:
		std::cout << "Token" << std::endl;
		break;
	case llvm::Type::TypeID::VectorTyID:
		std::cout << "Vector" << std::endl;
		break;
	case llvm::Type::TypeID::VoidTyID:
		std::cout << "VOid" << std::endl;
		break;
	case llvm::Type::TypeID::X86_FP80TyID:
		std::cout << "X86_FP80" << std::endl;
		break;
	case llvm::Type::TypeID::X86_MMXTyID:
		std::cout << "X86_MMX" << std::endl;
		break;
	}
}
