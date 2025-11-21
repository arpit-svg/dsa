#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next; // pointer, not object

    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertInFront(node*& head, int data) {
    node* temp = new node(data);
    temp->next = head;
    head = temp;
}

void print(node* &head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void reverse(node*&head){
    node*prev=NULL;
    node*curr=head;
    while(curr!=NULL){
        node*forward=curr->next;
        curr->next=prev;
        curr=forward;

    }
    head=prev;

}

int main() {
    node* n1 = new node(20);
    node* head = n1;

    insertInFront(head, 15);
    insertInFront(head, 10);
    insertInFront(head,30);
    reverse(head);
    print(head);
    
    

    

    return 0;
}
