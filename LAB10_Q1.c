#include <stdio.h>
int main(){
    char product_name;
 int price,quantity;
 
 FILE *file;
 file = fopen("products.txt","a");
 if (file == NULL){
          printf("Error opeing the file \n");
          return 1;
          }
  printf("=== Product Data Logger ===\n");
  printf("Enter the name of Product: \n");
 scanf("%s", product_name);
 printf("Enter the Price of Product: \n");
 scanf("%d", price );
 printf("Enter the quantity you want: \n");
 scanf("%d", quantity );
 fprintf(file,"%s,%d,%d\n",product_name ,price ,quantity)
 fclose(file);
     printf("? Product saved successfully to products.txt\n");
return 0;
}
