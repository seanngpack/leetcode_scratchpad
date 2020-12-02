// We consider an alphabet with only three letters: a, b, c. a string is called diverse if not hree consecutive letters
// are the same. In other words, a diverse string may not contain any of the strings "aaa", "bbb", "ccc".
#include <iostream>
#include <queue>
#include <stack>
#include <map>

using namespace std;

string solution(int A, int B, int C) {
    map<char, int> m = {{'a', A}, {'b', B}, {'c', C}};
    queue<char> q;
    stack<char> s;

    // set up the q
    for (const auto& pair : m) {
        if (pair.second) q.push(pair.first);
    }

    string result = "";

    s.push(q.front());
    m[q.front()]--;
    result.push_back(q.front());

    bool warn = false;
    while (!s.empty()) {
        cout << result << endl;
        char front = q.front();

        // if the count is 0 then remove from queue
        if (m[front] < 1) {
            q.pop();
            continue;
        }

        // if there's 2 items, then pop the front of the queue and add it to the back
        // and continue
        if (warn) {
            q.pop();
            q.push(front);
            warn = false;
            continue;
        }

        // if the top of the stack matches, that means ur gonna have 2 in a row, so turn on warning
        // else, pop the top of the stack and add
        if (s.top() == front) {
            warn = true;
        }
        else {
            s.pop();
            s.push(front);
        }
        
        result.push_back(front);

        // decrement count and add to stack, also check for warning
        m[front]--;






    }
    return result;

}

int main() {
    cout << "ueet" << endl;
    cout << solution(1, 3, 1) << endl;

    return 0;
}