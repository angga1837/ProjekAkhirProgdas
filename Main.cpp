#include <bits/stdc++.h>
#include "ManajerTugas.h"
using namespace std;

int main() {
    ManajerTugas app;

    int pilihan;

    while (true) {
        cout << endl;
        cout << "=== Aplikasi Manajemen Tugas Kuliah ===\n";
        cout << "1. Tambah Tugas\n";
        cout << "2. Edit Tugas\n";
        cout << "3. Hapus Tugas\n";
        cout << "4. Tampilkan Semua\n";
        cout << "5. Cari Tugas\n";
        cout << "6. Sort by Deadline\n";
        cout << "7. Sort by Prioritas\n";
        cout << "8. Load File (input.txt)\n";
        cout << "9. Save File (output.txt)\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: app.addTugas(); break;
            case 2: app.editTugas(); break;
            case 3: app.deleteTugas(); break;
            case 4: app.tampilkanSemua(); break;
            case 5: app.cariTugas(); break;
            case 6: app.sortByDeadline(); break;
            case 7: app.sortByPrioritas(); break;
            case 8: app.loadFile("input.txt"); break;
            case 9: app.saveFile("output.txt"); break;
            case 0: return 0;
            default: cout << "Pilihan tidak valid!\n";
        }
    }
}
