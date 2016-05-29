#include <stack>
#include "LookupTable.H"

class Env {
public:
	std::stack<LookupTable> scopeStack;
}