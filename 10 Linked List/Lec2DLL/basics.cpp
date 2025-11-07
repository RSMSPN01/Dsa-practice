#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data) {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
    void print(Node* head) {
        Node* temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    
};
int main() {
    Node* head = new Node(10);
    Node* temp = new Node(20);
    Node* temp1 = new Node(30);
    head->next = temp;
    temp->prev = head;
    temp->next = temp1;
    temp1->prev = temp;
    head->print(head);
    return 0;
}