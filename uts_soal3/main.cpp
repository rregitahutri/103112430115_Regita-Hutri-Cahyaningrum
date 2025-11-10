#include "stackGame.h"
#include <iostream> // Diperlukan untuk cout/endl

int main() {
    Stack StackAksi, StackRedo;
    create_stack(StackAksi);
    create_stack(StackRedo);

    kelolaAksi("ATTACK", StackAksi, StackRedo);
    kelolaAksi("ATTACK", StackAksi, StackRedo);
    kelolaAksi("DEFENSE", StackAksi, StackRedo);

    int totalDamage;
    hitungTotalDamage(StackAksi, totalDamage);
    std::cout << "Total Damage: " << totalDamage << std::endl;

    kelolaAksi("UNDO", StackAksi, StackRedo);
    hitungTotalDamage(StackAksi, totalDamage);
    std::cout << "Total Damage setelah UNDO: " << totalDamage << std::endl;

    kelolaAksi("REDO", StackAksi, StackRedo);
    hitungTotalDamage(StackAksi, totalDamage);
    std::cout << "Total Damage setelah REDO: " << totalDamage << std::endl;

    return 0;
}    