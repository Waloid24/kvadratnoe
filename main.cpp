#include "shared_file.h"
#include <stdio.h>
#include <assert.h>
#include "interface.h"
#include "user_interaction.h"
#include "unit_test.h"

int main (void)
{	
	UnitTest();
	
	struct coef_and_sol eq = {};  
	
	while (menu()) 
	{
		enter_coefficients_for_eq(&eq);  

		output_solutions_this_equation(&eq);		
	}		
	
	return 0;
}