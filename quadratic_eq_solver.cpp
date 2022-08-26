#include "quadratic_eq_solver.h"
#include "utilities.h"

NUM_ROOTS solve_quad_eq (struct coef_and_sol * eq)
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
	
	return ZERO_ROOTS;
} 

NUM_ROOTS solve_lin_equation (struct coef_and_sol * eq)
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
	
	return ZERO_ROOTS;
}

int isCmpZero(double a)
{
	return fabs(a) <= eps ? 1 : 0;
}