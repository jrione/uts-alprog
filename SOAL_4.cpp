/*
NMata Kuliah    : Algoritma Pemrograman
Nama Mahasiswa  : Pajri Zahrawaani Ahmad
NIM             : 230401010279
SOAL            : Buatlah program untuk menghitung perkalian nilai kolom dengan baris.
berikut tampilan keluaran yang diinginkan:
1       2       3       4       5
2       4       6       8       10
3       6       9       12      15
4       8       12      16      20
5       10      15      20      25
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int baris= 5, kolom= 5;
    vector<vector<int>> table(baris, vector<int>(kolom));

    for (int i = 0; i<baris; i++) {
        for (int j=0; j<kolom; j++) { 
            table[i][j]=(i+1)*(j+1); 
            cout<<table[i][j]<<"\t";
        }
        cout<<endl;
    }
}