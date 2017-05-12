#include<stdio.h>
#include<string.h>
#define TAM 100

int different (int x[], int tam){
	int i, countP = 0, countI = 0;
	for(i=0;i < tam;i++){
		if((x[i] % 2) == 0){
			countP++;
		}else{
			countI++;
		}
	}	
	return(countP-countI);
}

int main(){
	char st1[TAM],st2[TAM],st3[TAM],st4[2*TAM];
	printf("Digite tres strings de ate 100 cars cada uma:\n");
	fgets(st1, TAM, stdin);
	strtok(st1, "\n");
	fgets(st2, TAM, stdin);
	strtok(st2, "\n");
	fgets(st3, TAM, stdin);
	strtok(st3, "\n");
	
	//Item A
	if (strcasecmp(st1, st2)==0){
		if(strcasecmp(st1, st3)==0){
			printf("Todas as strings sao iguais\n");
		} else{
			printf("A string 1 e igual a string 2 \n");
		}
	}else{
		if (strcasecmp(st1, st3)==0){
			printf("A string 1 e igual a string 3 \n");
		}else{
			if (strcasecmp(st2, st3)==0){
				printf("A string 2 e igual a string 3 \n");
			}else{
				printf("As strings que voce digitou nao sao iguais \n");
				if (strcasecmp(st1, st2)>0){
					if (strcasecmp(st1, st3)>0){
						printf ("%s e a maior digitada \n",st1);
						strcpy(st4, st1);
					}else {
						printf ("%s e a maior digitada \n",st3);
						strcpy(st4, st3);
					}
				}else{
					if (strcasecmp(st2, st3)>0){
						printf ("%s e a maior digitada \n",st2);
						strcpy(st4, st2);
					}else {
						printf ("%s e a maior digitada \n",st3);
						strcpy(st4, st3);
					}
				}
			}
		}
	}
	printf("\n\n");

    //Item B:
    if (strncasecmp(st1, st2, TAM) < 0) {
        if (strncasecmp(st1, st3, TAM) < 0) {
            printf("%s - %d cars\n",st1,strlen(st1));
            strcat(st4,st1);
            if(strncasecmp(st2,st3, TAM) <= 0){
                printf("%s - %d cars\n",st2,strlen(st2));
                printf("%s - %d cars\n",st3,strlen(st3));
            }else{
                printf("%s - %d cars\n",st3,strlen(st3));
                printf("%s - %d cars\n",st2,strlen(st2));
            }
        }
    }
    
    if (strncasecmp(st2, st1, TAM) < 0) {
        if (strncasecmp(st2, st3, TAM) < 0) {
            printf("%s - %d cars\n",st2,strlen(st2));
            strcat(st4,st2);
            if(strncasecmp(st1,st3, TAM) <= 0){
                printf("%s - %d cars\n",st1,strlen(st1));
                printf("%s - %d cars\n",st3,strlen(st3));
            }else{
                printf("%s - %d cars\n",st3,strlen(st3));
                printf("%s - %d cars\n",st1,strlen(st1));
            }
        }
    }
    
    if (strncasecmp(st3, st1, TAM) < 0) {
        if (strncasecmp(st3, st2, TAM) < 0) {
            strcat(st4,st3);
            printf("%s - %d cars\n",st3,strlen(st3));
            if(strncasecmp(st1,st2, TAM) <= 0){
                printf("%s - %d cars\n",st1,strlen(st1));
                printf("%s - %d cars\n",st2,strlen(st2));
            }else{
                printf("%s - %d cars\n",st2,strlen(st2));
                printf("%s - %d cars\n",st1,strlen(st1));
            }
        }
    }
	
	//Item C:
	if (strcasecmp (st1,st2)<0){
		if (strcasecmp (st1,st3)<0){
			strcat(st4, st1);
		}else{
			strcat(st4,st3);
		}
	}else{
		if (strcasecmp (st2,st3)<0){
			strcat(st4, st2);
		}else{
			strcat(st4, st3);
		}
	}
	printf("A string concatenada ficou \n %s", st4);
	}
