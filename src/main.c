#include "procedure.h"
#include <stdio.h>
#include <math.h>

int main ()
{
	int i;
	float x,D,a,b,c;
	printf("a*(x*x)+b*x+c=0\n");
	printf ("a = ");
	scanf("%f",&a);	
	printf("b = ");
	scanf("%f",&b);
	printf("c = ");
	scanf("%f",&c);
	if ( (a == 0) && (b == 0)) {
		printf("Net kornei");
		return 0;
	}
	if (a == 0) {
		x = c * -1 / b;
		printf ("%.2f",x);
		return 0;
	}
	D = Discriminant(a,b,c);
	i = Proverka(D);
	switch (i) {
		case 0:
			x = Znachenie (D, a, b, c, 1);
			printf ("%.2f",x);
			break;
		case 1:
			printf("Net kornei");
			break;
		case 2:
			x = Znachenie (D, a, b, c, 1);
			printf ("%.2f\n",x);
			x = Znachenie (D, a, b, c, -1);
			printf ("%.2f",x);
			break;
	}
	return 0;
}
