#ifndef MANAJER_TUGAS_H
#define MANAJER_TUGAS_H

#include <vector>
#include "Tugas.h"

class ManajerTugas {
private:
    vector<Tugas> daftarTugas;
    int nextID;

public:
    ManajerTugas();

    void addTugas();
    void editTugas();
    void deleteTugas();
    void tampilkanSemua();
    void cariTugas();
    void sortByDeadline();

    void loadFile(string filename);
    void saveFile(string filename);
};

#endif
