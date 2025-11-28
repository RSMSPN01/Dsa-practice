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
    vector<vector<int>> findPairsWithGivenSum(Node* head, int target) {
        // There are some prerequisities for this that there are all unique numbers in the LL there is no repetition and all are in the 
        // sorted order.
        // The ll is in sorted order keep that in mind so i am using two pointer approach to solve the problem although this appraoch is
        // going to take two traversals of the LL and i don't find any better way to solve the problem or either we can use some extra space
        // to store the data is some sort of hash table.
        // Mistakes i have done in the code is i was putting the elements in the vector in the wrong way like v[i].push_back(start->data) this
        // is wrong because the vector is empty instead we can put the data in the form of pairs i have done below
        // another mistake is the condition of while loop and moving the pointer when we found the target with sum of two nodes it means we have
        // to move both the pointer becuase there is no duplicates of the values so move both of them at the same time and condition should be based
        // on the value smaller then other because our DLL is sorted so we can do that here.
        vector<vector<int>> v;
        if (head == nullptr) {
            return v;
        }
        Node* start = head;
        Node* end = head;
        // moving the end to the tail so that we can use two pointer approach in the DLL.
        while (end->next != nullptr) {
            end = end->next;
        }
        while (start != nullptr && end != nullptr && start->data < end->data) // please make sure to use this safer condition to exit
        {
            if ((start->data + end->data) == target) {
                v.push_back({ start->data,end->data });
                start = start->next; // move both the pointers reason is explained above.
                end = end->prev;
            } else if ((start->data + end->data) > target) {
                end = end->prev;
            } else {
                start = start->next;
            }
        }
        return v;
    }
};
int main() {
    Node* head = new Node(6);
    Node* temp = new Node(8);
    Node* temp1 = new Node(9);
    head->next = temp;
    temp->prev = head;
    temp->next = temp1;
    temp1->prev = temp;
    head = head->insertHead(head, 5);
    head = head->insertHead(head, 4);
    head = head->insertHead(head, 2);
    head = head->insertHead(head, 1);
    vector<vector<int>> x = head->findPairsWithGivenSum(head, 7);
    for (int i = 0;i < x.size();i++) {
        for (int j = 0;j < x[i].size();j++) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
    // head->printReverse(head);
    // cout << endl;
    // head->print(head);
    return 0;
}