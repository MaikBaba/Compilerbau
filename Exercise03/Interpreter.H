class Interpreter {
  public:
    Integer interpret(Exp e) {
      return e.accept(new Value(), null ) ;
    }
  private:
    class Value : public Exp.Visitor<R, A> {
      public: 
        R visit (EAdd p, A arg) {
          return interpret(p.exp_1) + interpret(p.exp_2) ;
        }
        R visit (EMul p, A arg) {
          return interpret(p.exp_1) * interpret(p.exp_2) ;
        }
        R visit (EInt p, A arg) {
          return p.integer_ ;
        }
    } 
}