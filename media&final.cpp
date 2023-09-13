#include <stdio.h>
#include <stdio.h>
#include <conio.h>

    int main()
{
    double repetir = 1;
    while(repetir == 1){
    repetir = 0;
    float math1;
    float math2;
    float math3;
    float math4;
    float exam;
    printf("Digite a nota do 1° bimestre: ");
    scanf("%f",&math1);
    printf("Digite a nota do 2° bimestre: ");
    scanf("%f",&math2);
    printf("Digite a nota do 3° bimestre: ");
    scanf("%f",&math3);
    printf("Digite a nota do 4° bimestre: ");
    scanf("%f",&math4);
    float sum = math1 + math2 + math3 + math4;
    float media = sum/4;
	if ( media > 7){
		printf("Aprovado media = %.2f", media);
	} else {
		printf("De exame, media final = %.2f", media);
		printf("\n Digite a nota do exame: ");
	        scanf("%f",&exam);
            	float final = (exam + media)/2;
		if (final > 5){
			printf("Aprovado media final = %.2f", final);
	        } else {
			printf("reprovado, media final = %.2f", final);}}
	
    printf("\n Se quiser repetir clique 1: ");
    scanf("%le",&repetir);}
}
