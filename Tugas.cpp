#include "Tugas.h"

Tugas::Tugas(int id, string matkul, string judul, string deadline, string status, int prioritas) {
    this->id = id;
    this->matkul = matkul;
    this->judul = judul;
    this->deadline = deadline;
    this->status  = status;
    this->prioritas = prioritas;
}

void Tugas::display() {
    cout << "ID: " << id << endl;
    cout << "Mata Kuliah: " << matkul << endl;
    cout << "Judul: " << judul << endl;
    cout << "Deadline: " << deadline << endl;
    cout << "Status: " << status << endl;
    cout << "Prioritas: " << prioritas << endl;
    cout << "-----------------------------------" << endl;
}