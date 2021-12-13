# %%
# ************************************
# *  Name: Mohammad Amini Nasab      *
# *  Student No.: 39911541054532     *
# ************************************


class Queue:
  def __init__(self):
    self.items = []

  def isEmpty(self):
    return self.items == []

  def enqueue(self, item):
    self.items.insert(0, item)

  def dequeue(self):
    if self.isEmpty():
      return None
    return self.items.pop()

  def size(self):
    return len(self.items)

  def __str__(self):
    return str(self.items)


class Node:
  def __init__(self, data):
    self.data = data
    self.next = None


class Queue_in_linked_list:
  def __init__(self, data):
    new_node = Node(data)
    self.first = new_node
    self.last = new_node
    self.length = 1

  def enqueue(self, data):
    new_node = Node(data)

    if self.first is None:
      self.first = new_node
      self.last = new_node
    else:
      self.last.next = new_node
      self.last = new_node

    self.length += 1

  def dequeue(self):
    if self.first is None:
      return None

    temp = self.first
    if self.first == self.last:
      self.first = None
      self.last = None
    else:
      self.first = self.first.next
      temp.next = None

    self.length -= 1
    return temp

  def __str__(self):
    string = ""
    temp = self.first
    while temp:
      string += str(temp.data) + " "
      temp = temp.next

    if string == "":
      return "Empty Queue"
    return string


def main():
  my_queue = Queue_in_linked_list(4)
  print(my_queue, my_queue.length)
  my_queue.enqueue(5)
  my_queue.enqueue(6)
  print(my_queue, my_queue.length)
  my_queue.dequeue()
  print(my_queue, my_queue.length)
  my_queue.dequeue()
  print(my_queue, my_queue.length)
  my_queue.dequeue()
  print(my_queue, my_queue.length)
  my_queue.dequeue()
  print(my_queue, my_queue.length)


if __name__ == "__main__":
  main()
