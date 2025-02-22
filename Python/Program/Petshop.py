class Petshop:
    __id = ""
    __nama = ""
    __kategori = ""
    __harga = 0
    
    def __init__(self, id = "", nama = "", kategori = "", harga = 0):
        self.__id = id
        self.__nama = nama
        self.__kategori = kategori
        self.__harga = harga
        
    def getId(self):
        return self.__id

    def setId(self, id):
        self.__id = id 

    def getNama(self):
        return self.__nama

    def setNama(self, nama):
        self.__nama = nama

    def getKategori(self):
        return self.__kategori

    def setKategori(self, kategori):
        self.__kategori = kategori
        
    def getHarga(self):
        return self.__harga

    def setHarga(self, harga):
        self.__harga = harga

    def border(self):
        print("+--------------------------------------------+")
        
    def add(self, ls):
        masukan = input().split()
        
        id = masukan[0]
        nama = masukan[1]
        kategori = masukan[2]
        harga = int(masukan[3])
        
        ls.append(Petshop(id, nama, kategori, harga))
        
    def show(self, ls):
        print(" ID | Nama | Kategori | Harga")
        self.border()
        for elmt in ls:
            print(elmt.getId(), elmt.getNama(), elmt.getKategori(), elmt.getHarga())

    def find(self, ls, command):
        if command == "find":
            target = str(input("input item name: "))        
            for elmt in ls:
                if elmt.getNama() == target:
                    return elmt
        else:
            target = str(input("input item ID: "))
            for elmt in ls:
                if elmt.getId() == target:
                    return elmt
        return None

    def update(self, it):
        masukan = input().split()

        nama = masukan[0]
        kategori = masukan[1]
        harga = int(masukan[2])
        
        it.setNama(nama)
        it.setKategori(kategori)
        it.setHarga(harga)