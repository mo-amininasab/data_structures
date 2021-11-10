#include <iostream>
using namespace std;

template <class T>
class Stack {
  friend ostream& operator<<(ostream& out, const Stack& obj) {
    if (obj.is_full()) {
      out << "Stack is FULL" << endl;
    } else if (obj.is_empty()) {
      out << "Stack is EMPTY" << endl;
    }

    for (int i = 0; i <= obj.top; i++) {
      out << obj.stack_ptr[i] << "  ";
    }
    out << endl;

    return out;
  }

 public:
  Stack(int _capacity = 10) {
    top = -1;
    capacity = (_capacity > 0) ? _capacity : 10;

    stack_ptr = new T[capacity];
  }
  ~Stack() { delete[] stack_ptr; }

  bool push(const T& item) {
    if (is_full()) {
      return false;
    }
    stack_ptr[++top] = item;

    return true;
  }

  T pop() {
    if (is_empty()) {
      return false;
    }
    return stack_ptr[top--];
  }

  bool is_empty() const { return (top == -1); }
  bool is_full() const { return top == capacity - 1; }

 private:
  // ! assuming top is index of top reserved cell.
  int top;
  int capacity;
  T* stack_ptr;
};

int main() {
  cout << "STACK OF INTERGERS" << endl << endl;

  Stack<int> stack1(7);

  stack1.push(2);
  stack1.push(32);
  stack1.push(48);
  stack1.push(43);
  stack1.push(28);

  // cout << stack1 << endl;

  // stack1.pop();

  // cout << stack1 << endl;

  while (!stack1.is_empty()) {
    cout << stack1.pop() << endl;
  }
  {
    /* code */
  }
  
 

  return 0;
}
