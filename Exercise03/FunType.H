#include <list>
#include <string>

#include "BasicType.H"

typedef std::string Id;

class FunType {
  public:
    Id fun_id;
	std::list<BasicType*> fun_args;
    BasicType* fun_type;
};
