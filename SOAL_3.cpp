/*
NMata Kuliah    : Algoritma Pemrograman
Nama Mahasiswa  : Pajri Zahrawaani Ahmad
NIM             : 230401010279
SOAL            :  Buatlah program untuk menghitung total pembayaran dari sebuah penjualan agen susu di kota besar (Ketentuan di soal)*/
#include <iostream>
#include <map>
using namespace std;

map<string,map<int,int>> brandInfo={
    {"A",{{1,15000},{2,20000},{3,25000}}},
    {"B",{{1,13500},{2,17500},{3,20000}}},
    {"C",{{1,15000},{2,18500},{3,22000}}}
};

void itung(){
    string jenis;
    int size, jml;

    cout<<"Masukkan Jenis Susu\t: ";cin>>jenis;
    if (brandInfo.find(jenis) == brandInfo.end()) {
        cout<<"\n\nJenis susu tidak ditemukan.\n"<<endl;
        return;
    }

    cout<<"Masukkan Ukuran Kaleng\t: ";cin>>size;
    if (brandInfo[jenis].find(size) == brandInfo[jenis].end()) {
        cout<<"Size tidak ditemukan.\n";
        return;
    }

    cout<<"Harga Satuan Barang\t: Rp."<<brandInfo[jenis][size]<<endl;
    cout<<"Jumlah Yang Diberi\t: ";cin>>jml;

    cout<<"\nHarga Yang Harus Dibayar Sebesar Rp. "<<brandInfo[jenis][size]*jml<<endl;
}


int main(){
    string yesno;

    do{
        cout<<"\n--------------------------"<<endl;
        cout<<"TOKO KELONTONG KERONCONGAN"<<endl;
        cout<<"--------------------------"<<endl;
        cout<<"A. Susu Dancow"<<endl;
        cout<<"   1. Ukuran Kecil"<<endl;
        cout<<"   2. Ukuran Sedang"<<endl;
        cout<<"   3. Ukuran Besar"<<endl;
        cout<<"B. Susu Bendera"<<endl;
        cout<<"   1. Ukuran Kecil"<<endl;
        cout<<"   2. Ukuran Sedang"<<endl;
        cout<<"   3. Ukuran Besar"<<endl;
        cout<<"C. Susu SGM"<<endl;
        cout<<"   1. Ukuran Kecil"<<endl;
        cout<<"   2. Ukuran Sedang"<<endl;
        cout<<"   3. Ukuran Besar"<<endl;
        cout<<"--------------------------"<<endl;

        itung();

        cout<<"Ingin Itung transaksi lainnya? (Y/N): ";
        cin>>yesno;
        if (yesno != "Y" && yesno != "y") {
            cout << "\nTerima kasih!\n" << endl;
            break;
        }
    } while (yesno == "Y" || yesno == "y");

    return 0;
}