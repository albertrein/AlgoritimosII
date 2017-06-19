#include <stdio.h>
#include <string.h>
#define STRTAM 40
#define MAX 10
#define MAXALUNOS 20

struct ALUNOS {
	char disc[STRTAM];
	char codDISC[STRTAM];
	char nomeAL[STRTAM];
	char codAL[STRTAM];
	int quantTRAB;	
	double notaTRAB[3][MAX];

	double notaPROVA;
	double pesoPROVA;
	double somaTRAB;
	double soma;

};

struct ALUNOS leitura(int max, int strtam){
	struct ALUNOS a;
	int i, j, cont=1;
	double x = 0, soma=0, somaPesos=0;	

	//le o nome do aluno	
	do{
		printf("# Digite o nome Aluno: \n");
		fgets(a.nomeAL, strtam, stdin);
		strtok(a.nomeAL, "\n");
	}while(strlen(a.nomeAL)<2);

	//le o COD do aluno	
	do{
		printf("# Digite o codigo do aluno: \n");
		fgets(a.codAL, strtam, stdin);
		strtok(a.codAL, "\n");
	}while(strlen(a.codAL)<2);


	//le o numero de trabalhos (com máximo 10 notas)
	for(i=0;i!=1;){
		printf("Quantos Trabalhos (MAXIMO %i)\n",max);
		scanf("%i",&a.quantTRAB);
		if (a.quantTRAB <= max && a.quantTRAB > 0){
			i=1;
		}
	}
	a.soma = 0;
	//le os trabalhos e pesos
	for(i=0;i<a.quantTRAB;i++){
		j=0;
		printf("# Nota do Trabalho %i: \n",cont);
		scanf("%lf",&a.notaTRAB[j][i]);
		x = a.notaTRAB[j][i];
		j++;
		printf("# Peso do Trabalho %i: \n",cont); 
		scanf("%lf",&a.notaTRAB[j][i]);
		somaPesos += a.notaTRAB[j][i];

		if(somaPesos > 8){
			a.notaTRAB[j][i] = 0;
			somaPesos -= a.notaTRAB[j][i];
		}

		x = (x * a.notaTRAB[j][i])/10;
		j++;
		a.notaTRAB[j][i] = x;
		a.soma += x;
		cont++;//conta numero do trab
	}
	a.somaTRAB = a.soma;/// 			???
	//le a nota da prova
	printf("# Digite nota da prova: \n");
	scanf("%lf",&a.notaPROVA);
	a.pesoPROVA = max - somaPesos;
	a.soma = a.soma + ((a.notaPROVA*a.pesoPROVA)/10);
	return(a);
	
} 

int main(){
	struct ALUNOS aa[MAXALUNOS];
	int i, j, aux1=0, aux2=1, r, nAlunos;
	char disc[STRTAM], codDISC[STRTAM];

	//le disciplina	
	do{
		printf("# Digite o nome da disciplina: \n");
		fgets(disc, STRTAM, stdin);
		strtok(disc, "\n");
	}while(strlen(disc)<1);
	
	//le CóDIGO da disciplina	
	do{
		printf("# Digite o codigo da disciplina: \n");
		fgets(codDISC, STRTAM, stdin);
		strtok(codDISC, "\n");
	}while(strlen(codDISC)<1);

	do{
		printf("# Digite quantos alunos voce quer (%i MAXIMO)\n",MAXALUNOS);
		scanf("%i",&nAlunos);
	}while(nAlunos>MAXALUNOS);
	
	for(i=0;i<nAlunos;i++){
		aa[i] = leitura(MAX, STRTAM);
		printf("# FIM DO CADASTRO DO ALUNO %i\n\n",i);	
	}
	printf("# FIM DO CADASTRO DE TODOS OS ALUNOS\n\n");
	printf("Disciplina: %s %s\n",codDISC, disc);
	for(r=0;r<nAlunos;r++){
		aux1=0;
		aux2=1;	
		printf("Aluno     : %s %s\n\n", aa[r].codAL, aa[r].nomeAL);	
		printf("%i trabalhos\n", aa[r].quantTRAB);
		j=1;
		for(i=0;i<aa[r].quantTRAB;i++){
			printf("	TRAB %i: %.1lf (peso %.1lf) \n",j, aa[r].notaTRAB[aux1][i], aa[r].notaTRAB[aux2][i]);
			j++;		
		}
		printf("Total pontos dos Trabalhos: %.1lf\n", aa[r].somaTRAB);
		printf("Prova %.1lf (peso %.1lf)\n", aa[r].notaPROVA, aa[r].pesoPROVA);
		printf("Nota final = %.1lf\n", aa[r].soma);		
		printf("\n\n");
	}	
}