/** 
*	@Projeto			: Conversor de bases
*	----------------------------------------
*	@Autor				: Caio Barbosa
*	@Data de criação	: 06/11/2018
*	@Proposta			: Converter valores de uma determinada base numérica para outra
* 	-----------------------------------------------------------------------------------
*	Exemplificação:
*
*	VALOR  	| 	BASE
*		   	|_________
*	RESTO	   QUOEFICIENTE
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para ter elemento com tamanho dinâmico
struct Resultado{
	int valorR;
	
	struct Resultado *proximo; 
};

// Definção dos ponteiros
typedef struct Resultado *ponteiro;
typedef ponteiro resultado; 

// Instanciação do elemento
resultado r;

// Definição dos métodos
ponteiro* Criar(resultado r);
ponteiro* Empilhar(int mValorR,resultado r);
void Imprimir(int valorOriginal, int base, resultado r);
	
// Método principal **************************************************************************************************
int main(int argc, char *argv[]) {
	// Variaveis
	int valor, valorOriginal, base, resto, quoeficiente;
	char repetir;
	
	do{		
		// Limpa a tela
		system("cls");
		
		// Cria estrutura
		r = Criar(r);
		
		printf(" *Por enquanto somente da base 10 para outras \n");
		// Cabeçalho
		printf("**************************************************************************\n");
		printf("**                      CONVERSOR DE BASES                              **\n");
		printf("**************************************************************************\n\n");	
		printf(" -- Insira valor: ");
		scanf("%d", &valorOriginal);
		printf(" -- Insira base a ser convertida: ");
		scanf("%d", &base);
		
		if(base == 0 || base == 1){
			printf("\n\n :::: INFINITO");
			
		}else{
			// Valor Original permanecera inalterado
			valor = valorOriginal;
			
			// Cálculo
			do{		
				resto 			= valor % base;
				quoeficiente	= valor / base;
				
				r 		= Empilhar(resto, r);
				valor 	=  quoeficiente;			
			}while(quoeficiente != 0);
			
			
			Imprimir(valorOriginal, base, r);
		}	
		
		printf("\n\n :::: Deseja converter novamente(S/N)? ");
		scanf("%s", &repetir);		
	}while(repetir == 'S' || repetir == 's' || repetir == 'Y' || repetir == 'y' || repetir == '1');	
	
	return 0;
}

// METODOS  ************************************************************************************************************

// Cria novo elemento
ponteiro* Criar(resultado r){
	r = NULL;
	return r;
}

// Empilha elemento
ponteiro* Empilhar(int mValorR, resultado r){
	resultado pont;
	
	// Verifica se tem espaço em memória
	if((pont = malloc(sizeof(ponteiro)))==NULL){
		printf(" :::: Memoria insuficiente \n\n");
	}else{
		pont->valorR 	= mValorR;
		pont->proximo 	= r; 
	}
	return pont;
}

// Imprimi valor resultante
void Imprimir(int valorOriginal, int base, resultado r){
	ponteiro auxiliar;
	auxiliar = r;
	
	printf("\n\n :::: %d na base %d = ", valorOriginal, base);
	while(auxiliar != NULL){
		printf("%X", auxiliar->valorR);
		auxiliar = auxiliar->proximo;
	}
}
