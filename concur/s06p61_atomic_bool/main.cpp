#include <iostream>
#include <atomic>

int main() {

    std::atomic<bool> a;
    std::cout << "Atomic Bool a: " << a << '\n';

    std::atomic<bool> b{1};
    std::cout << "Atomic Bool b: " << b << '\n';
    b = 0;
    std::cout << "Atomic Bool b after assigning false: " << b << '\n';
    std::cout << "Is Lock Free: " << b.is_lock_free() << '\n';
    std::cout << "Load: " << b.load() << '\n';
    b.store(1);
    std::cout << "Load after store(1): " << b.load() << '\n';
    b.store(a);
    std::cout << "Load after store(a): " << b.load() << '\n';

    return 0;
}
