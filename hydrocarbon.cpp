#include <iostream>
#include <string>
#include <stdlib.h>

void drawVerticalLines(int stringLength) {
    std::cout << "  ";
    for (int i = 0; i < stringLength-4; ++i) {
        std::cout << (i % 2 == 0 ? "|" : " ");
    }
    std::cout << "  \n";
}

void drawHydrogenLine(int stringLength) {
    std::cout << "  ";
    for (int i = 0; i < stringLength-4; ++i) {
        std::cout << (i % 2 == 0 ? "H" : " ");
    }
    std::cout << "  \n";
}

int main() {
    int carbonAmount;

    std::cout << "Set amount of Carbon atoms: ";
    std::cout << "\n> ";
    std::cin >> carbonAmount;
    int hydrogenAmount = 2*carbonAmount+2;
    int carbonBoundsAmount = carbonAmount - 1;
    int carbonHydrogenBoundsAmount = hydrogenAmount;
    int stringLength = 2*carbonAmount+3; 
    

    drawHydrogenLine(stringLength);
    drawVerticalLines(stringLength);

    std::cout << "H-";
    for (int i = 0; i < stringLength - 4; ++i) {
        std::cout << (i % 2 == 0 ? "C" : "-");
    }
    std::cout << "-H\n";

    drawVerticalLines(stringLength);
    drawHydrogenLine(stringLength);

    
    std::cout << "\nAmount of carbon atoms: " << carbonAmount << "\n"; 
    std::cout << "Amount of hydrogen atoms: " << hydrogenAmount << "\n"; 
    std::cout << "Amount of bounds between carbon atoms: " << carbonBoundsAmount << "\n"; 
    std::cout << "Amount of bounds between carbon and hydrogen atoms: " << carbonHydrogenBoundsAmount << "\n";
    std::cout << "\n";
    return 0;
}