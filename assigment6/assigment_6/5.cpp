bool isCircular(CNode *head){
    if(!head) return false;
    CNode *t=head->next;
    while(t && t!=head) t=t->next;
    return t==head;
}
