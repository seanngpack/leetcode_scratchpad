#include <iostream>
#include <math.h>

int factors3and5(int low, int high) {
    // find max x
    int x, y = -1;
    int exp3, exp5 = 1;
    while (exp3 <= high) {
        exp3 *= 3;
        x++;
    }
    // find max y
    while (exp5 <= high) {
        exp5 *= 5;
        y++;
    }

    int total = 0;
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            int res = pow(3, i) * pow(5, j);

            if (res >= low && res <= high ) {
                std::cout << "x: " << i << std::endl;
                std::cout << "y: " << j << std::endl;
                std::cout << "res:" << res << std::endl;
                total++;
            }
        }
    }
    return total;
}

int main() {
    std::cout << "hi" << std::endl;
    std::cout << factors3and5(100000, 10000000000) << std::endl;
    return 0;
}