// ************************************
// *  Name: Mohammad Amini Nasab      *
// *  Student No.: 39911541054532     *
// ************************************

#include <iostream>
#include <string>
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

  const Stack& operator=(const Stack& stk) {
    if (this != &stk) {
      delete[] stack_ptr;
      top = stk.top;
      capacity = stk.capacity;
      stack_ptr = new T[capacity];
      for (int i = 0; i <= top; i++) {
        stack_ptr[i] = stk.stack_ptr[i];
      }
    }
    return *this;
  }

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

  T peak() {
    if (is_empty()) {
      return false;
    }

    return stack_ptr[top];
  }

  string get_str() const {
    string str = "";
    for (int i = 0; i <= top; i++) {
      char item = stack_ptr[i];
      if (item == NULL) {
        break;
      }
      str += item;
    }
    return str;
  }

  int get_size() const { return top; }

  bool is_empty() const { return (top == -1); }
  bool is_full() const { return top == capacity - 1; }

 private:
  // ! assuming top is index of top reserved cell.
  int top;
  int capacity;
  T* stack_ptr;
};



int main() {

  return 0;
}