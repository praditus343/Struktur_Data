#include <iostream>
#include <ctime>

using namespace std;

const int MAX_SIZE = 100;

// Define struct to store IPK value
struct Student {
    double ipk;
};

// Function prototypes
void init_data(Student[], int);
void view_data(Student[], int);
void bubble_sort(Student[], int);
double find_nth_highest_ipk(Student[], int, int);

int main() {
    int n = 10; // jumlah data awal
    int k = 3; // pencarian nilai tertinggi ke-k
    
    Student students[MAX_SIZE]; // inisialisasi array untuk menyimpan data IPK
    
    // inisialisasi nilai IPK secara acak
    init_data(students, n);
    
    cout << "Data awal:\n";
    view_data(students, n);
    
    // sorting data menggunakan bubble sort
    bubble_sort(students, n);
    
    cout << "\nData terurut:\n";
    view_data(students, n);
    
    // mencari nilai IPK tertinggi ke-k
    double highest_k = find_nth_highest_ipk(students, n, k);
    
    cout << "\nIPK tertinggi ke-" << k << " adalah " << highest_k << endl;
    
    return 0;
}

// Function to initialize IPK value randomly
void init_data(Student students[], int n) {
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        students[i].ipk = rand() % 40 / 10.0; // nilai IPK antara 0-4.0
    }
}

// Function to display IPK value
void view_data(Student students[], int n) {
    for(int i = 0; i < n; i++) {
        cout << students[i].ipk << " ";
    }
    cout << endl;
}

// Bubble Sort function to sort IPK values
void bubble_sort(Student students[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(students[j].ipk < students[j+1].ipk) {
                // swap data
                Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
}

// Function to find the nth highest IPK value
double find_nth_highest_ipk(Student students[], int n, int k) {
    if(k > n) {
        cout << "Tidak bisa mencari IPK tertinggi ke-" << k << ". Hanya ada " << n << " data." << endl;
        return 0;
    }
    return students[k-1].ipk;
}

