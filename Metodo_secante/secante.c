#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x) {
	double value;
	value = cos(x) - x;
	return value;
}

int main(void) {
	
	// Encontrar raíz de ecuación f(x) = cos(x) - x, con Newton-Raphson	
		
	double Tol;
	int Nmax;
	double p;
	double p_prev1;
	double p_prev2;
	double error;
	int i;

	Nmax = 1000;
	p_prev1 = -3.0;
	p_prev2 = 5.0;
	error = 1.0;
	i = 0;

	while(error>Tol) {
		p = p_prev1 - (p_prev1 - p_prev2)*f(p_prev1)/(f(p_prev1) - f(p_prev2));
		error = fabs(p-p_prev1);
		p_prev2 = p_prev1;
		p_prev1 = p;
		i = i + 1;
		if(i>Nmax) {
			printf("El método no converge después de %d iteraciones",Nmax);
			break;
		}
		printf("p_n = %.8f\t error = %.8f\t abs(f(p))=%.8f\n",p,error,fabs(p));
	}

	printf("%f\n", cos(0.0));

	return 0;
}
