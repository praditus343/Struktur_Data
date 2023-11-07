#include <iostream>

using namespace std;

int main(){
	int x = 100, y = 130, z; // deklrasi var non pointer
	
	int *ptrX, *ptrY; // deklarasi var pointer
	
	//TODO : tampilkan nilai x dan y
	cout << "Nilai dari x : " << x << ", Nilai dari y : " << y << endl << endl;
	
	//TODO : tampilkan alamat x dan y
	cout << "Alamat dari x : " << &x << " , Nilai dari y : " << &y << endl << endl;;
	
	ptrX = &x; // ptrX menunjuk alamat x
	// TODO : tampilkan nilai ptrX dan *ptrX;
	cout << "Nilai dari ptrX : " << ptrX << ", Nilai dari *ptrX : " << *ptrX << endl <<endl;;
	
	ptrY = &y; // ptrY menunjuk alamat y
	// TODO : tampilkan nilai ptrY dan *ptrY
	cout << "Nilai dari ptrY : " << ptrY << ", Nilai dari *ptrY : " << *ptrY << endl << endl;;
	
	z = *ptrX; //z berisi nilai yang ditunjuk ptrX
	// TODO : tampilkan nilai z dan x
	cout << "Nilai dari z : " << z << ", Nilai dari x : " << x << endl << endl;
	
	*ptrY = 70; // merubah nilai yang ditunjuk ptrY
	//TODO : tampilkan nilai ptrY dan y
	cout << "Nilai dari ptrY : " << ptrY << ", Nilai dari y : " << y << endl << endl;
	
	*ptrX = *ptrY + 5;
	// TODO : tampilkan nilai ptrX dan x
	cout << "Nilai dari ptrX : " << ptrX << ", Nilai dari x : " << x << endl << endl;
	
	ptrX = ptrY; // ptrX menunjuk apa yang ditunjuk ptrY
	// TODO : tampilkan nilai ptrX dan ptrY
	cout << "Nilai dari ptrX : " << ptrX << ", Nilai dari ptrY : " << ptrY << endl << endl;
	//TODO tampilkan nilai *ptrX dan *ptrY
	cout << "Nilai dari *ptrX : " << *ptrX << ", Nilai dari *ptrY : " << *ptrY << endl << endl;
	
	cout << "Praditus Egi Danuarta - 22.11.4662" << endl;
	
	cout << endl << endl;
	system("pause");
	return 0;
}
