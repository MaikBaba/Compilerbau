#ifndef ENV_H_
#define ENV_H_

#include <list>
#include <map>
#include <string>

#include "Absyn.H"

#include "FunType.H"
#include "BasicType.H"
#include "TypeException.H"

using namespace std;

class Env {

	//TODO all new function

public:

  BasicType lookupVar(Id id);
  BasicType lookupFun(Id id, vector<BasicType>* arglist);
  void updateVar(Id id, BasicType ty);
  void updateFun(Id id, FunType func);
  void addScope();
  void delScope();
  void clearEnv();

private:
  multimap<Id, FunType*> m_fun_context;
  list<map<Id, BasicType>* > m_context;
};

#endif


/*


Env.C:8:25: error: request for member ‘find’ in ‘((Env*)this)->Env::m_context.std::__cxx11::list<_Tp, _Alloc>::back<std::map<std::__cxx11::basic_string<char>, BasicType>*, std::allocator<std::map<std::__cxx11::basic_string<char>, BasicType>*> >()’, which is of pointer type ‘std::map<std::__cxx11::basic_string<char>, BasicType>*’ (maybe you meant to use ‘->’ ?)
   it = m_context.back().find(id);
                         
                         ^
Env.C:9:30: error: request for member ‘end’ in ‘((Env*)this)->Env::m_context.std::__cxx11::list<_Tp, _Alloc>::back<std::map<std::__cxx11::basic_string<char>, BasicType>*, std::allocator<std::map<std::__cxx11::basic_string<char>, BasicType>*> >()’, which is of pointer type ‘std::map<std::__cxx11::basic_string<char>, BasicType>*’ (maybe you meant to use ‘->’ ?)
   if (it == m_context.back().end()) {
                         


Env.C:27:26: error: request for member ‘insert’ in ‘((Env*)this)->Env::m_context.std::__cxx11::list<_Tp, _Alloc>::back<std::map<std::__cxx11::basic_string<char>, BasicType>*, std::allocator<std::map<std::__cxx11::basic_string<char>, BasicType>*> >()’, which is of pointer type ‘std::map<std::__cxx11::basic_string<char>, BasicType>*’ (maybe you meant to use ‘->’ ?)
   ret = m_context.back().insert(pair<Id, BasicType>(id, ty));
                       

                          ^



            ^

-------------------------------------  ohne pointer
                                             




Env.C: In member function ‘void Env::addScope()’:
Env.C:42:46: error: no matching function for call to ‘std::__cxx11::list<std::map<std::__cxx11::basic_string<char>, BasicType> >::push_back(std::map<std::__cxx11::basic_string<char>, BasicType>*)’
  m_context.push_back(new map<Id, BasicType>());



Env.C: In member function ‘void Env::delScope()’:
Env.C:47:26: error: type ‘class std::map<std::__cxx11::basic_string<char>, BasicType>’ argument given to ‘delete’, expected pointer
   delete(m_context.back());


------------------ beide 

Env.C: In member function ‘BasicType Env::lookupFun(Id, std::vector<BasicType>*)’:
Env.C:21:14: error: cannot convert ‘FunType*’ to ‘BasicType’ in return
   return it->second;

Env.C: In member function ‘void Env::updateFun(Id, FunType)’:
Env.C:35:62: error: no matching function for call to ‘std::pair<std::__cxx11::basic_string<char>, FunType*>::pair(Id&, FunType&)’
     ret = m_fun_context.insert(std::pair<Id, FunType*>(id, ty));


/usr/include/c++/5/bits/stl_pair.h:141:38: error: no type named ‘type’ in ‘struct std::enable_if<false, void>’
       template<class _U1, class _U2, class = typename


/usr/include/c++/5/bits/stl_pair.h:138:12: note:   template argument deduction/substitution failed:
/usr/include/c++/5/bits/stl_pair.h:136:27: error: no type named ‘type’ in ‘struct std::enable_if<false, void>’
       template<class _U2, class = typename



*/
