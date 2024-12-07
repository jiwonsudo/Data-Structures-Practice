#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "list_based_stack.h"
#include "infix_to_postfix.h"

int GetOpPrec(char op) {
	switch(op) {
	case '*':
	case '/':
		return 5;
		break;
	case '+':
	case '-':
		return 3;
		break;
	case '(':
		return 1;
		break;
	}
	
	return -1;  // 연산자가 아닐 경우
}

int WhoPrecOP(char op1, char op2) {
	int op1_prec = GetOpPrec(op1);
	int op2_prec = GetOpPrec(op2);
	
	if (op1_prec > op2_prec)
		return 1;
	else if (op1_prec < op2_prec)
		return -1;
	else return 0;
}

void ConvToRPNExp(char exp[]) {
	Stack stack;
	int exp_len = strlen(exp);
	char *conv_exp = (char*)malloc(exp_len + 1);
	
	int idx = 0;
	char token, pop_op;
	
	memset(conv_exp, 0, sizeof(char) * exp_len + 1);
	StackInit(&stack);
	
	for (int i = 0; i < exp_len; i++) {
		token = exp[i];
		if (isdigit(token)) {
			conv_exp[idx++] = token;
		} else {
			switch(token) {
				case '(':
					Push(&stack, token);
					break;
				case ')':
					while(1) {
						pop_op = Pop(&stack);
						if (pop_op == '(') break;
						conv_exp[idx++] = pop_op;
					}
					break;
				case '+': case '-': case '*': case '/':
					while (!IsStackEmpty(&stack) && WhoPrecOP(Peek(&stack), token) >= 0)
						conv_exp[idx++] = Pop(&stack);
					
					Push(&stack, token);
					break;
			}
		}
	}
	
	while (!IsStackEmpty(&stack))
		conv_exp[idx++] = Pop(&stack);
	
	strcpy(exp, conv_exp);
	free(conv_exp);
}

