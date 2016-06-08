#include "Env.H"
#include "TypeException.H"
#include "Absyn.H"

using namespace std;

BasicType Env::lookupVar(string id){
  unordered_map<string,BasicType>::iterator it;

  // Find variable at the last element ("top of the stack")
  it = m_context.back().find(id);
  if (it == m_context.end()) {
    //ERROR no var with this name exists
  }
  return it->second;
}

BasicType Env::lookupFun(FunType* func){
  unordered_map<string, FunType>::iterator it;
  it = m_fun_context.find(func->fun_id);
  if (it == m_fun_context.end()) {
    //ERROR no fun with this name exists
  }
  return it->second.fun_type;
}

void Env::updateVar(string id, BasicType* ty) {
  pair<unordered_map<string, BasicType&>::iterator, bool> ret;
  // insert to last list item ("top of stack") a new pair (symbol table)
  ret = m_context.back().insert(pair<string, BasicType&>(id, ty));
  if (ret.second == false) {
    //ERROR var with id already exist
  }
}


void Env::updateFun(string id, FunType* ty) {
    pair<map<string, FunType&>::iterator, bool> ret;
    ret = m_fun_context.insert(std::pair<string, FunType&>(id, ty));
    if (ret.second == false) {
      //ERROR fun with id already exist
    }
}
