#include <iostream>
#include <string>
using namespace std;

bool estaOrdenada (string palavra){
	int i=0;
	bool ordenada = true;
	for(i=0; i<palavra.size(); i++){
		if(i < palavra.size()-1){
			if(tolower(palavra[i]) >= tolower(palavra[i+1])) ordenada = false;
		}
	}
	return ordenada;
}

int main()
{
	int n=0, i=0;
	cin >> n;
	string *palavras = new string[n];
	char ordenadas[n];

	for(i=0;i<n;i++){
		cin >> palavras[i];
		if(estaOrdenada(palavras[i])) ordenadas[i] = 'O';
		else ordenadas[i] = 'N';
	}

	for(i=0;i<n;i++){
		cout << palavras[i] << ": " << ordenadas[i] << "\n";
	}
	return 0;
}