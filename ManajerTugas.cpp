#include "ManajerTugas.h"
#include <bits/stdc++.h>

using namespace std;

ManajerTugas::ManajerTugas() {
    nextID = 1;
}

void ManajerTugas::addTugas() {
    string matkul, judul, deadline, status;
    int prioritas;

    cout << "Mata Kuliah: ";
    getline(cin, matkul);
    cout << "Judul Tugas: ";
    getline(cin, judul);
    cout << "Deadline (YYYY-MM-DD): ";
    getline(cin, deadline);
    cout << "Status: ";
    getline(cin, status);
    cout << "Prioritas (1-5): ";
    cin >> prioritas;
    cin.ignore();

    daftarTugas.push_back(Tugas(nextID++, matkul, judul, deadline, status, prioritas));
    cout << "Tugas berhasil ditambahkan!\n";
}

void ManajerTugas::editTugas() {
    int id;
    cout << "Masukkan ID tugas yang ingin diedit: ";
    cin >> id;
    cin.ignore();

    for (auto &t : daftarTugas) {
        if (t.id == id) {

            string temp;
            int angka;

            cout << "Matkul baru (kosongkan jika tidak diubah): ";
            getline(cin, temp);
            if (!temp.empty()) t.matkul = temp;

            cout << "Judul baru: ";
            getline(cin, temp);
            if (!temp.empty()) t.judul = temp;

            cout << "Deadline baru (YYYY-MM-DD): ";
            getline(cin, temp);
            if (!temp.empty()) t.deadline = temp;

            cout << "Status baru: ";
            getline(cin, temp);
            if (!temp.empty()) t.status = temp;

            cout << "Prioritas baru (1-5): ";
            cin >> angka;
            cin.ignore();
            if (angka >= 1 && angka <= 5) 
                t.prioritas = angka;

            cout << "Tugas berhasil diperbarui!\n";
            return;
        }
        else(
            
        )
    }

    cout << "ID tidak ditemukan!\n";
}

void ManajerTugas::deleteTugas() {
    int id;
    cout << "Masukkan ID tugas yang ingin dihapus: ";
    cin >> id;
    cin.ignore();

    for (auto it = daftarTugas.begin(); it != daftarTugas.end(); ++it) {
        if (it->id == id) {
            daftarTugas.erase(it);
            cout << "Tugas berhasil dihapus!\n";
            return;
        }
    }

    cout << "ID tidak ditemukan!\n";
}

void ManajerTugas::tampilkanSemua() {
    for (auto &t : daftarTugas) {
        t.display();
    }
}

void ManajerTugas::cariTugas() {
    string keyword;
    cout << "Masukkan keyword pencarian: ";
    getline(cin, keyword);

    bool ditemukan = false;

    for (auto &t : daftarTugas) {
        if (t.judul.find(keyword) != string::npos ||
            t.matkul.find(keyword) != string::npos) {
            t.display();
            ditemukan = true;
        }
    }

    if (!ditemukan) {
        cout << "Tidak ada tugas yang cocok dengan pencarian.\n";
    }
}

void ManajerTugas::sortByDeadline() {
    sort(daftarTugas.begin(), daftarTugas.end(),
         [](const Tugas &a, const Tugas &b) {
             return a.deadline < b.deadline; // sort ascending
         });

    cout << "Tugas berhasil diurutkan berdasarkan deadline.\n";
}

void ManajerTugas::loadFile(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Gagal membuka file!\n";
        return;
    }

    daftarTugas.clear();

    string matkul, judul, deadline, status;
    int prioritas;

    while (getline(file, matkul, ';')) {
        getline(file, judul, ';');
        getline(file, deadline, ';');
        getline(file, status, ';');
        file >> prioritas;
        file.ignore();

        daftarTugas.push_back(Tugas(nextID++, matkul, judul, deadline, status, prioritas));
    }

    file.close();
    cout << "Data berhasil dimuat.\n";
}

void ManajerTugas::saveFile(string filename) {
    ofstream file(filename);

    for (auto &t : daftarTugas) {
        file << t.matkul << ";"
             << t.judul << ";"
             << t.deadline << ";"
             << t.status << ";"
             << t.prioritas << endl;
    }

    file.close();
    cout << "Data berhasil disimpan.\n";
}
