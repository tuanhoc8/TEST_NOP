/*
 * Initialize_Stack.S
 *
 *  Created on: Oct 5, 2023
 *      Author: phana
 */

 	.syntax unified
    .arch armv7-m
	.thumb_func
    .align 2
   	.section .text, "a"
    .globl   init_stack
    .type    init_stack, %function

init_stack:
	    /* Initialize the stack pointer */
    ldr     r0,=__StackTop
    mov     r13,r0
	bx		LR


