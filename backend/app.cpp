#include <iostream>
#include <cstdlib>

int main() {
    std::cout << "Served by backend: " << getenv("HOSTNAME") << std::endl;
    return 0;
}
