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
    float inss1, inss2, inss3, inss4, inss5;
    float salario1, salario2, salario3, salario4, salario5, salario6, salario7;
    if (salario > 7507.49){
        salario1 = salario - 3856.94;
        inss1 = (salario1 * 14)/100;}
    if(salario > 3856.94 && salario < 7507.49){
        salario2 = salario - 3859.95;
        inss2 = (salario2 * 14)/100;
    } else if(salario > 3856.94){
        salario3 = 7507.49 - 3856.95;
        inss2 = (salario3 * 14)/100;
    }
    if(salario > 2571.30 && salario < 3856.95){
        salario4 = salario - 2571.30;
        inss3 = (salario4 * 12)/100;
    } else if(salario > 2571.30){
        salario5 = 3856.94 - 2571.30;
        inss3 = (salario5 * 12)/100;
    }
    if(salario > 1320.01 && salario < 3856.94){
        salario6 = 2571.29 - 1320.01;
        inss4 = (salario6 * 9)/100;
    } else if(salario > 1320.01 && salario < 2571.29){
        salario6 = 2571.29 - 1320.01;
        inss4 = (salario6 * 9)/100;
    } else if(salario > 1320.00){
        salario7 = 2571.29 - 1320.01;
        inss4 = (salario7 * 9)/100;
    } 
    if(salario < 1320.00 || salario > 1320.00){
        inss5 = (1320.00*7.5)/100;
    }
    
    inss = inss5+inss4 + inss3 + inss2+inss1;
    printf("\n valor dedução: %.2f R$", inss);
    float deducao = salario-inss;
    printf("\n valor dedução: %.2f R$", deducao);
    
    
    printf("\n Se quiser repetir clique 1: ");
    scanf("%le",&repetir);}
}
