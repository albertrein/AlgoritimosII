#include <stdio.h>
#include <string.h>
#define STRTAM 40
#define MAXTRAB 10

struct ALUNOS {
	char disc[STRTAM];
	char codDISC[STRTAM];
	char nomeAL[STRTAM];
	char codAL[STRTAM];
	int quantTRAB;
	double somaTRAB;
	double notasTRAB[3][MAXTRAB];
	double notaPROVA;
	double pesoPROVA;
	double soma;

};

struct ALUNOS leitura(){
	struct ALUNOS a;
	int i, j, cont=1;
	double x = 0, soma=0, somaPesos=0;

	
	//le disciplina
	printf("# Digite o nome da disciplina: \n");
	fgets(a.disc, STRTAM, stdin);
	strtok(a.disc, "\n");
	
	//le CóDIGO da disciplina
	printf("# Digite o codigo da disciplina: \n");
	fgets(a.codDISC, STRTAM, stdin);
	strtok(a.codDISC, "\n");

	//le o nome do aluno
	printf("# Digite o nome Aluno: \n");
	fgets(a.nomeAL, STRTAM, stdin);
	strtok(a.nomeAL, "\n");

	//le o COD do aluno
	printf("# Digite o codigo do aluno: \n");
	fgets(a.codAL, STRTAM, stdin);
	strtok(a.codAL, "\n");

	//le o numero de trabalhos (com máximo 10 notas)
	for(i=0;i!=1;){
		printf("Quantos Trabalhos (%i MAXIMO)\n",MAXTRAB);
		scanf("%i",&a.quantTRAB);
		if (a.quantTRAB <= MAXTRAB && a.quantTRAB > 0){i=1;}
	}
	//le os trabalhos e pesos
	for(i=0;i<a.quantTRAB;i++){
		j=0;
		printf("# Nota do Trabalho %i: \n",cont);
		scanf("%lf",&a.notasTRAB[j][i]);
		x = a.notasTRAB[j][i];
		printf("# Peso do Trabalho %i: \n",cont);
		j++; 
		scanf("%lf",&a.notasTRAB[j][i]);
		somaPesos += a.notasTRAB[j][i];
		if(somaPesos > 8){
			a.notasTRAB[j][i] = 0.0;
		}
		x *= a.notasTRAB[j][i];
		j++;
		a.notasTRAB[j][i] = x;
		a.soma += x;
		cont++;
	}
	a.somaTRAB = a.soma;
	//le a nota da prova
	printf("# Digite nota da prova: \n");
	scanf("%lf",&a.notaPROVA);
	a.pesoPROVA = MAXTRAB - somaPesos;
	a.soma = a.soma + (a.notaPROVA*a.pesoPROVA);
	a.soma /= 10;
	
	return(a);
	
} 

int main(){
	struct ALUNOS aa;
	int i, j, aux1=0, aux2=1;
	aa = leitura();
	
	printf("\nRELATORIO DOS DADOS DIGITADOS\n\n");
	printf("Disciplina: %s %s\n", aa.codDISC, aa.disc);
	printf("Aluno     : %s %s\n\n",aa.codAL, aa.nomeAL);	
	printf("%i trabalhos\n",aa.quantTRAB);
	j=1;
	for(i=0;i<aa.quantTRAB;i++){
		printf("	TRAB %i: %.1lf (peso %.1lf) \n",j, aa.notasTRAB[aux1][i], aa.notasTRAB[aux2][i]);
		j++;		
	}
	printf("Total pontos dos Trabalhos: %.1lf\n",aa.somaTRAB/10);
	printf("Prova %.1lf (peso %.1lf)\n",aa.notaPROVA,aa.pesoPROVA);
	printf("A nota final eh %.1lf\n",aa.soma);
}
