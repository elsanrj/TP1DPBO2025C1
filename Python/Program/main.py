from Petshop import Petshop

ps = Petshop()
ls = []

ps.border()
print("|                   Petshop                  |")
ps.border()

n = int(input('input item quantity: '))
ps.border()
print('input item(s):')
ps.border()
for i in range (n):
    ps.add(ls)
ps.border()
print("")

command = str(input('input command: '))
ps.border()

while command != "stop":
    if command == "show":
        ps.show(ls)
        
    elif command == "add":
        print("input item:")
        ps.border()
        ps.add(ls)
        ps.border()
        print("item added")
        
    else:
        it = ps.find(ls, command)
        ps.border()
        if it == None:
            print("item not found")
            
        else:
            print("item found")
            ps.border()
            if command == "find":
                print(it.getId(), it.getNama(), it.getKategori(), it.getHarga())
                
            elif command == "update":
                print("edit to:")
                ps.border()
                ps.update(it)
                ps.border()
                print("item updated to", it.getId(), it.getNama(), it.getKategori(), it.getHarga())
                
            elif command == "delete":
                ls.remove(it)
                print("item", it.getId(), it.getNama(), it.getKategori(), it.getHarga(), "deleted")
    ps.border()
    print("")
    command = str(input('input command: '))
    ps.border()

