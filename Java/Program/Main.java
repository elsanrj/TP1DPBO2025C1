package Java.Program;

import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args)
    {
        Petshop ps = new Petshop();
        ArrayList<Petshop> ls = new ArrayList<Petshop>();

        int n = 0;
        Scanner sc = new Scanner(System.in);

        ps.border();
        System.out.println("|                   Petshop                  |");
        ps.border();

        // proses input data barang
        System.out.print("input item quantity: ");
        n = sc.nextInt();
        ps.border();
        System.out.println("input item(s):");
        ps.border();
        for (int i = 0; i < n; i++) {
            ps.add(sc, ls);
        }
        ps.border();
        System.out.println("");

        // proses meminta command yang akan dijalankan
        String command;
        System.out.print("input command: ");
        command = sc.next();
        ps.border();
        while (!command.equals("stop"))
        {
            if (command.equals("show"))// menampilkan seluruh data
            {
                // proses menampilkan seluruh elemen list
                ps.show(ls);
            }
            else if (command.equals("add")) // menambahkan data
            {
                System.out.print("input item: ");
                ps.add(sc, ls);
                ps.border();
                System.out.println("item added");
            }
            else
            {
                Petshop it = ps.find(sc, ls, command);
                if (it == null)
                {
                    System.out.println("item not found");
                }
                else
                {
                    System.out.println("item found");
                    ps.border();
                    if (command.equals("find"))
                    {
                        System.out.println(it.getId() + " " + it.getNama() + " " + it.getKategori() + " " + it.getHarga());
                    }
                    else if (command.equals("update")) // mengubah data
                    {
                        System.out.print("edit to: ");
                        ps.update(sc, it);
                        System.out.println("item updated to: " + it.getId() + " " + it.getNama() + " " + it.getKategori() + " " + it.getHarga());
                    }
                    else if (command.equals("delete")) // menghapus data
                    {
                        ls.remove(it);
                        System.out.println("item " + it.getId() + " " + it.getNama() + " " + it.getKategori() + " " + it.getHarga() + " deleted");
                    }
                }
            }
            ps.border();
            System.out.println("");
            System.out.print("input command: "); // meminta command kembali
            command = sc.next();
            ps.border();
        }
        sc.close();
    }
}