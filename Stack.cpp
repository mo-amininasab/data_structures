// ************************************
// *  Name: Mohammad Amini Nasab      *
// *  Student No.: 39911541054532     *
// ************************************

#include <iostream>
using namespace std;

template <typename T>
class Stack {
  friend ostream& operator<<(ostream& out, const Stack& obj) {
    if (obj.top == -1) {
      out << "empty" << endl;
    } else {
      for (int i = 0; i <= obj.top; i++) {
        out << obj.stack_ptr[i] << "  ";
      }
      out << endl;
    }
    return out;
  }

 public:
  Stack(int _size = 10) {
    size = (_size > 0) ? _size : 10;
    top = -1;
    stack_ptr = new T[size];
  };

  ~Stack() { delete[] stack_ptr; };

  bool push(const T& item) {
    if (!is_full()) {
      stack_ptr[++top] = item;  // place item on stack
      return true;
    }

    return false;
  };

  bool pop(T& item) {
    if (!is_empty()) {
      item = stack_ptr[top--];  // remove item from stack
      return true;
    }

    return false;
  };

  bool is_empty() const { return top == -1; };
  bool is_full() const { return top == (size - 1); };

 private:
  // index of top reserved cell
  int top;
  int size;
  T* stack_ptr;
};

int main() {
  cout << "STACK OF INTERGERS" << endl << endl;

  Stack<int> stack1(10);

  stack1.push(2);
  stack1.push(32);
  stack1.push(48);
  stack1.push(43);
  stack1.push(28);
  stack1.push(23);
  stack1.push(1);

  cout << "Stack after pushing 2, 32, 48, 43, 28, 23, 1:" << endl
       << stack1 << endl;

  int a;
  stack1.pop(a);
  cout << "Stack after pop:" << endl << stack1 << endl;

  stack1.pop(a);
  cout << "Stack after pop:" << endl << stack1 << endl;

  stack1.pop(a);
  cout << "Stack after pop:" << endl << stack1 << endl << endl;

  cout << "---------------------------------------------------" << endl;

  cout << "STACK OF FLOATS: " << endl << endl;

  Stack<float> stack2(10);

  stack2.push(2.3);
  stack2.push(32.67);
  stack2.push(48.69);
  stack2.push(43.50);
  stack2.push(28.21);
  stack2.push(23.43);
  stack2.push(1.23);

  cout << "Stack after pushing 2.3, 32.67, 48.69, 43.50, 28.21, 23.43, 1.23:"
       << endl
       << stack2 << endl;

  float b;
  stack2.pop(b);
  cout << "Stack after pop:" << endl << stack2 << endl;

  stack2.pop(b);
  cout << "Stack after pop:" << endl << stack2 << endl;

  stack2.pop(b);
  cout << "Stack after pop:" << endl << stack2 << endl << endl;
}