
#include <iostream>
using namespace std;

int main() {
	cout << "\n\nPraditus Egi Danuarta - 22.11.4662" << endl;
	cout << "Data yang tersimpan : " << endl;
	cout << "1	2	5	7	8	9	11	13	15	16 " << endl;
	//x adl nilai yang akan dicari
	int m, x;
	int arr[]{1,2,5,7,8,9,9,11,15,16,20};
	int l{0};
	int r{10};
	char yesNo;
	menu:
	cout << "Masukan nilai yang ingin dicari : ";
	cin >> x;
	
	//Proses pencarian dengan binary search :
	bool found{false};
	while (l <= r && !found) {
		m = l + (r - l) / 2;
		
		if (x == arr[m]) {
			found = true;
			cout << "Data ditemukan di indeks ke-" << m;
			cout << "\n\nApakah ingin mencari lagi? (y/n) : ";
			cin >> yesNo;
			
			if (yesNo == 'Y' || yesNo == 'y') {
				found = false;
				goto menu;
			}
			
		}
		
		if (x < arr[m]) r = m - 1;
		else if (x > arr[m]) l = m + 1;
	}
	
	if (found == false) {
		found = false;
		cout << "Data tidak ditemukan!" << endl;
		cout << "\n\nApakah ingin mencari lagi? (y/n) : ";
		cin >> yesNo;
			
		if (yesNo == 'Y' || yesNo == 'y') {
			goto menu;
			found = false;
		}
	}
	
	cout << "\n\nPraditus Egi Danuarta - 22.11.4662";
}
