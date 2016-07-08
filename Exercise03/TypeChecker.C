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

//
void TypeChecker::visitProgram(Program* t) {} //abstract class
void TypeChecker::visitDef(Def* t) {} //abstract class
void TypeChecker::visitArg(Arg* t) {} //abstract class
void TypeChecker::visitStm(Stm* t) {} //abstract class
void TypeChecker::visitExp(Exp* t) {} //abstract class
void TypeChecker::visitType(Type* t) {} //abstract class

void TypeChecker::visitPDefs(PDefs *pdefs)
{
  env_.clearEnv();
  typecheck(pdefs->listdef_);
}

void TypeChecker::visitDFun(DFun *dfun)
{
	env_.addScope();
	working_fun = dfun;
	working_fun_has_return_statement = false;
	typecheck(dfun->listarg_);
	typecheck(dfun->liststm_);
	ty_ = typecheck(dfun->type_);
	if(ty_ != BasicType::VOID && working_fun_has_return_statement == false)
	{
		throw new TypeException("The function must have a return statement.");
	}

	env_.delScope();
}

void TypeChecker::visitADecl(ADecl *adecl)
{
	ty_ = typecheck(adecl->type_);
	env_.updateVar(adecl->id_,ty_);
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
		throw new TypeException("Declaration: ");
	}

	env_.updateVar(sinit->id_, ty_One);
	//ty_ = ty_One;
}

void TypeChecker::visitSReturn(SReturn *sreturn)
{
	BasicType ty_return = typecheck(sreturn->exp_);
	BasicType ty_fun = typecheck(working_fun->type_);

	if(ty_return != ty_fun)
	{
		throw TypeException("Return statement type dose not match with function return type");
	}

	working_fun_has_return_statement = true;
}

void TypeChecker::visitSReturnVoid(SReturnVoid *sreturnvoid)
{
	BasicType ty_fun = typecheck(working_fun->type_);

	if(ty_fun != BasicType::VOID)
	{
		throw TypeException("Return statement type dose not match with function return type");
	}

	//Wird zwar nicht gebraucht aber der vollständigkeitshalber.
	working_fun_has_return_statement = true;
}

void TypeChecker::visitSWhile(SWhile *swhile)
{
	BasicType ty_while = typecheck(swhile->exp_);

	if(ty_while != BasicType::BOOLEAN)
	{
		throw new TypeException("While: ");
	}

	typecheck(swhile->stm_);
}

void TypeChecker::visitSBlock(SBlock *sblock)
{
	env_.addScope();
	typecheck(sblock->liststm_);
	env_.delScope();
}

void TypeChecker::visitSIfElse(SIfElse *sifelse)
{
	BasicType ty_ifelse = typecheck(sifelse->exp_);

  if(ty_ifelse != BasicType::BOOLEAN)
  {
	  throw new TypeException("If: ");
  }

  typecheck(sifelse->stm_1);
  typecheck(sifelse->stm_2);
}

//
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

//
void TypeChecker::visitEApp(EApp *eapp)
{
	std::vector<BasicType>* fun_args = new std::vector<BasicType>();

	for(ListExp::iterator it = eapp->listexp_->begin(); it != eapp->listexp_->end(); ++it)
	{
		fun_args->push_back(typecheck(*it));
	}

	ty_ = env_.lookupFun(eapp->id_, fun_args);

	delete(fun_args);
}

//Hier werden die Operationen implemtier, sie prüfen den Typ der Operatoren
//und weisen der Membervariable den jeweiligen Typ zu.
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

//
void TypeChecker::visitETyped(ETyped *etyped)
{
	throw new TypeException("ERROR: Call visitETyped");
}

//
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
	// Hieraus konstruieren wir später unseren FunType, der ins environment eingetragen wird
	set<Id>* fun_unique_ids = new set<Id>();

	// Iteriere über alle Funktionsdefinitionen
	for (ListDef::iterator defit = listdef->begin(); defit != listdef->end(); defit++) {
		DFun* fun = (DFun*) *defit;

        FunType* fundef = new FunType();

        // Baue den FunType auf
		for (ListArg::iterator listargit = fun->listarg_->begin() ; listargit != fun->listarg_->end() ; ++listargit)
		{
			// Hole aktuelle Argumentdeklaration und prüfe auf Einzigartigkeit
			// (Argumente müssen verschiedene IDs haben)
			ADecl* adecl = (ADecl*) *listargit;
			auto ret = fun_unique_ids->insert(adecl->id_);
			if(!ret.second) {
				throw new TypeException("Functions arguments ids are not unique.");
			}
			// Prüfe, ob Argument einen gültigen Typ hat, falls ja füge in FunType ein
			fundef->fun_args.push_back(typecheck(adecl->type_));
		}
		// Set löschen für nächste Runde
		fun_unique_ids->clear();
		// Prüfe, ob der deklarierte Rückgabetyp gültig ist
		fundef->fun_type = typecheck(fun->type_);

		// Füge FunType mit seiner ID in Environment ein
		env_.updateFun(fun->id_, fundef);
	}

	delete(fun_unique_ids);

	for (ListDef::iterator it = listdef->begin(); it != listdef->end(); ++it)
	{
		typecheck(*it);
	}
}

void TypeChecker::visitListArg(ListArg* listarg)
{
  for (ListArg::iterator it = listarg->begin(); it != listarg->end(); ++it)
  {
	  typecheck(*it);
  }
}

void TypeChecker::visitListStm(ListStm* liststm)
{
  for (ListStm::iterator it = liststm->begin(); it != liststm->end(); ++it)
  {
	  typecheck(*it);
  }
}

void TypeChecker::visitListExp(ListExp* listexp)
{
	throw new TypeException("");
}

void TypeChecker::visitListId(ListId* listid)
{
	for (ListId::iterator it = listid->begin(); it != listid->end(); ++it)
	{
		env_.updateVar(*it, ty_);
	}
}

//Hier wird nach einer ID in der env gesucht und an die Membervariable ty übergeben.
void TypeChecker::visitId(Id x)
{
	ty_ = env_.lookupVar(x);
}

//Hier wird der Membervariable ty ein Typ zugewiesen, ausser BOOL und VOID alle anderen werden von visitE* aufgerufen.
//Könne man also auch oben in visitE* zuweisen.
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