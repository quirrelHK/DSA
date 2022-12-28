#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout << "Memory freed for node with data: " << value << endl;
    }
};

void insertAtHead(Node* &head, int d){
    // If we use pointer then a copy of LL will be created that is why we pass by reference
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);

    tail->next = temp;
    tail = tail->next;
}

void insertInMiddle(Node* &head, Node* &tail, int d, int pos){
    if(pos == 1){
        insertAtHead(head,d);
        return;
    }

    Node* temp = head;
    int cnt=1;
    while(cnt < pos-1){
        if(temp->next == NULL) break;

        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL){
        insertAtTail(tail,d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(Node* &head, Node* &tail, int pos){
    if(pos==1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL; // Before deleting we need to make sure that that node is not pointing to any other node
        delete temp;
    }
    else{
        int cnt=1;
        Node* prev = NULL;
        Node* cur = head;
        while(cnt < pos){
            prev = cur;
            cur = cur->next;
            cnt++;
        }
        if(cur->next == NULL){
            tail = prev;
        }
        prev->next = cur->next;
        cur->next = NULL;
        delete cur;
    }
}

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

 Node* divide(int N, Node *head){
        Node* temp = head;
        Node* even = NULL;
        Node* odd = NULL;
        Node* ehead = head;
        Node* ohead = head;
        while(temp){
            if(even == NULL && (temp->data)%2==0){
                
                even = temp;
                even->next = NULL;
                ehead = even;
            }
            else if(odd == NULL && (temp->data)%2==1){
                odd = temp;
                odd->next = NULL;
                ohead=odd;
            }
            else{
                if( (temp->data)%2==0){
                    even->next = temp;
                    
                    if(even->next != NULL)
                        even = even->next;
                }
                else{
                    odd->next = temp;
                    
                    if(odd->next != NULL)
                        odd = odd->next;
                }
            }
            
            temp = temp->next;
            
        }
        
        // even->next = ohead;
        // odd->next = NULL;
        
        while(ohead){
            cout << ohead->data << " ";
            ohead = ohead->next;
        }
        cout << endl;
        
        while(ehead){
            cout << ehead->data << " ";
            ehead = ehead->next;
        }
        
        // return ehead;
        return NULL;
        
        
        
    }

int main(){

    Node* head = new Node(17);
    Node* tail = head;   // When only one node is there head & tail will point to the same node 
    
    // cout << head->data << endl;
    // cout << head->next << endl;


    // insertAtHead(head,11);
    // print(head);

    // insertAtTail(tail,13);
    // print(head);

    // insertAtTail(tail,20);
    // print(head);

    // insertInMiddle(head,tail,12,3);
    // print(head);

    // insertInMiddle(head,tail,22,6);
    // print(head);

    // deleteNode(head,tail,6);
    // print(head);
    // cout << "head: " << head->data << endl;
    // cout << "tail: " << tail->data << endl;
    
 
    insertAtTail(tail,15);
    insertAtTail(tail,8);
    insertAtTail(tail,9);
    insertAtTail(tail,2);
    insertAtTail(tail,4);
    insertAtTail(tail,6);

    print(head);

    divide(7,head);
    


    return 0;
}