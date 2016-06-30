/*
 * CodeGen.H
 *
 *  Created on: Jun 28, 2016
 *      Author: MB
 */

#ifndef CODEGEN_H_
#define CODEGEN_H_

#include "Absyn.H"
#include "Env.H"
#include "BasicType.H"
#include "FunType.H"
#include "TypeException.H"
#include <llvm-3.5/llvm/IR/Value.h>
#include <llvm-3.5/llvm/IR/BasicBlock.h>
#include <llvm-3.5/llvm/IR/Constants.h>
#include <llvm-3.5/llvm/IR/DerivedTypes.h>
#include <llvm-3.5/llvm/IR/Function.h>
#include <llvm-3.5/llvm/IR/IRBuilder.h>
#include <llvm-3.5/llvm/IR/LLVMContext.h>
#include <llvm-3.5/llvm/IR/Module.h>
#include <llvm-3.5/llvm/IR/Type.h>
#include <llvm-3.5/llvm/IR/Verifier.h>
#include <string>
#include <vector>
#include <map>
#include <memory>

using namespace std;

class CodeGen : public Visitor
{
public:

	CodeGen();
    ~CodeGen();
    llvm::Value* codegen(Visitable* v);

	Type* infer(Env T, Exp* e);

	void check(Env T, Exp* e, Type* t);
	void check(Env T, Stm* s);
	void check(Env T, Def* d);
	void check(Program* p);

	void visitProgram(Program* p);
	void visitDef(Def* p);
	void visitArg(Arg* p);
	void visitStm(Stm* p);
	void visitExp(Exp* p);
	void visitType(Type* p);
	void visitPDefs(PDefs* p);
	void visitDFun(DFun* p);
	void visitADecl(ADecl* p);
	void visitSExp(SExp* p);
	void visitSDecls(SDecls* p);
	void visitSInit(SInit* p);
	void visitSReturn(SReturn* p);
	void visitSReturnVoid(SReturnVoid* p);
	void visitSWhile(SWhile* p);
	void visitSBlock(SBlock* p);
	void visitSIfElse(SIfElse* p);
	void visitETrue(ETrue* p);
	void visitEFalse(EFalse* p);
	void visitEInt(EInt* p);
	void visitEDouble(EDouble* p);
	void visitEString(EString* p);
	void visitEId(EId* p);
	void visitEApp(EApp* p);
	void visitEPIncr(EPIncr* p);
	void visitEPDecr(EPDecr* p);
	void visitEIncr(EIncr* p);
	void visitEDecr(EDecr* p);
	void visitETimes(ETimes* p);
	void visitEDiv(EDiv* p);
	void visitEPlus(EPlus* p);
	void visitEMinus(EMinus* p);
	void visitELt(ELt* p);
	void visitEGt(EGt* p);
	void visitELtEq(ELtEq* p);
	void visitEGtEq(EGtEq* p);
	void visitEEq(EEq* p);
	void visitENEq(ENEq* p);
	void visitEAnd(EAnd* p);
	void visitEOr(EOr* p);
	void visitEAss(EAss* p);
	void visitETyped(ETyped* p);
	void visitType_bool(Type_bool* p);
	void visitType_int(Type_int* p);
	void visitType_double(Type_double* p);
	void visitType_void(Type_void* p);
	void visitType_string(Type_string* p);
	void visitListDef(ListDef* p);
	void visitListArg(ListArg* p);
	void visitListStm(ListStm* p);
	void visitListExp(ListExp* p);
	void visitListId(ListId* p);

	void visitId(Id x);
	void visitInteger(Integer x);
	void visitChar(Char x);
	void visitDouble(Double x);
	void visitString(String x);
	void visitIdent(Ident x);

private:
        Env env_;
        llvm::Value* val;
        static llvm::LLVMContext TheContext;
        static unique_ptr<llvm::Module>∗ TheModule;
        static llvm::IRBuilder<> Builder(llvm::getGlobalContext());
        static map<string, llvm::Value∗> NamedValues;

};

#endif /* CODEGEN_H_ */
