#include "Title.h"


int main(void) {
	struct Answers ans = { ZERO,
						  {0, 0} }; // первый элемент является числом решений
	// второй и третьий равны значениям х, если они существуют
	struct Coefficients Coef = { 0, 0, 0 };
	printf("Hi! This program solves quadratic equations a*x^2 + b*x + c = 0 \n");
	menu(&ans, &Coef);
	return 0;
}
