#include <stdio.h>

int different (int x[], int tam)
{
	int i, countP = 0, countI = 0;

	for(i=0;i<tam;i++){
		if((x[i] % 2) == 0){
			countP++;
		}else{
			countI++;
		}
	}	
	return(countP-countI);
}


main(){
	int x[10], y;
	int i;
	
	for(i=0;i<10;i++){
		printf("Digite um Valor: ");
		scanf("%i",&x[i]);
	}	
	
	y = different(x);
	
	printf("The Different is: %i",y);
}
