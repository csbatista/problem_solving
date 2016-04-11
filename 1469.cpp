#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int N=0, M=0, I=0; //Num empresgaos, num rel diretas e num inst
	int X=0, Y=0, K=0;
	int A=0, B=0, E=0;
	int i=0, j=0, k=0;
	char id;

	int cont = 0;
	while(cin >> N){ 


		cin >> M;
		cin >> I;

		int ages[N]; //idades
		int grafo[N][N];

		int aux=0;


		for(i=0; i<N; i++){
			for(j=0; j<N; j++){
				grafo[i][j]=0;
			}
		}

		//linhas para idades
		for(i=0; i<N; i++){
			cin >> K;
			ages[i] = K;
		}

		//linhas para relacoes diretas
		for(i=0; i<M; i++){
			cin >> X;
			X = X-1;
			cin >> Y;
			Y = Y-1;

			grafo[X][Y] = 1;//X eh gerente direto de Y
		}

		for(i=0; i<N; i++){
			for(j=0; j<N; j++){
				if(grafo[i][j] > 0){ // i eh gerente de j
					for(k=0; k<N; k++){
						if(grafo[j][k] > 0){
							if(grafo[i][k] == 0)
								grafo[i][k] = grafo[i][j]+1;		
						}
					}
				}
			}
		}

		//linhas para instrucoes
		for(i=0; i<I; i++){
			cin >> id;
			if(id == 'T'){
				cin >> A;
				A = A-1;
				cin >> B;
				B = B-1;

				for(j=0; j<N; j++){
					aux = grafo[A][j];
					grafo[A][j] = grafo[B][j];
					grafo[B][j] = aux;
				}

				for(j=0; j<N; j++){
					aux = grafo[j][A];
					grafo[j][A] = grafo[j][B];
					grafo[j][B] = aux;
				}
			}
			if(id == 'P'){ //mostrar idade do empregado
				cin >> E;

				int menor = 101;
				for(j=0; j<N; j++){
					if(grafo[j][E-1] > 0 && ages[j] < menor){
						menor = ages[j];
					}
				}
				if(menor < 101){
					cout << menor;
				}
				else{
					cout << "*";
				}
				cout << "\n";
			}
		}
	}
	
	return 0;
}