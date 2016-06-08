#include "Env.H"
#include "TypeException.H"
#include "Absyn.H"

using namespace std;

Type& Env::lookupVar(string id) {
  unordered_map<string,Type>::iterator it;

  // Find variable at the last element ("top of the stack")
  it = m_context.back().find(id);
  if (it == m_context.end()) {
    //ERROR no var with this name exists
  }
  return it->second;
}

FunType Env::lookupFun(string id) {
  unordered_map<string,FunType>::iterator it;
  it = m_fun_context.find(id);
  if (it == m_fun_context.end()) {
    //ERROR no fun with this name exists
  }
  return it->second;
}

void Env::updateVar(string id, Type& ty) {
  pair<unordered_map<string, Type&>::iterator, bool> ret;
  // insert to last list item ("top of stack") a new pair (symbol table)
  ret = m_context.back().insert(pair<string, Type&>(id, ty));
  if (ret.second == false) {
    //ERROR var with id already exist
  }
}

void Env::updateFun(String id, FunType& ty) {
  // TODO
}
