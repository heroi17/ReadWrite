#include <iostream>
#include <chrono>
#include <thread>


void readTest() {
    using namespace std::chrono;
    size_t INTBYTES = ((size_t)pow(2., 34)) / sizeof(int);

    int* dataPtr = new int[INTBYTES];

    size_t minListSize = 512; // 512b - min size of mem list.

    for (size_t i = 0; i < INTBYTES; i += minListSize / sizeof(int)) {
        auto el = const_cast<const volatile int*>(dataPtr)[i];
        std::this_thread::sleep_for(10ms);
    }
    delete[] dataPtr;

}


void writeTest() {
    using namespace std::chrono;
    size_t INTBYTES = ((size_t)pow(2., 34)) / sizeof(int);

    int* dataPtr = new int[INTBYTES];

    size_t minListSize = 512;

    for (size_t i = 0; i < INTBYTES; i += minListSize / sizeof(int)) {
        const_cast<volatile int*>(dataPtr)[i] = 0;
        std::this_thread::sleep_for(10ms);
    }
    delete[] dataPtr;

}
#define ReadTest false

int main() {
#if ReadTest
    readTest();
#else
    writeTest();
#endif 
    return 0;
}
