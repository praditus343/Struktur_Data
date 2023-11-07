#include <iostream>

using namespace std;

int main() {
	int x = 500;
	int *ptrX = &x;
	int *ptrY = &x;
	
	cout << "Value dari x : " << x << ", Alamat dari x : " << &x << endl;
	
	
	 cout << "Value dari ptrX : " << ptrX << ", sama dengan x : " << &x << endl;
	 cout << "Value dari ptrX : " << ptrY << ", sama dengan x : " << &x << endl;
	 cout << endl;
	 
	 cout << "Nilai yang ditunjuk ptrX : " << *ptrX << ", sama dengan nilai x : " << x << endl;
	 cout << "Nilai yang ditunjuk ptrY : " << *ptrY << ", sama dengan nilai x : " << x << endl;
	 cout << "Praditus Egi Danuarta - 22.11.4662" << endl;
}
