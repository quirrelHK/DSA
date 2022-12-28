#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    Node* prev;
    Node* next;
    int data =0;

    Node(int x){
        this->data = x;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node(){
        int val = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout << "Memory freed for node with data: " << val << endl;

    }
};

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node* &head, Node* &tail, int x){
    Node* temp = new Node(x);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node* &head, Node* &tail, int x){
    Node* temp = new Node(x);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtMiddle(Node* &head, Node* &tail, int pos, int x){
    if(pos==1){
        insertAtHead(head,tail,x);
        return;
    }
    else{
        Node* temp = head;
        int cnt=1;
        while(cnt < pos-1){
            temp=temp->next;
            ++cnt;
        }

        if(temp->next == NULL){
            insertAtTail(head,tail,x);
            return;
        }
        Node* node_to_insert = new Node(x);
        node_to_insert->prev = temp;
        node_to_insert->next = temp->next;
        temp->next->prev = node_to_insert;
        temp->next = node_to_insert;
    }
}

void deleteNode(Node* &head, Node* &tail, int pos){
    if(pos == 1){
        Node* temp = head;
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* prev = NULL;
        Node* cur = head;
        int cnt=1;
        while(cnt < pos){
            prev = cur;
            cur = cur->next;
            ++cnt;
        }

        if(cur->next == NULL){
            tail = cur->prev;
            cur->prev = NULL;
            tail->next = NULL;
            delete cur;
            return;
        }
        cur->next->prev = prev;
        prev->next = cur->next;
        cur->next = NULL;
        cur->prev = NULL;
        delete cur;
    }
}

int main(){
    Node* node1 = new Node(5);
    Node* head = node1;
    Node* tail = node1;


    insertAtHead(head,tail,22);
    print(head);

    insertAtMiddle(head,tail,3,55);
    print(head);

    insertAtMiddle(head,tail,1,66);
    print(head);

    insertAtMiddle(head,tail,2,10);
    print(head);

    insertAtMiddle(head,tail,2,78);
    print(head);

    insertAtMiddle(head,tail,2,66);
    print(head);

    insertAtMiddle(head,tail,2,23);
    print(head);

    deleteNode(head,tail,8);
    print(head);

    deleteNode(head,tail,1);
    print(head);

    deleteNode(head,tail,3);
    print(head);

    cout << "h:" << head->data << " t:" << tail->data;



}