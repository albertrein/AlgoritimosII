#include <stdio.h>
#include <string.h>
#define STRTAM 100
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

};

int main(){
	int i, j, cont=1;
	double x = 0, soma=0;

	struct ALUNOS a;
	a.pesoPROVA = 7.0;
	//le disciplina
	printf("# Digite o nome da disciplina: \n");
	fgets(a.disc, STRTAM, stdin);
	strtok(a.disc, "\n");
	//le COD da disciplina
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
		if (a.quantTRAB <= MAXTRAB){i=1;}
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
		x *= a.notasTRAB[j][i];
		j++;
		a.notasTRAB[j][i] = x;
		soma += x;
		cont++;
	}
	a.somaTRAB = soma;
	//le a nota da prova
	printf("# Digite nota da prova: \n");
	scanf("%lf",&a.notaPROVA);

	soma = soma + (a.notaPROVA*a.pesoPROVA);

	/// notastrab[continua][varia]

/*- Nome da disciplina (até STRTAM cars)
  - código da disciplina (não é inteiro, pois podem ter letras. Até STRTAM cars)
  - Nome do aluno (até STRTAM cars)
  - código do aluno (não é inteiro, pois podem ter letras. Até STRTAM cars)
  - Quantidade de trabalhos  (no máximo MAXTRAB)
  - matriz que suporte nota, peso e o valor final de cada trabalho 
    (matriz de 3 linhas com MAXTRAB colunas, mas considerar apenas as 
    colunas que tem trabalho (valor do qtdtrab)
  - Nota da prova (uma nota)
  - Peso da prova (não será digitado)
  - nota final do aluno (será calculado)*/

	//Imprimindo a matriz dos trabalhos
/*	for(i=0;i<3;i++){
		for(j=0;j<MAXTRAB;j++){
			printf("%lf  ",a.notasTRAB[i][j]);
		}
		printf("\n");
	}*/
	soma /= 10;

	printf("\nRELATORIO DOS DADOS DIGITADOS\n\n");
	printf("Disciplina: %s %s\n", a.codDISC, a.disc);
	printf("Aluno     : %s %s\n\n",a.codAL, a.nomeAL);
	
	printf("%i trabalhos\n",a.quantTRAB);
	/*for(i=0;i<a.quantTRAB;i++){
		j=0;
		printf("	TRAB ");
	}*/
	printf("Total pontos dos Trabalhos: %.1lf\n",a.somaTRAB/10);
	printf("Prova %.1lf (peso %.1lf)\n",a.notaPROVA,a.pesoPROVA);
	printf("A nota final eh %.1lf\n",soma);

}