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
bison_target(parser ./src/lib/blawn/parser/parser.yy ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
flex_target(lexer ./src/lib/blawn/parser/lexer.ll ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp)
ADD_FLEX_BISON_DEPENDENCY(lexer parser)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-std=c++17 --debug -O0 -Wno-unused-command-line-argument -I/usr/local/Cellar/llvm/9.0.0_1/include -std=c++17 -stdlib=libc++ -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS -L/usr/local/Cellar/llvm/9.0.0_1/lib -Wl,-search_paths_first -Wl,-headerpad_max_install_names -lLLVMXRay -lLLVMWindowsManifest -lLLVMTextAPI -lLLVMTableGen -lLLVMSymbolize -lLLVMDebugInfoPDB -lLLVMOrcJIT -lLLVMJITLink -lLLVMObjectYAML -lLLVMMCA -lLLVMLTO -lLLVMPasses -lLLVMObjCARCOpts -lLLVMLineEditor -lLLVMLibDriver -lLLVMInterpreter -lLLVMFuzzMutate -lLLVMMCJIT -lLLVMExecutionEngine -lLLVMRuntimeDyld -lLLVMDlltoolDriver -lLLVMOption -lLLVMDebugInfoGSYM -lLLVMCoverage -lLLVMCoroutines -lLLVMXCoreDisassembler -lLLVMXCoreCodeGen -lLLVMXCoreDesc -lLLVMXCoreInfo -lLLVMX86Disassembler -lLLVMX86AsmParser -lLLVMX86CodeGen -lLLVMX86Desc -lLLVMX86Utils -lLLVMX86Info -lLLVMWebAssemblyDisassembler -lLLVMWebAssemblyCodeGen -lLLVMWebAssemblyDesc -lLLVMWebAssemblyAsmParser -lLLVMWebAssemblyInfo -lLLVMSystemZDisassembler -lLLVMSystemZCodeGen -lLLVMSystemZAsmParser -lLLVMSystemZDesc -lLLVMSystemZInfo -lLLVMSparcDisassembler -lLLVMSparcCodeGen -lLLVMSparcAsmParser -lLLVMSparcDesc -lLLVMSparcInfo -lLLVMRISCVDisassembler -lLLVMRISCVCodeGen -lLLVMRISCVAsmParser -lLLVMRISCVDesc -lLLVMRISCVUtils -lLLVMRISCVInfo -lLLVMPowerPCDisassembler -lLLVMPowerPCCodeGen -lLLVMPowerPCAsmParser -lLLVMPowerPCDesc -lLLVMPowerPCInfo -lLLVMNVPTXCodeGen -lLLVMNVPTXDesc -lLLVMNVPTXInfo -lLLVMMSP430Disassembler -lLLVMMSP430CodeGen -lLLVMMSP430AsmParser -lLLVMMSP430Desc -lLLVMMSP430Info -lLLVMMipsDisassembler -lLLVMMipsCodeGen -lLLVMMipsAsmParser -lLLVMMipsDesc -lLLVMMipsInfo -lLLVMLanaiDisassembler -lLLVMLanaiCodeGen -lLLVMLanaiAsmParser -lLLVMLanaiDesc -lLLVMLanaiInfo -lLLVMHexagonDisassembler -lLLVMHexagonCodeGen -lLLVMHexagonAsmParser -lLLVMHexagonDesc -lLLVMHexagonInfo -lLLVMBPFDisassembler -lLLVMBPFCodeGen -lLLVMBPFAsmParser -lLLVMBPFDesc -lLLVMBPFInfo -lLLVMARMDisassembler -lLLVMARMCodeGen -lLLVMARMAsmParser -lLLVMARMDesc -lLLVMARMUtils -lLLVMARMInfo -lLLVMAMDGPUDisassembler -lLLVMAMDGPUCodeGen -lLLVMMIRParser -lLLVMipo -lLLVMInstrumentation -lLLVMVectorize -lLLVMLinker -lLLVMIRReader -lLLVMAsmParser -lLLVMAMDGPUAsmParser -lLLVMAMDGPUDesc -lLLVMAMDGPUUtils -lLLVMAMDGPUInfo -lLLVMAArch64Disassembler -lLLVMMCDisassembler -lLLVMAArch64CodeGen -lLLVMGlobalISel -lLLVMSelectionDAG -lLLVMAsmPrinter -lLLVMDebugInfoDWARF -lLLVMCodeGen -lLLVMTarget -lLLVMScalarOpts -lLLVMInstCombine -lLLVMAggressiveInstCombine -lLLVMTransformUtils -lLLVMBitWriter -lLLVMAnalysis -lLLVMProfileData -lLLVMObject -lLLVMBitReader -lLLVMBitstreamReader -lLLVMCore -lLLVMRemarks -lLLVMAArch64AsmParser -lLLVMMCParser -lLLVMAArch64Desc -lLLVMMC -lLLVMDebugInfoCodeView -lLLVMDebugInfoMSF -lLLVMBinaryFormat -lLLVMAArch64Utils -lLLVMAArch64Info -lLLVMSupport -lLLVMDemangle -O0")

set(ld_flags "--debug -O0 -Wno-unused-command-line-argument /usr/local/opt/llvm/lib/liblldCOFF.a /usr/local/opt/llvm/lib/liblldCommon.a /usr/local/opt/llvm/lib/liblldCore.a /usr/local/opt/llvm/lib/liblldDriver.a /usr/local/opt/llvm/lib/liblldELF.a /usr/local/opt/llvm/lib/liblldMachO.a /usr/local/opt/llvm/lib/liblldMinGW.a /usr/local/opt/llvm/lib/liblldReaderWriter.a /usr/local/opt/llvm/lib/liblldWasm.a /usr/local/opt/llvm/lib/liblldYAML.a -O0")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${ld_flags}")

llvm_map_components_to_libnames(llvm_libs support core irreader) 

add_custom_target(bison_patch ALL COMMAND "python3" "../src/lib/blawn/parser/patch.py")

add_executable(blawn
    ./src/lib/blawn/main.cpp
    ./src/lib/blawn/module/module.cpp
    ./src/lib/ast/builder.cpp
    ./src/lib/blawn/compiler.cpp
    ./src/lib/blawn/visitors/ast_to_mir.cpp
    ./src/lib/debug/debug_info.cpp
    ./src/lib/scope/scope.cpp
    ./src/lib/scope/mangler.cpp
    ./src/lib/utils/unique_number.cpp
    ./src/lib/blawn/parser/driver.cpp
    ./src/lib/ast/node.cpp
    ${BISON_parser_OUTPUTS}
    ${FLEX_lexer_OUTPUTS})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/ ${LLVM_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR} /usr/local/opt/flex/include)
target_link_libraries(blawn ${llvm_libs})

add_custom_target(format ALL python3 /Users/ueharanaoto/Desktop/Blawn/dev_utils/format_cpp.py /Users/ueharanaoto/Desktop/Blawn/src)