#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = NULL;

void pushEnd(int x) {
    Node* n = new Node;
    n->data = x;
    n->next = NULL;
    if (head == NULL) head = n;
    else {
        Node* t = head;
        while (t->next != NULL) t = t->next;
        t->next = n;
    }
}

int main() {
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        pushEnd(x);
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* nxt;

    while (curr != NULL) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    head = prev;

    Node* t = head;
    while (t != NULL) {
        cout << t->data << " ";
        t = t->next;
    }
}
