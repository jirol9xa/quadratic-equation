#include "Title.h"


void input(struct Coefficients* Coef) {
	assert(Coef != NULL);
	printf("Now enter the values a, b, c \n");
	do{
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
		printf("We're checking the coefficients for admissibility \n");
	}
	while(!check_Coef(Coef));
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
	assert(check_Coef(Coef));
	assert(ans != NULL);

	if (iseallity(0, Coef->a)) {
		linear_equation(ans, Coef);
	}
	else {
		the_quadratic_equation(ans, Coef);
	}
}


void linear_equation(struct Answers* ans, struct Coefficients* Coef) {
	assert(Coef != NULL);
	assert(check_Coef(Coef));
	assert(ans != NULL);

	if (iseallity(0, Coef->b)) {
		if (iseallity(0, Coef->c)) {
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
	assert(check_Coef(Coef));
	assert(ans != NULL);

	double diskr = Coef->b * Coef->b - 4 * Coef->a * Coef->c;
	
	if (diskr < -zero) {
		ans->amount = ZERO;
	}
	else
        if (iseallity(diskr, 0)) {
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
	assert(check_Ans(ans));

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


int menu(){
	printf("Do you want to solve your equation or check the boundary values? \n");
	printf("a) Solve       b)Check \n");

	char ch = 0;
	scanf("%c", &ch);
	while (!strchr("ab", ch)){
		printf("Just enter \"a\" or \"b\" ");
		eatline();
		scanf("%c", &ch);
	}
	eatline();
	if  (ch == 'a'){
		return 1;
	}
	else{
		return 0;
	}
	
}


int check_Coef(struct Coefficients * Coef){
	return (isfinite(Coef->a) && isfinite(Coef->b) && isfinite(Coef->c));
}


int check_Ans(struct Answers * ans){
	return (isfinite((double)ans->amount) && isfinite(ans->roots[0]) && isfinite(ans->roots[1]));
}

int iseallity(double a, double b){
	return (fabs(a - b) < zero);
}