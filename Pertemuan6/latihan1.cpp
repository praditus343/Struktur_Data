#include <iostream>
using namespace std;

int main(){
	
	int x=3; //nilai yg akan dicari
	int arr[]{5,9,2,7,8,1,6};
	
	//proses pencarian data secara linier :
	bool found{false};
	for(int i = 0; i< 7; i++) {
		if (x == arr[i]){
			found = true;
			cout << "Data ditemukan di indeks ke-" << i;
			break;
		} 
			
		if (found == false) {
				cout << " " << endl;
			cout << "Data tidak ditemukan!" << endl;
			break;
		}
	}
	cout << "\n\nPraditus Egi Danuarta - 22.11.4662";
}
