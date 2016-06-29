/*
 * CodeGen.H
 *
 *  Created on: Jun 28, 2016
 *      Author: MB
 */

#ifndef CODEGEN_H_
#define CODEGEN_H_

static std::unique_ptr<Module>∗ TheModule;
static IRBuilder<> Builder(getGlobalContext());
static std::map<std::string, Value∗> NamedValues;

Value∗ ErrorV(const char∗ Str) {
	Error(Str);
	return nullptr ;
}


#endif /* CODEGEN_H_ */
