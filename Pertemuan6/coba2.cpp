#include <iostream>
using namespace std;

int main(){
	//x adl nilai yg akan dicari
	int m, x=5;
	int arr[]={1, 2, 5, 7, 8, 9, 9, 11, 15, 16, 20};
	int l={0};
	int r={10};
	
	//proses pencarian dengan binary search
	bool found={false};
	while(l <= r && !found){
		m = l + (r - 1) / 2;
		
		if(x == arr[m]){
			found = true;
			cout << "Data ditemukan di indeks ke-" << m;
		}
		
		if(x < arr[m]) r = m - 1;
		else if(x > arr[m]) l = m + 1;
	}
}
