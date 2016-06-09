/*** BNFC-Generated Visitor Design Pattern TypeChecker. ***/
/* This implements the common visitor design pattern.
   Note that this method uses Visitor-traversal of lists, so
   List->accept() does NOT traverse the list. This allows different
   algorithms to use context information differently. */

#include "TypeChecker.H"

TypeChecker::~TypeChecker() {}

/* Eigene Definitionen */

BasicType TypeChecker::typecheck(Visitable* v) {
    v->accept(this);
    return ty_ ;
}

void TypeChecker::visitProgram(Program* t) {} //abstract class
void TypeChecker::visitDef(Def* t) {} //abstract class
void TypeChecker::visitArg(Arg* t) {} //abstract class
void TypeChecker::visitStm(Stm* t) {} //abstract class
void TypeChecker::visitExp(Exp* t) {} //abstract class
void TypeChecker::visitType(Type* t) {} //abstract class

void TypeChecker::visitPDefs(PDefs *pdefs)
{
  /* Code For PDefs Goes Here */


  typecheck(pdefs->listdef_);

}

void TypeChecker::visitDFun(DFun *dfun)
{
  /* Code For DFun Goes Here */

  dfun->type_->accept(this);
  visitId(dfun->id_);
  dfun->listarg_->accept(this);
  dfun->liststm_->accept(this);

}

void TypeChecker::visitADecl(ADecl *adecl)
{
  /* Code For ADecl Goes Here */

  adecl->type_->accept(this);
  visitId(adecl->id_);

}

void TypeChecker::visitSExp(SExp *sexp)
{
	typecheck(sexp->exp_);
}

void TypeChecker::visitSDecls(SDecls *sdecls)
{
	typecheck(sdecls->type_);
	typecheck(sdecls->type_);
}

void TypeChecker::visitSInit(SInit *sinit)
{
	BasicType ty_One = typecheck(sinit->type_);
	BasicType ty_Two = typecheck(sinit->exp_);

	if(ty_One != ty_Two)
	{
		throw new TypeException("Declaration: ")
	}

	env_.updateVar(sinit->id_, ty_One);
	ty_ = ty_One;
}

void TypeChecker::visitSReturn(SReturn *sreturn)
{
  /* Code For SReturn Goes Here */

}

void TypeChecker::visitSReturnVoid(SReturnVoid *sreturnvoid)
{
  /* Code For SReturnVoid Goes Here */

}

void TypeChecker::visitSWhile(SWhile *swhile)
{
	ty_ = typecheck(swhile->exp_);

	if(ty_ != BasicType::BOOLEAN)
	{
		throw new TypeException("While: ");
	}

	typecheck(swhile->stm_);
}

void TypeChecker::visitSBlock(SBlock *sblock)
{
	env_.addScop();
	typecheck(sblock->liststm_);
	env_.delScop();
}

void TypeChecker::visitSIfElse(SIfElse *sifelse)
{
  ty_ = typecheck(sifelse->exp_);

  if(ty_ != BasicType::BOOLEAN)
  {
	  throw new TypeException("If: ");
  }

  typecheck(sifelse->stm_1);
  typecheck(sifelse->stm_2);
}

void TypeChecker::visitETrue(ETrue *etrue)
{
	ty_ = BasicType::BOOLEAN;
}

void TypeChecker::visitEFalse(EFalse *efalse)
{
	ty_ = BasicType::BOOLEAN;
}

void TypeChecker::visitEInt(EInt *eint)
{
  visitInteger(eint->integer_);
}

void TypeChecker::visitEDouble(EDouble *edouble)
{
  visitDouble(edouble->double_);
}

void TypeChecker::visitEString(EString *estring)
{
  visitString(estring->string_);
}

void TypeChecker::visitEId(EId *eid)
{
	visitId(eid->id_);
}

void TypeChecker::visitEApp(EApp *eapp)
{
  /* Code For EApp Goes Here */

  // visitId(eapp->id_);
  // eapp->listexp_->accept(this);

  FunType* fun = env_.lookupFun(eapp->id_);

  std::vector<Type*>* fun_args2 = new std::vector<Type*>();

  for (ListExp::iterator it = eapp->listexp_->begin(); it != eapp->listexp_->end(); ++it) {
    fun_args2->push_back(typecheck(*it));
  }

  //Jetzt die Signatur vergleichen falls nötig;
}

void TypeChecker::visitEPIncr(EPIncr *epincr)
{
	ty_ = typecheck(epincr->exp_);

	if(ty_ != BasicType::DOUBLE &&
	   ty_ != BasicType::INTEGER)
	{
		throw new TypeException("Operation: ");
	}
}

void TypeChecker::visitEPDecr(EPDecr *epdecr)
{
	ty_ = typecheck(epdecr->exp_);

	if(ty_ != BasicType::DOUBLE &&
	   ty_ != BasicType::INTEGER)
	{
		throw new TypeException("Operation: ");
	}
}

void TypeChecker::visitEIncr(EIncr *eincr)
{
	ty_ = typecheck(eincr->exp_);

	if(ty_ != BasicType::DOUBLE &&
	   ty_ != BasicType::INTEGER)
	{
		throw new TypeException("Operation: ");
	}
}

void TypeChecker::visitEDecr(EDecr *edecr)
{
	ty_ = typecheck(edecr->exp_);

	if(ty_ != BasicType::DOUBLE &&
	   ty_ != BasicType::INTEGER)
	{
		throw new TypeException("Operation: ");
	}
}

void TypeChecker::visitETimes(ETimes *etimes)
{
	BasicType ty_One = typecheck(etimes->exp_1);
	BasicType ty_Two = typecheck(etimes->exp_2);

	if(ty_One != ty_Two || (ty_One != BasicType::DOUBLE &&
							ty_One != BasicType::INTEGER))
	{
		throw new TypeException("Operation: ");
	}

	ty_ = ty_One;
}

void TypeChecker::visitEDiv(EDiv *ediv)
{
	BasicType ty_One = typecheck(ediv->exp_1);
	BasicType ty_Two = typecheck(ediv->exp_2);

	if(ty_One != ty_Two || (ty_One != BasicType::DOUBLE &&
							ty_One != BasicType::INTEGER))
	{
		throw new TypeException("Operation: ");
	}

	ty_ = ty_One;
}

void TypeChecker::visitEPlus(EPlus *eplus)
{
	BasicType ty_One = typecheck(eplus->exp_1);
	BasicType ty_Two = typecheck(eplus->exp_2);

	if(ty_One != ty_Two || (ty_One != BasicType::DOUBLE &&
							ty_One != BasicType::INTEGER &&
							ty_One != BasicType::STRING))
	{
		throw new TypeException("Operation: ");
	}

	ty_ = ty_One;
}

void TypeChecker::visitEMinus(EMinus *eminus)
{
	BasicType ty_One = typecheck(eminus->exp_1);
	BasicType ty_Two = typecheck(eminus->exp_2);

	if(ty_One != ty_Two || (ty_One != BasicType::DOUBLE &&
							ty_One != BasicType::INTEGER))
	{
		throw new TypeException("Operation: ");
	}

	ty_ = ty_One;
}

void TypeChecker::visitELt(ELt *elt)
{
	BasicType ty_One = typecheck(elt->exp_1);
	BasicType ty_Two = typecheck(elt->exp_2);

	if(ty_One != ty_Two || (ty_One != BasicType::BOOLEAN &&
							ty_One != BasicType::DOUBLE &&
							ty_One != BasicType::INTEGER &&
							ty_One != BasicType::STRING))
	{
		throw new TypeException("Operation: ");
	}

	ty_ = BasicType::BOOLEAN;
}

void TypeChecker::visitEGt(EGt *egt)
{
	BasicType ty_One = typecheck(egt->exp_1);
	BasicType ty_Two = typecheck(egt->exp_2);

	if(ty_One != ty_Two || (ty_One != BasicType::BOOLEAN &&
							ty_One != BasicType::DOUBLE &&
							ty_One != BasicType::INTEGER &&
							ty_One != BasicType::STRING))
	{
		throw new TypeException("Operation: ");
	}

	ty_ = BasicType::BOOLEAN;
}

void TypeChecker::visitELtEq(ELtEq *elteq)
{
	BasicType ty_One = typecheck(elteq->exp_1);
	BasicType ty_Two = typecheck(elteq->exp_2);

	if(ty_One != ty_Two || (ty_One != BasicType::BOOLEAN &&
							ty_One != BasicType::DOUBLE &&
							ty_One != BasicType::INTEGER &&
							ty_One != BasicType::STRING))
	{
		throw new TypeException("Operation: ");
	}

	ty_ = BasicType::BOOLEAN;
}

void TypeChecker::visitEGtEq(EGtEq *egteq)
{
	BasicType ty_One = typecheck(egteq->exp_1);
	BasicType ty_Two = typecheck(egteq->exp_2);

	if(ty_One != ty_Two || (ty_One != BasicType::BOOLEAN &&
							ty_One != BasicType::DOUBLE &&
							ty_One != BasicType::INTEGER &&
							ty_One != BasicType::STRING))
	{
		throw new TypeException("Operation: ");
	}

	ty_ = BasicType::BOOLEAN;
}

void TypeChecker::visitEEq(EEq *eeq)
{
	BasicType ty_One = typecheck(eeq->exp_1);
	BasicType ty_Two = typecheck(eeq->exp_2);

	if(ty_One != ty_Two || (ty_One != BasicType::BOOLEAN &&
							ty_One != BasicType::DOUBLE &&
							ty_One != BasicType::INTEGER &&
							ty_One != BasicType::STRING))
	{
		throw new TypeException("Operation: ");
	}

	ty_ = BasicType::BOOLEAN;
}

void TypeChecker::visitENEq(ENEq *eneq)
{
	BasicType ty_One = typecheck(eneq->exp_1);
	BasicType ty_Two = typecheck(eneq->exp_2);

	if(ty_One != ty_Two || (ty_One != BasicType::BOOLEAN &&
							ty_One != BasicType::DOUBLE &&
							ty_One != BasicType::INTEGER &&
							ty_One != BasicType::STRING))
	{
		throw new TypeException("Operation: ");
	}

	ty_ = BasicType::BOOLEAN;
}

void TypeChecker::visitEAnd(EAnd *eand)
{
	BasicType ty_One = typecheck(eand->exp_1);
	BasicType ty_Two = typecheck(eand->exp_2);

	if(ty_One != ty_Two || ty_One != BasicType::BOOLEAN)
	{
		throw new TypeException("Operation: ");
	}

	ty_ = BasicType::BOOLEAN;
}

void TypeChecker::visitEOr(EOr *eor)
{
	BasicType ty_One = typecheck(eor->exp_1);
	BasicType ty_Two = typecheck(eor->exp_2);

	if(ty_One != ty_Two || ty_One != BasicType::BOOLEAN)
	{
		throw new TypeException("Operation: ");
	}

	ty_ = BasicType::BOOLEAN;
}

void TypeChecker::visitEAss(EAss *eass)
{
	BasicType ty_One = typecheck(eass->exp_1);
	BasicType ty_Two = typecheck(eass->exp_2);

	if(ty_One != ty_Two)
	{
		throw new TypeException("Operation: ");
	}

	ty_ = ty_One;
}

void TypeChecker::visitETyped(ETyped *etyped)
{
  /* Code For ETyped Goes Here */

  etyped->exp_->accept(this);
  etyped->type_->accept(this);

}

void TypeChecker::visitType_bool(Type_bool *type_bool)
{
	ty_ = BasicType::BOOLEAN;
}

void TypeChecker::visitType_int(Type_int *type_int)
{
	ty_ = BasicType::INTEGER;
}

void TypeChecker::visitType_double(Type_double *type_double)
{
	ty_ = BasicType::DOUBLE;
}

void TypeChecker::visitType_void(Type_void *type_void)
{
	ty_ = BasicType::VOID;
}

void TypeChecker::visitType_string(Type_string *type_string)
{
	ty_ = BasicType::STRING;
}


void TypeChecker::visitListDef(ListDef* listdef)
{
	  for (ListDef::iterator i = listdef->begin() ; i != listdef->end() ; ++i)
	  {
		DFun* fun = (DFun*)*i;

		std::vector<BasicType>* listarg = new vector<BasicType>();

		  for (ListArg::iterator it= fun->listarg_->begin() ; it != fun->listarg_->end() ; ++it)
		  {
			  ADecl* decl = (ADecl*)*it;

			  decl
		  }
	  }

  for (ListDef::iterator i = listdef->begin() ; i != listdef->end() ; ++i)
  {
    typechecker(*i);
  }
}

void TypeChecker::visitListArg(ListArg* listarg)
{
  for (ListArg::iterator i = listarg->begin() ; i != listarg->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void TypeChecker::visitListStm(ListStm* liststm)
{
  for (ListStm::iterator i = liststm->begin() ; i != liststm->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void TypeChecker::visitListExp(ListExp* listexp)
{
  for (ListExp::iterator i = listexp->begin() ; i != listexp->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void TypeChecker::visitListId(ListId* listid)
{
  for (ListId::iterator i = listid->begin() ; i != listid->end() ; ++i)
  {
    visitId(*i) ;
  }
}

void TypeChecker::visitId(Id x)
{
    /* Code for Id Goes Here */
	ty_ = env_.lookupVar(x);
}

void TypeChecker::visitInteger(Integer x)
{
    /* Code for Integer Goes Here */
	ty_ = BasicType::INTEGER;
}

void TypeChecker::visitChar(Char x)
{
    /* Code for Char Goes Here */
	throw new TypeException("ERROR: Call visitChar");
}

void TypeChecker::visitDouble(Double x)
{
    /* Code for Double Goes Here */
	ty_ = BasicType::DOUBLE;
}

void TypeChecker::visitString(String x)
{
	/* Code for String Goes Here */
	ty_ = BasicType::STRING;
}

void TypeChecker::visitIdent(Ident x)
{
	/* Code for Ident Goes Here */
	throw new TypeException("ERROR: Call visitIdent");
}
