#include <iostream>
#include <iomanip>
using namespace std;

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

int main(){

    User dataUser[100];
    Pokemon dataPokemon[100];

    int jumlahUser = 1;
    int jumlahPokemon = 0;

    dataUser[0].username = "Rayandra";
    dataUser[0].password = "036";

    int menuAwal;

    do{
        cout << "\n===== MENU AWAL =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Keluar\n";
        cout << "Pilih : ";
        cin >> menuAwal;
        cin.ignore();

        if(menuAwal == 1){

            cout << "\n=== REGISTER ===\n";
            cout << "Masukkan Username : ";
            getline(cin, dataUser[jumlahUser].username);

            cout << "Masukkan Password : ";
            getline(cin, dataUser[jumlahUser].password);

            jumlahUser++;

            cout << "Register berhasil!\n";
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.get();
        }

        else if(menuAwal == 2){

            string username, password;
            int percobaan = 0;
            bool login = false;

            while(percobaan < 3){

                cout << "\n=== LOGIN ===\n";
                cout << "Username : ";
                getline(cin, username);

                cout << "Password : ";
                getline(cin, password);

                for(int i=0;i<jumlahUser;i++){

                    if(username == dataUser[i].username &&
                       password == dataUser[i].password){

                        login = true;
                        break;
                    }
                }

                if(login){
                    cout << "Login berhasil!\n";
                    cout << "\nTekan Enter untuk melanjutkan...";
                    cin.get();
                    break;
                }
                else{
                    percobaan++;
                    cout << "Login gagal!\n";
                    cout << "Sisa percobaan: " << 3 - percobaan << "\n\n";
                }
            }

            if(!login){
                cout << "Anda gagal login 3 kali. Program berhenti.\n";
                return 0;
            }

            int pilihan;

            do{

                cout << "\n===== SISTEM MANAJEMEN DATA POKEMON =====\n";
                cout << "1. Tambah Data Pokemon\n";
                cout << "2. Lihat Data Pokemon\n";
                cout << "3. Update Data Pokemon\n";
                cout << "4. Hapus Data Pokemon\n";
                cout << "5. Logout\n";
                cout << "Pilih Menu : ";
                cin >> pilihan;

                if(pilihan == 1){

                    cout << "\n=== Tambah Data Pokemon ===\n";

                    cout << "ID Pokemon : ";
                    cin >> dataPokemon[jumlahPokemon].id;
                    cin.ignore();

                    cout << "Nama Pokemon : ";
                    getline(cin, dataPokemon[jumlahPokemon].nama);

                    cout << "Tipe Pokemon : ";
                    getline(cin, dataPokemon[jumlahPokemon].tipe);

                    cout << "Level : ";
                    cin >> dataPokemon[jumlahPokemon].level;

                    cout << "HP : ";
                    cin >> dataPokemon[jumlahPokemon].stat.hp;

                    cout << "Attack : ";
                    cin >> dataPokemon[jumlahPokemon].stat.attack;

                    jumlahPokemon++;

                    cout << "\nData Pokemon berhasil ditambahkan!\n";
                    cout << "Tekan Enter untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                }

                else if(pilihan == 2){
                    cout<<"======================== DATA POKEMON ========================\n";

                    if(jumlahPokemon==0){
                        cout<<"Belum ada data.\n";
                    }
                    else{
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
                    }

                    cout << "\nTekan Enter untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                }

                else if(pilihan == 3){
                    cout<<"======================== DATA POKEMON ========================\n";

                    if(jumlahPokemon==0){
                        cout<<"Belum ada data.\n";
                    }
                    else{
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

                        int id;
                        bool ditemukan = false;

                        cout << "Masukkan ID Pokemon yang ingin diubah : ";
                        cin >> id;
                        cin.ignore();

                        for(int i=0;i<jumlahPokemon;i++){
                            if(dataPokemon[i].id == id){

                                cout << "Nama baru : ";
                                getline(cin, dataPokemon[i].nama);

                                cout << "Tipe baru : ";
                                getline(cin, dataPokemon[i].tipe);

                                cout << "Level baru : ";
                                cin >> dataPokemon[i].level;

                                cout << "HP baru : ";
                                cin >> dataPokemon[i].stat.hp;

                                cout << "Attack baru : ";
                                cin >> dataPokemon[i].stat.attack;

                                ditemukan = true;
                                break;
                            }
                        }

                        if(ditemukan)
                            cout << "\nData pokemon berhasil diupdate!\n";
                        else
                            cout << "Data tidak ditemukan.\n";
                    }

                    cout << "Tekan Enter untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                }

                else if(pilihan == 4){
                    cout<<"======================== DATA POKEMON ========================\n";

                    if(jumlahPokemon==0){
                        cout<<"Belum ada data.\n";
                    }
                    else{
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

                        int id;
                        bool ditemukan = false;

                        cout << "Masukkan ID Pokemon yang ingin dihapus : ";
                        cin >> id;

                        for(int i=0;i<jumlahPokemon;i++){
                            if(dataPokemon[i].id == id){
                                for(int j=i;j<jumlahPokemon-1;j++){
                                    dataPokemon[j] = dataPokemon[j+1];
                                }

                                jumlahPokemon--;
                                ditemukan = true;
                                break;
                            }
                        }

                        if(ditemukan)
                            cout << "\nData Pokemon berhasil dihapus!\n";
                        else
                            cout << "ID Pokemon tidak ditemukan!\n";
                    }

                    cout << "Tekan Enter untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                }

                else if(pilihan==5){
                    cout << "\nBerhasil Logout.\n";
                    cout << "Tekan Enter untuk login kembali.";
                    cin.ignore();
                    cin.get();
                }

                else{
                    cout << "\nPilihan tidak tersedia.\n";
                    cout << "Tekan Enter untuk kembali.";
                    cin.ignore();
                    cin.get();
                }

            }while(pilihan != 5);
        }

        else if(menuAwal == 3){
            cout << "\nProgram selesai.\n";
            cout << "Terimakasih telah menggunakan program ini.\n";
        }

        else{
            cout << "\nPilihan tidak tersedia.\n";
            cout << "Tekan Enter untuk kembali.";
            cin.get();
        }

    }while(menuAwal != 3);

}