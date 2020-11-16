#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void print_arr(vector<int>& arr) {
    cout << "[";
    for (const auto& i : arr) {
        cout << i << ", ";
    }
    cout << "]" << endl;
}

// is x a coprime of y?
bool is_coprime(int x, int y) {
    cout << "comparing coprime of " << x << " and " << y << endl;
    if (gcd(x, y) == 1) {
        cout << "true" << endl;
        return true;
    }
    cout << "false" << endl;
    return false;
}

void backtrack(vector<int> &temp, int rotorCount, int minRotorValue, int maxRotorValue, vector<vector<int>> &result) {
    if (temp.size() == rotorCount) {
        print_arr(temp);
        for (int i = 1; i < temp.size(); i++) {
            if (!is_coprime(temp[0], temp[i])) {
                // just return, don't add result
                return;
            }
        }
        cout << "pushing" << endl;
        result.push_back(temp);
        return;
    }
    print_arr(temp);

    for (int i = minRotorValue; i <= maxRotorValue; i++) {
        temp.push_back(i);
        backtrack(temp, rotorCount, minRotorValue, maxRotorValue, result);
        temp.pop_back();
    }
}

// seems like all I have to do is the permutations problem, but add the condition about the subsequent
// numbers
// first I'll write the permutation backtracking algo including passing the vector, but when I get it working
// then remove the vector
int calculateTotalRotorConfiguration(int rotorCount, int minRotorValue, int maxRotorValue) {
    vector<vector<int>> result;
    if (rotorCount == 0) return 0;
    vector<int> temp;
    backtrack(temp, rotorCount, minRotorValue, maxRotorValue, result);

    cout << "printing results" << endl;
    for (auto& v: result) {
        print_arr(v);
    }
    return result.size();
}


// need a function to check whether y is a coprime of x. if it is, then don't do the function


int main() {

    int result = calculateTotalRotorConfiguration(3, 2, 4);
    cout << "result: " << result << endl;

    return 0;
}