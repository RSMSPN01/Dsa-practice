// Total length of the Linked List 
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
    int totalLength(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    bool searchKey(ListNode* head, int key) {
        ListNode* temp = head;
        while (temp != NULL) {
            if (temp->data == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};
class Solution {
public:
    ListNode* insertAtHead(ListNode*& head, int X) {
        ListNode* temp = new ListNode(X);
        temp->next = head;
        head = temp;
        return head;
    }
};
int main() {
    Solution s1;
    ListNode* head = NULL;
    s1.insertAtHead(head, 25);
    s1.insertAtHead(head, 26);
    cout << (head->searchKey(head, 26));
    return 0;
}