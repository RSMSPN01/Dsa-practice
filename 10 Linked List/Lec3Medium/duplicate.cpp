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
    Node* removeDuplicate(Node* head) {
        // So there are some conditions before we move ahead, the LL is in sorted order and the duplicates are only present after one 
        // another so the duplicates are in continous order my approach here is to use the same method we use in to remove duplicates in
        // an array by using two pointer approach
        // SC = O(1) && T.C = O(n) only one traversal of the LL is required.
        // dry run the code by yourself in these cases
        // 1<->2<->3<->4<->5<->6 all unique.
        // 1<->1<->1<->1<->2 more than one duplicate of one value.
        // 1<->1<->2<->2<->3<->4 equally distributes only one duplicate.
        if (head == nullptr)
        {
            return nullptr;
        }
        if (head->next == nullptr) {
            return head;
        }
        Node* curr = head->next;
        Node* window = head;
        while (curr != nullptr && window != nullptr)
        {
            if (curr->data != window->data)
            {
                // handle dangling pointer 
                window = window->next; // move the window to next step first
                Node* prevNode = window->prev; // then store the last and the next node of the current window
                if (window != curr) {
                    // swap 
                    // delete window; // free the memory from here
                    // we also need to handle the memory leeks between the nodes here too.
                    // please understand this why i have written this, it is very important to know about.
                    while (window != curr)
                    {
                        Node* nextNode = window->next;
                        delete window;
                        window = nextNode;
                    }
                    prevNode->next = curr; // point the last node to the new node
                    curr->prev = prevNode; // also point the prev of the new node to the last node
                } else {
                    curr = curr->next; // only update the window one 
                }
            } else {
                curr = curr->next;
            }
        }
        window->next = nullptr;
        return head;
    }
    // this is the most efficient way to solve the problem by only using one pointer at a time and by using only one 
    // while loop the code is given by chatGpt itself it is easy to understand but works is the same time and space 
    // complexity of the above code.
    // Node* removeDuplicates(Node* head) {
    //     if (!head) return head;

    //     Node* curr = head;

    //     while (curr && curr->next) {
    //         if (curr->data == curr->next->data) {
    //             // Duplicate found
    //             Node* duplicate = curr->next;

    //             // Connect curr to duplicate->next
    //             curr->next = duplicate->next;
    //             if (duplicate->next) {
    //                 duplicate->next->prev = curr;
    //             }

    //             delete duplicate; // free memory safely
    //         } else {
    //             curr = curr->next; // move only when no duplicate
    //         }
    //     }

    //     return head;
    // }

};
int main() {
    Node* head = new Node(7);
    // Node* temp = new Node(5);
    // Node* temp1 = new Node(9);
    // head->next = temp;
    // temp->prev = head;
    // temp->next = temp1;
    // temp1->prev = temp;
    head = head->insertHead(head, 6);
    head = head->insertHead(head, 6);
    head = head->insertHead(head, 5);
    head = head->insertHead(head, 4);
    head = head->insertHead(head, 4);
    head = head->insertHead(head, 3);
    head = head->insertHead(head, 2);
    head = head->insertHead(head, 2);
    head = head->insertHead(head, 1);
    head = head->removeDuplicate(head);
    head->printReverse(head);
    cout << endl;
    head->print(head);
    return 0;
}