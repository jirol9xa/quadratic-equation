#include <stdio.h> 
#include <math.h>
#include <assert.h>


/*!
	\brief Структура для хранения ответов

	Данная структура сохраняет количество корней в переменную amount и сами корни в массив roots
*/
struct Answers {
	int amount;
	double roots[2];
};


/*!
	\brief Структура для хранения коэффициентов уравнения

	Даннас структура сохраняет значения коэффициентов a,b,c в переменные a,b и с соответсвенно
*/
struct Coefficients {
	double a;
	double b;
	double c;
};


/*!
	\brief Функция для ввода данных
	\param Coefficient Структура для хранения коэффициентов уравнения 

	Функция записывает в уже созданную структуру значения a,b и с    
*/
void input(struct Coefficients* Coefficients); // для ввода данных


/*!
	\brief Функция очищения ввода

	При неверном формате ввода коэффициентов данная функция очищает входные данные,
	чтобы scanf() могла обработать следующую попытку ввода
*/
void eatline(); // для отбрасывания отсальной части строки, если данные будут введены с мусором


/*!
	\brief Функция повторного ввода

	При неверном формате ввода коэффициентов данная функция запрашивает у пользователя
	повторный ввод данных, выводя перед этим сообщение "Just enter a number". Используется
	совместно с eatline()
*/
void wrong_input(); // на случай неправильного ввода


/*!
	\brief Функция, управляющая решением уравнения
	\param ans Структура для хранения ответа
	\param Coef Структура для хранения коэффициентов уравнения

	Данная функция вызывает функцию linear_equation(), если уравнение является линейным (а = 0)
	и вызывает функцию the_quadratic_equation в противном случае.
*/
void solve_equation(struct Answers* ans, struct Coefficients* Coef); // решение уравнения


/*!
	\brief Функция для решения линейного уравнения
	\param ans Структура для хранения ответа
	\param Coef Структура для хранения коэффициентов уравнения

	Данная функция вызывается функцией solve_equation() в случае, если а = 0 
	(то есть уравнение является линейным)
*/
void linear_equation(struct Answers* ans, struct Coefficients* Coef); // если а == 0


/*!
	\brief Функция решения через дpискриминант
	\param ans Структура для хранения ответа
	\param Coef Структура для хранения коэффициентов уравнения

	Данная функция вызывается функцией solve_equation() в случае, если а != 0
	(то есть уравнение является квадратным). Решение происходит через дискриминант.

*/
void the_quadratic_equation(struct Answers* ans, struct Coefficients* Coef); // решение через дискриминант


/*!
	\brief Функция для вывода ответа
	\param ans Структура для хранения ответа

	Данная функция выводит члены структуры Answers, а именно количество корней и их значения
	(если они существуют).
*/
void print_answers(struct Answers*);

const double zero = 1e-20;



int main(void) {
	struct Answers ans = { 0,
						  {0, 0} }; // первый элемент является числом решений
	// второй и третьий равны значениям х, если они существуют
	struct Coefficients Coef = { 0, 0, 0 };
	printf("Hi! This program solves quadratic equations a*x^2 + b*x + c = 0 \n");
	input(&Coef);
	printf("Quadratic equation: %lg*x^2 + %lg*x + %lg = 0 \n", Coef.a, Coef.b, Coef.c);
	solve_equation(&ans, &Coef);
	print_answers(&ans);
	printf("The equation is solved :)");
	return 0;
}


void input(struct Coefficients* Coef) {
	assert(Coef != NULL);
	printf("Now enter the values a, b, c \n");
	printf("enter a \n");
	while(scanf("%lf", &(Coef->a)) !=1){
		wrong_input();
		eatline();
	}
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
			(*ans).amount = 3;
		}
		else {
			(*ans).amount = 0;
		}
	}
	else {
		(*ans).amount = 1;
		(*ans).roots[0] = -(*Coef).c / (*Coef).b;
	}
}


void the_quadratic_equation(struct Answers* ans, struct Coefficients* Coef) {
	assert(Coef != NULL);
	assert(ans != NULL);
	double diskr = Coef->b * Coef->b - 4 * Coef->a * Coef->c;
	if (diskr < 0) {
		ans->amount = 0;
	}
	else if (fabs(diskr - 0) < zero) {
		ans->amount = 1;
		ans->roots[0] = -(Coef->b) / (2 * (Coef->a));
	}
	else {
		ans->amount = 2;
		ans->roots[0] = (-(Coef->b) - sqrt(diskr)) / (2 * (Coef->a));
		ans->roots[1] = (-(Coef->b) + sqrt(diskr)) / (2 * (Coef->a));
	}
}

void print_answers(struct Answers* ans) {
	assert(ans != NULL);
	switch (ans->amount) {
	case 0:
		printf("The equation has no solutions \n");
		break;
	case 1:
		printf("The equation has one solution x = %lg \n", ans->roots[0]);
		break;
	case 2:
		printf("The equation has one solution x1 = % lg   x2 = %lg \n", ans->roots[0], ans->roots[1]);
		break;
	default:
		printf("The equation has an infinite number of solutions \n");

	}
}
