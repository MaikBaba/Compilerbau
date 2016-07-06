
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
	std::cout << "visitListDef" << std::endl;
}

/* Funktionsdefinition besuchen*/
void CodeGen::visitDFun(DFun *dfun)
{
	std::cout << "visitDFun" << std::endl;
}

/* Funktionsaufruf besuchen */
void CodeGen::visitEApp(EApp *eapp)
{
	std::cout << "visitEApp" << std::endl;
}

void CodeGen::visitADecl(ADecl *adecl)
{
	/* Code For ADecl Goes Here */

	adecl->type_->accept(this);
	visitId(adecl->id_);

	std::cout << "visitADecl" << std::endl;
}

void CodeGen::visitSExp(SExp *sexp)
{
	/* Code For SExp Goes Here */

	sexp->exp_->accept(this);

	std::cout << "visitSExp" << std::endl;
}

void CodeGen::visitSDecls(SDecls *sdecls)
{
	/* Code For SDecls Goes Here */

	sdecls->type_->accept(this);
	sdecls->listid_->accept(this);

	std::cout << "visitSDecls" << std::endl;
}

void CodeGen::visitSInit(SInit *sinit)
{
	/* Code For SInit Goes Here */

	sinit->type_->accept(this);
	visitId(sinit->id_);
	sinit->exp_->accept(this);

	std::cout << "visitSInit" << std::endl;
}

void CodeGen::visitSReturn(SReturn *sreturn)
{
	/* Code For SReturn Goes Here */

	std::cout << "visitSReturn" << std::endl;
}

void CodeGen::visitSReturnVoid(SReturnVoid *sreturnvoid)
{
	/* Code For SReturnVoid Goes Here */

	std::cout << "visitSReturnVoid" << std::endl;
}

void CodeGen::visitSWhile(SWhile *swhile)
{
	/* Code For SWhile Goes Here */

	swhile->exp_->accept(this);
	swhile->stm_->accept(this);

	std::cout << "visitSWhile" << std::endl;
}

void CodeGen::visitSBlock(SBlock *sblock)
{
	/* Code For SBlock Goes Here */

	sblock->liststm_->accept(this);

	std::cout << "visitSBlock" << std::endl;
}

void CodeGen::visitSIfElse(SIfElse *sifelse)
{
	/* Code For SIfElse Goes Here */

	sifelse->stm_1->accept(this);
	sifelse->stm_2->accept(this);

	std::cout << "visitSIfElse" << std::endl;
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
	for (ListArg::iterator i = listarg->begin() ; i != listarg->end() ; ++i)
	{
		(*i)->accept(this);
	}

	std::cout << "visitListArg" << std::endl;
}

void CodeGen::visitListStm(ListStm* liststm)
{
	for (ListStm::iterator i = liststm->begin() ; i != liststm->end() ; ++i)
	{
		(*i)->accept(this);
	}

	std::cout << "visitListStm" << std::endl;
}

void CodeGen::visitListExp(ListExp* listexp)
{
	for (ListExp::iterator i = listexp->begin() ; i != listexp->end() ; ++i)
	{
		(*i)->accept(this);
	}

	std::cout << "visitListExp" << std::endl;
}

void CodeGen::visitListId(ListId* listid)
{
	for (ListId::iterator i = listid->begin() ; i != listid->end() ; ++i)
	{
		visitId(*i) ;
	}

	std::cout << "visitListId" << std::endl;
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
