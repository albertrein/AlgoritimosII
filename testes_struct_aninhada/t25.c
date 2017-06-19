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

struct DISCIPLINA {
	char disc[STRTAM];
	char codDISC[STRTAM]; 
	struct ALUNOS stud[MAXALUNOS];
};

void leitura(struct DISCIPLINA *a){
	int i, j, cont=1, nAlunos, q;
	double x = 0, soma=0, somaPesos=0;

	
	//le disciplina	
	do{
		printf("# Digite o nome da disciplina: \n");
		fgets(a->disc, STRTAM, stdin);
		strtok(a->disc, "\n");
	}while(strlen(a->disc)<1);
	
	//le CóDIGO da disciplina	
	do{
		printf("# Digite o codigo da disciplina: \n");
		fgets(a->codDISC, STRTAM, stdin);
		strtok(a->codDISC, "\n");
	}while(strlen(a->codDISC)<1);

	do{
		printf("# Digite quantos alunos voce quer (%i MAXIMO)\n",MAXALUNOS);
		scanf("%i",&nAlunos);
	}while(nAlunos>MAXALUNOS);
	
	for(q=0;q<nAlunos;q++){

		//le o nome do aluno	
		do{
			printf("# Digite o nome Aluno: \n");
			fgets(a->stud[q].nomeAL, STRTAM, stdin);
			strtok(a->stud[q].nomeAL, "\n");
		}while(strlen(a->stud[q].nomeAL)<1);

		//le o COD do aluno	
		do{
			printf("# Digite o codigo do aluno: \n");
			fgets(a->stud[q].codAL, STRTAM, stdin);
			strtok(a->stud[q].codAL, "\n");
		}while(strlen(a->stud[q].codAL)<2);


		//le o numero de trabalhos (com máximo 10 notas)
		for(i=0;i!=1;){
			printf("Quantos Trabalhos (MAXIMO %i)\n",MAX);
			scanf("%i",&a->stud[q].quantTRAB);
			if (a->stud[q].quantTRAB <= MAX && a->stud[q].quantTRAB > 0){
				i=1;
			}
		}
		a->stud[q].soma = 0;
		//le os trabalhos e pesos
		for(i=0;i<a->stud[q].quantTRAB;i++){
			j=0;
			printf("# Nota do Trabalho %i: \n",cont);
			scanf("%lf",&a->stud[q].notaTRAB[j][i]);
			x = a->stud[q].notaTRAB[j][i];
			j++;
			printf("# Peso do Trabalho %i: \n",cont); 
			scanf("%lf",&a->stud[q].notaTRAB[j][i]);
			somaPesos += a->stud[q].notaTRAB[j][i];

			if(somaPesos > 8){
				a->stud[q].notaTRAB[j][i] = 0;
				somaPesos -= a->stud[q].notaTRAB[j][i];
			}

			x = (x * a->stud[q].notaTRAB[j][i])/10;
			j++;
			a->stud[q].notaTRAB[j][i] = x;
			a->stud[q].soma += x;
			cont++;//conta numero do trab
		}
		a->stud[q].somaTRAB = a->stud[q].soma;
		//le a nota da prova
		printf("# Digite nota da prova: \n");
		scanf("%lf",&a->stud[q].notaPROVA);
		a->stud[q].pesoPROVA = MAX - somaPesos;
		a->stud[q].soma = a->stud[q].soma + ((a->stud[q].notaPROVA*a->stud[q].pesoPROVA)/10);
		}	
} 

int main(){
	struct ALUNOS aa[2];
	int i, j, aux1=0, aux2=1, r;
	
	for(i=0;i<2;i++){
		leitura(&aa[i]);	
	}
	printf("Disciplina: %s %s\n", aa[0].codDISC, aa[r].disc);
	for(r=0;r<2;r++){
		aux1=0;
		aux2=1;
		printf("\nRELATORIO %i\n\n",r);		
		printf("Aluno     : %s %s\n\n", aa[r].codAL, aa[r].nomeAL);	
		printf("%i trabalhos\n", aa[r].quantTRAB);
		j=1;
		for(i=0;i<aa[r].quantTRAB;i++){
			printf("	TRAB %i: %.1lf (peso %.1lf) \n",j, aa[r].notaTRAB[aux1][i], aa[r].notaTRAB[aux2][i]);
			j++;		
		}
		printf("Total pontos dos Trabalhos: %.1lf\n", aa[r].somaTRAB);
		printf("Prova %.1lf (peso %.1lf)\n", aa[r].notaPROVA, aa[r].pesoPROVA);
		printf("A nota final eh %.1lf\n", aa[r].soma);		
		printf("\n\n");
	}
	
	
}