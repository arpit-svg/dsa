#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = NULL;

void push(int x) {
    Node* n = new Node;
    n->data = x;
    n->next = head;
    head = n;
}

int main() {
    int n, x, key;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        push(x);
    }
    cin >> key;

    int cnt = 0;
    Node* t = head;
    while (t != NULL) {
        if (t->data == key) cnt++;
        t = t->next;
    }
    cout << "Count: " << cnt << endl;

    while (head != NULL && head->data == key) {
        Node* d = head;
        head = head->next;
        delete d;
    }

    Node* p = head;
    while (p != NULL && p->next != NULL) {
        if (p->next->data == key) {
            Node* d = p->next;
            p->next = d->next;
            delete d;
        } else p = p->next;
    }

    p = head;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}
