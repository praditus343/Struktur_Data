#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

const int UKURAN{25};
const int BUBBLE{0};
const int SELECTION{1};
const int INSERTION{2};
int nsrc[UKURAN];
int ndata[UKURAN];

void init_data();
void load_data();
void view_data();
void bubsort();
void selsort();
void inssort();
void run_sort(int);

int main(void) {
    cout << "\nPraditus Egi Danuarta - 22.11.4662" << endl;
    cout << "Perbandingan Metode Pengurutan\n";
    init_data();
    load_data();
    cout << "Data Acak:\n";
    view_data();
    cout << "\n\n";
    
    // Bubble Sort
    cout << "Bubble Sort\n";
    load_data();
    run_sort(BUBBLE);
    
    // Selection Sort
    cout << "Selection Sort\n";
    load_data();
    run_sort(SELECTION);
    
    // Insertion Sort
    load_data();
    cout << "Insertion Sort\n";
    run_sort(INSERTION);
    
    return 0;
}

void init_data() {
    srand(time(NULL));
    for(int i = 0; i < UKURAN; ++i) {
        nsrc[i] = rand() % 100;
    }
}

void load_data() {
    for(int i = 0; i < UKURAN; ++i) {
        ndata[i] = nsrc[i];
    }
}

void view_data() {
    for(int i = 0; i < UKURAN; ++i) {
        printf("%d ", ndata[i]);
    }
    cout << endl;
}

void bubsort() {
    for(int i = 0; i < UKURAN - 1; ++i) {
        for(int j = 0; j < UKURAN - i - 1; ++j) {
            if(ndata[j] > ndata[j + 1]) {
                int tmp = ndata[j];
                ndata[j] = ndata[j + 1];
                ndata[j + 1] = tmp;
                Sleep(10);
            }
            Sleep(10);
        }
        Sleep(10);
    }
}

void selsort() {
    for(int i = 0; i < UKURAN - 1; ++i) {
        int min = i;
        for(int j = i ; j < UKURAN; ++j) {
            if(ndata[j] < ndata[min]) {
                min = j;
                Sleep(10);
            }
            Sleep(10);
        }
        int tmp = ndata[i];
        ndata[i] = ndata[min];
        ndata[min] = tmp;
        Sleep(10);
    }
}

void inssort() {
    for(int i = 1; i < UKURAN; ++i) {
        int m = ndata[i];
        int s = i;
        while(s > 0 && m < ndata[s - 1]) {
            ndata[s] = ndata[--s];
            Sleep(10);
        }
        ndata[s] = m;
        Sleep(10);
    }
}

void run_sort(int m) {
    auto int t1 = time(NULL);
    switch(m) {
        case 0: bubsort(); break;
        case 1: selsort(); break;
        case 2:
        default: inssort(); break;
    }
    auto int t2 = time(NULL);
    auto int t = t2 - t1;
    cout << "data terurut:\n";
    view_data();
    cout << "waktu: " << t << " milisecond\n";
    cout << "---------------------------\n\n";
}
