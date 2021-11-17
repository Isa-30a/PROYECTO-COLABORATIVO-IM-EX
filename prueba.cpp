#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int n;
	cout<<"Ingrese el valor de n: ";cin>>n;
	int vector_prueba[n];
	
	for(int i=0; i<n; i++){
		n++;
		vector_prueba[i]=i;
		cout<<vector_prueba[i]<<endl;
	}

}
