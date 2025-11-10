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
    // Reverse is done using extra space (vector) so the space complexity = O(n).
    // and we have traverse the LL twice so overall time Complexity is also = O(n).
    void reverseNode(Node* head) {
        // using vector to reverse the LL
        // Node* temp = head;
        // vector<int>v;
        // while (temp != NULL)
        // {
        //     v.push_back(temp->data); // stored into the vector
        //     temp = temp->next;
        // }
        // reverse(v.begin(), v.end());
        // int i = 0;
        // Node* temp2 = head;
        // while (temp2 != NULL)
        // {

        //     temp2->data = v[i++];
        //     temp2 = temp2->next;
        // }

        // using two pointer approach to solve the problem
        // but still we don't have the tail so we did two traversals of the linked List.
        Node* temp = head;
        int count = 0;
        while (temp->next != NULL)
        {
            count++;
            temp = temp->next;
        }
        Node* temp1 = head;
        while (count / 2)
        {
            int tempValue = temp->data;
            temp->data = temp1->data;
            temp1->data = tempValue;
            temp1 = temp1->next;
            temp = temp->prev;
            count /= 2;
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
    head = head->insertHead(head, 5);
    head = head->insertHead(head, 5);
    head = head->deletefNode(head);
    head->reverseNode(head);
    head->print(head);
    return 0;
}