#include "Title.h"


void input(struct Coefficients* Coef) {
	assert(Coef != NULL);
	printf("Now enter the values a, b, c \n");
	printf("enter a \n");
	while(scanf("%lf", &(Coef->a)) !=1){
		wrong_input();
		eatline();
	}
	eatline();
	printf("enter b \n");
	while(scanf("%lf", &(Coef->b)) !=1){
		wrong_input();
		eatline();
	}
	eatline();
	printf("enter c \n");
	while(scanf("%lf", &(Coef->c)) !=1){
		wrong_input();
		eatline();
	}
}


void eatline() {
	while (getchar() != '\n') {
		continue;
	}
}


void wrong_input() {
	printf("Just enter a number \n");
}


void solve_equation(struct Answers* ans, struct Coefficients* Coef) {
	assert(Coef != NULL);
	assert(ans != NULL);
	if (fabs(Coef->a) < zero) {
		linear_equation(ans, Coef);
	}
	else {
		the_quadratic_equation(ans, Coef);
	}
}


void linear_equation(struct Answers* ans, struct Coefficients* Coef) {
	assert(Coef != NULL);
	assert(ans != NULL);
	if (fabs((*Coef).b) < zero) {
		if (fabs((*Coef).c) < zero) {
			(*ans).amount = INFINIT;
		}
		else {
			(*ans).amount = ZERO;
		}
	}
	else {
		(*ans).amount = ONE;
		(*ans).roots[0] = -(*Coef).c / (*Coef).b;
	}
}


void the_quadratic_equation(struct Answers* ans, struct Coefficients* Coef) {
	assert(Coef != NULL);
	assert(ans != NULL);
	double diskr = Coef->b * Coef->b - 4 * Coef->a * Coef->c;
	if (diskr < 0) {
		ans->amount = ZERO;
	}
	else
        if (fabs(diskr - 0) < zero) {
		    ans->amount = ONE;
		    ans->roots[0] = -(Coef->b) / (2 * (Coef->a));
	    }
	    else {
		    ans->amount = TWO;
		    ans->roots[0] = (-(Coef->b) - sqrt(diskr)) / (2 * (Coef->a));
		    ans->roots[1] = (-(Coef->b) + sqrt(diskr)) / (2 * (Coef->a));
	    }
}

void print_answers(struct Answers* ans) {
	assert(ans != NULL);
	switch (ans->amount) {
	case ZERO:
		printf("The equation has no solutions \n");
		break;
	case ONE:
		printf("The equation has one solution x = %lg \n", ans->roots[0]);
		break;
	case TWO:
		printf("The equation has one solution x1 = % lg   x2 = %lg \n", ans->roots[0], ans->roots[1]);
		break;
	default:
		printf("The equation has an infinite number of solutions \n");

	}
}


void menu(struct Answers* ans, struct Coefficients* Coef){
	printf("Do you want to solve your equation or check the boundary values? \n");
	printf("a) Solve       b)Check \n");
	char ch = 0;
	scanf("%c", &ch);
	if (ch == 'a'){
		input(Coef);
		printf("Quadratic equation: %lg*x^2 + %lg*x + %lg = 0 \n", Coef->a, Coef->b, Coef->c);
		solve_equation(ans, Coef);
		print_answers(ans);
		printf("The equation is solved :) \n");
	}
	else if (ch == 'b'){
		if (!UnitTestSolution()){
			printf("Checking failed \n");
		}

	}
}
