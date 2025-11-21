#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertBeg(int x) {
    Node* n = new Node;
    n->data = x;
    n->next = head;
    head = n;
}

void insertEnd(int x) {
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

void insertBefore(int val, int x) {
    if (head == NULL) return;
    if (head->data == val) {
        insertBeg(x);
        return;
    }
    Node* t = head;
    while (t->next != NULL && t->next->data != val) t = t->next;
    if (t->next != NULL) {
        Node* n = new Node;
        n->data = x;
        n->next = t->next;
        t->next = n;
    }
}

void insertAfter(int val, int x) {
    Node* t = head;
    while (t != NULL && t->data != val) t = t->next;
    if (t != NULL) {
        Node* n = new Node;
        n->data = x;
        n->next = t->next;
        t->next = n;
    }
}

void deleteBeg() {
    if (head == NULL) return;
    Node* t = head;
    head = head->next;
    delete t;
}

void deleteEnd() {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* t = head;
    while (t->next->next != NULL) t = t->next;
    delete t->next;
    t->next = NULL;
}

void deleteVal(int val) {
    if (head == NULL) return;
    if (head->data == val) {
        deleteBeg();
        return;
    }
    Node* t = head;
    while (t->next != NULL && t->next->data != val) t = t->next;
    if (t->next != NULL) {
        Node* d = t->next;
        t->next = d->next;
        delete d;
    }
}

void search(int val) {
    Node* t = head;
    int pos = 1;
    while (t != NULL) {
        if (t->data == val) {
            cout << "Position: " << pos << endl;
            return;
        }
        t = t->next;
        pos++;
    }
    cout << "Not found\n";
}

void display() {
    Node* t = head;
    while (t != NULL) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}


