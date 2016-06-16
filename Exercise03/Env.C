#include "Env.H"

using namespace std;

BasicType Env::lookupVar(Id id){
  map<Id, BasicType>::iterator it;
  // Find variable at the last element ("top of the stack")
  it = m_context.back().find(id);
  if (it == m_context.back().end()) {
    throw new TypeException("Variable " + id + " was not declared.");
  }
  return it->second;
}

BasicType Env::lookupFun(Id id, vector<BasicType>* arglist){
  map<Id, FunType>::iterator it;
  it = m_fun_context.find(id);
  // TODO Do we need to check of the exact signature matches?
  if (it == m_fun_context.end()) {
    throw new TypeException("Function " + id + " was not declared.");
  }
  return it->second.getFunReturnType();
}

void Env::updateVar(Id id, BasicType ty) {
  pair<map<Id, BasicType>::iterator, bool> ret;
  // insert to last list item ("top of stack") a new pair (symbol table)
  ret = m_context.back().insert(pair<Id, BasicType>(id, ty));
  if (ret.second == false) {
	  throw new TypeException("Variable" + id + " already exists");
  }
}

void Env::updateFun(Id id, FunType ty) {
    pair<map<Id, FunType>::iterator, bool> ret;
    ret = m_fun_context.insert(std::pair<Id, FunType>(id, ty));
    if (ret.second == false) {
      throw new TypeException("Function " + id + " already exists.");
    }
}

void Env::addScope() {
  map<Id, BasicType>* tmp = new map<Id, BasicType>();
	m_context.push_back(*tmp); 
  delete tmp; // push_back is call-by-value, therefore we can free tmp
}

void Env::delScope() {
	if(!m_context.empty()) {
		m_context.pop_back();
	}
}

void Env::clearEnv() {
	for(auto item : m_context) {
		delete(item);
		m_context.erase(item++);

	}
}
