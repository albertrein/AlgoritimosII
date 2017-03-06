#include <stdio.h>
#define N1 5
#define N2 9
main(){
	int a = N1, b = N2, c;
	
	// Etapa 1
	if(N1 < N2){
		c = N1;
	}else{
		c = N2;
	}
	printf("c = %i",c);
	
	
	// Etapa 2
	if(N1 > N2){
		c = N1 - N2;
		if(N1 % 2 == 0){
			printf("PAR \n");
		}else{
			printf("IMPAR \n");
		}
	}else{
		c = N2 - N1;
		if(N2 % 2 == 0) {
			printf("PAR \n");
		}else{
			printf("IMPAR \n");
		}
	}
	printf("\n ***************** \n");
	
	//Etapa 3
	int vet[50], i, tot;
	vet[0] = 9;
	tot = vet[0];
	for(i = 1;i < 50;i++){
		tot += c;
		if(tot > 500){
			vet[i] = i;
		}else{
			vet[i] = tot;
		}
				
	}
		
	
	/*	
	for(i=0;i<50;i++){
		printf("vet[%i] = %i \n",i,vet[i]);
	} */
		
	/// Etapa 4
	int cont, j, val, z, h;
	
	for(i=0;i<50;i++){
		cont = 0;
		printf("vet[%i] = %i \n",i,vet[i]);
		
		for(j=1;j<=vet[i];j++){
			if(vet[i] % j == 0){
				cont++;
			}
		}
		if(vet[i] % 2 == 0){
			printf("PAR - ");
		}else{
			printf("IMPAR - ");
		}
		if(cont == 2){
			printf("PRIMO \n\n");
		}else{
			//printf("N PRIMO \n\n");
			val = vet[i];
			for(z = 0; z != 1;){
				cont = 0;
				val++;
				for(h = 1; h <= val; h++){
					if(val % h == 0){
						cont++;
					}		
				}
				if(cont == 2){
					z = 1;
				}
			}
			printf("O proximo primo eh: %i \n\n",val);
		}		
	}
	
	
	
	
	
	
	
	
	
	
}//main
