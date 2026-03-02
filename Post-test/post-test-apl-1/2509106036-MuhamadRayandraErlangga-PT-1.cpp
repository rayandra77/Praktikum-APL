#include <iostream>
using namespace std;

int main() {

    string username, password;
    int percobaan = 0;
    bool login = false;

    while (percobaan < 3) {
        cout << "=====================================\n";
        cout << "        LOGIN PROGRAM KONVERSI      \n";
        cout << "=====================================\n";
        cout << "Masukkan Username : ";
        cin >> username;
        cout << "Masukkan Password : ";
        cin >> password;

        if (username == "Rayandra" && password == "036") {
            login = true;
            break;
        } else {
            percobaan++;
            cout << "Login gagal!\n";
            cout << "Sisa percobaan: " << 3 - percobaan << "\n\n";
        }
    }

    if (login == false) {
        cout << "Anda gagal login 3 kali. Program berhenti.\n";
        return 0;
    }

    cout << "\nLogin Berhasil!\n";

    int pilihan;
    double nilai;

    while (true) {
        cout << "\n=====================================\n";
        cout << "         MENU KONVERSI PANJANG      \n";
        cout << "=====================================\n";
        cout << "1. Meter ke Kilometer & Centimeter\n";
        cout << "2. Kilometer ke Meter & Centimeter\n";
        cout << "3. Centimeter ke Meter & Kilometer\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "Masukkan nilai dalam Meter: ";
            cin >> nilai;
            cout << "Hasil: "
                 << nilai/1000 << " km dan "
                 << nilai*100 << " cm\n";

        } else if (pilihan == 2) {
            cout << "Masukkan nilai dalam Kilometer: ";
            cin >> nilai;
            cout << "Hasil: "
                 << nilai*1000 << " m dan "
                 << nilai*100000 << " cm\n";

        } else if (pilihan == 3) {
            cout << "Masukkan nilai dalam Centimeter: ";
            cin >> nilai;
            cout << "Hasil: "
                 << nilai/100 << " m dan "
                 << nilai/100000 << " km\n";

        } else if (pilihan == 4) {
            cout << "Terima kasih telah menggunakan program ini.\n";
            break;

        } else {
            cout << "Pilihan tidak tersedia!\n";
        }
    }

    return 0;
}