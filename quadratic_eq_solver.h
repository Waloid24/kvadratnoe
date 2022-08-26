#ifndef USER_INTERACTION_H
#define USER_INTERACTION_H

#include <stdbool.h>

enum NUM_ROOTS 
{
	INF_ROOTS = -1, 
	ZERO_ROOTS = 0,
	ONE_ROOTS = 1,
	TWO_ROOTS = 2
};

const double eps = 0.000000001;

NUM_ROOTS solve_lin_equation (struct coef_and_sol * );

NUM_ROOTS solve_quad_eq (struct coef_and_sol * eq); 

int isCmpZero(double );

#endif
