#include "Env.H"

using namespace std;

BasicType Env::lookupVar(Id id){
  map<Id, BasicType>::iterator it;
  // Find variable at the last element ("top of the stack")
  it = m_context.back().find(id);
  if (it == m_context.back().end()) {
    //ERROR no var with this name exists
  }
  return it->second;
}

BasicType Env::lookupFun(Id id, vector<BasicType>* arglist){
  map<Id, FunType*>::iterator it;
  it = m_fun_context.find(id);
  if (it == m_fun_context.end()) {
    //ERROR no fun with this name exists
  }
  return it->second;
}

void Env::updateVar(Id id, Type* ty) {
  pair<map<Id, Type*>::iterator, bool> ret;
  // insert to last list item ("top of stack") a new pair (symbol table)
  ret = m_context.back().insert(pair<Id, Type*>(id, ty));
  if (ret.second == false) {
    //ERROR var with id already exist
  }
}

void Env::updateFun(Id id, FunType* ty) {
    pair<map<Id, FunType*>::iterator, bool> ret;
    ret = m_fun_context.insert(std::pair<Id, FunType*>(id, ty));
    if (ret.second == false) {
      //ERROR fun with id already exist
    }
}

void Env::addScop() {
	m_context.push_back(new multimap<Id, BasicType>);
}

void ENv::delScop() {
	m_context.pop_back();
}
