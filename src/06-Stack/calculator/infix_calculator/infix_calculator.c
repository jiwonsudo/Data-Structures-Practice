#include <string.h>
#include <stdlib.h>
#include "../infix_to_postfix/infix_to_postfix.h"
#include "../post_calculator/post_calculator.h"

int EvalInfixExp(char exp[]) {
	int len = strlen(exp);
	int res;
	char *expcpy = (char*)malloc(len + 1);
	strcpy(expcpy, exp);
	
	ConvToRPNExp(expcpy);
	res = EvalRPNExp(expcpy);
	
	free(expcpy);
	return res;
}