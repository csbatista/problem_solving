#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	int n=0, i=0;
	cin >> n;
	int valores[n];

	for(i=0;i<n;i++){
		cin >> valores[i];
	}

      std::sort(valores, valores + n);
	
      cout << valores[n/2];

	return 0;
}
