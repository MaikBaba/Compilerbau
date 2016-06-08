#include "TypeException.H"

#include <string>


TypeException::TypeException(const char* msg){
  m_msg=msg;
}

TypeException::~TypeException() throw(){
}

string TypeException::what() throw(){
  return m_msg;
}
