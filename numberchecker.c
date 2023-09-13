#include <stdio.h>

int main()
{
        printf("Questão 8 - Faça um programa que leia um número inteiro e imprima na tela\n se o mesmo está na faixa entre 20 e 40 ou não.");
    int number;
    printf("\n\n R = Digite um número: ");
    scanf("%d", &number);
    if(number >= 20 && number <= 40){
        printf("%d pertence ao grupo", number);
    }else{
        printf("Não pertence ao grupo\n");
    }
    
    int number1;
    printf("\n\n Questão 9 - Faça um programa que leia um número e mostre na tela se ele é igual \n a 10, a 20, a 30, se não for imprimir a mensagem “Número inválido”.");
    
    printf("\n\n Digite um número: ");
    scanf("%d", &number1);
    if(number1 == 10 || number1 == 20 || number1 == 30){
        printf("%d é valido", number1);
    }else{
        printf("Número invalido");
    }
}

