#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node * next;
};

// Traversing a Linked List
void printList(Node *head) {
    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

// Add Node at front
void push(Node **head_ref, int new_value) {
    Node * new_node = new Node();
    new_node->data = new_value;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Add Node after a given node
void insertAfter(Node * prevnode, int val) {
    if(prevnode == NULL) {
        return;
    }
    Node * newnode = new Node();
    newnode->data = val;
    newnode->next = prevnode->next;
    prevnode->next = newnode;
}

void append(Node **head_ref, int new_value) {
    Node * new_node = new Node();
    new_node->data = new_value;
    new_node->next = NULL;

    // if LL is empty
    if(*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // if LL is not empty
    Node * temp = *head_ref;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Deleting a node
void deleteIt(Node **head_ref, int key) {
    Node * temp = *head_ref;
    Node * prev = NULL;
    // If key is at head
    if(temp->data == key && temp != NULL) {
        *head_ref = temp->next;
        delete(temp);
        return;
    }

    // Find first occurance of key
    while(temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        return;
    }

    prev->next = temp->next;
    delete(temp);
}

void deleteRec(Node *&head_ref, int key){
    // element not found
    if(head_ref == NULL) {
        return;
    }

    // base case
    if(head_ref->data == key){
        Node * temp = head_ref;
        head_ref = head_ref->next;
        delete(temp);
        return;
    }

    // Reursive
    deleteRec(head_ref->next, key);
}

void deletePos(Node **head_ref, int position) {
    Node * temp = *head_ref;
    Node * prev = NULL;
    for(int i = 0; i < position; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == *head_ref){
        *head_ref = temp->next;
        delete(temp);
        return;
    }
    prev->next = temp->next;
    delete(temp);
}

void deleteLL(Node **head_ref) {
    while(*head_ref != NULL) {
        Node * temp = *head_ref;
        *head_ref = temp->next;
        delete(temp);
    }
}

int lengthLLIt(Node **head_ref) {
   int length = 0;
   Node * temp = *head_ref;
   while(temp != NULL) {
       length++;
       temp = temp->next;
   }
   delete(temp);
   return length;
}

int lengthLLRec(Node **head_ref) {
   // base case
   Node * temp = *head_ref;
   if(temp == NULL) {
       delete(temp);
       return 0;
   }
   // Recursive case
   return (1 + lengthLLRec(&temp->next));
}

bool searchIt(Node *head, int key) {
    Node * temp = head;
    while(temp != NULL) {
        if(temp->data == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool searchRec(Node *head, int key) {
    // base case
    if(head == NULL) {
        return false;
    }
    if(head->data == key) {
        return true;
    }
    // Recursive case
    return searchRec(head->next, key);
}

int getNthIt(Node **head_ref, int n) {
    Node * temp = *head_ref;
    int count = 0;
    while(temp != NULL) {
        if(count == n){
            return temp->data;
        }
        count++;
        temp = temp->next;
    }
    return -1;
}

int getNthRec(Node **head_ref, int n) {
    // base case
    Node * temp = *head_ref;
    if(temp == NULL) {
        delete(temp);
        return -1;
    }

    if(n == 0) {
        return temp->data;
    }

    // Recursive case
    return getNthRec(&temp->next, n-1);
}

int main() {
    Node * head = NULL;
    Node * first = NULL;
    Node * second = NULL;
    Node * third = NULL;

    first = new Node();
    second = new Node();
    third = new Node();

    head = first;

    first->data = 1;
    first->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    push(&head, 0);
    insertAfter(second, 22);
    // insertAfter(fourth, 44);
    append(&head, 4);
    append(&head, 5);

    printList(head);

    // deleteIt(&head, 0);
    // deleteRec(head, 22);
    // deleteRec(head, 6);
    // printList(head);

    // deletePos(&head, 0);
    // deleteLL(&head);
    // printList(head);
    cout<<searchIt(head, 22)<<endl<<"Deleting 22...\n";    
    deleteIt(&head, 22);
    // cout<<searchIt(head, 22)<<endl;
    printList(head);
    cout<<searchRec(head, 22)<<endl;

    cout<<"length It: "<<lengthLLIt(&head)<<endl;
    cout<<"length Rec: "<<lengthLLRec(&head)<<endl;

    cout<<"Found 3rd Node: "<<getNthRec(&head, 3)<<endl;
    cout<<"Didn't find 9th Node: "<<getNthRec(&head, 9)<<endl;

    // delete(first);
    // delete(second);
    // delete(third);

    return 0;
}