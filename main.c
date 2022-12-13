#include <stdio.h>
#include <stdlib.h>

int main(){
	
   	unsigned int save[200];	//armazena tudo
   	int entr;				//entrada
   	int aux;				//auiliar
   	int divi;				//valor da divisão
   	int res;				//valor do resto
   	int veri;				//verificador
   	int i;					//laço for

	for(divi = 0; divi <= 200; divi++){	//laço para zerar todas posições de X e não bugar mais na frente...
		save[divi]=0;
	};
   	
   	printf("Digite um numero de 0 a 5000: ");		//Recebe o primeiro número
	scanf("%d",&entr);

	while(entr != -1){									//laço while para terminar com "-1"

		if(entr >= 0 && entr <= 5000){					//define tamanho do número de entrada
			divi = entr / 32;			//divisão para saber qual posição do vetor
			
			res = entr%32;				//resto da divisão

			aux = 1 << res;				//move os bits com o valor do resto e armaena em aux
			
			save[divi] = save[divi] | aux;	//compara e guarda os bits

			printf("Digite um numero de 0 a 5000: ");		//entrada de outro número
			scanf("%d",&entr);
		}else{
			printf("NUMERO INVALIDO!!\nDigite um numero de 0 a 5000: ");	//se o número estiver fora do definido pede outro número
			scanf("%d",&entr);
		};
	};

	printf("\nVoce digitou:");				//Quando sai do "laço de entrada de dados"

	for(divi = 0; divi <= 200; divi++){			//laço para percorrer todas posições de save e mostrar todos números em ordem crescente.
		
		if(save[divi]!=0){						//se a posição do valor divi em save não for vazia
			
			for(i = 0; i <= 31; i++){		//laço para verificar o número
				
				veri = save[divi] >> i;				//move vetor para posição do número
				
				if(veri&1){					//se tiver um bit printa o respectivo número
					printf(" %d",32*divi+i);
				};
			};
		};
	};

	printf("\n");
   	
	return 0;  
}