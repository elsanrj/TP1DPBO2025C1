package Java.Program;

import java.util.Scanner;
import java.util.ArrayList;

public class Petshop {
    private String id;
    private String nama;
    private String kategori;
    private int harga;

    public Petshop() {
        this.id = "";
        this.nama = "";
        this.kategori = "";
        this.harga = 0;
    }

    public Petshop(String id, String nama, String kategori, int harga) {
        this.id = id;
        this.nama = nama;
        this.kategori = kategori;
        this.harga = harga;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getNama() {
        return nama;
    }

    public void setNama(String nama) {
        this.nama = nama;
    }

    public String getKategori() {
        return kategori;
    }

    public void setKategori(String kategori) {
        this.kategori = kategori;
    }

    public int getHarga() {
        return harga;
    }

    public void setHarga(int harga) {
        this.harga = harga;
    }

    public void border() {
        System.out.println("+--------------------------------------------+");
    }

    public void add(Scanner sc, ArrayList<Petshop> ls) {
        
        id = sc.next();
        nama = sc.next();
        kategori = sc.next();
        harga = sc.nextInt();
        
        Petshop temp = new Petshop();
        temp.setId(id);
        temp.setNama(nama);
        temp.setKategori(kategori);
        temp.setHarga(harga);

        ls.add(temp);
    }

    public void show(ArrayList<Petshop> ls) {
        System.out.println(" ID | Nama | Kategori | Harga");
        border();
        for (int i = 0; i < ls.size(); i++) {
            System.out.println(ls.get(i).getId() + " " + ls.get(i).getNama() + " " + ls.get(i).getKategori() + " "
                    + ls.get(i).getHarga());
        }
    }

    public Petshop find(Scanner sc, ArrayList<Petshop> ls, String command) {
        String target;
        if (command.equals("find")) {
            System.out.print("input item name: ");
            target = sc.next();
            for (Petshop temp : ls) {
                if (temp.getNama().equals(target)) {
                    return temp;
                }
            }
        } else {
            System.out.print("input item ID: ");
            target = sc.next();
            // proses mencari nama barang dalam list dan "menyimpan alamat" iterator
            for (Petshop temp : ls) {
                if (temp.getId().equals(target)) {
                    return temp;
                }
            }
        }
        border();
        return null;
    }

    public void update(Scanner sc, Petshop it)
    {
        nama = sc.next();
        kategori = sc.next();
        harga = sc.nextInt();
        border();
        // set atribut dengan setter
        it.setNama(nama);
        it.setKategori(kategori);
        it.setHarga(harga);
    }
}