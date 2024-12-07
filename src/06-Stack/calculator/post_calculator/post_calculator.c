#include <string.h>
#include <ctype.h>
#include "../list_based_stack/list_based_stack.h"

int EvalRPNExp(char exp[]) {
	Stack stack;
	int exp_len = strlen(exp);
	char token, op1, op2;
	
	StackInit(&stack);
	
	for (int i = 0; i < exp_len; i++) {
		token = exp[i];
		
		if (isdigit(token))
			Push(&stack, token - '0');
		else {
			op2 = Pop(&stack);
			op1 = Pop(&stack);
			
			switch(token) {
				case '+':
					Push(&stack, op1 + op2);
					break;
				case '-':
					Push(&stack, op1 - op2);
					break;
				case '*':
					Push(&stack, op1 * op2);
					break;
				case '/':
					Push(&stack, op1 / op2);
					break;
			}
		}
	}
	
	return Pop(&stack);
}