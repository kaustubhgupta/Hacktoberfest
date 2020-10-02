#include <stdio.h>
#include <math.h>
#define n  3
#define bn 3

int main()
{
	float A[n][n] = { 10, 2, 3, 1, 5, 1, 2, 3, 10 };
	float b[bn] = { 7, -8, 6 };
	float Xk[bn] = { 1, 1, 1 };
	float Xk1[bn] = { 0, 0, 0 };
	float solucao[bn] = { 0, 0, 0 };
	float maiorXk1 = 0;
	float maiorXk = 0;
	float maior = 0, maiorD = 0;
	float epslon = 0.00001;
	int i, j, a = 0;
	float C[n][n], g[bn];
	float dif = 0;

	//imrime A
	printf("\nMATRIZ A = b\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%fx%d		", A[i][j], j+1);
		}
		printf(" = %f\n", b[i]);
	}

	//gera c e g
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j)
				C[i][j] = 0;
			else
			{
				C[i][j] = A[i][j] / A[i][i] * (-1);
				//Xk1[i] += C[i][j];
			}
		}
		g[i] = b[i] / A[i][i];
		//Xk1[i] += g[i];
	}
	
	//imrpme c e g
	printf("\nMATRIZ C = g\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%fx%d		", C[i][j],j+1);
		}
		printf(" = %f\n", g[i]);
	}
	printf("\n");
	
	//calcular xk segundo video
	/*
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j)
				Xk[i] = b[i] / A[i][j];
		}
		//printf(" ::::::::::::::::::::::::::   XK %f\n", Xk[i]);
	}
	*/
	
	//faz processo de X^(k+1) = C * x^(k) + g
	do {
		//multiplicação Xk+1 = C*xk + g
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				Xk1[i] += C[i][j] * Xk[j];
				//printf("Xk[%d] %f\n", i, Xk1[i]);
			}
			Xk1[i] += g[i];
			printf("Xk[%d] %f\n", i, Xk1[i]);
		}

		//calcula diferença modulo
		for (i = 0; i < n; i++) 
		{
			maiorXk1 = sqrt(pow(Xk1[i], 2));
			maiorXk = sqrt(pow(Xk[i], 2));
			//parte video
			if (maiorXk1 > maiorD)
				maiorD = maiorXk1;

			if ((maiorXk1 - maiorXk) > maior)
				maior = maiorXk1 - maiorXk;
			//dif = maior / maiorD;
			//ou como professor passou usar o de baixo
			dif = maior;
			printf("[%d]  dif %f		maior: %f		maiorXk: %f		Xk1: %f\n", i, dif, maior, maiorXk, Xk1[i]);

		}
		printf("\n");

		//transfere valores para xk[] e pssa o valor 0 para xk1[]
		for (i = 0; i < n && dif > epslon; i++) {
			Xk[i] = Xk1[i];
			Xk1[i] = 0;
			//printf("XK1: %f XK: %f", Xk1[i], Xk[i]);
		}
		maiorD = 0;
		maior = 0;
	} while (dif > epslon);
	//printf("AAAAAAAAAAA: %f %f\n", Xk1[0], Xk1[1]);

	////impime C*Xk + g e Xk+1
	/*
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%fx%d ", C[i][j], j + 1);

		printf("+ %f \n", g[i]);
		printf("IMPR::::: Xk+%d: %f\n", i + 1, Xk1[i]);
	}
	*/

	//calcula substituindo no sistema
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			solucao[i] += A[i][j] * Xk1[j];
			//printf("solucao[%d] %f,		%f\n", i, solucao[i], Xk1[j]);
		}
	}
	
	//imprime solucao
	for (i = 0; i < n; i++) 
	{
		printf("solucao[%d] %f\n", i, solucao[i]);
	}
	
	return 0;
}
