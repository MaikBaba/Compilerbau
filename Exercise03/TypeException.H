#ifndef XOUTOFBOUNDS_H_
#define XOUTOFBOUNDS_H_

#include "exception"
#include "string"
using namespace std;

class TypeException: public exception{
public:
  XOutOfBounds(const char* msg);
  ~XOutOfBounds() throw();

  const char* what() throw();

private:
  string m_msg;
};

#endif
