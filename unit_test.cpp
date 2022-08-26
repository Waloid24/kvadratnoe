#include "utilities.h"
#include "quadratic_eq_solver.h"
#include "unit_test.h"

struct coef_and_sol tests[NUMBER_OF_TESTS] = 
{
	{0, 0, 0, 0, 0, -1},
	{1, 2, 1, -1, -1, 1}
};

void UnitTest ()
{
	int n_failed_tests = 0;
	
	struct coef_and_sol my_solve = {};
	
	double x_1 = NAN, x_2 = NAN;
	
	for (int i = 0; i < NUMBER_OF_TESTS; i++)
	{
		duplicate_coefficients(&my_solve, &tests[i]);
		
		my_solve.num_x = solve_quad_eq(&my_solve);
		n_failed_tests += isFailed(&my_solve, &tests[i], i);
	}
	
	printf("Out of %d tests, %d failed.\n", NUMBER_OF_TESTS, n_failed_tests);
	
	return ; 
} 

void duplicate_coefficients (struct coef_and_sol * to_calculate, struct coef_and_sol * to_comparison)
{	
	assert (to_calculate != nullptr);
	assert (to_comparison != nullptr);
	
	to_calculate->a = to_comparison->a;
	to_calculate->b = to_comparison->b;
	to_calculate->c = to_comparison->c;
}

int isFailed (struct coef_and_sol * to_calculate, struct coef_and_sol * to_comparison, int n)
{		
	assert (to_calculate != nullptr);
	assert (to_comparison != nullptr);
	
	if (to_calculate->x_1 == to_comparison->x_1 && to_calculate->x_2 == to_comparison->x_2 && to_calculate->num_x == to_comparison->num_x)
	{
		printf("Successed test_%d.\n", n+1);
		
		return SUCCESS;
	}
	else
	{
		printf("Test_%d failed: coefficient a = %lf, b = %lf, c = %lf\n", 
				n+1, to_comparison->a, to_comparison->b, to_comparison->c);
		printf("Received solutoins: x_1 = %lf, x_2 = %lf, number of roots is %d\n",
				to_calculate->x_1, to_calculate->x_2, to_calculate->num_x);
		printf("Expected solutions: x_1 = %lf, x_2 = %lf, number of roots is %d\n", 
				to_comparison->x_1, to_comparison->x_2, to_comparison->num_x);
				
		return FAILED;
	}
}
