#include <iostream>
using namespace std;
class queueImplement {
  int start = -1;
  int end = -1;
  int array[5] = {0};
  int currSize = 0;
  int maxSize = 5;

public:
  void push(int x) {
    if (!(currSize == maxSize)) {
      if (currSize == 0) {
        start++;
        end++;
      } else {
        end = (end + 1) % 5;
      }
      array[end] = x;
      currSize++;
    } else {
      cout << "Stack Is full!";
    }
  }
  int pop() {
    int popped = -1;
    if (!isEmpty()) {
      popped = array[start];
      array[start] = 0;
      if (start == end) {
        start = -1;
        end = -1;
      } else {
        start = (start + 1) % 5;
      }
      currSize--;
    } else {
      cout << "Stack is empty!";
    }
    return popped;
  }

  int peek() {
    if (!isEmpty()) {
      return array[start];
    }
    return -1;
  }

  bool isEmpty() {
    if (currSize == 0) {
      return true;
    }
    return false;
  }
  void print() {
    // while (start != end) {
    //   cout << array[start];
    //   start = (start % 4) + 1;
    // }
    for (int i = 0; i < 5; i++) {
      cout << array[i] << " ";
    }
  }
};
int main() {
  queueImplement q1;
  q1.push(1);
  q1.push(2);
  q1.push(3);
  q1.push(4);
  q1.push(5);
  cout << q1.pop() << endl;
  cout << q1.pop() << endl;
  cout << q1.pop() << endl;
  q1.print();
  return 0;
}