#include <conio.h>
#include <stdio.h>

int main()
{   
    int sexo;
    char nome[30];
    printf("Qual o seu nome? ");
    scanf("%s", nome);
    printf("Digite 1 para masculino e 0 para feminino \n");
     printf("sexo: ");
    scanf("%d", &sexo);
    if(sexo == 1){
        printf("Sr. %s", nome);
    }
    if(sexo == 0){
        printf("Sra. %s", nome);
    }
}
