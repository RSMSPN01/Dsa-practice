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
    Node* insertEnd(Node* head, int data) {
        Node* newNode = new Node(data);
        if (head == NULL)
        {
            return newNode;
        }
        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        return head;
    }
    Node* delHead(Node* head) {
        if (head == NULL)
        {
            return NULL;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return head;
    }
    Node* delLast(Node* head) {
        if (head == NULL)
        {
            return NULL;
        }
        if (head->next == NULL)
        {
            delete head;
            return NULL;
        }
        Node* temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        return head;
    }
    Node* insertAtIndex(Node* head, int pos, int data) {
        if (pos == 1)
        {
            return (insertBegin(head, data));
        }
        Node* curen = head;
        int count = 1;
        while (curen != NULL)
        {
            if (count == pos - 1)
            {
                break;
            }
            count++;
            curen = curen->next;
        }
        if (curen != NULL && count == pos - 1)
        {
            Node* temp = curen->next;
            curen->next = new Node(data);
            curen->next->next = temp;
        }
        return head;
    }
    int searchValue(Node* head, int k) {
        if (head == NULL)
        {
            return -1;
        }
        Node* temp = head;
        int count = 1;
        while (temp != NULL)
        {
            if (temp->data == k)
            {
                return count;
            }
            count++;
            temp = temp->next;
        }
        return -1;
    }
};
int main() {
    Node* head = NULL;
    head = head->insertBegin(head, 50);
    head = head->insertBegin(head, 30);
    head = head->insertBegin(head, 10);
    head->insertEnd(head, 5);
    head->insertEnd(head, 6);
    head = head->delHead(head);
    head = head->delLast(head);
    head = head->insertAtIndex(head, 1, 20);
    head = head->insertAtIndex(head, 3, 90);
    cout << head->searchValue(head, 40) << endl;
    head->print(head);
    return 0;
}