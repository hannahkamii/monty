#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void op_pint(stack_t **h, unsigned int line_number);
void f_pint(stack_t **stack, unsigned int line_number);
void pall(stack_t **s, unsigned int line_number);
void pint(stack_t **s, unsigned int line_number);
void push(stack_t **s, int value);
void pall(stack_t **s, unsigned int line_number);
void free_s(stack_t *s);
void swap(stack_t **s, unsigned int line_number);
void add(stack_t **s, unsigned int line_number);
void pop(stack_t **s, unsigned int line_number);
void nop(stack_t **s, unsigned int line_number);
void sub(stack_t **s, unsigned int line_number);
void div_no(stack_t **s, unsigned int line_number);
void mul(stack_t **s, unsigned int line_number);
void mod(stack_t **s, unsigned int line_number);
#endif
