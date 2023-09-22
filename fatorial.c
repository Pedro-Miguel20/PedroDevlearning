#include <stdio.h>

int main()
{
    //Title
    printf("Calcular fatorial\n");
    printf("----------------\n\n");
    
    //defining some variables
    //definir algumas variaveis
    int i;
    //imput
    //entrada
    int numero;
    int rep = 1;
    
    //repeating the code operation
    //Opção pra repetir a operação
    while(rep == 1){
        rep=0;
        printf("digite um numero: ");
        scanf("%d", &numero);
        
        //for loop that subtract the imput number that will be multiplied for the operation
        //loop que subtrai o número escolhido que vai ser subtraido para a operação
        for(i = numero; i > 1; i){
            i--;
            numero *= i;
        }
        
        //output
        //saída
        printf("resultado = %d\n\n", numero);
        printf(" Para novo fatorial, pressione 1: ");
        scanf("%d", &rep);
        printf("\n");
    }
    //end
    
    //Entrou tudo?
}
