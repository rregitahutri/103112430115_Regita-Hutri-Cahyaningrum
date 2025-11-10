#include "stackGame.h"
#include <iostream> 
#include <iomanip>

void printTableRow(const std::string &aksi, const Stack &StackAksi, const Stack &StackRedo) {
    std::cout << "| " << std::left << std::setw(8) << aksi;
    
    std::cout << "| " << std::left << std::setw(30) << getStackString(StackAksi);
    std::cout << " Top = " << std::left << std::setw(5) << StackAksi.top;

    std::cout << "| " << std::left << std::setw(30) << getStackString(StackRedo);
    std::cout << " Top = " << std::left << std::setw(5) << StackRedo.top << "|" << std::endl;
}

int main() {
    Stack StackAksi, StackRedo;
    create_stack(StackAksi);
    create_stack(StackRedo);

    // Untuk Header Tabel
    std::cout << "+-" << std::string(8, '-') << "+-" << std::string(42, '-') << "+-" << std::string(42, '-') << "+" << std::endl;
    std::cout << "| " << std::left << std::setw(8) << "Aksi";
    std::cout << "| " << std::left << std::setw(42) << "Stack Aksi";
    std::cout << "| " << std::left << std::setw(42) << "Stack Redo" << "|" << std::endl;
    std::cout << "+-" << std::string(8, '-') << "+-" << std::string(42, '-') << "+-" << std::string(42, '-') << "+" << std::endl;

    kelolaAksi("ATTACK", StackAksi, StackRedo);
    printTableRow("ATTACK", StackAksi, StackRedo);

    kelolaAksi("ATTACK", StackAksi, StackRedo);
    printTableRow("ATTACK", StackAksi, StackRedo);

    kelolaAksi("DEFENSE", StackAksi, StackRedo);
    printTableRow("DEFENSE", StackAksi, StackRedo);

    kelolaAksi("ATTACK", StackAksi, StackRedo);
    printTableRow("ATTACK", StackAksi, StackRedo);

    kelolaAksi("UNDO", StackAksi, StackRedo);
    printTableRow("UNDO", StackAksi, StackRedo);
    
    kelolaAksi("UNDO", StackAksi, StackRedo);
    printTableRow("UNDO", StackAksi, StackRedo);

    kelolaAksi("REDO", StackAksi, StackRedo);
    printTableRow("REDO", StackAksi, StackRedo);
    
    kelolaAksi("DEFENSE", StackAksi, StackRedo);
    printTableRow("DEFENSE", StackAksi, StackRedo);

    std::cout << "+-" << std::string(8, '-') << "+-" << std::string(42, '-') << "+-" << std::string(42, '-') << "+" << std::endl;

    return 0;
}