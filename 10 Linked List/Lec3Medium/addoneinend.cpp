#include <iostream>
#include <algorithm>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
    void print(Node* head) {
        Node* temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    Node* insertBegin(Node* head, int data) {
        Node* temp = new Node(data);
        temp->next = head;
        return temp;
    }
    int addOnefun(Node* head) { // used recursion to solve the problem.
        if (head == nullptr) {
            return 1; // first carry is sent from here.
        }
        Node* temp = head; // make sure to store the current flow of head other wise the you will miss it.
        int carry = addOnefun(head->next);
        int val = temp->data + carry;
        temp->data = val % 10;
        return (val / 10);
    }
    Node* addOne(Node* head) {
        int carry = addOnefun(head);
        if (carry > 0) {
            Node* temp = new Node(carry);
            temp->next = head;
            return temp;
        }
        return head;
    }
};
int main() {
    Node* head = NULL;
    head = head->insertBegin(head, 9);
    head = head->insertBegin(head, 9);
    head = head->insertBegin(head, 9);
    head = head->insertBegin(head, 9);
    head = head->addOne(head);
    head->print(head);
    return 0;
}