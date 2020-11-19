#include <iostream>
#include <mutex>
#include <thread>

int a = 0;
int b = 0;

std::mutex A;
std::mutex B;

void critical() {
    // critical section 1
    A.lock();
    a = a + 1;

    B.lock();
    b = a + b;

    B.unlock();
    A.unlock();

    // critical section 2
    B.lock();
    b = b + 1;

    A.lock();
    a = a - b;

    B.unlock();
    A.unlock();


    std::cout << "A = " << a << std::endl;
    std::cout << "B = " << b << std::endl;
}


int main() {
    std::thread t1(critical);
    std::thread t2(critical);

    t1.join();
    t2.join();
    critical();
    return 0;
}