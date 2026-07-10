// The question expected to not take any extra space but striver itslef took
// three different lists and merge them in the end

// So i was wrong it don't take three list but just three pointers, this code
// can be improved further first by sending the tail node as reference so that i
// can change that in the function itself rather than manually doing all that,
// second i need to extra check the Lists before combining and in the end also
// free the memory from the heap
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Node class representing each element of the linked list
class Node {
public:
  int data;
  Node *next;

  // Constructor to initialize node with a value
  Node(int val) {
    data = val;
    next = nullptr;
  }
};

// LinkedList class to manage list operations
class ListNode {
public:
  Node *head;

  // Constructor to initialize an empty list
  ListNode() { head = nullptr; }

  // Function to insert a new node at the end
  void insert(int val) {
    Node *newNode = new Node(val);
    if (!head) {
      head = newNode;
      return;
    }
    Node *temp = head;
    while (temp->next)
      temp = temp->next;
    temp->next = newNode;
  }

  // Function to print the entire linked list
  void print() {
    Node *temp = head;
    while (temp) {
      cout << temp->data;
      if (temp->next)
        cout << " -> ";
      temp = temp->next;
    }
    cout << " -> NULL\n";
  }
};

class Solution {
public:
  //   void insertAtTail(ListNode *tail, ListNode *node) {
  //     tail->next = node;
  //     node->next = nullptr;
  //   }
  //   ListNode *sortList(ListNode *&head) {

  //     ListNode *zeroHead = new ListNode(-1);
  //     ListNode *oneHead = new ListNode(-1);
  //     ListNode *twoHead = new ListNode(-1);
  //     ListNode *zeroTail = zeroHead;
  //     ListNode *oneTail = oneHead;
  //     ListNode *twoTail = twoHead;
  //     while (head != nullptr) {
  //       ListNode *nextNode = head->next;
  //       if (head->data == 0) {
  //         insertAtTail(zeroTail, head);
  //         zeroTail = zeroTail->next;
  //       } else if (head->data == 1) {
  //         insertAtTail(oneTail, head);
  //         oneTail = oneTail->next;
  //       } else {
  //         insertAtTail(twoTail, head);
  //         twoTail = twoTail->next;
  //       }
  //       head = nextNode;
  //     }
  //     // first check too that they are not pointing to nullptr
  //     zeroTail->next = oneHead->next;
  //     oneTail->next = twoHead->next;
  //     return zeroHead->next;
  //   }
};

// Driver code to demonstrate usage
int main() {
  //   LinkedList ll;
  Solution sol;

  // Insert nodes into the list
  //   ll.insert(1);
  //   ll.insert(2);
  //   ll.insert(0);
  //   ll.insert(1);
  //   ll.insert(2);
  //   ll.insert(0);

  cout << "Original List:\n";
  //   ll.print();

  // Sort the list using rearrangement of links
  //   sol.sortZeroOneTwo(ll);

  cout << "Sorted List:\n";
  //   ll.print();

  return 0;
}
