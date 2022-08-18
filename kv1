#include <stdio.h>
#include <ctype.h>
#include <math.h>
double vvod(void);
int main (void)
{
	double a, b, c, d, x_1, x_2;
	
	printf("Kvadratnoe yrvnenie imeet vid:"
		" a*(x^2) + b*x + c = 0\n");
	printf("Enter a: ");
	a = vvod();
	printf("Enter b: ");
	b = vvod();
	printf("Enter c: ");
	c = vvod();
	printf("The equation is: "
		"%.2lf*x^2 + %.2lf*x + %.2lf = 0\n", a,b,c);
	
	if (a == 0 && b == 0)
	{
		if (c == 0)
			printf("x is any real number.\n");
		else
			printf("The equation has no solutions.\n");
	}
	
	if (a == 0 && b != 0 && c != 0)
		printf("The quadratic equation has 1 solution: x = %.2lf.\n", (-c)/b);
	
	if (a != 0)
	{
		d = b*b - 4*a*c;
		
		if (d < 0)
			printf("The equation has no solutions.\n");	
		else if (d = 0)
			printf("The quadratic equation has 1 solution: x = %.2lf.\n", (-b)/(2*a));	
		else
		{
			printf("Discriminant D = %.2lf.\n", d);
			x_1 = (-b + sqrt(d)) / (2*a);
			x_2 = (-b - sqrt(d)) / (2*a);
			printf("The quadratic equation has 2 solutions: x_1 = %lf, "
				"x_2 = %lf.\n", x_1, x_2);
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
	if (isdigit(a))
		return a;
}
