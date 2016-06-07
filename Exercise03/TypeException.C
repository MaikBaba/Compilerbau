#include "TypeException.h"

#include "string"


TypeException::TypeException(const char* msg){
  m_msg=msg;
}

TypeException::~TypeException() throw(){
}

const char* TypeException::what() throw(){
  const char* return_msg = m_msg.c_str();
  return return_msg;
}
