#include <iostream>
#include <cstring> 
using namespace std;

int main () 
{
    char word[100];
    int cek = 0;
    

    cout << "\nMasukkan kata\t: ";
	cin.getline(word, 100);
    

    int length = strlen(word);
	cout << endl;
    
    cout << "Kata asli\t\t: " << word << endl;
	

    cout << "Kata dibalik\t\t: ";
	
    char *x = word + length - 1; 
    while (x >= word) 
	{
        cout << *x;
        x--;
    }
	
    for(int i=0; i < length ;i++) {
        if(word[i] != word[length-i-1]) 
		{ 
            cek = 1; 
            break;
        }
    }
    
    cout << endl << endl;
    
    if (cek) {
        cout << word << " bukan palindrome karenah apabila dibaca dari kiri atau kanan tidak menghasilkan kata yang sama" << endl; 
    }    
    else {
        cout << word << " adalah palindrome karenah apabila dibaca dari kiri atau kanan akan menghasilkan kata yang sama" << endl; 
    }
    
    cout << "\nPraditus Egi Danuarta - 22.11.4662" << endl << endl;
    system("pause");
    return 0;
}
