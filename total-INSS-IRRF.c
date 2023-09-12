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
    float inss1, inss2, inss3, inss4;
    if(salario < 1320.01){
        inss4 = (salario * 7.5)/100;
        printf("valor inss: %.2f R$", inss);}
    if(salario >= 1320.01){
        inss3 = (salario * 9)/100;
        printf("valor inss: %.2f R$", inss);
        if(salario >= 2571.30){
            inss2 = (salario * 12)/100;
            printf("valor inss: %.2f R$", inss);
            if(salario >= 3856.95){
                inss1 = (salario * 14)/100;
                printf("valor inss: %.2f R$", inss);
        
    }}}
    inss = inss1+inss2+inss3+inss4;
    float deducao = salario-inss;
    printf("\n valor dedução: %.2f R$", deducao);
    
    
    printf("\n Se quiser repetir clique 1: ");
    scanf("%le",&repetir);}
}
