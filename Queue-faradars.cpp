#include <iostream>
using namespace std;

template <typename T>
class Queue {
  friend ostream& operator<<(ostream& out, const Queue& obj) {
    out << "front: " << obj.front << " rear: " << obj.rear << endl;

    if (obj.is_full()) {
      out << "Queue is FULL" << endl;
    } else if (obj.is_empty()) {
      out << "Queue is EMPTY" << endl;
    }
    int distance = obj.front - obj.rear;
    int positive_distance = (distance > 0) ? distance : obj.capacity + distance;
    int steps = obj.capacity - positive_distance;

    for (int i = 1; i <= steps; i++) {
      int index = (obj.front + i) % obj.capacity;
      out << obj.queue_ptr[index] << "  ";
    }

    return out;
  }

 public:
  Queue(int _capacity = 10) {
    front = rear = size = 0;
    capacity = (_capacity > 0) ? _capacity : 10;

    queue_ptr = new T[capacity];
  }

  ~Queue() { delete[] queue_ptr; }

  bool insert(const int& item) {
    if (is_full()) {
      return false;
    }

    rear = (rear + 1) % capacity;
    queue_ptr[rear] = item;
    size++;

    return true;
  }

  T del() {
    if (is_empty()) {
      return INT_MIN;
    }

    T deleted_item = queue_ptr[front + 1];
    // nothing really deleted, just 'front' incremented.
    front = (front + 1) % capacity;
    size--;
    return deleted_item;
  }

  bool is_full() const { return (rear + 1) % capacity == front; }
  bool is_empty() const { return rear == front; }

 private:
  T* queue_ptr;
  int size;      // num of items
  int capacity;  // size of the queue
  int front;     // ! assuming front is always empty.
  int rear;
};

int main() {
  Queue<float> q(5);
  q.insert(10);
  q.insert(11);
  q.insert(12);
  q.insert(13);
  q.insert(14);

  cout << q << endl;
}