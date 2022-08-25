#ifndef UNIT_TEST_H
#define UNIT_TEST_H

enum output
	{
		FAILED = 0,
		SUCCESS = 1
	};
	
const int NUMBER_OF_TESTS = 2;

int UnitTest ();
void duplicate_coefficients (struct coef_and_sol * , struct coef_and_sol * );
int isFailed (struct coef_and_sol *, struct coef_and_sol *, int );

#endif
