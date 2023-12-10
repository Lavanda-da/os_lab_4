#include <iostream>
#include <dlfcn.h>

// g++ -shared -o second.so second.cpp
// g++ -rdynamic -o main main_dynamic.cpp -ldl

typedef double (*E)(int x);
typedef int (*primeCount)(int a, int b);

int main() {
    void *libHandle;
    primeCount prime;
    libHandle = dlopen("./second.so", RTLD_LAZY);
    int lib;
    int r = 1;
    while(std::cin >> lib) {
        if (lib == 0 && r == 1) {
            dlclose(libHandle);
            libHandle = dlopen("./first.so", RTLD_LAZY);
            r = 2;
        } else if (lib == 0 && r == 2) {
            dlclose(libHandle);
            libHandle = dlopen("./second.so", RTLD_LAZY);
            r = 1;
        } else {
            break;
        }
    }
    if (lib == 1) {
        E e = (E)dlsym(libHandle, "E");
        int x;
        std::cin >> x;
        double result = e(x);
        std::cout << result << std::endl;
    } else if (lib == 2) {
        primeCount prime = (primeCount)dlsym(libHandle, "primeCount");
        int a, b;
        std::cin >> a >> b;
        int result = prime(a, b);
        std::cout << result << std::endl;
    }
    dlclose(libHandle);
    return 0;
}
