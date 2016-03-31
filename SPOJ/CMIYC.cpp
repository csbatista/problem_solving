#include <iostream>
#include <stdlib.h>
using namespace std;


int main()
{
	int t=0, i=0;
	long long size=0;
	cin >> t;

	for(i=0;i<t;i++){ //casos de teste
		cin >> size; //tamanho terreno

		//se nao for divisivel por 3, o encontro vai ser no pt de partida
		if(size%3 != 0){ 
			cout << "0";
		}

		//se for divisivel por 3, o encontro vai ser a uma distancia size/3
		//padrao observado fazendo testes para tamanhos de 1 a 12
		else{
			cout << size/3;
		}
		if(i < t-1){
			cout << "\n";
		}
	}
	
	return 0;
}