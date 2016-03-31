#include <iostream>
#include <stdlib.h>
using namespace std;


int main()
{
	int n=0, i=0, d=0, total_doces = 0, dif=0 ;
	cin >> n;
	while(n != -1){
		//zerar variaveis
		total_doces=0;
		dif=0;

		int doces[n];

		//pegar total de doces
		for(i=0;i<n;i++){
			cin >> d;
			doces[i] = d;
			total_doces += d;
		}

		//se nao da pra ter todas as caixas iguais
		if(total_doces%n != 0){
			cout << "-1";
		}

		//se da
		else{
			//pega a diferenca entre o valor que tem e o que devia ter
			for(i=0;i<n;i++){
				dif += abs((total_doces/n) - doces[i]);
			}

			//divide por dois, ja que cada movimento ta representado em duas diferencas
			cout << dif/2;
		}


		cin >> n; //pegra prox caso de teste
		if(n!= -1){
			cout << "\n";
		}
	}
	
	return 0;
}