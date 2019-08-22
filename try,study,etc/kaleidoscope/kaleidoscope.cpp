#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include <llvm/IR/Instructions.h>
#include <llvm/Transforms/Utils/Cloning.h>
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include <iostream>
/* g++ -g -O3 kaleidoscope.cpp `llvm-config --cxxflags --ldflags --system-libs --libs core` -o toy*/
using namespace llvm;

//===----------------------------------------------------------------------===//
// Lexer
//===----------------------------------------------------------------------===//
static LLVMContext TheContext;
static IRBuilder<> Builder(TheContext);
static std::unique_ptr<Module> TheModule;

int main() {
  // Install standard binary operators.
  // 1 is lowest precedence.
 
  // Make the module, which holds all the code.
  TheModule = llvm::make_unique<Module>("my cool jit", TheContext);

  // Run the main "interpreter loop" now.

  // Print out all of the generated code.
  auto o = Builder.GetInsertBlock();
  llvm::Value* v = llvm::ConstantInt::get(TheContext, llvm::APInt(16,8));
  std::vector<Type*> types;
  //types.push_back(v->getType());
  auto ft = FunctionType::get(Builder.getVoidTy(),types,false);
  auto func = Function::Create(ft,Function::ExternalLinkage,"tf",TheModule.get());
  auto block = BasicBlock::Create(TheContext,"entry",func);
  Builder.SetInsertPoint(block);
  Builder.CreateRetVoid();
  
 // Builder.SetInsertPoint(o);
  Builder.CreateCall(func);

  std::vector<Type*> types_(1,Builder.getInt16Ty());
  //types.push_back(v->getType());
  auto ft_ = FunctionType::get(Builder.getInt16Ty(),types_,false);
  auto func_ = Function::Create(ft_,Function::ExternalLinkage,"b",TheModule.get());
  auto block_ = BasicBlock::Create(TheContext,"entry",func_);
  Builder.SetInsertPoint(block_);
  Builder.CreateRet(v);
  //Builder.SetInsertPoint(o);
  Builder.CreateCall(func);

  Builder.CreateCall(func_);

  func->replaceAllUsesWith(func_);

  std::cout << std::endl;
  TheModule->print(errs(), nullptr);
  return 0;
}
/*g++ -g -O0 kaleidoscope.cpp `llvm-config --cxxflags --ldflags --system-libs --libs core` -o toy
*/