#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Petshop
{
private:
    string id;       // id barang
    string nama;     // nama barang
    string kategori; // kategori barang
    int harga;       // harga barang

public:
    // constructor
    Petshop()
    {
        id = "";
        nama = "";
        kategori = "";
        harga = 0;
    }

    // constructor
    Petshop(string ID, string nm, string kt, int hg)
    {
        id = ID;
        nama = nm;
        kategori = kt;
        harga = hg;
    }

    // setter
    void setID(string ID)
    {
        id = ID;
    }

    void setNama(string nm)
    {
        nama = nm;
    }

    void setKategori(string kt)
    {
        kategori = kt;
    }

    void setHarga(int hg)
    {
        harga = hg;
    }

    // getter
    string getID()
    {
        return id;
    }

    string getNama()
    {
        return nama;
    }

    string getKategori()
    {
        return kategori;
    }

    int getHarga()
    {
        return harga;
    }
    ~Petshop() {} // destructor
};
