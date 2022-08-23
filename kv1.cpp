#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define SIZE 10

double menu(void);
double input(void);
int quad_eq (struct coef_and_sol * );
void f_inp (struct coef_and_sol * );
void f_out (struct coef_and_sol * );
void f_sol (struct coef_and_sol * );

struct coef_and_sol
	{
		double a;
		double b;
		double c;
		double x_1;
		double x_2;
		int num_x;
	};
	
int main (void)
{	
	struct coef_and_sol eq;  //coefficients and solutions
	
	while (menu() != 2)
	{
		f_inp(&eq);
		// сделать функцию ввода, функцию вывода, функция решения, убрать массив структур, в отдельный файл ф-ии
		f_sol(&eq);		
	}
	
	f_out (&eq);
			
	return 0;
}

int quad_eq (struct coef_and_sol * eq)
{
	if (eq->a == 0 && eq->b == 0)
	{
		if (eq->c == 0)
		{
			return 3;  //корней бесконечно много
		}
		else
		{
			return 0;
		}
	}
	
	if (eq->a == 0 && eq->b != 0 && eq->c != 0)
	{
		eq->x_1 = eq->x_2 = (-eq->c)/eq->b;
		return 1;
	}
		
	// разбить на линейное и квадратное уравнение
	
	if (eq->a != 0)
	{
		double d = eq->b*eq->b - 4*eq->a*eq->c;
		if (d < 0)
		{
			return 0;
		}
		else if (d>0)
		{
			eq->x_1 = (-eq->b - sqrt(d)) / (2*eq->a);
			eq->x_2 = (-eq->b + sqrt(d)) / (2*eq->a);
			return 2;
		}
		else
		{
			eq->x_1 = eq->x_2 = (-eq->b)/(2*eq->a);
			return 1;
		}
	}
	return 0;
}


double input (void)
{
	double a = 0;
	while (scanf("%lf", &a) != 1)
	{
		printf("Enter a number again please.\n");
		while (getchar() != '\n')
			continue;
	}
	return a;
}

double menu (void)
{
	printf("Our opportunities:\n");
	printf("a) Input \"1\" for new equations; b) Input \"2\" for exit;\n");
	double a = input();
	
	return a;
}

void f_inp (struct coef_and_sol * eq)
{
	printf("The quadratic equation has the form:"
		" a*(x^2) + b*x + c = 0\n");
		
	printf("Enter a: ");
	eq->a = input();
	
	printf("Enter b: ");
	eq->b = input();
	
	printf("Enter c: ");
	eq->c = input();
	
	printf("The equation is: "
		"%.2lf*x^2 + %.2lf*x + %.2lf = 0\n", eq->a, eq->b, eq->c);
}

void f_out (struct coef_and_sol * eq)
{
		printf("Coefficients: a = %.2lf, b = %.2lf, c = %.2lf;\n", eq->a, eq->b, eq->c);
		if(eq->num_x == 0)
			printf("No solutions.\n");
		else if (eq->num_x == 1)
			printf("Answer: %.2lf.\n", eq->x_1);
		else if(eq->num_x == 2)
			printf("Answers: %.2lf, %.2lf.\n", eq->x_1, eq->x_2);
		else 
			printf("x is any real number.\n");
}

void f_sol (struct coef_and_sol * eq)
{
	switch (eq->num_x = quad_eq (eq))
		{
			case 0: printf("The quadratic equation has no solutions.\n");
					break;
			case 1: printf("Solution: %.2lf.\n", eq->x_1);
					break;
			case 2: printf("Solutions: %.2lf, %.2lf\n", eq->x_1, eq->x_2);
					break;
			case 3: printf("x is any real number.\n");
					break;
			default: printf("()_().\n");
					break; 
		};
} 
