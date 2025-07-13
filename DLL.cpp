#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;
    
    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convert2ArrDLL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* prev = head;
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;

    delete prev;
    return head;
}

Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }

    Node* prev = tail->back;
    prev->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}

Node* removeKthElement(Node* head, int k){
    if(head == NULL){
        return NULL;
    }

    int cnt = 0;
    Node* kNode = head;
    while(kNode != NULL){
        cnt++;
        if(cnt == k) break;
        kNode = kNode->next;
    }

    Node* prev = kNode->back;
    Node* next = kNode->next;

    if(prev == NULL && next == NULL) return NULL;

    else if(prev == NULL){
        return deleteHead(head);
    }
    else if(next == NULL){
        return deleteTail(head);
    }
    prev->next = next;
    next->back = prev;
    kNode->next = nullptr;
    kNode->back = nullptr;
    delete kNode;
    return head;
}

Node* deleteNode(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;

    if(front == NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return prev;
    }
}

Node* insertAtHead(Node* head, int val){
    Node* newNode = new Node(val, head, nullptr);
    head->back = newNode;

    return newNode;
}

Node* insertBeforeTail(Node* head, int val){
    if(head->next == NULL){
        return insertAtHead(head, val);
    }

    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }

    Node* prev = tail->back;
    Node* newNode = new Node(val, tail, prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){
    vector<int> arr = {12, 5, 8, 7};
    Node* head = convert2ArrDLL(arr);
    
    // Node* newHead = deleteTail(head);
    // head = newHead;
    // Node* newHead = removeKthElement(head, 2);

    // head = newHead;

    head = insertAtHead(head, 10);
    print(head);
    return 0;
}