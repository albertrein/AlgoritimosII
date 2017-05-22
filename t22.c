#include <stdio.h>
#define TAM 5
#define MAX TAM * 2

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
int itemC (int vet[], int tam){
	int i;
	printf("Digite %d inteiros... \n",tam);
	for(i=0;i<tam;i++){
		scanf("%i",&vet[i]);
	}
}
double itemD (double z[], int tam){
	int i;
	printf("Digite %d ponto flutuante... \n",tam);
	for (i=0;i<tam;i++){
		scanf("%lf",&z[i]);
	}
}
int itemE (int x[], int y[], int xy[][TAM], int tam, int tamM){
	int i, u, maior, maiorS = 0, controle;
	int vet[tamM];

	//Carrega a Matrix
	for(i=0;i<tam;i++){
		controle = i + 1;
		for(u=0;u<tam;u++){
			maior = x[u];
			if(y[u] > maior){
				maior = y[u];
			}
			xy[i][u] = (maior * controle);			
		}
	}
	
	for(i=0;i<tam;i++){
		vet[i] = x[i];
	}
	u=0;	
	for(i=tam;i<tamM;i++){
		vet[i] = y[u];
		u++;
	}

	for(i=0;i<tamM;i++){
		printf("vet[%i] = %i \n",i,vet[i]);
	}

	int aux=0, soma=0;
 
	for(i=0; i<tamM; i++){ 
		for(u=0; u<tamM; u++){ 
      		if(vet[i] > vet[u]){
                aux = vet[i];
                vet[i] = vet[u];
                vet[u] = aux;
      		}
    	} 
  	} 
	
	for(i=0;i<tam;i++){
		soma += vet[i];	
	}

	//printf("\nSOMA EH %i \n",soma);


	/* Imprime matriz
	for(i=0;i<tam;i++){
		for(u=0;u<tam;u++){
			printf("%5d",xy[i][u]);
		}
		printf("\n");
	}
	*/	
	return (soma);	
}

double itemF (double z[], double p[], double zp[][TAM], int tam){
	int i, u, controle;
	double maior, media = 0, mediaF;
	for(i=0;i<tam;i++){
		controle = i + 1;
		for(u=0;u<tam;u++){
			maior = z[u];
			if(p[u] > maior){
				maior = p[u];
			}
			zp[i][u] = (maior / controle);							
		}
	}/*
	for(i=0;i<tam;i++){
		for(u=0;u<tam;u++){
			printf("%.1lf ",zp[i][u]);
		}
		printf("\n");
	}*/

	for(i=0;i<tam;i++){
		for(u=0;u<tam;u++){
			if(i == u){
				media += zp[i][u];
			}
		}
	}

	mediaF = media / tam;
	//printf("A media da diagonal da matriz de doubles eh %lf\n",mediaF);
	return (mediaF);
}


main(){

	int x[TAM], y[TAM], xy[TAM][TAM];
	double z[TAM], p[TAM], zp[TAM][TAM], mediaDoub;
	int i, u, maiorInt;

	itemA(x, y, xy, TAM);
	itemB(z, p, zp, TAM);
	itemC(x, TAM);
	itemC(y, TAM);
	
	itemD(z, TAM);
	itemD(p, TAM);

	maiorInt = itemE(x, y, xy, TAM, MAX);
	//itemE(x, y, xy, TAM, MAX);
	mediaDoub = itemF(z, p, zp, TAM);
	//itemF(z, p, zp, TAM);
	printf("A soma dos %i maiores eh: %i\n",TAM, maiorInt);
	printf("A media da diagonal da matriz de doubles eh %lf\n",mediaDoub); 
	printf("\n\n\n\n");
	printf("Para este exemplo a matriz de inteiros gerada ficou: \n");
	printf("A matriz de doubles ficou: \n");
	for(i=0;i<TAM;i++){
		for(u=0;u<TAM;u++){
			printf("%5d",xy[i][u]);
		}
		printf("\n");
	}

	printf("\nA matriz de doubles ficou: \n");
	for(i=0;i<TAM;i++){
		for(u=0;u<TAM;u++){
			printf("%.1lf ",zp[i][u]);
		}
		printf("\n");
	}
}
