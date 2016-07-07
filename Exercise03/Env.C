#include "Env.H"

using namespace std;

Env::Env() {
	m_context = new list<map<Id, BasicType>* >();
	m_fun_context = new multimap<Id, FunType*>();
}

Env::~Env() {
	clearEnv();
	delete(m_context);
	delete(m_fun_context);
}

BasicType Env::lookupVar(Id id) {
  auto it = m_context->back()->find(id);
  if (it == m_context->back()->end()) {
    throw new TypeException("Variable " + id + " was not declared.");
  }
  return it->second;
}

BasicType Env::lookupFun(Id id, vector<BasicType>* arglist) {
	auto ret = m_fun_context->equal_range(id);
	for(auto item = ret.first; item != ret.second; item++) {
		bool isequal = false;
		if(arglist->size() == item->second->fun_args.size()) {
			isequal = true;
			auto funargit = item->second->fun_args.begin();
			for(auto arglistit = arglist->begin(); arglistit != arglist->end();) {
			    if ((*arglistit != *funargit)) {
			    	isequal = false;
			    }
			    ++arglistit; ++funargit;
			  }

		}

		if(isequal){
			return item->second->fun_type;
		}
	}
    throw new TypeException("Function " + id + " was not declared.");
}

void Env::updateVar(Id id, BasicType ty) {
  auto ret = m_context->back()->insert(pair<Id, BasicType>(id, ty));
  if (ret.second == false) {
	  throw new TypeException("Variable" + id + " already exists");
  }
}

void Env::updateFun(Id id, FunType* ty) {
	auto ret = m_fun_context->equal_range(id);
	for(auto item = ret.first; item != ret.second; item++) {
		bool isequal = false;
		if(ty->fun_args.size() == item->second->fun_args.size()) {
			isequal = true;
			auto funargit = item->second->fun_args.begin();
			for(auto arglistit = ty->fun_args.begin(); arglistit != ty->fun_args.end();) {
				if ((*arglistit != *funargit)) {
					isequal = false;
				}
				++arglistit; ++funargit;
			  }

		}

		if(isequal){
			throw new TypeException("Function alread delc.");
		}
	}
	m_fun_context->insert(pair<Id, FunType*>(id, ty));
}

void Env::addScope() {
	m_context->push_back( new map<Id, BasicType>());
}

void Env::delScope() {
	if(!m_context->empty()) {
		delete(m_context->back());
		m_context->pop_back();
	}
}

void Env::clearEnv() {
	for(auto item = m_context->begin(); item != m_context->end();) {
		delete(*item);
		m_context->erase(item++);
	}

	for(auto item = m_fun_context->begin(); item != m_fun_context->end();) {
		delete(item->second);
		m_fun_context->erase(item++);
	}

}
