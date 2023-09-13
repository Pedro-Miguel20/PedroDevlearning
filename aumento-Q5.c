#include <stdio.h>

int main()
{
    char nome[30];
    printf("Nome: ");
    scanf("%s", nome);
    
    float salario;
    printf("Remuneração: ");
    scanf("%f", &salario);
    
    float aumento;
    if(salario >= 2000 && salario <= 3000){
        aumento = salario*0.05;
    }else if (salario >= 1000 && salario < 2000){
        aumento = salario*0.10;
    }else if(salario < 1000){
        aumento = salario*0.20;
    }else{
        printf("Não tem direito");
    }
    
    int percentagem = (aumento/salario)*100;
    
    printf("Tem direito a %d/100", percentagem);
    printf(" aumento = %.2f", aumento);
    
}
