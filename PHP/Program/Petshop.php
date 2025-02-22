<?php
class Petshop
{
    // Properties
    private $id, $nama, $kategori, $image;
    private $harga;

    // Constructor
    function __construct()
    {
        $this->id = "";
        $this->nama = "";
        $this->kategori = "";
        $this->harga = 0;
        $this->image = "";
    }
    
    // Setter
    function setID($id) {
        $this->id = $id;
    }
    function setNama($nama) {
        $this->nama = $nama;
    }
    function setKategori($kategori) {
        $this->kategori = $kategori;
    }
    function setHarga($harga) {
        $this->harga = $harga;
    }
    function setImage($image) {
        $this->image = $image;
    }

    // Getter
    function getID() {
        return $this->id;
    }
    function getNama() {
        return $this->nama;
    }
    function getKategori() {
        return $this->kategori;
    }
    function getHarga() {
        return $this->harga;
    }
    function getImage() {
        return $this->image;
    }

    // Method
    function add($id, $nama, $kategori, $harga, $image) {
        $temp = new Petshop();
        $temp->setID($id);
        $temp->setNama($nama);
        $temp->setKategori($kategori);
        $temp->setHarga($harga);
        $temp->setImage($image);
    
        return $temp;
    }
    
    function update($List, $target, $nama, $kategori, $harga, $image) {
        $found = false;
        foreach ($List as $data) {
            if($data->getID() == $target) {
                $data->setNama($nama);
                $data->setKategori($kategori);
                $data->setHarga($harga);
                $data->setImage($image);
                $found = true;
            }
        }
        if($found) {
            echo "item ". $target ." found<br>";
            echo "item with ID ". $target ." updated<br>";
        } else {
            echo "item with ID ". $target ." doesn't exist<br>";
        }
        echo "<br>";
    }
    
    function find($List, $target) {
        foreach ($List as $key=>$data) {
            if($data->getID() == $target) {
                echo "item with ID ". $target ." deleted<br><br>";
                return $key;
            }
        }
        echo "item with ID ". $target ." doesn't exist<br><br>";
        return -1;
    }
    
    function show($List) {
        echo "<table border='1'>";
            echo "<thead>";
                echo "<th>ID</th>";
                echo "<th>Gambar</th>";
                echo "<th>Nama</th>";
                echo "<th>Kategori</th>";
                echo "<th>Harga</th>";
            echo "</thead>";
            
            echo "<tbody>";
                foreach ($List as $data) {
                echo "<tr>";
                    echo "<td>" . $data->getID() . "</td>";
                    echo "<td><img src='img/" . $data->getImage() . "' width='100'/></td>";
                    echo "<td>" . $data->getNama() . "</td>";
                    echo "<td>" . $data->getKategori() . "</td>";
                    echo "<td>" . $data->getHarga() . "</td>";
                echo "</tr>";
                }
            echo "</tbody>";
        echo "</table>";
        echo "<br>";
    }
}
