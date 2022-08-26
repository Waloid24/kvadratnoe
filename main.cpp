//==================================================================================
//!
//! @brief Программа для решения квадратного уравнения
//!
//! @author Казачков Андрей (https://github.com/Waloid24/kvadratnoe)
//! @file main.cpp
//! @date 26.08.2022
//!
//! @copyright Copyright (c) 2022
//!
//!=================================================================================

#include "quadratic_eq_solver.h"
#include "interface.h"
#include "unit_test.h"
#include "utilities.h"

int main (void)
{
	UnitTest();
	
	struct coef_and_sol eq = {};  
	
	while (menu()) 
	{
		enter_coefficients_for_eq(&eq); 
		 
		eq.num_x = solve_quad_eq(&eq);
		
		output_solutions_this_equation(&eq);		
	}		
	
	return 0;
}