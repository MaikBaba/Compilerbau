
class TypeChecker
{
public:
        Type infer(Env T, Exp e);
        void check(Env T, Exp e, Type t);
        void check(Env T, Stms s);
        void check(Env T, Def d);
        void check(Program p);

        Type lookup(Ident x, Env T);
        FunType lookup(Ident f, Env T);
        Env extend(Env T, Ident x, Type t);
        Env extend(Env, Def d);
        Env newBlock(Env T);
        Env emptEnv();
};
