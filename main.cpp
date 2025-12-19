#include "sigma.h"
#include <iostream>
using namespace std;

int main(){
    listBlok L;
    createListBlok(L);

    int pilih;
    do{
        tampilkanList();
        cin >> pilih;

        if(pilih == 1){
            string nama, tipe;
            cout << "Nama Blok (tanpa spasi): ";
            cin >> nama;
            cout << "Jenis Tipe Rumah: ";
            cin >> tipe;

            if(cariBlok(L, nama) != nullptr){
                cout << "Blok sudah ada!\n";
            }else{
                adrBlok p = createElementBlok(nama, tipe);
                tambahBlok(L, p);
                cout << "Blok berhasil ditambahkan.\n";
            }

        }else if(pilih == 2){
            string namaBlok, nomor, pemilik, status;
            int luas, penghuni;

            cout << "Nama Blok: ";
            cin >> namaBlok;

            adrBlok p = cariBlok(L, namaBlok);
            if(p == nullptr){
                cout << "Blok tidak ditemukan!\n";
            }else{
                cout << "Nomor Rumah: ";
                cin >> nomor;
                cout << "Nama Pemilik: ";
                cin >> pemilik;
                cout << "Status (Lunas/KPR): ";
                cin >> status;
                cout << "Luas Tanah: ";
                cin >> luas;
                cout << "Jumlah Penghuni: ";
                cin >> penghuni;

                adrRumah r = createElementRumah(nomor, pemilik, status, luas, penghuni);
                tambahRumah(p, r);
                cout << "Rumah berhasil ditambahkan.\n";
            }

        }else if(pilih == 3){
            displaySemuaBlok(L);

        }else if(pilih == 4){
            string nama;
            cout << "Nama Blok: ";
            cin >> nama;
            adrBlok p = cariBlok(L, nama);
            displayRumahDalamBlok(p);

        }else if(pilih == 5){
            string nama;
            cout << "Nama Blok: ";
            cin >> nama;
            hapusBlok(L, nama);

        }else if(pilih == 6){
            string namaBlok, nomor;
            cout << "Nama Blok: ";
            cin >> namaBlok;
            adrBlok p = cariBlok(L, namaBlok);

            if(p == nullptr){
                cout << "Blok tidak ditemukan!\n";
            }else{
                cout << "Nomor Rumah: ";
                cin >> nomor;
                hapusRumah(p, nomor);
            }

        }else if(pilih == 7){
            string nama;
            cout << "Nama Blok: ";
            cin >> nama;
            adrBlok p = cariBlok(L, nama);
            if(p == nullptr){
                cout << "Blok tidak ditemukan!\n";
            }else{
                updateDataBlok(p);
            }

        }else if(pilih == 8){
            string namaBlok, nomor;
            cout << "Nama Blok: ";
            cin >> namaBlok;
            adrBlok p = cariBlok(L, namaBlok);

            if(p == nullptr){
                cout << "Blok tidak ditemukan!\n";
            }else{
                cout << "Nomor Rumah: ";
                cin >> nomor;
                adrRumah r = cariRumah(p, nomor);
                if(r == nullptr){
                    cout << "Rumah tidak ditemukan!\n";
                }else{
                    updateDataRumah(r);
                }
            }

        }else if(pilih == 9){
            string nama;
            cout << "Nama Blok: ";
            cin >> nama;
            displayDetailBlok(L, nama);

        }else if(pilih == 10){
            string namaBlok, nomor;
            cout << "Nama Blok: ";
            cin >> namaBlok;
            adrBlok p = cariBlok(L, namaBlok);

            if(p == nullptr){
                cout << "Blok tidak ditemukan!\n";
            }else{
                cout << "Nomor Rumah: ";
                cin >> nomor;
                adrRumah r = cariRumah(p, nomor);
                if(r == nullptr){
                    cout << "Rumah tidak ditemukan!\n";
                }else{
                    cout << "Pemilik: " << r->info.namaPemilik << endl;
                    cout << "Status: " << r->info.statusKepemilikan << endl;
                    cout << "Luas: " << r->info.luasTanah << endl;
                    cout << "Penghuni: " << r->info.jumlahPenghuni << endl;
                }
            }

        }else if(pilih == 11){
            int s;
            cout << "1. Ascending\n2. Descending\nPilih: ";
            cin >> s;
            if(s == 1) sortBlokByJumlahRumahAsc(L);
            else sortBlokByJumlahRumahDesc(L);

        }else if(pilih == 12){
            string nama;
            int s;
            cout << "Nama Blok: ";
            cin >> nama;
            adrBlok p = cariBlok(L, nama);

            if(p == nullptr){
                cout << "Blok tidak ditemukan!\n";
            }else{
                cout << "1. Luas Asc\n2. Luas Desc\n3. Penghuni Asc\n4. Penghuni Desc\nPilih: ";
                cin >> s;

                if(s == 1){
                    sortRumahByLuasAsc(p);
                    displayRumahDalamBlok(p);
                }else if(s == 2){
                    sortRumahByLuasDesc(p);
                    displayRumahDalamBlok(p);
                }else if(s == 3){
                    sortRumahByPenghuniAsc(p);
                    displayRumahDalamBlok(p);
                }else if(s == 4){
                    sortRumahByPenghuniDesc(p);
                    displayRumahDalamBlok(p);
                }
            }

        }else if(pilih == 13){
            cout << "Total Blok: " << totalBlok(L) << endl;

        }else if(pilih == 14){
            cout << "Total Rumah: " << totalRumah(L) << endl;

        }

    }while(pilih != 15);

    goodbyeThankYou();
    return 0;
}
