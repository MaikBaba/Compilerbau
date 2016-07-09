#include "CodeGenException.H"

CodeGenException::CodeGenException(string msg){
  m_msg = msg;
}

CodeGenException::~CodeGenException() throw(){
}

string CodeGenException::what() throw(){
  return m_msg;
}
