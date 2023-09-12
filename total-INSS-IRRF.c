#include <stdio.h>

int main()
{   
    double repetir = 1;
    while (repetir == 1){
    repetir = 0;
    
    float salario;
    float inss;
    printf("Seu salário: ");
    scanf("%f", &salario);
    
    //CONSIDERANDO A TEBELA 2023 DO inss
    
    if(salario >= 3856.95){
        inss = (salario * 14)/100;
        printf("valor inss: %.2f R$", inss);}
    if(salario >= 2571.30 && salario < 3856.95){
        inss = (salario * 12)/100;
        printf("valor inss: %.2f R$", inss);}
    if(salario >= 1320.01 && salario < 2571.30){
        inss = (salario * 9)/100;
        printf("valor inss: %.2f R$", inss);}
    if(salario < 1320.01){
        inss = (salario * 7.5)/100;
        printf("valor inss: %.2f R$", inss);}
    float deducao = salario-inss;
    printf("\n valor dedução: %.2f R$", deducao);
    
    
    printf("\n Se quiser repetir clique 1: ");
    scanf("%le",&repetir);}
}
