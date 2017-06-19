#include <stdio.h>
#include <string.h>
#define STRTAM 99
#define MAX 10

struct LIVROS {
   char name[STRTAM];    
}; 

struct EDITORA {
   char editor[STRTAM];  
   struct LIVROS book[STRTAM];   
};


struct EDITORA xx(){
   int xlivros, i, j;
   struct EDITORA xxx;

   printf("Digite a Editora: ");
   fgets(xxx.editor, STRTAM, stdin);
   strtok(xxx.editor, "\n");
 
   printf("Quantos Livros: ");
   scanf("%i",&xlivros);
   setbuf(stdin,NULL);
   for(i=0;i<xlivros;i++){
      printf("Digite o Nome do Livro: ");
      fgets(xxx.book[i].name, STRTAM, stdin);
      strtok(xxx.book[i].name, "\n");
   }
   return (xxx);
}/*
struct LIVROS yy(){

   struct LIVROS yyy;
   printf("Digite o Nome do Livro: ");
   fgets(yyy.name, STRTAM, stdin);
   strtok(yyy.name, "\n");

   return (yyy);
}*/

int main() {

   //struct LIVROS y[MAX];
   struct EDITORA x[MAX];
	int xedit, xlivros, i, j;

   printf("Digite Quantas Editoras: ");
   scanf("%i",&xedit);
   setbuf(stdin,NULL);

   for(i=0;i<xedit;i++){
      x[i] = xx();
   }
  
   ///imprimindo
     for(i=0;i<xedit;i++){
      printf("Editora: %s",x[i].editor);
      printf("\n");      
      for(j=0;j<MAX;j++){
         printf("     >>> %s\n",x[i].book[j].name);   
      }
      printf("\n\n");
   }
}
 

/*
#define LEN 50
    #define NUM 2

    struct endereco {
        char rua[LEN];
        char cidade_estado_cep[LEN];
    };

    struct student {
        char id[10];
        int idade;
        struct endereco casa;
        struct endereco escola;
    };

    struct student pessoa;

    void obtem_endereco(struct endereco [], int);
    void imprime_endereco(struct endereco);

    void obtem_endereco(struct endereco aender [], int index)
    {
         printf("Entre rua: ");
         fgets(aender[index].rua, STRTAM, stdin);
         printf("Entre cidade/estado/cep: ");
         fgets(aender[index].cidade_estado_cep, STRTAM, stdin);
    }

    void imprime_endereco(struct endereco ender)
    {
         printf("%s\n", ender.rua);
         printf("%s\n", ender.cidade_estado_cep);
    }

    main()
    {
         struct endereco residencias[NUM];
         int i;

         for (i = 0; i < NUM; i++) {
             printf("Entre o endereco da pessoa %d:\n", i);
             obtem_endereco(residencias,i);
         }

         for (i = 0; i < NUM; i++) {
             printf("endereco da pessoa %d:\n", i);
             imprime_endereco(residencias[i]);
         }
    }

 #include <stdio.h>
 
 struct Date    //estrutura chamada de date
 {
   int day;
   int month;
   int year;
 };
 struct Person 
 {
   char name[100]; 
   int height;
   Date bDay;    //temos uma nova variável, mas notem o tipo
 };
 

 int main ()
 {
   Person p1;
   setValues(&p1);  
   printf("Outputting person data\n");
   printf("======================\n");
   getValues(&p1);
   return 0;
 }
 
 void setValues(Person* pers)
 {
   printf("Enter person's name: ");
   fgets(pers.name, 100, stdin);
   printf("Enter height in inches: ");
   scanf("%d", &pers.height);
   printf("Enter day, month and year of birthday separated by spaces: ");
   scanf("%d %d %d\n", &pers.bDay.day, &pers.bDay.month, &pers.bDay.year );
 }
 
 void getValues(const Person* pers)
 {
   printf("Person's name: %s\n", pers.name);
   printf("Person's height in inches is: %d\n", pers.height);
   printf("Person's birthday in dd/mm/yyyy format is: %d/%d/%d\n", pers.bDay.day, pers.bDay.month, pers.bDay.year );
 }
*/