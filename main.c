#include "Title.h"


int main(void) {
	struct Answers ans = {};

	struct Coefficients Coef = {};
	
	printf("Hi! This program solves quadratic equations a*x^2 + b*x + c = 0 \n");
	if (menu()){
		input(&Coef);

		printf("Quadratic equation: %lg*x^2 + %lg*x + %lg = 0 \n", Coef.a, Coef.b, Coef.c);
		
		solve_equation(&ans, &Coef);
		print_answers(&ans);
		
		printf("The equation is solved :) \n");
	}
	else {
		if (!UnitTestSolution()){
			printf("Checking failed \n");
		}

	}
	return 0;
}
