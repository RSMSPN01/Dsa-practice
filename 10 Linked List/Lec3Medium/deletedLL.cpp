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
        //it is not the most efficient way to write the code we can even write it more bettwe then this see the code below.
        // Node* curr = head;
        // while (curr != nullptr)
        // {
        //     // checking for head first if head and current is same then move head and current both ahead by one
        //     if (curr->data == target && curr == head) {
        //         Node* temp = head; // make a temp node to point the node to remove.
        //         head = head->next; // move head and current one step ahead
        //         curr = curr->next;
        //         head->prev = nullptr; // make sure to add this line other wise it is a dangling pointer.
        //         delete temp; // free the memory
        //     } else if (curr->data == target && curr->next == nullptr) {
        //         // it means we are standing at the tail which need to be removed from the LL
        //         curr->prev->next = nullptr; // make the prev of last as nullptr
        //         delete curr; // free the memory for the tail node. // it will not delete the pointer but only where it is pointing to
        //         curr = nullptr; // and safely end the code.
        //     } else if (curr->data == target) {
        //         // it is the middle of LL 
        //         Node* nextNode = curr->next; // store the value where we should move ahead.
        //         curr->prev->next = nextNode; // change the previous node and point it to the next node of the current node
        //         nextNode->prev = curr->prev; // change the next node's prev and point it to the currn node's prev.
        //         delete curr; // free the memory 
        //         curr = nextNode; // and move ahead to the next node.
        //     } else {
        //         curr = curr->next;
        //     }
        // }
        // return head;

        // Efficient code written from the striver sheet
        // in this we don't have to handle the cases seprately for the head,tail and middle we can do it together
        Node* curr = head;
        while (curr != nullptr)
        {
            if (target == curr->data) // simply check here if target is matched or not if yes then go ahead else come back
            {
                if (curr == head) { // if it is at the head then handle it seprately
                    head = head->next;
                    head->prev = nullptr;
                    curr = head;
                } else {
                    Node* prevNode = curr->prev;
                    Node* nextNode = curr->next;
                    if (prevNode) { // these two cases will handled the tail node by itself and if we don't write these the code will fail
                        prevNode->next = nextNode;
                    }
                    if (nextNode)
                    {
                        nextNode->prev = prevNode;
                    }
                    delete curr; // free memory for the code
                    curr = nextNode; // move the current pointer to the next node.
                }
            } else {
                curr = curr->next; // just move ahead if we don't find anyone 
            }
        }
        return head;
    }
    void printReverse(Node* head) {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
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
    head = head->insertHead(head, 1);
    head = head->insertHead(head, 3);
    head = head->insertHead(head, 5);
    head = head->deleteOccurences(head, 5);
    head->printReverse(head);
    cout << endl;
    head->print(head);
    return 0;
}