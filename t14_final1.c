#include <stdio.h>
#include <string.h>

#define TAM 500

main(){
	int i, y, x, z, cwords=1;
	int num, nmaior;
	char st1[TAM];
	char st11[TAM];
	char st2[TAM];
	char st3[TAM];

	for(i=1;i<=10;i++){
		x=i;
		fgets(st1,TAM,stdin);				
		if((y = strlen(st1)) == 1){
			strcat(st11,"\n ");
			i=11;
		}	
		strcat(st11,st1);	
	}	
	
	strcpy(st2,strtok(st11,"\n"));
	
	num = strlen(st2);
	nmaior = num;	
	strcpy(st3, st2);	
	x-=1;
	//z = x -2;
	for(i=0;i<x;i++){
		if(num > nmaior){
			nmaior = num;
			strcpy(st3, st2);
		}
		
		strcpy(st2,strtok(NULL,"\n"));
		num = strlen(st2);
			
	}
	
	printf("\nO Maior paragrafo digitado foi:\n");
	printf("\"%s\"",st3);
	printf("\nCom %i caracteres",nmaior);
	
	///ETAPA C == achar quantas palavras em uma frase
	
	if (strtok(st3, " \t") == NULL){}	
	while(strtok(NULL, " \t")){
		cwords++;
	}
	printf("\nO maior paragrafo tem %i palavras\n",cwords);

}
