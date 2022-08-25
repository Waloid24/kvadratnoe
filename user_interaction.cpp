#include "shared_file.h"
#include <stdio.h>
#include "interface.h"
#include "user_interaction.h"

// Эта функци должна не решать квадратное уравнение, а только выводить его корни, то есть должна принимать заполненную структуру
// и выводить информацию.
// void
int output_solutions_this_equation (struct coef_and_sol * eq)
{
	assert (eq != nullptr);
	
	// switch (eq->num_x)
	
	switch (eq->num_x = solve_quad_eq (eq))
		{
			case 0 : { /* printf("The quadratic equation has no solutions.\n");  */ return ZERO_ROOTS; }
			case 1 : { /* printf("Solution: %.2lf.\n", eq->x_1); 				 */ return ONE_ROOTS;  }
			case 2 : { /* printf("Solutions: %.2lf, %.2lf\n", eq->x_1, eq->x_2); */ return TWO_ROOTS;  }
			case -1: { /* printf("x is any real number.\n"); 					 */ return INF_ROOTS;  }
			default: { /* printf("()_().\n"); 									 */ return -2;         }
		};
}

// NUM_ROOTS solve_quad_eq (struct coef_and_sol * eq);
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

// NUM_ROOTS solve_lin_equation (struct coef_and_sol * eq)
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
	return fabs(a) <= eps ? 1 : 0;
}