#include "Petshop.cpp"

using namespace std;

int main()
{
    Petshop PS; // objek temporary
    list<Petshop> L; // list

    int n = 0; // banyak data yang akan diinput
    int harga = 0; // atribut objek temporary
    string ID, nama, kategori;

    cout << "+----------------------------------+" << endl;
    cout << "|              Petshop             |" << endl;
    cout << "+----------------------------------+" << endl;

    // proses input data barang
    cout << "input item quantity: ";
    cin >> n;
    cout << "+----------------------------------+" << endl;
    cout << "input item(s):" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> ID >> nama >> kategori >> harga; // input atribut
        
        // set atribut objek dengan setter
        PS.setID(ID);
        PS.setNama(nama);
        PS.setKategori(kategori);
        PS.setHarga(harga);

        L.push_back(PS); // masukkan objek ke dalam list
    }
    cout << "+----------------------------------+" << endl << endl;

    // proses meminta command yang akan dijalankan
    cout << "input command: ";
    string command;
    cin >> command;
    while (command != "stop") // meminta command sampai menginput stop
    {
        string target;
        cout << "+------------------------------+" << endl;
        if (command == "show") // menampilkan seluruh data
        {
            cout << "| ID | Nama | Kategori | Harga |" << endl;
            cout << "+------------------------------+" << endl;
            // proses menampilkan seluruh elemen list
            for (list<Petshop>::iterator it = L.begin(); it != L.end(); ++it)
            {
                cout << it->getID() << " | " << it->getNama() << " | " << it->getKategori() << " | " << it->getHarga() << endl;
            }
        }
        else if (command == "add") // menambahkan data
        {
            cout << "input item: ";
            cin >> ID >> nama >> kategori >> harga;
            cout << "+------------------------------+" << endl;

            // set atribut objek dengan setter
            PS.setID(ID);
            PS.setNama(nama);
            PS.setKategori(kategori);
            PS.setHarga(harga);

            L.push_back(PS); // memasukkan objek ke dalam list
            cout << "item with ID " << ID << " added" << endl;
        }
        else if (command == "find") // mencari data berdasarkan nama barang
        {
            cout << "input item name: ";
            cin >> target;
            bool found = false;
            // proses mencari nama barang dalam list dan "menyimpan alamat" iterator
            list<Petshop>::iterator it = L.begin();
            while (it != L.end() && found == false)
            {
                if (it->getNama() == target)
                {
                    found = true;
                }
                else
                    it++;
            }

            cout << "+------------------------------+" << endl;
            // conditional message
            if (found == false)
            {
                cout << "item " << target << " not found" << endl;
            }
            else
            {
                cout << "item " << target << " found" << endl;
            }
        }
        else
        {
            // proses mengecek barang berdasarkan id barang 
            bool found = false;
            cout << "input item ID to check: ";
            cin >> target;
            cout << "+------------------------------+" << endl;

            // proses mencari id barang dalam list dan "menyimpan alamat" iterator
            list<Petshop>::iterator it = L.begin();
            while (it != L.end() && found == false)
            {
                if (it->getID() == target)
                {
                    found = true;
                }
                else
                    it++;
            }

            if (found == false)
            {
                cout << "item with ID " << target << " doesnt exist" << endl;
            }
            else
            {
                if (command == "update") // mengubah data
                {
                    cout << "edit to: ";
                    cin >> nama >> kategori >> harga;
                    cout << "+------------------------------+" << endl;
                    // set atribut dengan setter
                    it->setNama(nama);
                    it->setKategori(kategori);
                    it->setHarga(harga);
                    cout << "item with ID " << target << " updated" << endl;
                }
                else if (command == "delete") // menghapus data
                {
                    L.erase(it);
                    cout << "item with ID " << target << " deleted" << endl;
                }
            }
        }
        cout << "+------------------------------+" << endl << endl;
        cout << "input command: "; // meminta command kembali
        cin >> command;
    }

    return 0;
}