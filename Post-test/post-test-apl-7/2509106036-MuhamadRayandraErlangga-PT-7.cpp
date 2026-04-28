#include <iostream>
#include <iomanip>
#include <stdexcept>
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

bool cekUsername(User *dataUser, int jumlahUser, string username){
    for(int i=0;i<jumlahUser;i++){
        if(username == (dataUser+i)->username){
            return false;
        }
    }
    return true;
}

void registerUser(User *dataUser, int &jumlahUser){
    try{
        string username;

        cout<<"\n=== REGISTER ===\n";
        cout<<"Masukkan Username : ";
        getline(cin, username);

        if(username.empty()){
            throw invalid_argument("Username tidak boleh kosong!");
        }

        if(!cekUsername(dataUser, jumlahUser, username)){
            throw runtime_error("Username sudah digunakan!");
        }

        (dataUser+jumlahUser)->username = username;

        cout<<"Masukkan Password : ";
        getline(cin, (dataUser+jumlahUser)->password);

        if((dataUser+jumlahUser)->password.empty()){
            throw invalid_argument("Password tidak boleh kosong!");
        }

        jumlahUser++;

        cout<<"Register berhasil!\n";
    }
    catch(exception &e){
        cout<<"[ERROR] "<<e.what()<<endl;
    }

    cout << "\nTekan Enter untuk melanjutkan...";
    cin.get();
}

bool loginUser(User *dataUser, int jumlahUser){

    string username,password;
    int percobaan = 0;
    bool login = false;

    while(percobaan < 3){
        try{
            cout<<"\n=== LOGIN ===\n";
            cout<<"Username : ";
            getline(cin, username);

            if(username.empty()){
                throw invalid_argument("Username tidak boleh kosong!");
            }

            cout<<"Password : ";
            getline(cin, password);

            for(int i=0;i<jumlahUser;i++){
                if(username == (dataUser+i)->username &&
                   password == (dataUser+i)->password){

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
                throw runtime_error("Username / Password salah!");
            }
        }
        catch(exception &e){
            percobaan++;
            cout<<"\n[ERROR] "<<e.what()<<endl;
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

void tambahPokemon(Pokemon *dataPokemon, int &jumlahPokemon){
    try{
        cout<<"\n=== Tambah Pokemon ===\n";

        if(jumlahPokemon >= MAX){
            throw runtime_error("Kapasitas penuh!");
        }

        (dataPokemon+jumlahPokemon)->id = generateID(jumlahPokemon);
        cin.ignore();

        cout<<"Nama Pokemon : ";
        getline(cin, (dataPokemon+jumlahPokemon)->nama);

        if((dataPokemon+jumlahPokemon)->nama.empty()){
            throw invalid_argument("Nama tidak boleh kosong!");
        }

        cout<<"Tipe Pokemon : ";
        getline(cin, (dataPokemon+jumlahPokemon)->tipe);

        cout<<"Level : ";
        cin>>(dataPokemon+jumlahPokemon)->level;
        if(cin.fail()){
            throw invalid_argument("Level harus angka!");
        }

        cout<<"HP : ";
        cin>>(dataPokemon+jumlahPokemon)->stat.hp;
        cout<<"Attack : ";
        cin>>(dataPokemon+jumlahPokemon)->stat.attack;

        jumlahPokemon++;

        cout<<"\nPokemon berhasil ditambahkan!\n";
    }
    catch(exception &e){
        cout<<"\n[ERROR] "<<e.what()<<endl;
        cin.clear();
        cin.ignore(1000,'\n');
    }

    cout << "\nTekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

void lihatPokemon(Pokemon *dataPokemon, int jumlahPokemon){
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
        cout<<"| "<<left<<setw(3)<<(dataPokemon+i)->id
            <<" | "<<setw(15)<<(dataPokemon+i)->nama
            <<" | "<<setw(10)<<(dataPokemon+i)->tipe
            <<" | "<<setw(5)<<(dataPokemon+i)->level
            <<" | "<<setw(5)<<(dataPokemon+i)->stat.hp
            <<" | "<<setw(5)<<(dataPokemon+i)->stat.attack
            <<" |\n";
    }

    cout<<"--------------------------------------------------------------\n";

    cout<<"Total Pokemon : "<<hitungPokemon(jumlahPokemon)<<endl;
    cin.ignore();
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.get();
}

void updatePokemon(Pokemon *dataPokemon, int jumlahPokemon){
    try{
        if(jumlahPokemon == 0){
            throw runtime_error("Belum ada data Pokemon!");
        }

        int id;
        bool ditemukan=false;

        lihatPokemon(dataPokemon,jumlahPokemon);

        cout<<"Masukkan ID Pokemon yang ingin diubah : ";
        cin>>id;

        if(cin.fail()){
            throw invalid_argument("ID harus angka!");
        }

        cin.ignore();

        for(int i=0;i<jumlahPokemon;i++){
            if((dataPokemon+i)->id==id){
                cout<<"Nama baru : ";
                getline(cin,(dataPokemon+i)->nama);
                cout<<"Tipe baru : ";
                getline(cin,(dataPokemon+i)->tipe);
                cout<<"Level baru : ";
                cin>>(dataPokemon+i)->level;
                cout<<"HP baru : ";
                cin>>(dataPokemon+i)->stat.hp;
                cout<<"Attack baru : ";
                cin>>(dataPokemon+i)->stat.attack;

                ditemukan=true;
                break;
            }
        }

        if(ditemukan)
            cout<<"Data berhasil diupdate\n";
        else
            throw runtime_error("Data tidak ditemukan");
    }
    catch(exception &e){
        cout<<"\n[ERROR] "<<e.what()<<endl;
        cin.clear();
        cin.ignore(1000,'\n');
    }

    cout << "\nTekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

void hapusPokemon(Pokemon *dataPokemon, int &jumlahPokemon){
    try{
        if(jumlahPokemon == 0){
            throw runtime_error("Belum ada data Pokemon!");
        }

        int id;
        bool ditemukan=false;

        lihatPokemon(dataPokemon,jumlahPokemon);

        cout<<"Masukkan ID Pokemon yang ingin dihapus : ";
        cin>>id;

        if(cin.fail()){
            throw invalid_argument("Input harus angka!");
        }

        for(int i=0;i<jumlahPokemon;i++){
            if((dataPokemon+i)->id==id){
                for(int j=i;j<jumlahPokemon-1;j++){
                    *(dataPokemon+j)=*(dataPokemon+j+1);
                }

                jumlahPokemon--;

                for(int k=0;k<jumlahPokemon;k++){
                    (dataPokemon+k)->id = k + 1;
                }

                ditemukan=true;
                break;
            }
        }

        if(ditemukan)
            cout<<"Data berhasil dihapus\n";
        else
            throw runtime_error("ID tidak ditemukan");
    }
    catch(exception &e){
        cout<<"\n[ERROR] "<<e.what()<<endl;
        cin.clear();
        cin.ignore(1000,'\n');
    }

    cout << "\nTekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

void sortNama(Pokemon *dataPokemon, int jumlahPokemon){
    for(int i=0;i<jumlahPokemon-1;i++){
        for(int j=0;j<jumlahPokemon-i-1;j++){
            if((dataPokemon+j)->nama < (dataPokemon+j+1)->nama){
                swap(*(dataPokemon+j), *(dataPokemon+j+1));
            }
        }
    }
}

void sortLevel(Pokemon *dataPokemon, int jumlahPokemon){
    for(int i=0;i<jumlahPokemon-1;i++){
        int minIndex = i;
        for(int j=i+1;j<jumlahPokemon;j++){
            if((dataPokemon+j)->level < (dataPokemon+minIndex)->level){
                minIndex = j;
            }
        }
        swap(*(dataPokemon+i), *(dataPokemon+minIndex));
    }
}

void sortHP(Pokemon *dataPokemon, int jumlahPokemon){
    for(int i=1;i<jumlahPokemon;i++){
        Pokemon key = *(dataPokemon+i);
        int j = i-1;

        while(j>=0 && (dataPokemon+j)->stat.hp > key.stat.hp){
            *(dataPokemon+j+1) = *(dataPokemon+j);
            j--;
        }
        *(dataPokemon+j+1) = key;
    }
}

int cariID(Pokemon *dataPokemon, int jumlahPokemon, int id){
    for(int i = 0; i < jumlahPokemon; i++){
        if((dataPokemon+i)->id == id){
            return i;
        }
    }
    return -1;
}

int cariNama(Pokemon *dataPokemon, int jumlahPokemon, string nama){
    int kiri = 0, kanan = jumlahPokemon - 1;

    while(kiri <= kanan){
        int tengah = (kiri + kanan) / 2;

        if((dataPokemon+tengah)->nama == nama){
            return tengah;
        }
        else if((dataPokemon+tengah)->nama > nama){
            kiri = tengah + 1;
        }
        else{
            kanan = tengah - 1;
        }
    }
    return -1;
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
                    cout<<"5. Urutkan Nama (Descending)\n";
                    cout<<"6. Urutkan Level (Ascending)\n";
                    cout<<"7. Urutkan HP (Ascending)\n";
                    cout<<"8. Cari Pokemon (ID)\n";
                    cout<<"9. Cari Pokemon (Nama)\n";
                    cout<<"10. Logout\n";
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
                        sortNama(dataPokemon,jumlahPokemon);
                        cout<<"\nData berhasil diurutkan berdasarkan NAMA (DESCENDING)\n";
                    }

                    else if(pilihan==6){
                        sortLevel(dataPokemon,jumlahPokemon);
                        cout<<"\nData berhasil diurutkan berdasarkan LEVEL (ASCENDING)\n";
                    }

                    else if(pilihan==7){
                        sortHP(dataPokemon,jumlahPokemon);
                        cout<<"\nData berhasil diurutkan berdasarkan HP (ASCENDING)\n";
                    }

                    else if(pilihan==8){
                        int id;

                        cout<<"\nMasukkan ID: ";
                        cin>>id;

                        int index = cariID(dataPokemon, jumlahPokemon, id);

                        if(index != -1){
                            cout<<"Data ditemukan:\n";
                            cout<<"Nama: "<<(dataPokemon+index)->nama<<endl;
                            cout<<"Tipe: "<<(dataPokemon+index)->tipe<<endl;
                            cout<<"Level: "<<(dataPokemon+index)->level<<endl;
                            cout<<"HP: "<<(dataPokemon+index)->stat.hp<<endl;
                            cout<<"Attack: "<<(dataPokemon+index)->stat.attack<<endl;
                        }
                        
                        else {
                            cout<<"Data tidak ditemukan\n";
                        }

                        cout << "\nTekan Enter untuk melanjutkan...";
                        cin.get();
                        cin.ignore();
                    }

                    else if(pilihan==9){
                        string nama;
                        cin.ignore();

                        cout<<"\nMasukkan Nama: ";
                        getline(cin, nama);

                        sortNama(dataPokemon, jumlahPokemon);

                        int index = cariNama(dataPokemon, jumlahPokemon, nama);

                        if(index != -1){
                            cout<<"Data ditemukan:\n";
                            cout<<"ID: "<<(dataPokemon+index)->id<<endl;
                            cout<<"Nama: "<<(dataPokemon+index)->nama<<endl;
                            cout<<"Tipe: "<<(dataPokemon+index)->tipe<<endl;
                            cout<<"Level: "<<(dataPokemon+index)->level<<endl;
                            cout<<"HP: "<<(dataPokemon+index)->stat.hp<<endl;
                            cout<<"Attack: "<<(dataPokemon+index)->stat.attack<<endl;
                        }

                        else {
                            cout<<"Data tidak ditemukan\n";
                        }

                        cout << "\nTekan Enter untuk melanjutkan...";
                        cin.get();
                    }

                    else if(pilihan==10){
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

                }while(pilihan!=10);
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