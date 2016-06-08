#include "TypeException.H"


TypeException::TypeException(string msg){
  m_msg=msg;
}

TypeException::~TypeException() throw(){
}

string TypeException::what() throw(){
  return m_msg;
}
