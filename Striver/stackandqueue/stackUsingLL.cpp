// Approach : Create a top variable which has null in first, then each time
// create a new node and point the next node to the top and update the top that
// is it, its easy but the main question is all about implementing LL how to
// create that and how to handle the cases

#include <iostream>
using namespace std;
struct ListNode {
  int data;
  ListNode *next = nullptr;
  ListNode(int x) {
    data = x;
    next = nullptr;
  }
};
class LinkedListStack {
  ListNode *start = nullptr;
  int size = 0;

public:
  LinkedListStack() {}

  void push(int x) {
    ListNode *head = new ListNode(x);
    head->next = start;
    start = head;
    size++;
  }

  int pop() {
    if (start == nullptr) {
      return -1;
    }
    ListNode *temp = start;
    int value = start->data;
    start = start->next;
    delete temp;
    size--;
    return value;
  }

  int top() {
    if (start == nullptr) {
      return -1;
    }
    return start->data;
  }

  bool isEmpty() {
    if (size == 0) {
      return true;
    }
    return false;
  }
};
int main() { return 0; }