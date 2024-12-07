#include <stdio.h>
#include "post_calculator.h"

int main() {
	char post_exp_1[] = "42*8+";
	char post_exp_2[] = "123+*4/";
	
	printf("%s = %d \n", post_exp_1, EvalRPNExp(post_exp_1));
	printf("%s = %d \n", post_exp_2, EvalRPNExp(post_exp_2));
	
	return 0;
}