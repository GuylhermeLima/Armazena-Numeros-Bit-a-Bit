#include <stdio.h>
#include <stdlib.h>

int main(){
	
   	unsigned int save[200];	//armazena tudo
   	int entr;				//entrada
   	int aux;				//auiliar
   	int div;				//valor da divisão
   	int res;				//valor do resto
   	int veri;				//verificador
   	int i;					//laço for

	for(div = 0; div <= 200; div++){	//laço para zerar todas posições de X e não bugar mais na frente...
		save[div]=0;
	};
   	
   	printf("Digite um numero de 0 a 5000: ");		//Recebe o primeiro número
	scanf("%d",&entr);

	while(entr != -1){									//laço while para terminar com "-1"

		if(entr >= 0 && entr <= 5000){					//define tamanho do número de entrada
			div = entr / 32;			//divisão para saber qual posição do vetor
			
			res = entr%32;				//resto da divisão

			aux = 1 << res;				//move os bits com o valor do resto e armaena em aux
			
			save[div] = save[div] | aux;	//compara e guarda os bits

			printf("Digite um numero de 0 a 5000: ");		//entrada de outro número
			scanf("%d",&entr);
		}else{
			printf("NUMERO INVALIDO!!\nDigite um numero de 0 a 5000: ");	//se o número estiver fora do definido pede outro número
			scanf("%d",&entr);
		};
	};

	printf("\nVoce digitou:");				//Quando sai do "laço de entrada de dados"

	for(div = 0; div <= 200; div++){			//laço para percorrer todas posições de save e mostrar todos números em ordem crescente.
		
		if(save[div]!=0){						//se a posição do valor div em save não for vazia
			
			for(i = 0; i <= 31; i++){		//laço para verificar o número
				
				veri = save[div] >> i;				//move vetor para posição do número
				
				if(veri&1){					//se tiver um bit printa o respectivo número
					printf(" %d",32*div+i);
				};
			};
		};
	};

	printf("\n");
   	
	return 0;  
}