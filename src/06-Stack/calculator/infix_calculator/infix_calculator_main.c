#include <stdio.h>
#include "infix_calculator.h"

int main() {
	char exp_1[] = "1+2*3";
	char exp_2[] = "(1+2)*3";
	char exp_3[] = "((1-2)+3)*(5-2)";
	
	printf("%s = %d \n", exp_1, EvalInfixExp(exp_1));
	printf("%s = %d \n", exp_2, EvalInfixExp(exp_2));
	printf("%s = %d \n", exp_3, EvalInfixExp(exp_3));
	
	return 0;
}