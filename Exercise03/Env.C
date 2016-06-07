#include "Env.H"

Type Env::lookupVar(String id) {
        std::map<std::string,Type>::iterator it;

        it = contexts.back.find(id);
        if (it == signatur.end()) {
                //ERROR no var with this name exists
        }
        return it->second;
}

FunType Env::lookupFun(String id) {
        std::map<std::string,FunType>::iterator it;
        it = signatur.find(id);
        if (it == signatur.end()) {
                //ERROR no fun with this name exists
        }
        return it->second;
}

void Env::updateVar(String id, Type ty) {
        std::pair<std::map<std::string, Type>::iterator, bool> ret;
        ret = contexts.insert(std::pair<std::string, Type>(id, ty));
        if (ret.second == false) {
                //ERROR var with id already exist
        }
}