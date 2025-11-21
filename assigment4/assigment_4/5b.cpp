#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        int s = q.size();
        while (s > 1) {
            q.push(q.front());
            q.pop();
            s--;
        }
    }

    void pop() {
        if (!q.empty()) q.pop();
    }

    int top() {
        return q.front();
    }
};
