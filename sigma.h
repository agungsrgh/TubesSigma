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
    int pembayaranIuran[12];
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

void createListBlok(listBlok &L);
adrBlok createElementBlok(string nama, string tipe);
adrRumah createElementRumah(string nomor, string pemilik, string status, int luas);
bool isEmptyBlok(listBlok L);
bool isEmptyRumah(adrBlok p);

void tambahBlok(listBlok &L, adrBlok p);
void tambahRumah(adrBlok &p, adrRumah q);
adrBlok cariBlok(listBlok L, string namaBlok);
adrRumah cariRumah(adrBlok p, string nomor);

void display(listBlok L);
void displayDetailBlok(listBlok L, string nama);

void hapusBlok(listBlok &L, string nama);
void hapusRumah(adrBlok &p, string nomor);
void editDataBlok(adrBlok &p);
void editDataRumah(adrRumah &r);

void PembayaranIuran(adrRumah &r, int bulan, int jumlah);

int hitungRumahKosong(adrBlok p);
int TotalLuasTanah(adrBlok p);
adrRumah cariLuasTerbesar(listBlok L);
adrRumah laporanTunggakanTerbesar(listBlok L);
int TotalSemuaRumah(listBlok L);

#endif // SIGMA_H_INCLUDED
