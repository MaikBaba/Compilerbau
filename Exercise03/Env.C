#include "Env.H"


using namespace std;

Type Env::lookupVar(String id) {
  unordered_map<string,Type>::iterator it;

  it = m_context.back.find(id);
  if (it == m_context.end()) {
    //ERROR no var with this name exists
  }
  return it->second;
}

FunType Env::lookupFun(String id) {
  unordered_map<string,FunType>::iterator it;
  it = m_fun_context.find(id);
  if (it == m_fun_context.end()) {
    //ERROR no fun with this name exists
  }
  return it->second;
}

void Env::updateVar(String id, Type ty) {
  pair<map<string, Type>::iterator, bool> ret;
  ret = m_context.insert(pair<string, Type>(id, ty));
  if (ret.second == false) {
    //ERROR var with id already exist
  }
}

void Env::updateFun(String id, Type ty) {
  // TODO
}