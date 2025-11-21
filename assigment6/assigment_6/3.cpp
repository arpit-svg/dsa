int sizeD(DoublyList &d){
    int c=0;
    DNode *t=d.head;
    while(t){ c++; t=t->next; }
    return c;
}

int sizeC(CircularList &c){
    if(!c.head) return 0;
    int c1=0;
    CNode *t=c.head;
    do{
        c1++;
        t=t->next;
    }while(t!=c.head);
    return c1;
}
