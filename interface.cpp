#include "interface.h"
#include "utilities.h"

double check_coefficient_for_corret ()
{
	double coef = 0;
	
	while (scanf("%lf", &coef) != 1)
	{
		printf("Enter a number again please.\n");
		while (getchar() != '\n')
			continue;
	}
	
	return coef;
}

double menu (void)
{
	printf("Our opportunities:\n");
	printf("a) Input \"1\" for new equations; b) Input \"0\" for exit;\n");
	
	double coef = check_coefficient_for_corret();
	
	return coef;
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
	switch (eq->num_x) 
		{
			case 0 : { printf("The quadratic equation has no solutions.\n");  break; }
			case 1 : { printf("Solution: %.2lf.\n", eq->x_1); 				  break; }
			case 2 : { printf("Solutions: %.2lf, %.2lf\n", eq->x_1, eq->x_2); break; }
			case -1: { printf("x is any real number.\n");                     break; }
			default: {
				printf("()_().\n");
			}
		};
		
	return;
}