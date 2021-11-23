# %%
# ************************************
# *  Name: Mohammad Amini Nasab      *
# *  Student No.: 39911541054532     *
# ************************************

class Node:
  def __init__(self, data):
    self.data = data
    self.next = None


class LinkedList:
  def __init__(self, value):
    new_node = Node(value)
    self.head = new_node
    self.tail = new_node
    self.length = 1

  def is_empty(self):
    return self.length == 0

  def append(self, value):
    new_node = Node(value)
    if self.is_empty():
      self.head = new_node
      self.tail = new_node
    else:
      self.tail.next = new_node
      self.tail = new_node

    self.length += 1
    return True

  def prepend(self, value):
    new_node = Node(value)
    if self.is_empty():  # if list is empty
      self.head = new_node
      self.head.next = None
    else:  # if list is not empty
      new_node.next = self.head
      self.head = new_node

    self.length += 1
    return True

  def pop(self):
    if self.is_empty():  # if list is empty
      return None

    curr = self.head
    prev = None
    while curr.next:
      prev = curr
      curr = curr.next

    if self.length == 1:  # if only one node
      self.length -= 1
      self.head = None
      return curr.data

    # if more than one node
    prev.next = None
    self.tail = prev

    self.length -= 1
    return curr.data

  def pop_first(self):
    if self.is_empty():  # if list is empty
      return None

    curr = self.head
    self.head = curr.next
    curr.next = None

    self.length -= 1
    if self.length == 0:
      self.tail = None

    return curr.data

  def get(self, index):
    if index < 0 or index >= self.length:
      return None

    curr = self.head
    for _ in range(index):
      curr = curr.next

    return curr

  def set_value(self, index, value):
    the_node = self.get(index)
    if the_node:
      the_node.data = value
      return True

    return False

  def insert(self, index, value):
    if index < 0 or index > self.length:
      return False

    if index == 0:
      self.prepend(value)
      return True

    if index == self.length:
      self.append(value)
      return True

    new_node = Node(value)
    prev = self.get(index - 1)
    new_node.next = prev.next
    prev.next = new_node

    self.length += 1
    return True

  def remove(self, index):
    if index < 0 or index >= self.length:
      return None

    if index == 0:
      return self.pop_first()

    if index == self.length - 1:
      return self.pop()

    prev = self.get(index - 1)
    curr = prev.next
    prev.next = curr.next
    curr.next = None  # remove the reference to the node

    self.length -= 1
    return curr.data

  def reverse(self):
    curr = self.head
    self.head = self.tail
    self.tail = curr

    prev = None
    next = curr.next
    while curr:
      curr.next = prev
      prev = curr
      curr = next
      if next:
        next = next.next

    return True

  def __str__(self) -> (str):
    s = ''
    curr = self.head
    while curr != None:
      s += str(curr.data) + ' '
      curr = curr.next

    if s == '':
      return 'Empty'

    return s


def main():
  list1 = LinkedList(1)
  list1.append(21)
  list1.append(13)
  list1.append(4)
  list1.append(7)
  print('LINKED LIST')
  print('list1: ', list1, '\n')

  list1.pop()
  print('after pop: ', list1)
  list1.pop()
  print('after pop: ', list1)

  list1.append(222)
  print('after append 222: ', list1)
  list1.append(549)
  print('after append 549: ', list1)

  list1.insert(2, 20)
  print('after insert 20 at index 2: ', list1)
  list1.insert(4, 16)
  print('after insert 16 at index 4: ', list1)

  list1.reverse()
  print('after reverse: ', list1)


if __name__ == '__main__':
  main()
