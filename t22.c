#include <stdio.h>
#define TAM 3

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
		z[i] = 0.1;
		p[i] = 0.2;
		for(j=0;j<tam;j++){
			zp[i][j] = 0.3;
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
	int i, u, maior;
	for(i=0;i<tam;i++){
		maior = x[i];
		if(y[i] > maior){
			maior = y[i];
		}
		for(u=0;u<tam;u++){
			xy[i][u] = (maior * u) + 1;
		}
	}	
}

double itemF (double z[], double p[], double zp[][TAM], int tam){
	int i, u;
	double maior, media = 0, mediaF;
	for(i=0;i<tam;i++){
		maior = z[i];
		if(p[i] > maior){
			maior = p[i];
		}
		for(u=0;u<tam;u++){
			zp[i][u] = (maior / u);
			if(i == u){
				media += zp[i][u];
			}
		}
	}
	//mediaF = media / tam;
	printf("%lf\n",media);
	//printf("\n %lf / %d =  %lf \n",media, tam, mediaF);
}


main(){
	int x[TAM], y[TAM], xy[TAM][TAM];
	double z[TAM], p[TAM], zp[TAM][TAM];
	int i, j;

	//itemA(x, y, xy, TAM);
	/*for(i=0;i<TAM;i++){
		printf("x = %d || y = %d\n",x[i],y[i]);
		for(j=0;j<TAM;j++){
			printf("xy = %d\n",xy[i][j]);
		}	
	} */

	//itemB(z, p, zp, TAM);
	/*for(i=0;i<TAM;i++){
		printf("z = %.1lf || p = %.1lf\n",z[i], p[i]);
		for(j=0;j<TAM;j++){
			printf("zp = %.1lf\n",zp[i][j]);
		}	
	} */

//	itemC(x, TAM);
//	itemC(y, TAM);

	itemD(z, TAM);
	itemD(p, TAM);

	/*
	for (i = 0; i < TAM; i++){
		printf("y = %d 		|| 		x = %d\n",y[i], x[i]);
	}
	printf("\n\n");
	for (i = 0; i < TAM; i++){
		printf("z = %lf 		|| 		p = %lf\n",z[i], p[i]);
	} */
//	itemE(x, y, xy, TAM);

	itemF(z, p, zp, TAM);


 
}

/*
 dois vetores de inteiros
- dois vetores de doubles
- uma matriz de inteiros
- uma matriz de double

Todos de TAM tamanho, sendo TAM um define declarado como 10 (inicialmente).
As matrizes tem TAM linhas e TAM colunas.

Considere que o TAM pode mudar a qualquer momento, e que deve ser 
suficiente apenas alterar o define.


A) Faça uma função que receba um vetor de inteiros e inicialize todos
os seus elementos (coloque zero dentro). Invoque-a no main para inicializar
os três vetores de inteiros criados.

C) Faça uma função que receba um vetor de inteiros. A função deve imprimir
uma mensagem solicitando que o usuário digite cada um dos elementos. A função
deve ler estes elementos digitados e colocar no vetor. No main, invoque a
função para dois vetores criados.

E) Faça uma função que receba dois vetores de inteiros e a matriz de inteiros
A função deve colocar na matriz o maior elemento entre os dois vetores multiplicado
pelo indice da matriz mais um:

 m[0][0] = maior entre v1[0] e v2[0] * 1 (linha 1)
 m[1][4] = maior entre v1[4] e v2[4] * 2 (linha 2)

A função deve retornar a soma do N maiores elementos encontrado nos vetores.

F) Faça uma função idêntica ao item E, porém para o caso dos vetores de
doubles e dividindo pela linha.
A função deve retornar a media de todos os elementos da diagonal da matriz
*/
