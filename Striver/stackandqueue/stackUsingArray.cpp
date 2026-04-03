#include <bits/stdc++.h>
#include <iostream>

using namespace std;
// ArrayStack() {}
class stackImplement {
private:
  int top = -1;
  int array[5] = {0}; // must know a constant size before
public:
  void push(int x) {
    if (!isFull()) {
      top++;
      array[top] = x;
    } else {
      cout << "Stack is Full, Can't perform Operation";
    }
  }

  void pop() {
    if (!isEmpty()) {
      array[top] = 0;
      top--;
    } else {
      cout << "Stack is Empty, Nothing to remove";
    }
  }

  int tops() {
    if (!isEmpty() && !isFull())
      return array[top];
  }

  bool isEmpty() {
    if (top == -1) {
      return true;
    }
    return false;
  }
  bool isFull() {
    if (top >= 4) { // or when pointer reaches n
      return true;
    }
    return false;
  }
  void displayStack() {
    for (int i = 0; i < 5; i++) {
      cout << array[i] << " ";
    }
  }
};
int main() {
  stackImplement st1;
  st1.push(1);
  st1.push(1);
  st1.push(1);
  st1.push(1);
//   st1.push(1);
  st1.push(2);
  st1.push(3);
  st1.displayStack();
  st1.pop();
  st1.pop();

  return 0;
}