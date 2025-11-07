// Deleting first node in LinkedList
// Medimum level Code is submitted in the Leetcode
#include <iostream>
using namespace std;

// Definition of singly linked list:
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int data1)
//     {
//         val = data1;
//         next = NULL;
//     }
//     ListNode(int data1, ListNode *next1)
//     {
//         val = data1;
//         next = next1;
//     }
// };
class ListNode {
public:
    int data;
    ListNode* next;
    ListNode(int data) {
        this->data = data;
        next = NULL;
    }
    void printList(ListNode* head) {
        ListNode* temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    ListNode* insertAtHead(ListNode*& head, int X) {
        ListNode* temp = new ListNode(X);
        temp->next = head;
        head = temp;
        return head;
    }
};
class Solution {
public:
    ListNode* deleteHead(ListNode*& head) {
        ListNode* temp = head;
        head = temp->next;
        delete temp;
        return head;
    }
};
int main() {
    ListNode* head = NULL;
    head = head->insertAtHead(head, 30);
    head = head->insertAtHead(head, 20);
    Solution s1;
    s1.deleteHead(head);
    s1.deleteHead(head);
    head->printList(head);
    return 0;
}