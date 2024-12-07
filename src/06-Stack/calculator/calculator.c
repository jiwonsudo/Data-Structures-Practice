#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "infix_calculator/infix_calculator.h"

int main() {
	char temp[100];
	int len;
	
	puts("Enter infix expression to calculate:");
	scanf("%99[^\n]", temp);
	
	len = strlen(temp);
	
	char *exp = (char*)malloc((len + 1) * sizeof(char));
	strcpy(exp, temp);
	
	printf("The result for your expression: %d \n", EvalInfixExp(exp));
	
	return 0;
}