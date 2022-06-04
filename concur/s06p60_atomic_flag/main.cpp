#include <iostream>
#include <atomic>

int main() {
    std::atomic_flag a{ATOMIC_FLAG_INIT};
    std::atomic_flag b{true};
    std::atomic_flag c = true;
    std::atomic_flag d;

    std::cout << "Hello, World!" << std::endl;
    std::cout << "Atomic Flag: " << a.test_and_set() << '\n';
    std::cout << "Atomic Flag: " << b.test_and_set() << '\n';
    std::cout << "Atomic Flag: " << c.test_and_set() << '\n';
    std::cout << "Atomic Flag: " << d.test_and_set() << '\n';

    c.clear();
    std::cout << "Atomic Flag: " << c.test_and_set() << '\n';

    return 0;
}
