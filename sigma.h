#ifndef SIGMA_H_INCLUDED
#define SIGMA_H_INCLUDED
#include <iostream>
using namespace std;

struct elemenBlok;
struct elemenRumah;

typedef elemenBlok* adrBlok;
typedef elemenRumah* adrRumah;

struct infoBlok{
    string namaBlok;
    string jenisTipeRumah;
    int jumlahRumah;
};

struct infoRumah{
    string nomorRumah;
    string namaPemilik;
    string statusKepemilikan;
    int luasTanah;
    int jumlahPenghuni;
};

struct elemenBlok{
    infoBlok info;
    adrBlok next;
    adrBlok prev;
    adrRumah firstRumah;
};

struct elemenRumah{
    infoRumah info;
    adrRumah next;
    adrRumah prev;
};

struct listBlok{
    adrBlok first;
    adrBlok last;
};

// utility untuk Insert Blok dan Rumah
void createListBlok(listBlok &L);
adrBlok createElementBlok(string nama, string tipe);
adrRumah createElementRumah(string nomor, string pemilik, string status, int luas, int penghuni);
bool isEmptyBlok(listBlok L);
bool isEmptyRumah(adrBlok p);

// untuk insert Blok dan Rumah
void tambahBlok(listBlok &L, adrBlok p);
void tambahRumah(adrBlok &p, adrRumah q);

// utility untuk Delete Rumah atau Block
adrBlok cariBlok(listBlok L, string namaBlok);
adrRumah cariRumah(adrBlok p, string nomor);

// untuk menampilkan Detail Blok atau Rumah
void displaySemuaBlok(listBlok L);
void displayRumahDalamBlok(adrBlok p, string nama);
void displayDetailBlok(listBlok L, string nama);

// Untuk hapus Blok dan Rumah
void hapusBlok(listBlok &L, string nama);
void hapusRumah(adrBlok &p, string nomor);

// untuk Update Data Blok dan Rumah
void updateDataBlok(adrBlok &p);
void updateDataRumah(adrRumah &r);

// Sorting Blok berdasarkan jumlah rumah
void sortBlokByJumlahRumahAsc(listBlok &L);
void sortBlokByJumlahRumahDesc(listBlok &L);

// Sorting Rumah per blok berdasarkan luas tanah atau jumlah penghuni
void sortRumahByLuasAsc(adrBlok blok);
void sortRumahByLuasDesc(adrBlok blok);

void sortRumahByPenghuniAsc(adrBlok blok);
void sortRumahByPenghuniDesc(adrBlok blok);


// Statistik
int totalBlok(listBlok L);
int totalRumah(listBlok L);

//UI
void tampilkanList();
void goodbyeThankYou();

// main



#endif // SIGMA_H_INCLUDED