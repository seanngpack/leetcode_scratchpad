#include <iostream>
#include <vector>

using namespace std;

vector<string> checksum(const vector<string> &accs) {
    vector<string> result;
    for (const auto& acc : accs) {

        string first_6 = acc.substr(0, 6);
        string last_2 = acc.substr(6, 2);

        // sum the first 6, first convert to int, then string, then iterate through string summing
        int sum_6 = 0;
        string first_6_str = to_string(stoi(first_6, 0, 16));
        for (const auto& c : first_6_str) {
            int num = c - '0';
            sum_6 += num;
        }

        cout << sum_6 << endl;

        //get decimal rep of last two digits
        int last_2_int = stoi(last_2, 0, 16);


        cout << last_2_int << endl;

        if (sum_6 == last_2_int) {
            result.push_back("VALID");
        }
        else {
            result.push_back("INVALID");
        }
    }
    return result;
}

int main() {
    vector<string> result = checksum({"8BADF00D", "C0FFEE1C"});
    for (const auto& s: result) {
        cout << s << endl;
    }

    return 0;
}