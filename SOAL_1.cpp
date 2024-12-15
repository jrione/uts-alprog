/*
NMata Kuliah    : Algoritma Pemrograman
Nama Mahasiswa  : Pajri Zahrawaani Ahmad
NIM             : 230401010279
SOAL:           : Tentukan apa hasil numerik dari ekspresi relasi dan logika di bawah ini:
Diberikan nilai A = 3; B = 6 ; C = 2 ; K = 5; L = 4; M = 3
*/


#include <iostream>
#include <map>
using namespace std;

map<char,bool> jawaban;

int main(){
const int A=3, B=6, C=2, K=5, L=4, M=3;

jawaban['a'] = ( (4 + 2 > A) && (B - 2 > 3 + 2) ) || (B + 2 <= 6 + 2);
jawaban['b'] = ( K + 5 < M ) ||  (C * M < L ) && (2 * M - L < 0);
jawaban['c'] = (L + 5 < M) || ((C * K < L) && (2 * K - L > 0));
jawaban['d'] = (A * 4 <= 3 * M + B);
jawaban['e'] = (K + 10 > A) && (L - 2 > 4 * C);

cout<<"Hasil dari Soal 1.a yaitu: "<<jawaban['a']<<endl; 
cout<<"Hasil dari Soal 1.b yaitu: "<<jawaban['b']<<endl; 
cout<<"Hasil dari Soal 1.c yaitu: "<<jawaban['c']<<endl; 
cout<<"Hasil dari Soal 1.d yaitu: "<<jawaban['d']<<endl; 
cout<<"Hasil dari Soal 1.e yaitu: "<<jawaban['e']<<endl; 

}