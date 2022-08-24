#include <stdio.h>
//#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>

const double eps = 0.000000001;

enum NUM_ROOTS 
{
	INF_ROOTS = -1, 
	ZERO_ROOTS = 0,
	ONE_ROOTS = 1,
	TWO_ROOTS = 2
};

double menu(void);
double check_coefficient_for_corret(void);
int solve_quad_eq (struct coef_and_sol * );                // the function witch chooses whether to solve a quadratic or linear equation
int solve_lin_equation (struct coef_and_sol * );         // the function witch solves the linear equation (if a == 0)
void enter_coefficients_for_eq (struct coef_and_sol * );               // the function witch receive the values of the coefficients
void output_solutions_this_equation (struct coef_and_sol * );  // the function witch output solutions to this quadratic equation in the structure
int isCmpZero(double );

struct coef_and_sol
{
	double a;
	double b;
	double c;
	double x_1;
	double x_2;
	int num_x;
};

  // 5 ФАЙЛОВ: два ашника, main.cpp, 1 с интерфейсом, другой с пользователем
	
int main (void)
{	
	struct coef_and_sol eq = {};  //coefficients and solutions
	
	while (menu()) 
	{
		enter_coefficients_for_eq(&eq);  
		output_solutions_this_equation(&eq);		
	}		
	
	return 0;
}

double check_coefficient_for_corret (void)
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
	printf("a) Input \"1\" for new equations; b) Input \"0\" for exit;\n");
	double a = check_coefficient_for_corret();
	
	return a;
}

void enter_coefficients_for_eq (struct coef_and_sol * eq)
{
	assert (eq != nullptr);
	
	printf("The quadratic equation has the form:"
		" a*(x^2) + b*x + c = 0\n");
		
	printf("Enter a: ");
	eq->a = check_coefficient_for_corret();
	
	printf("Enter b: ");
	eq->b = check_coefficient_for_corret();
	
	printf("Enter c: ");
	eq->c = check_coefficient_for_corret();
	
	printf("The equation is: "
		"%.2lf*x^2 + %.2lf*x + %.2lf = 0\n", eq->a, eq->b, eq->c);
}

void output_solutions_this_equation (struct coef_and_sol * eq)
{
	assert (eq != nullptr);
	
	switch (eq->num_x = solve_quad_eq (eq))
		{
			case 0: { printf("The quadratic equation has no solutions.\n"); break; }
			case 1: { printf("Solution: %.2lf.\n", eq->x_1); break; }
			case 2: { printf("Solutions: %.2lf, %.2lf\n", eq->x_1, eq->x_2); break; }
			case -1: { printf("x is any real number.\n"); break; }
			default: { printf("()_().\n"); }
		};
} 



int solve_quad_eq (struct coef_and_sol * eq)
{
	assert(eq != nullptr);
	
	if (isCmpZero(eq->a))  
	{
		return solve_lin_equation(eq);
	}
	else 
	{
		assert (eq != nullptr);
		
		double double_a = 2*eq->a;
		double double_b = eq->b;
		double double_c = eq->c;
	
		double d = double_b*double_b - 2*double_a*double_c;
	
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
	
	return 0;
} 

int solve_lin_equation (struct coef_and_sol * eq)
{
	assert (eq != nullptr);
	
	if (isCmpZero(eq->b))
	{
		if (isCmpZero(eq->c))
			return INF_ROOTS;
		else 
			return ZERO_ROOTS;
	}
	else
	{
		eq->x_1 = eq->x_2 = (-eq->c)/eq->b;
		return ONE_ROOTS;
	}
	
	return 0;
}

int isCmpZero(double a)
{
	if (a <= eps && a >= -eps)
		return true;
	else 
		return false;
}
 