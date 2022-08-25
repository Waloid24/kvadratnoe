#ifndef USER_INTERACTION_H
#define USER_INTERACTION_H

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// rename file (quadratic_eq_solver)

enum NUM_ROOTS 
{
	INF_ROOTS = -1, 
	ZERO_ROOTS = 0,
	ONE_ROOTS = 1,
	TWO_ROOTS = 2
};

const double eps = 0.000000001;

int solve_quad_eq (struct coef_and_sol * ); 

int solve_lin_equation (struct coef_and_sol * );

// interface.h
int output_solutions_this_equation (struct coef_and_sol * eq);

int isCmpZero(double );

#endif
