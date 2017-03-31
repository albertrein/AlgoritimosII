/*
*	Título: T15 de Algoritimos II
*	Data: 2017/1
*	Integrantes: Francis Luis / Guilherme R. / Luis Gustavo M.
*	Definição: 
*		a) Criar um vetor de inteiros de TAM elementos. TAM deve ser uma constante
*		b) Criar um vetor de ponto flutante de mesmo tamanho.
*		c) Usar uma função que peça para o usuário digitar os elementos do vetor
*		de inteiros. A função deverá receber este vetor como parâmetro e seu
*		tamanho.
*		d) Outra função que receba os dois vetores como parâmetro e calcule o 
*		vetor de ponto flutante da seguinte forma: cada elemento do vetor
*		é a média de todos os elementos do vetor de inteiros até aquele índice.
*		e) Faça uma função que imprima o vetor de inteiros e o de ponto flutante
*		(um por linha).
*		f) faça uma função que retorne (NÃO É PARA IMPRIMIR) o maior elemento do
*		vetor de inteiros. O main irá imprimir este valor.
*/

#include <stdio.h>
#define TAM 4

int etapaC(int vet[],int taman){ // Etapa C
	int i;
	for(i=0;i<taman;i++){
		printf("Digite um valor: ");
		scanf("%i",&vet[i]);
	}
}
int etapaD(int vet[], float fvet[],int taman){ //Etapa D
	int i, soma=0,y=0;
	for(i=1;i<=taman;i++){
		soma+=vet[y];
		fvet[y] = (float) soma/i;
		y++;
	}
}
int etapaE(int vet[], float fvet[],int taman){ //Etapa E
	int i;
	for(i=0;i<taman;i++){
		printf("* vet[%i] = %i\n",i,vet[i]);
		printf("* fvet[%i] = %.2f\n",i,fvet[i]);
	}
}
int etapaF(int vet[],int taman){ //Etapa F
	int x, maior=0;
	for(x=0;x<taman;x++){
		if(vet[x] > maior){
			maior = vet[x];
		}
	}
	return (maior);
}
main(){
	int vet[TAM], maior;
	float fvet[TAM];
	int i;		
	etapaC(vet, TAM);
	etapaD(vet,fvet, TAM);
	etapaE(vet,fvet, TAM);
	maior = etapaF(vet, TAM);	
	printf("\nO Maior vetor inteiro eh: %i\n",maior);
	
}
