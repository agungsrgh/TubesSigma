#include "sigma.h"
#include <iostream>
using namespace std;

void createListBlok(listBlok &L){
    L.first = nullptr;
    L.last = nullptr;
}

adrBlok createElementBlok(string nama, string tipe){
    adrBlok p = new elemenBlok;
    p->info.namaBlok = nama;
    p->info.jenisTipeRumah = tipe;
    p->info.jumlahRumah = 0;
    p->next = p->prev = nullptr;
    p->firstRumah = nullptr;
    return p;
}

adrRumah createElementRumah(string nomor, string pemilik, string status, int luas){
    adrRumah r = new elemenRumah;
    r->info.nomorRumah = nomor;
    r->info.namaPemilik = pemilik;
    r->info.statusKepemilikan = status;
    r->info.luasTanah = luas;

}

bool isEmptyBlok(listBlok L){
    return L.first == nullptr;
}

bool isEmptyRumah(adrBlok p){
    return p->firstRumah == nullptr;
}

void tambahBlok(listBlok &L, adrBlok p){
    if(isEmptyBlok(L)){
        L.first = L.last = p;
    }else{
        L.last->next = p;
        p->prev = L.last;
        L.last = p;
    }
}

void tambahRumah(adrBlok &p, adrRumah q){
    if(isEmptyRumah(p)){
        p->firstRumah = q;
    }else{
        adrRumah temp = p->firstRumah;
        while(temp->next != nullptr){
            temp = temp->next;
            temp->next = q;
            q->prev = temp;
        }
    }
    p->info.jumlahRumah++;
}

adrBlok cariBlok(listBlok L, string namaBlok){
    adrBlok p = L.first;
    while(p != nullptr){
        if(p->info.namaBlok == namaBlok){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

adrRumah cariRumah(adrBlok p, string nomor){
    adrRumah q = p->firstRumah;
    while(q != nullptr){
        if(q->info.nomorRumah == nomor){
            return q;
        }
        q = q->next;
    }
    return nullptr;
}

void display(listBlok L){
    adrBlok p = L.first;
    while(p != nullptr){
        cout << "====" << p->info.namaBlok << "====" << endl;
        cout << "Tipe Rumah : " << p->info.jenisTipeRumah << endl;
        cout << "Jumlah Rumah : " << p->info.jumlahRumah << endl;
        cout << "Daftar Rumah : " << endl;

        adrRumah q = p->firstRumah;
        if(q == nullptr){
            cout << "Kosong";
        }else{
            while( q != nullptr){
                cout << q->info.nomorRumah;
                if(q->next != nullptr){
                    cout << ", ";
                }
                q = q->next;
            }
            cout << ", ";
        }
        cout << endl;
        p = p->next;
    }
}

void displayDetailBlok(listBlok L, string nama){
    adrBlok p = cariBlok(L, nama);
    if(p == nullptr){
        cout << "Blok Tidak Ditemukan!" << endl;
    }

    cout << "====" << p->info.namaBlok << "====" << endl;
    cout << "Tipe Rumah : " << p->info.jenisTipeRumah << endl;
    cout << "Jumlah Rumah : " << p->info.jumlahRumah << endl;
    cout << "Daftar Rumah : " << endl;

    adrRumah q = p->firstRumah;
    if(q == nullptr){
        cout << "Belum Ada Rumah" << endl;
    }else{
        while(q != nullptr){
            cout << "-" << q->info.nomorRumah;
            cout << "| Pemilik : " << q->info.namaPemilik;
            cout << "| Status : " << q->info.statusKepemilikan;
            cout << "| Luas : " << q->info.luasTanah << "m2" << endl;
        }
        cout << endl;
        q = q->next;
    }
}

void hapusBlok(listBlok &L, string nama){

}

void hapusRumah(adrBlok &p, string nomor){

}

void editDataBlok(adrBlok &p)

void editDataRumah(adrRumah &r)

void PembayaranIuran(adrRumah &r, int bulan, int jumlah)

int hitungRumahKosong(adrBlok p)

int TotalLuasTanah(adrBlok p)

adrRumah cariLuasTerbesar(listBlok L)

adrRumah laporanTunggakanTerbesar(listBlok L)

int TotalSemuaRumah(listBlok L)
