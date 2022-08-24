#include "shared_file.h"
#include <stdio.h>
#include <assert.h>
#include "interface.h"
#include "user_interaction.h"

double check_coefficient_for_corret ()
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
