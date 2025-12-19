#include "sigma.h"
#include <iostream>
using namespace std;

int main(){
    listBlok L;
    createListBlok(L);

    int pilihan;
    string namaBlok, tipe;
    string nomor, pemilik, status;
    int luas, penghuni;

    do{
        tampilkanList();
        cin >> pilihan;
        cout << endl;

        switch(pilihan){

        // ================= INPUT BLOK =================
        case 1:{
            cout << "=== INPUT BLOCK DATA ===\n";
            cout << "Nama Blok      : ";
            cin >> namaBlok;
            cout << "Tipe Rumah     : ";
            cin >> tipe;

            adrBlok p = createElementBlok(namaBlok, tipe);
            tambahBlok(L, p);

            cout << "Blok berhasil ditambahkan!\n\n";
            break;
        }

        // ================= INPUT RUMAH =================
        case 2:{
            cout << "=== INPUT HOUSE DATA ===\n";
            cout << "Nama Blok      : ";
            cin >> namaBlok;

            adrBlok p = cariBlok(L, namaBlok);
            if(p == nullptr){
                cout << "Blok tidak ditemukan!\n\n";
                break;
            }

            cout << "Nomor Rumah    : ";
            cin >> nomor;
            cout << "Nama Pemilik   : ";
            cin >> pemilik;
            cout << "Status Rumah   : ";
            cin >> status;
            cout << "Luas Tanah     : ";
            cin >> luas;
            cout << "Jumlah Penghuni: ";
            cin >> penghuni;

            adrRumah r = createElementRumah(nomor, pemilik, status, luas, penghuni);
            tambahRumah(p, r);

            cout << "Rumah berhasil ditambahkan!\n\n";
            break;
        }

        // ================= VIEW BLOK =================
        case 3:
            cout << "=== DAFTAR BLOK ===\n";
            displaySemuaBlok(L);
            cout << endl;
            break;

        // ================= VIEW RUMAH =================
        case 4:
            cout << "Nama Blok : ";
            cin >> namaBlok;
            displayRumahDalamBlok(L, namaBlok);
            cout << endl;
            break;

        // ================= DELETE BLOK =================
        case 5:
            cout << "Nama Blok : ";
            cin >> namaBlok;
            hapusBlok(L, namaBlok);
            cout << endl;
            break;

        // ================= DELETE RUMAH =================
        case 6:{
            cout << "Nama Blok : ";
            cin >> namaBlok;
            adrBlok p = cariBlok(L, namaBlok);
            if(p == nullptr){
                cout << "Blok tidak ditemukan!\n\n";
                break;
            }
            cout << "Nomor Rumah : ";
            cin >> nomor;
            hapusRumah(p, nomor);
            cout << endl;
            break;
        }

        // ================= UPDATE BLOK =================
        case 7:{
            cout << "Nama Blok : ";
            cin >> namaBlok;
            adrBlok p = cariBlok(L, namaBlok);
            if(p != nullptr){
                updateDataBlok(p);
                cout << "Data blok diperbarui!\n\n";
            }else{
                cout << "Blok tidak ditemukan!\n\n";
            }
            break;
        }

        // ================= UPDATE RUMAH =================
        case 8:{
            cout << "Nama Blok : ";
            cin >> namaBlok;
            adrBlok p = cariBlok(L, namaBlok);
            if(p == nullptr){
                cout << "Blok tidak ditemukan!\n\n";
                break;
            }
            cout << "Nomor Rumah : ";
            cin >> nomor;
            adrRumah r = cariRumah(p, nomor);
            if(r != nullptr){
                updateDataRumah(r);
            }else{
                cout << "Rumah tidak ditemukan!\n";
            }
            cout << endl;
            break;
        }

        // ================= SORT BLOK =================
        case 11:{
            int pilih;
            cout << "=== SORT BLOK (Jumlah Rumah) ===\n";
            cout << "1. Ascending\n";
            cout << "2. Descending\n";
            cout << "Pilih : ";
            cin >> pilih;

            if(pilih == 1)
                sortBlokByJumlahRumahAsc(L);
            else if(pilih == 2)
                sortBlokByJumlahRumahDesc(L);
            else{
                cout << "Pilihan tidak valid!\n\n";
                break;
            }

            cout << "\nHASIL SORTING BLOK:\n";
            displaySemuaBlok(L);
            cout << endl;
            break;
        }

        // ================= SORT RUMAH =================
        case 12:{
            int data, arah;
            cout << "Nama Blok : ";
            cin >> namaBlok;
            adrBlok p = cariBlok(L, namaBlok);
            if(p == nullptr){
                cout << "Blok tidak ditemukan!\n\n";
                break;
            }

            cout << "\n1. Luas Tanah\n";
            cout << "2. Jumlah Penghuni\n";
            cout << "Pilih : ";
            cin >> data;

            cout << "\n1. Ascending\n";
            cout << "2. Descending\n";
            cout << "Pilih : ";
            cin >> arah;

            if(data == 1){
                if(arah == 1) sortRumahByLuasAsc(p);
                else sortRumahByLuasDesc(p);
            }
            else if(data == 2){
                if(arah == 1) sortRumahByPenghuniAsc(p);
                else sortRumahByPenghuniDesc(p);
            }
            else{
                cout << "Pilihan tidak valid!\n\n";
                break;
            }

            cout << "\nHASIL SORTING RUMAH:\n";
            displayRumahDalamBlok(L, namaBlok);
            cout << endl;
            break;
        }

        // ================= STATISTIK =================
        case 13:
            cout << "Total Blok  : " << totalBlok(L) << endl << endl;
            break;

        case 14:
            cout << "Total Rumah: " << totalRumah(L) << endl << endl;
            break;

        case 15:
            goodbyeThankYou();
            break;

        default:
            cout << "Pilihan tidak valid!\n\n";
        }

    }while(pilihan != 15);

    return 0;
}
