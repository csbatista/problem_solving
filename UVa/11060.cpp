#include <iostream>
#include <stdlib.h>
using namespace std;


int getIndex(string nome, string nomes[], int n){
	int index=-1, i=0;
	for(i=0; i<n; i++){
		if(nomes[i] == nome){
			index = i;
		}
	}
	return index;
}


int main()
{
	int n=0; //numero de bebidas
	int i=0, j=0, k=0, cont=0; //contador
	int m=0; //numero de relacoes entre as bebidas

	string b1, b2; //bebidas da relacao

	while(cin >> n){
		cont++;

		int grafo[n][n];
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				grafo[i][j] = 0;
			}
		}

		string nomes[n];
		int quant_menos_fortes[n];

		for(i=0; i<n; i++){
			cin >> nomes[i];
			quant_menos_fortes[i] = 0;
		}

		cin >> m;
		for(i=0; i<m; i++){
			cin >> b1;
			cin >> b2;

			grafo[getIndex(b1, nomes, n)][getIndex(b2, nomes, n)] = 1;

		}

		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				if(grafo[i][j] == 1){ // i deve ser bebido antes de j
					for(k=0; k<n; k++){
						if(grafo[j][k] == 1){
							grafo[i][k] = 1;		
						}
					}
				}
			}
		}

		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				if(grafo[i][j] == 1){
					quant_menos_fortes[j]++;
				}
			}
		}

		cout << "Case #" << cont << ": Dilbert should drink beverages in this order: ";
		for(j=0; j<n; j++){
			int menor = n, index_maior=0;
			for(i=0; i<n; i++){
				if(quant_menos_fortes[i] < menor){
					index_maior = i;
					menor = quant_menos_fortes[i];
				}
			}

			cout << nomes[index_maior];
			if(j<n-1){
				cout << " ";
			}
			else{
				cout << ".";
			}
			

			for(k=0; k<n; k++){
				grafo[index_maior][k] = 0;
				if(quant_menos_fortes[k]  != n+1) quant_menos_fortes[k] = 0;
			}

			for(i=0; i<n; i++){
				for(k=0; k<n; k++){
					if(quant_menos_fortes[k]  != n+1){
						if(grafo[i][k] == 1){

							quant_menos_fortes[k]++;
						}
					}
				}
			}
			quant_menos_fortes[index_maior] = n+1;
		}

		cout << "\n\n";

	}
	
	return 0;
}
