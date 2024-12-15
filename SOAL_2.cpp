/*
Mata Kuliah    : Algoritma Pemrograman
Nama Mahasiswa  : Pajri Zahrawaani Ahmad
NIM             : 230401010279
SOAL            : Buatlah program untuk menghitung total pembayaran Honor karyawan PT. DINGIN DAMAI (Ketentuan di soal)
*/
#include <iostream>
#include <map>
using namespace std;

struct TP {
    int kode;
    double persentase;
};

struct Honor{
    int honorTetap = 3500000;
    int tunJab;
    int tunPen;
    int overtime;
};

struct employeeData{
    string name;
    int gol;
    string school;
    int workHour;
    Honor honor;
};

map<int, float> tunjangan_jabatan = {
    {1,5.0},
    {2,10.0},
    {3,15.0}
};

map<string,TP> tunjangan_pendidikan = {
    {"SMA",{1,2.5}},
    {"D3",{2,5.0}},
    {"S1",{3,7.5}}
};

void generateEmployeeHonor(employeeData* dk){
    //perhitungan lembur
    int normalWorkHour = 8 * 22; // 8 jam x jumlah hari kerja
    int ovtH = max(0, dk->workHour - normalWorkHour);
    dk->honor.overtime = ovtH * 12500;

    //perhitungan tunjangan
    auto jabat_percent = tunjangan_jabatan.find(dk->gol);
    auto didik_percent = tunjangan_pendidikan.find(dk->school);

    if ( jabat_percent != tunjangan_jabatan.end() ){
        dk->honor.tunJab= (jabat_percent->second / 100) * dk->honor.honorTetap;
    }
    else {
        cout << "Golongan "<<dk->gol<<" tidak tersedia!"<<endl;
        return;
    }

    if (didik_percent != tunjangan_pendidikan.end()){
        dk->honor.tunPen= (didik_percent->second.persentase / 100)* dk->honor.honorTetap;
    } 
    else {
        cout << "Pendidikan "<<dk->school<<" tidak tersedia!"<<endl;
        return;
    }

    cout<<"\n\n==================================="<<endl;
    cout<<"Karyawan yang bernama\t: "<<dk->name<<endl<<endl;
    cout<<"Honor yang diterima"<<endl;
    cout<<"Honor Tetap\t\t: Rp. "<<dk->honor.honorTetap<<endl;
    cout<<"Tunjangan Jabatan\t: Rp. "<<dk->honor.tunJab<<endl;
    cout<<"Tunjangan Pendidikan\t: Rp. "<<dk->honor.tunPen<<endl;
    cout<<"*Tunjangan Lembur\t: Rp. "<<dk->honor.overtime<<endl;
    cout<<"--------------------------------------+:"<<endl;
    cout<<"Honor Yang DIterima\t: Rp. "<<(dk->honor.honorTetap + dk->honor.tunJab + dk->honor.tunPen + dk->honor.overtime)<<endl;
    cout<<"\n\n==================================="<<endl;
    cout<<"*Note: Perhitungan kerja berdasarkan perkalian antara jam kerja (8) dengan jumlah hari kerja (22) ditambah lembur"<<endl;
    cout<<"==================================="<<endl;
}

int main(){
    employeeData* data = new employeeData;
    string yesno;

    while(true){
        cout<<"\n\nProgram Hitung Honor Karyawan Kontrak PT. DINGIN DAMAI"<<endl;
        cout<<"Nama Karyawan\t\t: ";
        cin.ignore();
        getline(cin, data->name);
        cout<<"Golongan\t\t: ";
        cin>>data->gol;
        cout<<"Pendidikan (SMA/D3/S1)\t: ";
        cin>>data->school;
        cout<<"Jumlah Jam Kerja\t: ";
        cin>>data->workHour;
        cout<<"\n\n";
        
        generateEmployeeHonor(data);

        cout << "Apakah ingin mengulang program? (Y/N): ";
        cin >> yesno;
        if (yesno != "Y" && yesno != "y") {
            cout << "\nTerima kasih!\n" << endl;
            break;
        }
    }
    
    delete data;
    return 0;
}