/*
*	T22 _ Algoritimos II
*	Integrantes: Francis Luis // Guilherme A. Reinheimer // Luis Gustavo Moretto
* 	Data: 19 de Maio, 2017
*/
#include <stdio.h>
#define TAM 10

int itemA (int x[],int y[], int xy[][TAM], int tam){
	int i, j;
	for(i=0;i<tam;i++){
		x[i] = 0;
		y[i] = 0;
		for(j=0;j<tam;j++){
			xy[i][j] = 0;
		}	
	}
}

double itemB (double z[], double p[], double zp[][TAM], int tam){
	int i, j;
	for(i=0;i<tam;i++){
		z[i] = 0;
		p[i] = 0;
		for(j=0;j<tam;j++){
			zp[i][j] = 0;
		}	
	}
}

int itemC (int x[], int tam){
	int i;
	printf("Digite alguns valores inteiros... \n");
	for(i=0;i<tam;i++){
		printf(">>> ");
		scanf("%d",&x[i]);
	}
}

double itemD (double z[], int tam){
	int i;
	printf("Digite alguns valores com ponto flutuante... \n");
	for (int i = 0; i < tam; i++){
		printf(">>> ");
		scanf("%lf",&z[i]);
	}
}

int itemE (int x[], int y[], int xy[][TAM], int tam){
	int i, u, maior, maiorS = 0;
	for(i=0;i<tam;i++){
		maior = x[i];
		if(y[i] > maior){
			maior = y[i];
		}
		maiorS += maior;
		for(u=0;u<tam;u++){
			xy[i][u] = (maior * u);
		}
	}
	return (maiorS);	
}

double itemF (double z[], double p[], double zp[][TAM], int tam){
	int i, u;
	double maior, media = 0, mediaF;
	for(i=0;i<tam;i++){
		maior = z[i];
		if(p[i] >= maior){
			maior = p[i];
		}
		for(u=0;u<tam;u++){
			if(u == 0){
				zp[i][u] = (maior * u);
			}else{
				zp[i][u] = (maior / u);
			}				
		}
	}
	for(i=0;i<tam;i++){
		for(u=0;u<tam;u++){
			if(i == u){
				media += zp[i][u];
			}
		}
	}
	mediaF = media / tam;
	return (mediaF);
}


main(){

	int x[TAM], y[TAM], xy[TAM][TAM];
	double z[TAM], p[TAM], zp[TAM][TAM], mediaDoub;
	int i, j, maiorInt;

	itemA(x, y, xy, TAM);
	itemB(z, p, zp, TAM);
	itemC(x, TAM);
	itemC(y, TAM);
	itemD(z, TAM);
	itemD(p, TAM);

	maiorInt = itemE(x, y, xy, TAM);
	mediaDoub = itemF(z, p, zp, TAM);

	printf("O Maior Inteiro = %i\n",maiorInt);
	printf("A Media Ponto Flutuante = %lf\n",mediaDoub); 
}
