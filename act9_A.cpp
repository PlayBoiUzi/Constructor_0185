#include <iostream>
#include <string>
using namespace std;

// Forward declaration
class Dosen;
class Staff;
class Universitas;

// ======= Class Mahasiswa =======
class Mahasiswa {
private:
    string nama;
    string NIM;
    float nilai;

public:
    Mahasiswa(string nama, string NIM)
        : nama(nama), NIM(NIM), nilai(0.0f) {}

    void tampilkan() {
        cout << "Mahasiswa: " << nama << ", NIM: " << NIM << ", Nilai: " << nilai << endl;
    }

    // Dosen bisa akses nilai
    friend class Dosen;
};

// ======= Class Dosen =======
class Dosen {
private:
    string nama;
    string NIDN;
    string pangkat;
    float gaji;

public:
    Dosen(string nama, string NIDN, string pangkat, float gaji)
        : nama(nama), NIDN(NIDN), pangkat(pangkat), gaji(gaji) {}

    void beriNilai(Mahasiswa* m, float nilai) {
        m->nilai = nilai;
    }

    void tampilkan() {
        cout << "Dosen: " << nama << ", NIDN: " << NIDN << ", Pangkat: " << pangkat << endl;
    }

    // Staff bisa ubah pangkat
    friend class Staff;

    // Friend function dideklarasikan di sini
    friend float LihatGajiDosen(Dosen* d);
};

// ======= Class Staff =======
class Staff {
private:
    string nama;
    string IDStaff;
    float gaji;

public:
    Staff(string nama, string IDStaff, float gaji)
        : nama(nama), IDStaff(IDStaff), gaji(gaji) {}

    void ubahPangkat(Dosen* d, string pangkatBaru) {
        d->pangkat = pangkatBaru;
    }

    // Friend function untuk lihat gaji staff
    friend float LihatGajiStaff(Staff* s);
};

// ======= Friend function Dosen diimplementasikan di Universitas =======
class Universitas {
public:
    float aksesGajiDosen(Dosen* d) {
        return LihatGajiDosen(d);
    }

    float aksesGajiStaff(Staff* s) {
        return LihatGajiStaff(s);
    }
};

// ======= Friend function implementations =======
float LihatGajiDosen(Dosen* d) {
    return d->gaji;
}

float LihatGajiStaff(Staff* s) {
    return s->gaji;
}

// ======= Main =======
int main() {
    Mahasiswa m("Ronaldo", "12345678");
    Dosen d("Pak Budi", "98765", "Lektor", 15000000);
    Staff s("Bu Rina", "S001", 10000000);
    Universitas u;

    d.beriNilai(&m, 85.5);
    m.tampilkan();

    s.ubahPangkat(&d, "Guru Besar");
    d.tampilkan();

    cout << "Gaji Dosen: " << u.aksesGajiDosen(&d) << endl;
    cout << "Gaji Staff: " << u.aksesGajiStaff(&s) << endl;

    return 0;
}
