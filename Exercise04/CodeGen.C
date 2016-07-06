
/*
 * CodeGen.C
 *
 *  Created on: Jun 28, 2016
 *      Author: MB
 */
#include "CodeGen.H"

CodeGen::CodeGen(){
	 module = new llvm::Module("top", llvm::getGlobalContext());
	 val = nullptr;
	 block = nullptr;
}

CodeGen::~CodeGen() {

}

llvm::Value* CodeGen::codegen(Visitable* v) {
	v->accept(this);
	return val;
}

void CodeGen::visitProgram(Program* t) {} //abstract class
void CodeGen::visitDef(Def* t) {} //abstract class
void CodeGen::visitArg(Arg* t) {} //abstract class
void CodeGen::visitStm(Stm* t) {} //abstract class
void CodeGen::visitExp(Exp* t) {} //abstract class
void CodeGen::visitType(Type* t) {} //abstract class

void CodeGen::visitPDefs(PDefs *pdefs)
{
	/* Code For PDefs Goes Here */

	codegen(pdefs->listdef_);

}
/*************************************************************************
 * 						 	  FUNKTIONEN ETC.							 *
/*************************************************************************/

/* Funktionsprototyp besuchen */
void CodeGen::visitListDef(ListDef* listdef)
{
	std::cout << "Enter visitListDef" << std::endl;

		for (ListDef::iterator proto_it = listdef->begin(); proto_it != listdef->end(); proto_it++) {
			DFun* proto = (DFun*) *proto_it;

			llvm::Function *f = TheModule->getFunction(proto->id_);
			// Übersringe, falls f schon in Modul vorhanden und Argumente stimmen
			if (f) {
				//
				if (f->arg_size() == proto->listarg_->size())
					continue;
				else {
					// TODO Error: Funktion existiert, aber Argumentanzahl stimmt nicht überein
				}
			}
			// Baue llvm Funktionstyp auf
			// Alle Typen sind llvm doubles
			vector<llvm::Type*> protoArgs(proto->listarg_->size(), llvm::Type::getDoubleTy(TheContext));
			llvm::FunctionType* llvm_funType = llvm::FunctionType::get(llvm::Type::getDoubleTy(TheContext), protoArgs, false);

			// Generiere Funktion unter dem vom Prototypen gegebenen Namen im Modul
			llvm::Function* llvm_fun = llvm::Function::Create(llvm_funType, llvm::Function::ExternalLinkage, proto->id_, TheModule);

			// Zwecks besserer Lesbarkeit des IR dumps Namen der Argumente setzen
			ListArg::iterator listarg = proto->listarg_->begin();
			for(auto &arg : llvm_fun->args()) {
				arg.setName(((ADecl*) *listarg)->id_);
				listarg++;
			}
		}

		std::cout << "Leave visitListDef" << std::endl;
}

/* Funktionsdefinition besuchen*/
void CodeGen::visitDFun(DFun *dfun) {

	std::cout << "Enter visitDFun" << std::endl;

	// Überspringen, wenn für diese Funktion schon Code generiert wurde
	// TODO Polymorphe Funktionen
	llvm::Function *TheFunction = TheModule->getFunction(dfun->id_);
	if (TheFunction)
		return;

	/* generiere einen einzigen entry block
	 * Branching statements müssen selbst Blöcke generieren
	 * und den insert point ändern */
	llvm::BasicBlock* entryBlock = llvm::BasicBlock::Create(TheContext, "entry", TheFunction);
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

	std::cout << "Leave visitDFun" << std::endl;
}

/* Funktionsaufruf besuchen */
void CodeGen::visitEApp(EApp *eapp)
{
	std::cout << "Enter visitEApp" << std::endl;

	std::cout << "Leave visitEApp" << std::endl;
}

void CodeGen::visitADecl(ADecl *adecl)
{
	/* Code For ADecl Goes Here */
	std::cout << "Enter visitADecl" << std::endl;

	adecl->type_->accept(this);
	visitId(adecl->id_);

	std::cout << "Leave visitADecl" << std::endl;
}

void CodeGen::visitSExp(SExp *sexp)
{
	/* Code For SExp Goes Here */
	std::cout << "Enter visit SExp" std::endl;

	sexp->exp_->accept(this);

	std::cout << "Leave visitSExp" << std::endl;
}

void CodeGen::visitSDecls(SDecls *sdecls)
{
	/* Code For SDecls Goes Here */
	std::cout << "Enter visitSDecls" << std::endl;

	sdecls->type_->accept(this);
	sdecls->listid_->accept(this);

	std::cout << "Leave visitSDecls" << std::endl;
}

void CodeGen::visitSInit(SInit *sinit)
{
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

void CodeGen::visitSReturnVoid(SReturnVoid *sreturnvoid)
{
	/* Code For SReturnVoid Goes Here */
	std::cout << "Enter visitSReturnVoid" << std::endl;

	std::cout << "Leave visitSReturnVoid" << std::endl;
}

void CodeGen::visitSWhile(SWhile *swhile)
{
	/* Code For SWhile Goes Here */
	std::cout << "Enter visitSWhile" << std::endl;

	swhile->exp_->accept(this);
	swhile->stm_->accept(this);

	std::cout << "Leave visitSWhile" << std::endl;
}

void CodeGen::visitSBlock(SBlock *sblock)
{
	/* Code For SBlock Goes Here */
	std::cout << "Enter visitSBlock" << std::endl;

	sblock->liststm_->accept(this);

	std::cout << "Leave visitSBlock" << std::endl;
}

void CodeGen::visitSIfElse(SIfElse *sifelse)
{
	// Hole die Funktion, für die wir gerade Code generieren
	llvm::Function* currentFun = builder.GetInsertBlock()->getParent();

	// Basic Blocks für then, else, merge in der aktuellen Funktion anlegen und einfügen
	llvm::BasicBlock *thenBB = llvm::BasicBlock::Create(TheContext, "thenBlock", currentFun);
	llvm::BasicBlock *elseBB = llvm::BasicBlock::Create(TheContext, "elsefBlock", currentFun);
	llvm::BasicBlock *mergeBB =llvm::BasicBlock::Create(TheContext, "mergeBlock", currentFun);
	/*** Einzelteile generieren ***/

	// Condition-Expression (gehört noch zu entry block)
	sifelse->exp_->accept(this);
	llvm::Value *condExprVal = val;
	// TODO if (!val) ?
	condExprVal = builder.CreateFCmpONE(condExprVal, llvm::ConstantFP::get(TheContext, llvm::APFloat(0.0)), "ifcond"); // vergleiche mit 0.0
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
	llvm::PHINode *phiStatement = builder.CreatePHI(llvm::Type::getDoubleTy(TheContext), 2, "merge");
	phiStatement->addIncoming(thenVal, thenBB); //wenn wir aus then-Block kommen, übernimm thenValue
	phiStatement->addIncoming(elseVal, elseBB); //wenn wir aus else-Block kommen, übernimm elseValue
}

void CodeGen::visitETrue(ETrue *etrue)
{
	/* Code For ETrue Goes Here */


}

void CodeGen::visitEFalse(EFalse *efalse)
{
	/* Code For EFalse Goes Here */


}

void CodeGen::visitEInt(EInt *eint)
{
	/* Code For EInt Goes Here */

	visitInteger(eint->integer_);

}

void CodeGen::visitEDouble(EDouble *edouble)
{
	/* Code For EDouble Goes Here */

	visitDouble(edouble->double_);

}

void CodeGen::visitEString(EString *estring)
{
	/* Code For EString Goes Here */

	visitString(estring->string_);

}

void CodeGen::visitEId(EId *eid)
{
	/* Code For EId Goes Here */

	visitId(eid->id_);

}

void CodeGen::visitEPIncr(EPIncr *epincr)
{
	/* Code For EPIncr Goes Here */

	epincr->exp_->accept(this);

}

void CodeGen::visitEPDecr(EPDecr *epdecr)
{
	/* Code For EPDecr Goes Here */

	epdecr->exp_->accept(this);

}

void CodeGen::visitEIncr(EIncr *eincr)
{
	/* Code For EIncr Goes Here */

	eincr->exp_->accept(this);

}

void CodeGen::visitEDecr(EDecr *edecr)
{
	/* Code For EDecr Goes Here */

	edecr->exp_->accept(this);

}

void CodeGen::visitETimes(ETimes *etimes)
{
	/* Code For ETimes Goes Here */

	etimes->exp_1->accept(this);
	etimes->exp_2->accept(this);

}

void CodeGen::visitEDiv(EDiv *ediv)
{
	/* Code For EDiv Goes Here */

	ediv->exp_1->accept(this);
	ediv->exp_2->accept(this);

}

void CodeGen::visitEPlus(EPlus *eplus)
{
	/* Code For EPlus Goes Here */

	eplus->exp_1->accept(this);
	eplus->exp_2->accept(this);

}

void CodeGen::visitEMinus(EMinus *eminus)
{
	/* Code For EMinus Goes Here */

	eminus->exp_1->accept(this);
	eminus->exp_2->accept(this);

}

void CodeGen::visitELt(ELt *elt)
{
	/* Code For ELt Goes Here */

	elt->exp_1->accept(this);
	elt->exp_2->accept(this);

}

void CodeGen::visitEGt(EGt *egt)
{
	/* Code For EGt Goes Here */

	egt->exp_1->accept(this);
	egt->exp_2->accept(this);

}

void CodeGen::visitELtEq(ELtEq *elteq)
{
	/* Code For ELtEq Goes Here */

	elteq->exp_1->accept(this);
	elteq->exp_2->accept(this);

}

void CodeGen::visitEGtEq(EGtEq *egteq)
{
	/* Code For EGtEq Goes Here */

	egteq->exp_1->accept(this);
	egteq->exp_2->accept(this);

}

void CodeGen::visitEEq(EEq *eeq)
{
	/* Code For EEq Goes Here */

	eeq->exp_1->accept(this);
	eeq->exp_2->accept(this);

}

void CodeGen::visitENEq(ENEq *eneq)
{
	/* Code For ENEq Goes Here */

	eneq->exp_1->accept(this);
	eneq->exp_2->accept(this);

}

void CodeGen::visitEAnd(EAnd *eand)
{
	/* Code For EAnd Goes Here */

	eand->exp_1->accept(this);
	eand->exp_2->accept(this);

}

void CodeGen::visitEOr(EOr *eor)
{
	/* Code For EOr Goes Here */

	eor->exp_1->accept(this);
	eor->exp_2->accept(this);

}

void CodeGen::visitEAss(EAss *eass)
{
	/* Code For EAss Goes Here */

	eass->exp_1->accept(this);
	eass->exp_2->accept(this);

}

void CodeGen::visitETyped(ETyped *etyped)
{
	/* Code For ETyped Goes Here */

	etyped->exp_->accept(this);
	etyped->type_->accept(this);

}

void CodeGen::visitType_bool(Type_bool *type_bool)
{
	/* Code For Type_bool Goes Here */


}

void CodeGen::visitType_int(Type_int *type_int)
{
	/* Code For Type_int Goes Here */


}

void CodeGen::visitType_double(Type_double *type_double)
{
	/* Code For Type_double Goes Here */


}

void CodeGen::visitType_void(Type_void *type_void)
{
	/* Code For Type_void Goes Here */


}

void CodeGen::visitType_string(Type_string *type_string)
{
	/* Code For Type_string Goes Here */


}


void CodeGen::visitListArg(ListArg* listarg)
{
	std::cout << "Enter visitListArg" << std::endl;

	for (ListArg::iterator i = listarg->begin() ; i != listarg->end() ; ++i)
	{
		(*i)->accept(this);
	}

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


void CodeGen::visitId(Id x)
{
	/* Code for Id Goes Here */
}

void CodeGen::visitInteger(Integer x)
{
	/* Code for Integer Goes Here */
}

void CodeGen::visitChar(Char x)
{
	/* Code for Char Goes Here */
}

void CodeGen::visitDouble(Double x)
{
	/* Code for Double Goes Here */
}

void CodeGen::visitString(String x)
{
	/* Code for String Goes Here */
}

void CodeGen::visitIdent(Ident x)
{
	/* Code for Ident Goes Here */
}
