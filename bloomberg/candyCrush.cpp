#include <iostream>
#include <stack>
#include <string>
using namespace std;

// goal: return string after you crush the candies
// return: processed string

// constraints:
// greedily processing from left to right

// example:
// "aaabbbc" ->  "bbbc" -> "c"

// "aabbc" -> "aabbc"

// "" -> ""

// "aabbccbbabbbaa" ->
// stk:
// flag: false
// removed
// curr: "aabbccbb"

// things to keep track of:
// we might wanna use a stack
// flag to say 3 or more
// flag removed to say if we removed anything in this while iteration

// watch out for:
//

// approach:
// start at left, add to stack. move to next char.
// while (stop == false)
//   If stack.top() == current character then mark flag = true
//   else flag = false
//   if flag == true && current = stack.top(), then pop twice from stack, move onto next, mark flag f
// if we're at the end of the curr and removed = false, then set stop to true

void print_stack(stack<char> &s) {
    cout << "stack: ";
    auto copy = s;
    while(!copy.empty()) {
        cout << copy.top() << " ";
        copy.pop();
    }
    cout << endl;
}
string candy(string input) {
    stack<char> stk;
    bool stop = false;
    bool flag = false;
    bool removed = false;
    string temp = input;



    while (!stop) {
        cout << temp <<endl;
        print_stack(stk);
        stk.push(temp[0]);
        for (int i = 1; i < temp.length(); i++) {
            print_stack(stk);
//            cout << temp[i] << endl;
//            cout << "we in this" <<endl;
            if (stk.top() == temp[i] && flag == true) {
                cout << "called1";
                stk.pop();
                stk.pop();
                print_stack(stk);
                flag = false;
                removed = true;
                for (int j = i+1; j < temp.length(); j++) {
                    stk.push(temp[j]);
                }
                break;
            }
            else if (stk.top() == temp[i] && flag == false) {
                cout << "called2";
                stk.push(temp[i]);
                flag = true;
            }
            else {
                cout << "called3";
                flag = false;
                stk.push(temp[i]);
            }
        }

        flag = false;
        if (!removed) {
            stop = true;
        }
        removed = false;
        temp = "";
        while (!stk.empty()) {
            temp.push_back(stk.top());
            stk.pop();
        }

        if (temp.empty()) return temp;

        reverse(temp.begin(), temp.end());
    }

    return temp;

}

int main() {
    string result = candy("aaabbbacd");
    cout << "the answer is: " << result << endl;
    return 0;
}