#include <stdio.h>
#include <ctype.h>
#include <math.h>
double vvod(void);
int quad_eq (double a, double b, double c);
double mass[2];
int main (void)
{	
	printf("The quadratic equation has the form:"
		" a*(x^2) + b*x + c = 0\n");
	printf("Enter a: ");
	double a = vvod();
	printf("Enter b: ");
	double b = vvod();
	printf("Enter c: ");
	double c = vvod();
	printf("The equation is: "
		"%.2lf*x^2 + %.2lf*x + %.2lf = 0\n", a,b,c);
	
	if (quad_eq(a,b,c))
		if(mass[0] == mass[1])
			printf("Solution: %lf.\n", mass[1]);
		else
			printf("Solutions: %lf, %lf.\n", mass[0], mass[1]);
}
int quad_eq (double a, double b, double c)
{
	extern double mass[2];
	if (a == 0 && b == 0)
	{
		if (c == 0)
		{
			printf("x is any real number.\n");
			return 0;
		}
		else
		{
			printf("The equation has no solutions.\n");
			return 0;
		}
	}
	
	if (a == 0 && b != 0 && c != 0)
	{
		mass[0] = mass[1] = (-c)/b;	
		return 1;	
	}
		
	
	if (a != 0)
	{
		double d = b*b - 4*a*c;
		
		if (d < 0)
			printf("The equation has no solutions.\n");	
		else if (d>0)
		{
			mass[0] = (-b + sqrt(d)) / (2*a);
			mass[1] = (-b - sqrt(d)) / (2*a);
			return 1;
		}
		else
		{
			mass[0] = mass[1] = (-b)/(2*a);
			return 1;
		}
	}
	
	return 0;
}
double vvod (void)
{
	double a;
	while (scanf("%lf", &a) != 1)
	{
		printf("Enter a number again please.\n");
		while (getchar() != '\n')
			continue;
	}
	if (isdigit(a)) // если a - число, то
		return a;
}
