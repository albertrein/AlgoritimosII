/*	
*	ULBRA Gravataí
*	Disciplina: T12 de algoritimos II
*	Autores: Guilherme R. | Francis Luis | Gustavo Moretto
*	Descrição do algoritimo: 
		Faça um programa que leia um determinado número de frases. No início do
		programa o usuário deverá fornecer quantas frases irá digitar (de 1 a N).
		Cada frase pode ter até 10000 cars.
		Use a função strlen para obter o tamanho da atual frase.
		Ao final da digitação das frases, informe qual foi a frase menor e qual
		foi a maior (quantidade de caracteres apenas).
		Apenas a função strlen da string.h pode ser usada.
*/
#include <stdio.h>
#include <string.h>fgdf

#define TAM 10000

main(){
	char vet[TAM];
	int qtd, val, mai, men, i=0;
	
	printf("Digite o Numero de Frases: >>>");
	scanf("%i",&qtd);
	mai=0;
	fgets(vet,TAM,stdin);	
	
	while(i<qtd){	
		printf("\nDigite Uma Frase: \n");
		fgets(vet,TAM,stdin);
		val = strlen(vet)-1;
		
		if(val >= mai){ //ACHA O MAIOR
			mai=val;
		}
		
		if(i==0){ // ACHA O MENOR
			men = val;
		}		
		if(val < men && val > 2){ // Maior que 2 para que nao pegue caracteres menores que 3 que nao sao aceitaveis
			men = val;
		}
		
		if(val > 2){ // Limite de CARACTERES ACEITAVEIS
			printf("A Frase tem %d cars.",val);	
			printf("\n\n");		
			i++;
		}			
	}
	printf("Voce digitou com sucesso %i frases.\n",qtd);
	printf("A menor tinha %i e a maior tinha %i\n",men,mai);	
}
