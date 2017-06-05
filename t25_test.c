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
	do{
		printf("# Digite o nome da disciplina: \n");
		fgets(a.disc, STRTAM, stdin);
		strtok(a.disc, "\n");
	}while(strlen(a.disc)<2);
	
	//le CóDIGO da disciplina
	
	do{
		printf("# Digite o codigo da disciplina: \n");
		fgets(a.codDISC, STRTAM, stdin);
		strtok(a.codDISC, "\n");
	}while(strlen(a.codDISC)<2);


	//le o nome do aluno
	
	do{
		printf("# Digite o nome Aluno: \n");
		fgets(a.nomeAL, STRTAM, stdin);
		strtok(a.nomeAL, "\n");
	}while(strlen(a.nomeAL)<2);

	//le o COD do aluno
	
	do{
		printf("# Digite o codigo do aluno: \n");
		fgets(a.codAL, STRTAM, stdin);
		strtok(a.codAL, "\n");
	}while(strlen(a.codAL)<2);


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
	

	printf("\n______________________________TESTE DA MATRIZ_______________________________________\n");
	for(i=0;i<3;i++){
		for(j=0;j<MAXTRAB;j++){
			printf("%.5lf	",a.notasTRAB[i][j]);
		}
		printf("\n");
	}
	printf("\n______________________________FIM DO TESTE DA MATRIZ_______________________________________\n\n\n");


	return(a);
	
} 
/*
struct FUNCIONARIO leitura ()
{
struct FUNCIONARIO f;
printf("Digite o nome do funcionario com ate %i cars\n", STRMAX);
fgets(f.nomef, STRMAX, stdin);
printf("Quantos anos tem o funcionario?");
scanf("%d", &f.idadef);
printf("Qual o seu salario? ");
scanf("%lf", &f.salariof);
return(f)
}
main ()
{
struct FUNCIONARIO f1;
f1 = leitura();
printf("%s %d %lf\n", f.nomef, f.idadef, f.salariof);
}
*/

int main(){
	struct ALUNOS aa[2];
	int i, j, aux1=0, aux2=1, r;
	
	for(i=0;i<2;i++){
		aa[i] = leitura();	
	}/*
	printf("Disciplina: %s %s\n", aa[0].codDISC, aa[r].disc);
	for(r=0;r<2;r++){
		aux1=0;
		aux2=1;
		printf("\nRELATORIO %i\n\n",r);		
		printf("Aluno     : %s %s\n\n", aa[r].codAL, aa[r].nomeAL);	
		printf("%i trabalhos\n", aa[r].quantTRAB);
		j=1;
		for(i=0;i<aa[r].quantTRAB;i++){
			printf("	TRAB %i: %.1lf (peso %.1lf) \n",j, aa[r].notasTRAB[aux1][i], aa[r].notasTRAB[aux2][i]);
			j++;		
		}
		printf("Total pontos dos Trabalhos: %.1lf\n", aa[r].somaTRAB/10);
		printf("Prova %.1lf (peso %.1lf)\n", aa[r].notaPROVA, aa[r].pesoPROVA);
		printf("A nota final eh %.1lf\n", aa[r].soma);		
		printf("\n\n");
	}*/
	
	
}
