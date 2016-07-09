#ifndef CODEGENEXCEPTIO_H_
#define CODEGENEXCEPTIO_H_

#include <exception>
#include <string>

using namespace std;

class CodeGenException : public exception{
public:
  CodeGenException(string msg);
  ~CodeGenException() throw();

  string what() throw();

private:
  string m_msg;
};

#endif
