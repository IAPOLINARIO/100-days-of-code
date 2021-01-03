;/**
; * FINAL DAY-100 C++ version (with ASM integration)
; * 
; * Just run 'make' to compile and run all the tests
; * 
; */

global InputAndOutputMessageFromExternalLinkedAssembly ;exported Symbol to be used from C++

section .data

section .text
InputAndOutputMessageFromExternalLinkedAssembly:    
    mov rax, rdi ;receives message from C++
    ret