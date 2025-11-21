#include<iostream>
using namespace std;
class node{
public:

    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;

    }
    ~node() {
        
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
    }

};
void insertnode(node*&tail,int element,int d){
    if(tail==NULL){
        node* n1= new node(d);
        tail=n1;
        n1->next=n1;
        return;
    }
    else{
        node* curr=tail;
        while(curr->data!=element){
            curr=curr->next;

        }
        node* temp=new node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
   
}
void print(node* tail) {

    node* temp = tail;

    //empty list
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }

    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);

    cout << endl;
} 


int main(){
    node*tail=NULL;
    insertnode(tail,3,5);
    insertnode(tail,5,6);
    insertnode(tail,6,7);
    print(tail);
    return 0;
}