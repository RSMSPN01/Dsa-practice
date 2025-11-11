#include <iostream>
using namespace std;
class Node {
public:
    int data = 0;
    Node* next = nullptr;
    Node* prev = nullptr;
    Node(int data) :data(data), next(nullptr), prev(nullptr) {}
    void printLL(Node* head) {
        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    Node* insertAtHead(int x, Node* head) {
        if (head == nullptr)
        {
            Node* temp = new Node(x);
            return temp;
        }
        Node* temp = new Node(x);
        temp->next = head;
        head->prev = temp;
        head = temp;
        return head;
    }
    // So i have also tried to solve this question in many different ways in the basics.cpp file
    // This is the most efficient way to solve this problem by using swapping of links 
    // This works in only one traversal of the LL and is more efficient
    // The login went from two travesal with space then two traversal without space and now single traversal
    Node* reverseList(Node* head) {
        if (head == nullptr)
        {
            return nullptr;
        }
        if (head->prev == nullptr && head->next == nullptr)
        {
            return head;
        }
        Node* temp = head;
        while (temp->next != nullptr)
        {
            Node* help = temp->next;
            swap(temp->next, temp->prev);
            temp = help;
        }
        swap(temp->next, temp->prev);
        return temp;
    }
};
int main() {
    Node* head = nullptr;
    head = head->insertAtHead(50, head);
    head = head->insertAtHead(40, head);
    head = head->insertAtHead(30, head);
    head = head->insertAtHead(20, head);
    head = head->reverseList(head);
    head->printLL(head);
    return 0;
}