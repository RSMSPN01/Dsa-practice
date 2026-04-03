#include <iostream>
using namespace std;
class queueImplement {
  int start = -1;
  int end = -1;
  int array[5] = {0};

public:
  void push(int x) {
    if (!isFull()) {
      if (start == -1 && end == -1) {
        start = (start % 4) + 1;
        end = (end % 4) + 1;
        array[start] = x;
      } else {
        end = (end % 4) + 1;
        array[end] = x;
      }
    } else {
      cout << "Queue is Full" << endl;
    }
  }

  void pop() {
    if (!isEmpty()) {
      array[start] = 0;
      start = (start % 4) + 1;
    } else {
      cout << "Queue is Empty" << endl;
    }
  }

  // int peek() {}
  int front() {
    if (!isEmpty()) {
      return array[start];
    }
  }
  int back() {
    if (!isEmpty()) {
      return array[end];
    }
  }
  bool isEmpty() {
    if (start == -1 && end == -1) {
      return true;
    }
    return false;
  }
  bool isFull() {
    // just for now i am checking based on values
    for (int i = 0; i < 5; i++) {
      if (array[i] == 0) {
        return false;
      }
    }
    return true;
  }
  void print() {
    while (start != end) {
      cout << array[start];
      start = (start % 4) + 1;
    }
  }
};
int main() {
  queueImplement q1;
  q1.push(1);
  q1.push(2);
  q1.push(3);
  q1.print();
  return 0;
}