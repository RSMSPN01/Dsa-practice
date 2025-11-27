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
        // The ll is in sorted order keep that in mind so i am using two pointer approach to solve the problem although this appraoch is
        // going to take two traversals of the LL and i don't find any better way to solve the problem or either we can use some extra space
        // to store the data is some sort of hash table.
        vector<vector<int>> v;
        if (head == nullptr) {
            return v;
        }
        Node* start = head;
        Node* end = head;
        int i = 0;
        // moving the end to the tail so that we can use two pointer approach in the DLL.
        while (end->next != nullptr) {
            end = end->next;
        }
        while (start != end)
        {
            if ((start->data + end->data) == target) {
                cout << start->data << endl;
                cout << end->data << endl;
                v[i].push_back(start->data);
                v[i].push_back(end->data);
                i++;
                start = start->next;
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
    vector<vector<int>> x = head->findPairsWithGivenSum(head, 10);
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