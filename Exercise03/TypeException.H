#ifndef TYPEEXCEPTION_H_
#define TYPEEXCEPTION_H_

#include <exception>
#include <string>
using namespace std;

class TypeException: public exception{
public:
  TypeException(string msg);
  ~TypeException() throw();

  string what() throw();

private:
  string m_msg;
};

#endif
