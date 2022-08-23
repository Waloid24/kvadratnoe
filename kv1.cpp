#include <stdio.h>
#include <ctype.h>
#include <math.h>

// const int SMTH = 2;
#define SIZE 10 // const !!!

// naming functions
double menu(void);
double input(void);
int quad_eq (struct coef_and_sol * );
void f_inp (struct coef_and_sol * );
void f_out (struct coef_and_sol * );
void f_sol (struct coef_and_sol * );
int f_lin (struct coef_and_sol * );
int f_sq_eq (struct coef_and_sol * );

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
	struct coef_and_sol eq = {};  //coefficients and solutions
	
	while (menu() != 2) // magic const
	{
		f_inp(&eq);
		f_sol(&eq);		
	}
	
	f_out(&eq);		
	
	return 0;
}

// писать название функций с глагола
int quad_eq (struct coef_and_sol * eq)
{
	assert(eq != nullptr);
	
	if (eq->a == 0)  //linear equation
	{
		return f_lin(eq);
	}
	
	if (eq->a != 0)  //quadratic equation
	{
		return f_sq_eq (eq);
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
	assert (eq != nullptr);
	
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
	assert (eq != nullptr);
	
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
	assert (eq != nullptr);
	
	switch (eq->num_x = quad_eq (eq))
		{
			case 0: { printf("The quadratic equation has no solutions.\n"); break; }
			case 1: { printf("Solution: %.2lf.\n", eq->x_1); break; }
			case 2: { printf("Solutions: %.2lf, %.2lf\n", eq->x_1, eq->x_2); break; }
			case -1: { printf("x is any real number.\n"); break; }
			default: { printf("()_().\n"); }
		};
} 

int f_lin (struct coef_and_sol * eq)
{
	assert (eq != nullptr);
	
	enum NUM_ROOTS {
	     INF_ROOTS = -1,  //в .h файле
	     ZERO_ROOTS = 0,
	     ONE_ROOTS = 1,
	     TWO_ROOTS = 2
	 }
	
	if (eq->c == 0 && eq->b == 0)
		return INF_ROOTS;
	else if (eq->b == 0 && eq->c != 0)
		return ZERO_ROOTS;
	else if (eq->b != 0 && eq->c == 0)
	{
		eq->x_1 = eq->x_2 = 0;
		return ONE_ROOTS;
	}
	else if (eq->b != 0 && eq->c != 0)
	{
		eq->x_1 = eq->x_2 = -(eq->c)/eq->b;
		return ONE_ROOTS;
	}
	return 0;
}

int f_sq_eq (struct coef_and_sol * eq)
{
	assert (eq != nullptr);
	enum NUM_ROOTS {
	     INF_ROOTS = -1,  // в .h файле
	     ZERO_ROOTS = 0,
	     ONE_ROOTS = 1,
	     TWO_ROOTS = 2
	}
	double double_a = 2*eq->a;
	double double_b = eq->b;
	double double_c = eq->c;
	
	double d = double_b*double_b - 2*double_a*double_c;
	
	// написать функцию (a)
	//
	//          |    true    |
	// --------(------|------)---
	//       0 - eps  0    0 + eps
	if (d < 0) //
		{
			return ZERO_ROOTS;
		}
		else if (d>0)
		{
			eq->x_1 = (-double_b - sqrt(d)) / (double_a);
			eq->x_2 = (-double_b + sqrt(d)) / (double_a);
			return TWO_ROOTS; //
		}
		else
		{
			eq->x_1 = eq->x_2 = (-double_b)/(double_a);
			return ONE_ROOTS;
		}
}
