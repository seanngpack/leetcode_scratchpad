// given n, try to find min steps from 1 to n
// you can only multiple by 2
// or you can divide by 3

// ex: n = 10
// result = 6
// Explanation: 1 * 2 * 2 * 2 * 2 / 3 * 2

// ex: n = 1
// result = 0;

// ex: n = 5
// 1 * 2 * 2 * 2 * 2 / 3
// 8 /3 = 2
// 1 * 2 * 2 * 2
// if curr / 3 is in set already, then multiple by 2

// things to keep track of:
// set of seen multiples
// current value
// number of steps

// approach:
// keep multiplying curr by 2 until >= n, keeping track of how many
// if n == curr return steps
//  if n // 3 in set, then multiply by 2
//  else divide by 3
// else mult curr by 2

#include <iostream>
#include <unordered_set>


using namespace std;

int minSteps(int n) {
    if (n == 1) return 0;
    unordered_set<int> seen;
    int steps = 0;
    int curr = 1;

    seen.insert(1);

    while(!seen.empty()) {
        seen.insert(curr);
        if (curr == n) {
            return steps;
        }
        else if (curr > n) {
            if (seen.count(curr / 3)) {
                curr *= 2;
            }
            else curr /= 3;
        }
        else {
            curr *= 2;
        }
        steps++;
    }
    return steps;

}

int main() {
    int res1 = minSteps(10);
    int res2 = minSteps(1);
    int res3 = minSteps(3);

    cout << res1 << endl;
    cout << res2 << endl;
    cout << res3 << endl;

    return 0;
}