// These all are the basics for the DLL
#include <iostream>
#include <vector>
#include <algorithm>
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
    // insert node at head
    Node* insertHead(Node* head, int x) {
        if (head == NULL)
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
    //Deleting first node
    Node* deletefNode(Node* head) {
        if (head->next == NULL && head->prev == NULL)
        {
            return NULL;
        }
        Node* temp = head;
        head = temp->next;
        head->prev = NULL;
        delete temp;
        return head;
    }
    Node* deleteOccurences(Node* head, int target) {
        if (head == nullptr) {
            return nullptr;
        }
        Node* temp = head;
        while (temp != nullptr)
        {
            // check for the head first if same them remove that seprately
            if (temp->data == target && temp == head) {
                // it means pointing to head node
                Node* temp2 = temp;
                head = head->next;
                temp = temp->next;
                delete temp2;
            } else if (temp->data == target && temp->next == nullptr) {
                // it means we are at the last node of ll 
                // here memory leak in not handled
                Node* temp2 = temp;
                temp->prev->next = nullptr;
                temp = temp->next;
                delete temp2;
            } else if (temp->data == target) {
                // handle memory leak
                temp->prev->next = temp->next;
                temp = temp->next;
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};
int main() {
    Node* head = new Node(10);
    Node* temp = new Node(5);
    Node* temp1 = new Node(5);
    head->next = temp;
    temp->prev = head;
    temp->next = temp1;
    temp1->prev = temp;
    head = head->insertHead(head, 5);
    head = head->insertHead(head, 5);
    head = head->insertHead(head, 5);
    head = head->deleteOccurences(head, 5);
    head->print(head);
    return 0;
}