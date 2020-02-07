cmake_minimum_required(VERSION 2.8)
project(blawn)

set(LLVM_DIR /usr/local/opt/llvm/lib/cmake/llvm)
find_package(bison 3.5)
set(BISON_EXECUTABLE /usr/local/opt/bison/bin/bison)
find_package(FLEX 2.6.4)
set(FLEX_EXECUTABLE /usr/local/opt/flex/bin/flex)
find_package(LLVM 9)
set(FLEX_INCLUDE_DIRS /usr/local/opt/flex/include)
set(FLEX_LIBRARIES /usr/local/opt/flex/lib)
set(BISON_INCLUDE_DIRS usr/local/opt/bison/include)
bison_target(parser ./src/compiler/parser/parser.yy ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
flex_target(lexer ./src/compiler/parser/lexer.ll ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp)
ADD_FLEX_BISON_DEPENDENCY(lexer parser)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-I/usr/local/Cellar/llvm/9.0.0_1/include -std=c++11 -stdlib=libc++ -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS -L/usr/local/Cellar/llvm/9.0.0_1/lib -Wl,-search_paths_first -Wl,-headerpad_max_install_names -lLLVMXRay -lLLVMWindowsManifest -lLLVMTextAPI -lLLVMTableGen -lLLVMSymbolize -lLLVMDebugInfoPDB -lLLVMOrcJIT -lLLVMJITLink -lLLVMObjectYAML -lLLVMMCA -lLLVMLTO -lLLVMPasses -lLLVMObjCARCOpts -lLLVMLineEditor -lLLVMLibDriver -lLLVMInterpreter -lLLVMFuzzMutate -lLLVMMCJIT -lLLVMExecutionEngine -lLLVMRuntimeDyld -lLLVMDlltoolDriver -lLLVMOption -lLLVMDebugInfoGSYM -lLLVMCoverage -lLLVMCoroutines -lLLVMXCoreDisassembler -lLLVMXCoreCodeGen -lLLVMXCoreDesc -lLLVMXCoreInfo -lLLVMX86Disassembler -lLLVMX86AsmParser -lLLVMX86CodeGen -lLLVMX86Desc -lLLVMX86Utils -lLLVMX86Info -lLLVMWebAssemblyDisassembler -lLLVMWebAssemblyCodeGen -lLLVMWebAssemblyDesc -lLLVMWebAssemblyAsmParser -lLLVMWebAssemblyInfo -lLLVMSystemZDisassembler -lLLVMSystemZCodeGen -lLLVMSystemZAsmParser -lLLVMSystemZDesc -lLLVMSystemZInfo -lLLVMSparcDisassembler -lLLVMSparcCodeGen -lLLVMSparcAsmParser -lLLVMSparcDesc -lLLVMSparcInfo -lLLVMRISCVDisassembler -lLLVMRISCVCodeGen -lLLVMRISCVAsmParser -lLLVMRISCVDesc -lLLVMRISCVUtils -lLLVMRISCVInfo -lLLVMPowerPCDisassembler -lLLVMPowerPCCodeGen -lLLVMPowerPCAsmParser -lLLVMPowerPCDesc -lLLVMPowerPCInfo -lLLVMNVPTXCodeGen -lLLVMNVPTXDesc -lLLVMNVPTXInfo -lLLVMMSP430Disassembler -lLLVMMSP430CodeGen -lLLVMMSP430AsmParser -lLLVMMSP430Desc -lLLVMMSP430Info -lLLVMMipsDisassembler -lLLVMMipsCodeGen -lLLVMMipsAsmParser -lLLVMMipsDesc -lLLVMMipsInfo -lLLVMLanaiDisassembler -lLLVMLanaiCodeGen -lLLVMLanaiAsmParser -lLLVMLanaiDesc -lLLVMLanaiInfo -lLLVMHexagonDisassembler -lLLVMHexagonCodeGen -lLLVMHexagonAsmParser -lLLVMHexagonDesc -lLLVMHexagonInfo -lLLVMBPFDisassembler -lLLVMBPFCodeGen -lLLVMBPFAsmParser -lLLVMBPFDesc -lLLVMBPFInfo -lLLVMARMDisassembler -lLLVMARMCodeGen -lLLVMARMAsmParser -lLLVMARMDesc -lLLVMARMUtils -lLLVMARMInfo -lLLVMAMDGPUDisassembler -lLLVMAMDGPUCodeGen -lLLVMMIRParser -lLLVMipo -lLLVMInstrumentation -lLLVMVectorize -lLLVMLinker -lLLVMIRReader -lLLVMAsmParser -lLLVMAMDGPUAsmParser -lLLVMAMDGPUDesc -lLLVMAMDGPUUtils -lLLVMAMDGPUInfo -lLLVMAArch64Disassembler -lLLVMMCDisassembler -lLLVMAArch64CodeGen -lLLVMGlobalISel -lLLVMSelectionDAG -lLLVMAsmPrinter -lLLVMDebugInfoDWARF -lLLVMCodeGen -lLLVMTarget -lLLVMScalarOpts -lLLVMInstCombine -lLLVMAggressiveInstCombine -lLLVMTransformUtils -lLLVMBitWriter -lLLVMAnalysis -lLLVMProfileData -lLLVMObject -lLLVMBitReader -lLLVMBitstreamReader -lLLVMCore -lLLVMRemarks -lLLVMAArch64AsmParser -lLLVMMCParser -lLLVMAArch64Desc -lLLVMMC -lLLVMDebugInfoCodeView -lLLVMDebugInfoMSF -lLLVMBinaryFormat -lLLVMAArch64Utils -lLLVMAArch64Info -lLLVMSupport -lLLVMDemangle")

llvm_map_components_to_libnames(llvm_libs support core irreader) 



add_executable(blawn
    ./src/compiler/ast_generator/ast_generator.cpp
    ./src/compiler/blawn_context/blawn_context.cpp
    ./src/compiler/utils/utils.cpp
    ./src/compiler/global_configuration/global_configuration.cpp
    ./src/compiler/parser/driver.cpp
    ./src/compiler/parser/main.cpp
    ./src/compiler/builtins/builtins.cpp
    ./src/compiler/ast/node.cpp
    ./src/compiler/errors/errors.cpp
    ./src/compiler/ir_generator/ir_generator.cpp
    ./src/compiler/compiler/compiler.cpp
    ${BISON_parser_OUTPUTS}
    ${FLEX_lexer_OUTPUTS})

include_directories(${LLVM_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR} /usr/local/opt/flex/include)
target_link_libraries(blawn ${llvm_libs})
add_custom_target(copy ALL cp blawn ../../blawn/blawn)
add_custom_target(format ALL python3 /Users/ueharanaoto/Desktop/Blawn/src/dev_utils/format_cpp.py /Users/ueharanaoto/Desktop/Blawn/src)