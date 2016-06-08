#include <list>

#include "Type.H"

class FunType {
  public:
          std::list<Type*> args;
          Type* ty_;
};
