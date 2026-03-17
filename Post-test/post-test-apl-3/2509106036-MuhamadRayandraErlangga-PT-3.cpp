#include <iostream>
#include <iomanip>
using namespace std;

#define MAX 100

struct User{
    string username;
    string password;
};

struct Status{
    int hp;
    int attack;
};

struct Pokemon{
    int id;
    string nama;
    string tipe;
    int level;
    Status stat;
};

bool cekUsername(User dataUser[], int jumlahUser, string username){
    for(int i=0;i<jumlahUser;i++){
        if(username == dataUser[i].username){
            return false;
        }
    }
    return true;
}

void registerUser(User dataUser[], int &jumlahUser){

    string username;

    cout<<"\n=== REGISTER ===\n";
    cout<<"Masukkan Username : ";
    getline(cin, username);

    if(!cekUsername(dataUser, jumlahUser, username)){
        cout<<"Username sudah digunakan!\n";
        cout << "\nTekan Enter untuk melanjutkan...";
        cin.get();
        return;
    }

    dataUser[jumlahUser].username = username;

    cout<<"Masukkan Password : ";
    getline(cin, dataUser[jumlahUser].password);

    jumlahUser++;

    cout<<"Register berhasil!\n";
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.get();
}

bool loginUser(User dataUser[], int jumlahUser){

    string username,password;
    int percobaan = 0;
    bool login = false;

    while(percobaan < 3){
        cout<<"\n=== LOGIN ===\n";
        cout<<"Username : ";
        getline(cin, username);
        cout<<"Password : ";
        getline(cin, password);

        for(int i=0;i<jumlahUser;i++){
            if(username == dataUser[i].username &&
               password == dataUser[i].password){

                login = true;
                break;
            }
        }

        if(login){
            cout<<"\nLogin berhasil!\n";
            cout<<"Selamat datang, " << username << "!\n";
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.get();
            return true;
        }
        else{
            percobaan++;
            cout<<"\nLogin gagal!\n";
            cout<<"Sisa percobaan: " << 3 - percobaan << endl;
        }
    }

    cout<<"\nAnda gagal login 3 kali!\n";
    cout<<"Program berhenti.\n";
    return false;
}

int generateID(int jumlahPokemon){
    return jumlahPokemon + 1;
}

int hitungPokemon(int n){
    if(n==0)
        return 0;
    return 1 + hitungPokemon(n-1);
}

void tambahPokemon(Pokemon dataPokemon[], int &jumlahPokemon){
    cout<<"\n=== Tambah Pokemon ===\n";

    dataPokemon[jumlahPokemon].id = generateID(jumlahPokemon);
    cin.ignore();

    cout<<"Nama Pokemon : ";
    getline(cin, dataPokemon[jumlahPokemon].nama);
    cout<<"Tipe Pokemon : ";
    getline(cin, dataPokemon[jumlahPokemon].tipe);
    cout<<"Level : ";
    cin>>dataPokemon[jumlahPokemon].level;
    cout<<"HP : ";
    cin>>dataPokemon[jumlahPokemon].stat.hp;
    cout<<"Attack : ";
    cin>>dataPokemon[jumlahPokemon].stat.attack;

    jumlahPokemon++;

    cout<<"\nPokemon berhasil ditambahkan!\n";
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

void lihatPokemon(Pokemon dataPokemon[], int jumlahPokemon){
    cout<<"======================== DATA POKEMON ========================\n";

    if(jumlahPokemon==0){
        cout<<"Belum ada data.\n";
        cout << "\nTekan Enter untuk melanjutkan...";
        cin.ignore();
        cin.get();
        return;
    }

    cout<<"--------------------------------------------------------------\n";
    cout<<"| "<<left<<setw(3)<<"ID"
        <<" | "<<setw(15)<<"Nama"
        <<" | "<<setw(10)<<"Tipe"
        <<" | "<<setw(5)<<"Lvl"
        <<" | "<<setw(5)<<"HP"
        <<" | "<<setw(5)<<"Atk"
        <<" |\n";
    cout<<"--------------------------------------------------------------\n";

    for(int i=0;i<jumlahPokemon;i++){
        cout<<"| "<<left<<setw(3)<<dataPokemon[i].id
            <<" | "<<setw(15)<<dataPokemon[i].nama
            <<" | "<<setw(10)<<dataPokemon[i].tipe
            <<" | "<<setw(5)<<dataPokemon[i].level
            <<" | "<<setw(5)<<dataPokemon[i].stat.hp
            <<" | "<<setw(5)<<dataPokemon[i].stat.attack
            <<" |\n";
    }

    cout<<"--------------------------------------------------------------\n";

    cout<<"Total Pokemon : "<<hitungPokemon(jumlahPokemon)<<endl;
    cin.ignore();
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.get();
}

void updatePokemon(Pokemon dataPokemon[], int jumlahPokemon){
    if(jumlahPokemon == 0){
        cout << "\nBelum ada data Pokemon!\n";
        cout << "\nTekan Enter untuk melanjutkan...";
        cin.ignore();
        cin.get();
        return;
    }

    int id;
    bool ditemukan=false;

    lihatPokemon(dataPokemon,jumlahPokemon);

    cout<<"Masukkan ID Pokemon yang ingin diubah : ";
    cin>>id;
    cin.ignore();

    for(int i=0;i<jumlahPokemon;i++){
        if(dataPokemon[i].id==id){
            cout<<"Nama baru : ";
            getline(cin,dataPokemon[i].nama);
            cout<<"Tipe baru : ";
            getline(cin,dataPokemon[i].tipe);
            cout<<"Level baru : ";
            cin>>dataPokemon[i].level;
            cout<<"HP baru : ";
            cin>>dataPokemon[i].stat.hp;
            cout<<"Attack baru : ";
            cin>>dataPokemon[i].stat.attack;

            ditemukan=true;
            break;
        }
    }

    if(ditemukan)
        cout<<"Data berhasil diupdate\n";
    else
        cout<<"Data tidak ditemukan\n";

    cout << "\nTekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

void hapusPokemon(Pokemon dataPokemon[], int &jumlahPokemon){
    if(jumlahPokemon == 0){
        cout << "\nBelum ada data Pokemon!\n";
        cout << "\nTekan Enter untuk melanjutkan...";
        cin.ignore();
        cin.get();
        return;
    }

    int id;
    bool ditemukan=false;

    lihatPokemon(dataPokemon,jumlahPokemon);

    cout<<"Masukkan ID Pokemon yang ingin dihapus : ";
    cin>>id;

    for(int i=0;i<jumlahPokemon;i++){
        if(dataPokemon[i].id==id){
            for(int j=i;j<jumlahPokemon-1;j++){
                dataPokemon[j]=dataPokemon[j+1];
            }

            jumlahPokemon--;

            for(int k=0;k<jumlahPokemon;k++){
                dataPokemon[k].id = k + 1;
            }

            ditemukan=true;
            break;
        }
    }

    if(ditemukan)
        cout<<"Data berhasil dihapus\n";
    else
        cout<<"ID tidak ditemukan\n";

    cout << "\nTekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

int main(){

    User dataUser[MAX];
    Pokemon dataPokemon[MAX];

    int jumlahUser=1;
    int jumlahPokemon=0;

    dataUser[0].username="Rayandra";
    dataUser[0].password="036";

    int menuAwal;

    do{
        cout<<"\n===== MENU AWAL =====\n";
        cout<<"1. Register\n";
        cout<<"2. Login\n";
        cout<<"3. Keluar\n";
        cout<<"Pilih : ";
        cin>>menuAwal;
        cin.ignore();

        if(menuAwal==1){
            registerUser(dataUser,jumlahUser);
        }

        else if(menuAwal==2){
            if(loginUser(dataUser,jumlahUser)){

                int pilihan;

                do{
                    cout<<"\n===== SISTEM MANAJEMEN DATA POKEMON =====\n";
                    cout<<"1. Tambah Pokemon\n";
                    cout<<"2. Lihat Pokemon\n";
                    cout<<"3. Update Pokemon\n";
                    cout<<"4. Hapus Pokemon\n";
                    cout<<"5. Logout\n";
                    cout<<"Pilih : ";
                    cin>>pilihan;

                    if(pilihan==1)
                        tambahPokemon(dataPokemon,jumlahPokemon);

                    else if(pilihan==2)
                        lihatPokemon(dataPokemon,jumlahPokemon);

                    else if(pilihan==3)
                        updatePokemon(dataPokemon,jumlahPokemon);

                    else if(pilihan==4)
                        hapusPokemon(dataPokemon,jumlahPokemon);

                    else if(pilihan==5){
                        cout<<"\nAnda telah logout.\n";
                        cout << "\nTekan Enter untuk melanjutkan...";
                        cin.ignore();
                        cin.get();
                    }
                    else{
                        cout << "\nPilihan tidak tersedia.\n";
                        cout << "\nTekan Enter untuk melanjutkan...";
                        cin.ignore();
                        cin.get();
                    }
                    

                }while(pilihan!=5);
            }
            else{
                return 0;
            }
        }

        else if(menuAwal==3){
            cout<<"\nProgram selesai.\n";
            cout<<"Terima kasih telah menggunakan sistem ini!\n";
        }
        else{
            cout << "\nPilihan tidak tersedia.\n";
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.get();
        }

    }while(menuAwal!=3);

}