#include <iostream>
using namespace std;
struct Mahasiswa {
string nama;
int nim;
};
int main() {
Mahasiswa mhs1;
Mahasiswa *angga = &mhs1;
mhs1.nama = "Yunjin";
mhs1.nim = 321;
cout << mhs1.nama << " - " << mhs1.nim << endl;
angga->nama = "Chaewon";
angga->nim = 123;
cout << mhs1.nama << " - " << mhs1.nim << endl;
cout << angga->nama << " - " << angga->nim << endl;
return 0;
}