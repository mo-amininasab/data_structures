// ************************************
// *  Name: Mohammad Amini Nasab      *
// *  Student No.: 39911541054532     *
// ************************************

#include <iostream>
using namespace std;

template <typename T>
class Queue {
  friend ostream& operator<<(ostream& out, const Queue& obj) {
    if (obj.is_full()) {
      out << "Queue is FULL" << endl;
    } else if (obj.is_empty()) {
      out << "Queue is EMPTY" << endl;
    }

    out << "front: " << obj.front << " rear: " << obj.rear << endl;

    int distance = obj.front - obj.rear;
    int positive_distance = (distance > 0) ? distance : obj.size + distance;
    int steps = obj.size - positive_distance;

    for (int i = 1; i <= steps; i++) {
      int index = (obj.front + i) % obj.size;
      out << obj.queue_ptr[index] << "  ";
    }

    return out;
  }

 public:
  Queue(int _size = 10) {
    size = (_size > 0) ? _size : 10;
    front = 0;
    rear = 0;

    queue_ptr = new T[size];
  }

  ~Queue() { delete[] queue_ptr; }

  bool insert(const T& item) {
    if (is_full()) {
      return false;
    }

    rear = (rear + 1) % size;
    queue_ptr[rear] = item;

    return true;
  }

  bool del() {
    if (is_empty()) {
      return false;
    }
    // not deleted, just 'front' incremented.
    front = (front + 1) % size;

    return true;
  }

  bool is_full() const { return (rear + 1) % size == front; }
  bool is_empty() const { return rear == front; }

  void show_front_rear() {
    cout << "front: " << front << '\t';
    cout << "rear: " << rear << endl;
  }

 private:
  // ! assuming front is always empty.
  int front, rear, size;
  T* queue_ptr;
};

int main() {
  Queue<int> q1(6);

  cout << "Queue of INTEGERS: " << endl << endl;
  q1.insert(2);
  q1.insert(33);
  q1.insert(34);
  q1.insert(65);
  q1.insert(50);

  cout << "After inserting 2, 33, 34, 65, 50: " << endl << q1 << endl << endl;

  q1.del();
  cout << "After calling 'del': " << endl << q1 << endl << endl;

  q1.del();
  cout << "After calling 'del': " << endl << q1 << endl << endl;

  q1.del();
  cout << "After calling 'del': " << endl << q1 << endl << endl;

  q1.insert(99);
  cout << "After inserting 99: " << endl << q1 << endl << endl;

  q1.insert(290);
  cout << "After inserting 290: " << endl << q1 << endl << endl;

  cout << "---------------------------------------------------" << endl;

  Queue<char> q2(6);

  cout << "Queue of CHARS: " << endl << endl;
  q2.insert('a');
  q2.insert('b');
  q2.insert('c');
  q2.insert('d');
  q2.insert('e');

  cout << "After inserting a, b, c, d, e: " << endl << q2 << endl << endl;

  q2.del();
  cout << "After calling 'del': " << endl << q2 << endl << endl;

  q2.del();
  cout << "After calling 'del': " << endl << q2 << endl << endl;

  q2.del();
  cout << "After calling 'del': " << endl << q2 << endl << endl;

  q2.insert('f');
  cout << "After inserting f: " << endl << q2 << endl << endl;

  q2.insert('g');
  cout << "After inserting g: " << endl << q2 << endl << endl;

  return 0;
}