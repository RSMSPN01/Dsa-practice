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
        int carry = addOnefun(head->next);
        int val = head->data + carry;
        head->data = val % 10; // this is unnecassary becs if val is >10 it means we have to directly store 10 in it not other no.
        return (val / 10); // similary here you can return only 1 and 0 rather then this because only 1 or 0 can be a valid carry.
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