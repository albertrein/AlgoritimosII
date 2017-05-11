#include <stdio.h>
#include <string.h>
#define TAM 100
#define STRMAX 200
main(){
	char txt1[TAM], txt2[TAM], txt3[TAM], txt4[STRMAX];
	int tf, x, y, z;
	
	printf("Digite 3 Frases: \n");
	fgets(txt1, TAM, stdin);
	tf = strlen(txt1);
    if (txt1[tf - 1] = "\n") {
        txt1[tf - 1] = 0;
    }
	fgets(txt2, TAM, stdin);
	tf = 0;
	tf = strlen(txt2);
	if (txt2[tf - 1] = "\n") {
        txt2[tf - 1] = 0;
    }
	fgets(txt3, TAM, stdin);
	tf = 0;
	tf = strlen(txt3);
	if (txt3[tf - 1] = "\n") {
        txt3[tf - 1] = 0;
    }
      	
	// Item A:
	if(strncasecmp(txt1,txt2,TAM) ==0){
		if(strncasecmp(txt2,txt3,TAM) == 0){
			printf("As strings sao iguais\n");
		}
	}else{
		printf("As strings que voce digitou nao sao iguais\n");
	}
	
	if (strncasecmp(txt1, txt2, TAM) > 0) {
        if (strncasecmp(txt1, txt3, TAM) > 0) {
        	printf("\"%s\" eh a maior digitada\n\n",txt1);
        	strcpy(txt4,txt1);
    	}
    }
    
    if (strncasecmp(txt2, txt1, TAM) > 0) {
        if (strncasecmp(txt2, txt3, TAM) > 0) {
        	printf("\"%s\" eh a maior digitada\n\n",txt2);
        	strcpy(txt4,txt2);
    	}
    }
	
	if (strncasecmp(txt3, txt1, TAM) > 0) {
        if (strncasecmp(txt3, txt2, TAM) > 0) {
        	printf("\"%s\" eh a maior digitada\n\n",txt3);
        	strcpy(txt4,txt3);
    	}
    } 
	
	//Item B:
	if (strncasecmp(txt1, txt2, TAM) < 0) {
        if (strncasecmp(txt1, txt3, TAM) < 0) {
        	printf("%s - %d cars\n",txt1,strlen(txt1));
        	strcat(txt4,txt1);
        	if(strncasecmp(txt2,txt3, TAM) <= 0){
        		printf("%s - %d cars\n",txt2,strlen(txt2));
        		printf("%s - %d cars\n",txt3,strlen(txt3));
			}else{
				printf("%s - %d cars\n",txt3,strlen(txt3));
				printf("%s - %d cars\n",txt2,strlen(txt2));
			}
    	}
    }
    
    if (strncasecmp(txt2, txt1, TAM) < 0) {
        if (strncasecmp(txt2, txt3, TAM) < 0) {
        	printf("%s - %d cars\n",txt2,strlen(txt2));
        	strcat(txt4,txt2);
        	if(strncasecmp(txt1,txt3, TAM) <= 0){
        		printf("%s - %d cars\n",txt1,strlen(txt1));
        		printf("%s - %d cars\n",txt3,strlen(txt3));
			}else{
				printf("%s - %d cars\n",txt3,strlen(txt3));
				printf("%s - %d cars\n",txt1,strlen(txt1));
			}
    	}
    }
	
	if (strncasecmp(txt3, txt1, TAM) < 0) {
        if (strncasecmp(txt3, txt2, TAM) < 0) {
        	strcat(txt4,txt3);
        	printf("%s - %d cars\n",txt3,strlen(txt3));
        	if(strncasecmp(txt1,txt2, TAM) <= 0){
        		printf("%s - %d cars\n",txt1,strlen(txt1));
        		printf("%s - %d cars\n",txt2,strlen(txt2));
			}else{
				printf("%s - %d cars\n",txt2,strlen(txt2));
				printf("%s - %d cars\n",txt1,strlen(txt1));
			}
    	}
    }
    //Item C:
	printf("\nA string concatenada ficou assim: \n");
	printf("%s",txt4);

}
