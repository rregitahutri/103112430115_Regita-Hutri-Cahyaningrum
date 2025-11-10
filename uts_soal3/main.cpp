#include "stackGame.h"
#include <iostream> 

int main() {
    Stack StackAksi, StackRedo;
    create_stack(StackAksi);
    create_stack(StackRedo);
    int totalDamage; // Deklarasikan di atas

    std::cout << "--- Program Dimulai ---" << std::endl;
    printStack(StackAksi, "Stack Aksi");
    printStack(StackRedo, "Stack Redo");

    std::cout << "\n--- Aksi 1: ATTACK ---" << std::endl;
    kelolaAksi("ATTACK", StackAksi, StackRedo);
    printStack(StackAksi, "Stack Aksi");
    printStack(StackRedo, "Stack Redo");

    std::cout << "\n--- Aksi 2: ATTACK ---" << std::endl;
    kelolaAksi("ATTACK", StackAksi, StackRedo);
    printStack(StackAksi, "Stack Aksi");
    printStack(StackRedo, "Stack Redo");

    std::cout << "\n--- Aksi 3: DEFENSE ---" << std::endl;
    kelolaAksi("DEFENSE", StackAksi, StackRedo);
    printStack(StackAksi, "Stack Aksi");
    printStack(StackRedo, "Stack Redo");
    
    std::cout << "\n--- Hitung Damage Awal ---" << std::endl;
    hitungTotalDamage(StackAksi, totalDamage);
    std::cout << "Total Damage: " << totalDamage << std::endl; // Harusnya 65

    std::cout << "\n--- Aksi 4: UNDO ---" << std::endl;
    kelolaAksi("UNDO", StackAksi, StackRedo);
    printStack(StackAksi, "Stack Aksi");
    printStack(StackRedo, "Stack Redo");
    hitungTotalDamage(StackAksi, totalDamage);
    std::cout << "Total Damage setelah UNDO: " << totalDamage << std::endl; // Harusnya 60

    std::cout << "\n--- Aksi 5: REDO ---" << std::endl;
    kelolaAksi("REDO", StackAksi, StackRedo);
    printStack(StackAksi, "Stack Aksi");
    printStack(StackRedo, "Stack Redo");
    hitungTotalDamage(StackAksi, totalDamage);
    std::cout << "Total Damage setelah REDO: " << totalDamage << std::endl; // Harusnya 65

    return 0;
}