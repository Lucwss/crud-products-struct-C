#include <stdio.h>
#include <stdlib.h>

//assinatura dos metodos
int menu(void);

//register
struct Product {
   int code;
   char description[30];
   float price;
};



int main(void) {
   int tam = 0;
   int option, code = 0, p_quantity=0, found;

   printf("How many products would you like to insert ? ");
   scanf("%d", &tam);

   struct Product products[tam];

   do
   {
      option = menu();

      switch (option) {
      case 1:
         printf("\n\n **** inclusao **** \n\n");

         if(p_quantity < tam) {
            printf("Type the code : ");
            scanf("%d", &products[p_quantity].code);
            printf("Type the description : ");
            getchar();
            fgets(products[p_quantity].description, 30, stdin);
            printf("Type the price : ");
            scanf("%f", &products[p_quantity].price);
            p_quantity++;
         }
         else printf("list of products full!\n");

         break;
      case 2:
         printf("\n\n **** consulta **** \n\n");

         printf("Type the code : ");
         scanf("%d", &code);
         for(int i = 0; i < p_quantity; i++) {
            if(code == products[i].code) {
               printf("%s", products[i].description);
               printf(" - ");
               printf("%.2f\n", products[i].price);
               found = 1;
            }  
         }
         if(!found) {
            printf("\n");
            printf("product not found!\n");
         }
         found = 0;
         break;
      case 3:
         printf("\n\n **** listagem **** \n\n");

         printf("code  - description  -  price\n");
         for(int i = 0; i < p_quantity; i++) {
            printf("%i", products[i].code);
            printf(" - ");
            printf("%s", products[i].description);
            printf(" - ");
            printf("%.2f\n", products[i].price);
         }
      break;
      case 4:
         printf("\n\n **** alteracao **** \n\n");

         printf("Type the code : ");
         scanf("%d", &code);
         for(int i = 0; i < p_quantity; i++) {
            if(code == products[i].code) {
               found = 1; 
               printf("%s", products[i].description);
               printf(" - ");
               printf("%.2f\n", products[i].price);
               printf("Type the new description : ");
               getchar();
               fgets(products[i].description, 30, stdin);
               printf("Type the new price : ");
               scanf("%f", &products[i].price);
            }  
         }
         if(!found) {
            printf("\n");
            printf("product not found!\n");
         }
         found = 0;
      break;
      case 5:
         printf("\n\n **** exclusao **** \n\n");
         printf("Type the code : ");
         scanf("%d", &code);
         for(int i = 0; i < p_quantity; i++) {
            if(code == products[i].code) {
               found = 1; 
               products[i] = products[p_quantity - 1];
               p_quantity--;
               
            }  
         }
         if(!found) {
            printf("\n");
            printf("product not found!\n");
         }
         found = 0;
      break;
      default:
         printf("opcao nao implementada no momento\n");
         break;
      }
   } while (option != 0);
   return 0;
}

int menu(void) {
   int opt;
   printf("\n\n ******* menu ******* \n\n");
   printf("1. Inclusao\n");
   printf("2. Consulta\n");
   printf("3. Listagem\n");
   printf("4. Alteração\n");
   printf("5. Exclusão\n");
   printf("0. Sair\n\n");
   printf("Escolha sua opção : ");
   scanf("%i", &opt);
   return opt;
}



