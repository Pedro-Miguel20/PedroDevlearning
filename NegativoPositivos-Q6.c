#include <stdio.h>

int main()
{
    int number;
    printf("Informe o número: ");
    scanf("%d", &number);
    if(number < 0){
    printf("%d é negativo", number);}
    if(number > 0){
    printf("%d é positivo", number);}
    else if(number == 0){
    printf("%d é nulo", number);}
}
