#include <stdio.h>

int main()
{
    int number;
    printf("Digite um número: ");
    scanf("%d", &number);
    if(number >= 20 && number <= 40){
        printf("%d pertence ao grupo", number);
    }else{
        printf("Não pertence ao grupo");
    }
}
