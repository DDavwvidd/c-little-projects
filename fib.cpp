#include <vector>
#include <iostream>

int main() {
    int a = 0;
    int b = 1;
    std::cout << a << "\n";
    std::cout << b << "\n";

    int c = a + b;

    long int until = 100;

    while (c < until) {
        std::cout << c << "\n";
        a = b;
        b = c;
        c = a + b;
    }
}
