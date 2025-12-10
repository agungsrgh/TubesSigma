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
    r->next = nullptr;
    r->prev = nullptr;
    return r;
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
        }
        temp->next = q;
        q->prev = temp;
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

void displaySemuaBlok(listBlok L){
    adrBlok p = L.first;
    while(p != nullptr){
        cout << "====" << p->info.namaBlok << "====" << endl;
        cout << "Tipe Rumah : " << p->info.jenisTipeRumah << endl;
        cout << "Jumlah Rumah : " << p->info.jumlahRumah << endl;
        p = p->next;
    }
}

void displayRumahDalamBlok(listBlok L, string nama){
    adrBlok p = cariBlok(L,nama);
    if (p == nullptr){
        cout << "Block tidak ditemukan ! " << endl ;
        return ;
    }

    adrRumah q = p->firstRumah;
    if(q == nullptr){
        cout << " Rumah tidak ditemukan " << endl;
        return ;
    }
     while(q != nullptr){
            cout << "-" << q->info.nomorRumah;
            cout << "| Pemilik : " << q->info.namaPemilik;
            cout << "| Status : " << q->info.statusKepemilikan;
            cout << "| Luas : " << q->info.luasTanah << "m2" << endl;
        }
        cout << endl;
        q = q->next;
}
    
void displayDetailBlok(listBlok L, string nama){
    adrBlok p = cariBlok(L, nama);
    if(p == nullptr){
        cout << "Blok Tidak Ditemukan!" << endl;
        return; 
    }

    cout << "=== DETAIL " << p->info.namaBlok << "===" << endl;
    cout << "Tipe Rumah : " << p->info.jenisTipeRumah << endl;
    cout << "Jumlah Rumah : " << p->info.jumlahRumah << endl;
    displayRumahDalamBlok(p);
}

// Untuk hapus Blok dan Rumah
void hapusBlok(listBlok &L, string nama){

    adrBlok p = cariBlok(L, nama);

    if(p == nullptr){
        cout << "Blok tidak ditemukan!\n";
        return;
    }

   
    if(L.first == p && L.last == p){
        L.first = L.last = nullptr;
    }
   
    else if(p == L.first){
        L.first = p->next;
        L.first->prev = nullptr;
    }
    
    else if(p == L.last){
        L.last = p->prev;
        L.last->next = nullptr;
    }
    
    else{
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }
    p->prev = nullptr;
    p->next = nullptr;
   

    cout << "Blok berhasil dihapus.\n";
}

void hapusRumah(adrBlok &p, string nomor){
  adrRumah r  = cariRumah(p, nomor);  

  if (r == nullptr){
    cout << " Rumah tidak ditemukan !";
    return;
  }

  if ( r == p->firstRumah){
    p->firstRumah = r->next;
        if(r->next != nullptr){
            r->next->prev = nullptr;
        }
  }else{
    r->prev->next = r->next;
    if(r->next != nullptr){
        r->next->prev = r->prev;

    }
  }
  r->next = nullptr;
  r->prev = nullptr;
  
  p->info.jumlahRumah--;
  cout << "Rumah berhasil dihapus.\n";

}
// untuk Update Data Blok dan Rumah
void updateDataBlok(adrBlok &p);
void updateDataRumah(adrRumah &r);

// Sorting Rumah per blok berdasarkan luas tanah atau jumlah penghuni
void sortRumahByLuasAsc(adrBlok blok);
void sortRumahByLuasDesc(adrBlok blok);

void sortRumahByPenghuniAsc(adrBlok blok);
void sortRumahByPenghuniDesc(adrBlok blok);

// Statistik
int totalBlok(listBlok L);
int totalRumah(listBlok L);
