// Approach : Similar way we have used with arrays but this time just have to
// create the struct for linked list and have to handle the dangling pointer and
// have to carefully move the pointers and update values that is it, super easy
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
class LinkedListQueue {
  ListNode *front = nullptr;
  ListNode *back = nullptr;
  int size = 0;

public:
  LinkedListQueue() {}

  void push(int x) {
    ListNode *newNode = new ListNode(x);
    if (size == 0) {
      front = newNode;
      back = newNode;
    } else {
      back->next = newNode;
      back = back->next;
    }
    size++;
  }

  int pop() {
    if (front == nullptr) {
      return -1;
    }
    if (front == back) {
      // either one value or now value
      size--;
      int value = front->data;
      delete front;
      delete back;
      front = nullptr;
      back = nullptr;
      return value;
    }
    size--;
    int value = front->data;
    ListNode *temp = front;
    front = front->next;
    delete temp;
    return value;
  }

  int peek() {
    if (front != nullptr) {
      return front->data;
    }
    return -1;
  }

  bool isEmpty() {
    if (size == 0) {
      return true;
    }
    return false;
  }
};
int main() {
  //
  return 0;
}