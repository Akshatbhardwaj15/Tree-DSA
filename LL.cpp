#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }

};

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int length(Node *head)
{
	//Write your code here
    int cnt = 0;
    Node* temp =  head;
    while(temp){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}
void traversal(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int searchInLinkedList(Node* head, int k) {
    // Write your code here.
    Node* temp = head;
    while(temp){
        if(temp->data == k) return 1;
        temp = temp->next;
    }
    return false;
}

Node* removesHead(Node* head){
    if(head == NULL) return head;
    Node* temp  = head;
    head = head->next;
    delete temp;
    return head;
}

Node* removeTail(Node* head){
    if(head == NULL || head->next == NULL)
        return NULL;

    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;

    return head;
}

Node* delK(Node* head, int k){
    if(head == NULL) return head;
    if(k == 1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int cnt = 0; 
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* insertAtHead(Node*head, int k){
    Node* temp = new Node(k, head);
    return temp;
}
int main(){
    vector<int> arr = {12, 5, 8, 7};

    Node* head = convertArr2LL(arr);
    // cout<<head->data<<endl;
    // cout<<length(head)<<endl;
    // cout<<searchInLinkedList(head, 5)<<endl;
    // traversal(head);
    // head = removesHead(head);
    // cout<<head->data<<endl;

    // head = delK(head, 5);
    head = insertAtHead(head, 100);
    Node* temp = head;
    while(temp){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
    
}
