#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double f(double x){
	double valor;
	valor=cos(x)-x;
	return valor;
}

double dfdx(double x){
	double valor;
	valor=-sin(x)-1.0;
	return valor;
}
int main(void){

	/* Vamos a encontrar la raiz de la ecuación
	 f(x)=cos(x)-x, usando el método de Newton-Raphson*/

	double tol; //tolerancia
	int Nmax; //Numero maximo de iteraciones
	double p; //p_n
	double p_prev; //p_(n-1)
	double error;
	int iteration;

	p_prev=5.0;
	error=1.0;
	iteration=0;
	Nmax=1000;

	while(error>tol){
		p=p_prev - f(p_prev)/dfdx(p_prev);
		error= fabs(p-p_prev);
		p_prev=p;
		iteration=iteration+1;
		if(iteration>Nmax){
			printf("EL metodo no converge despues de %d iteraciones",Nmax);
			break;
}
		printf("p=%.16f\t error= %.16f\t abs(f(p))=%.16f\n",p,error,fabs(f(p)));

}

	return 0;
}
