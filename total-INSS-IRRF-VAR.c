#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

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
    float a = 7507.49, b=3856.95, c=2571.30, d=1320.01;//
    
    float inss1, inss2, inss3, inss4, inss5;
    float salario1, salario2, salario3, salario4, salario5, salario6, salario7;
    
    if (salario > a){
        salario1 = a - b-0.01;
        inss1 = (salario1 * 14)/100;}
    else if(salario > b-0.01 && salario < a){
        salario2 = salario - b;
        inss2 = (salario2 * 14)/100;
    }else if(salario > b-0.01){
        salario3 = a - b;
        inss2 = (salario3 * 14)/100;
    } 

    
    if(salario > c && salario < b){
        salario4 = salario - c;
        inss3 = (salario4 * 12)/100;
    } else if(salario > c){
        salario5 = b-0.01 - c;
        inss3 = (salario5 * 12)/100;
    }
    if(salario > d && salario < c-0.01){
        salario6 = salario - d;
        inss4 = (salario6 * 9)/100;
    } else if(salario > d-0.01){
        salario7 = c-0.01 - d;
        inss4 = (salario7 * 9)/100;
    } 
    if(salario < d-0.01 || salario > d-0.01){
        inss5 = (1320.00*7.5)/100;
    }
    
    float liquido;
    float deducao_irrf;
    inss = inss5+inss4 + inss3 + inss2+inss1;
    float deducao_inss = salario-inss;
    
    
    //SEGUINDO A TABELE DO IRRF 2023 para dedução
    float irrf_a=4664.68, irrf_b=3751.06, irrf_c=2826.66, irrf_d=1903.99;//
    
    if(deducao_inss > irrf_a){
        deducao_irrf = ((deducao_inss*27.5)/100)-884.96;
        printf("\n valor dedução: %.2f R$", deducao_irrf);
    }
    if(deducao_inss < irrf_a-0.01 && deducao_inss > irrf_b){
        deducao_irrf = ((deducao_inss*22.5)/100)-651.73;
    }
    if(deducao_inss < irrf_b-0.01 && deducao_inss > irrf_c){
        deducao_irrf = ((deducao_inss*15)/100)-370.40;
    }
    if(deducao_inss < irrf_c-0.01 && deducao_inss > irrf_d){
        deducao_irrf = ((deducao_inss*7.5)/100)-158.40;
    }
    liquido = deducao_inss - deducao_irrf;
    
    printf("\n valor bruto: %.2f R$", salario);
    printf("\n valor inss: -%.2f R$", inss);
    printf("\n valor dedução-inss: %.2f R$", deducao_inss);
    printf("\n valor dedução: -%.2f R$", deducao_irrf);
    printf("\n valor liquido: %.2f R$", liquido);
    
    
    printf("\n Se quiser repetir clique 1: ");
    scanf("%le",&repetir);
    system("clear");
    }
}
