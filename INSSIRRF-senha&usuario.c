#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   
    char usuario[4];
    double senha;
    while(usuario != "Admin" && senha != 5432){
    printf("Usuário:");
    scanf("%s", usuario);
    system("clear");
    printf("Senha: ");
    scanf("%le", &senha);
    system("clear");
    }
     
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
        salario1 = 7507.49 - 3856.94;
        inss1 = (salario1 * 14)/100;}
    else if(salario > 3856.94 && salario < 7507.49){
        salario2 = salario - 3856.95;
        inss2 = (salario2 * 14)/100;
    }else if(salario > 3856.94){
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
    if(salario > 1320.01 && salario < 2571.29){
        salario6 = salario - 1320.01;
        inss4 = (salario6 * 9)/100;
    } else if(salario > 1320.00){
        salario7 = 2571.29 - 1320.01;
        inss4 = (salario7 * 9)/100;
    } 
    if(salario < 1320.00 || salario > 1320.00){
        inss5 = (1320.00*7.5)/100;
    }
    
    float liquido;
    float deducao_irrf;
    inss = inss5+inss4 + inss3 + inss2+inss1;
    float deducao_inss = salario-inss;
    
    
    //SEGUINDO A TABELE DO IRRF 2023 para dedução
    
    if(deducao_inss > 4664.68){
        deducao_irrf = ((deducao_inss*27.5)/100)-884.96;
        printf("\n valor dedução: %.2f R$", deducao_irrf);
    }
    if(deducao_inss < 4664.67 && deducao_inss > 3751.06){
        deducao_irrf = ((deducao_inss*22.5)/100)-651.73;
    }
    if(deducao_inss < 3751.05 && deducao_inss > 2826.66){
        deducao_irrf = ((deducao_inss*15)/100)-370.40;
    }
    if(deducao_inss < 2826.65 && deducao_inss > 1903.99){
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
