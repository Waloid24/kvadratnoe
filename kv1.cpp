#include <stdio.h>
#include <ctype.h>
#include <math.h>
#ifdef NAN  //я посмотрел на каком-то сайте, сказали, чтобы попробовал добавить эти 4 строчки
#endif
#ifdef INFINITY
#endif 

double input(void);
void quad_eq (double a, double b, double c, double *);
int main (void)
{	
	printf("The quadratic equation has the form:"
		" a*(x^2) + b*x + c = 0\n");
	printf("Enter a: ");
	double a = input();
	printf("Enter b: ");
	double b = input();
	printf("Enter c: ");
	double c = input();
	printf("The equation is: "
		"%.2lf*x^2 + %.2lf*x + %.2lf = 0\n", a,b,c);
		
	double *ptd = (double *) malloc(2 * sizeof(double));
	
	quad_eq(a,b,c,ptd);
	
	if(ptd[0] == ptd[1])
		printf("Solution: %lf", ptd[1]);
	else
		printf("Solutions: %lf, %lf", ptd[0], ptd[1]);
		
	return 0;
}
void quad_eq (double a, double b, double c, double * pt)
{
	if (a == 0 && b == 0)
	{
		if (c == 0)
		{
			printf("x is any real number.\n");
			pt[0] = pt[1] = INFINITY;
			return ;
		}
		else
		{
			printf("The equation has no solutions.\n");
			pt[0] = pt[1] = NAN;
			return ;
		}
	}
	
	if (a == 0 && b != 0 && c != 0)
	{
		pt[0] = pt[1] = (-c)/b;
		return ;
	}
		
	
	if (a != 0)
	{
		double d = b*b - 4*a*c;
		
		if (d < 0)
		{
			printf("The equation has no solutions.\n");
			pt[0] = pt[1] = NAN;
			return ;
		}
		else if (d>0)
		{
			pt[0] = (-b - sqrt(d)) / (2*a);
			pt[1] = (-b + sqrt(d)) / (2*a);
			return ;
		}
		else
		{
			pt[0] = pt[1] = (-b)/(2*a);
			return ;
		}
	}
	return ;
}
double input (void)
{
	double a;
	while (scanf("%lf", &a) != 1)
	{
		printf("Enter a number again please.\n");
		while (getchar() != '\n')
			continue;
	}
	return a;
}
