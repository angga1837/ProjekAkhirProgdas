#ifndef TUGAS_H
#define TUGAS_H

#include <bits/stdc++.h>
using namespace std;

class Tugas {
public:
    int id;
    string matkul;
    string judul;
    string deadline;
    string status;
    int prioritas;

    Tugas(int id, string matkul, string judul, string deadline, string status, int prioritas);

    void display();
};

#endif
