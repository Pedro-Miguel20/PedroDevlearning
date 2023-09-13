#include <stdio.h>

int main()
{
  double rep = 1;
  while(rep == 1){
  char nome_carro[10];
  rep = 0;
  float valor;
  printf("Informe o carro: ");
  scanf("%s", nome_carro);
  printf("Valor de fábrica: ");
  scanf("%f", &valor);
  float com_imposto = (valor* 45)/100;
  float vendedor =  valor + com_imposto;
  float com_lucro = (vendedor*28)/100;
  float preco = vendedor + com_lucro;
  printf("Carro %s está saindo por %.2f", nome_carro, preco);
  
  printf("\n Se quiser repetir clique 1: ");
  scanf("%le",&rep);}
}
