# %%
# ************************************
# *  Name: Mohammad Amini Nasab      *
# *  Student No.: 39911541054532     *
# ************************************

class Node:
  def __init__(self, data):
    self.data = data
    self.left = None
    self.right = None


class BinarySearchTree:
  def __init__(self, data):
    new_node = Node(data)
    self.root = new_node
    self.count = 1

  def insert(self, data):
    new_node = Node(data)

    if self.root.data == None:
      self.root = new_node
      return True

    current = self.root
    while True:
      if new_node.data == current.data:
        return False

      if data < current.data:
        if current.left == None:
          current.left = new_node
          return True
        current = current.left
      elif data > current.data:
        if current.right == None:
          current.right = new_node
          return True
        current = current.right

  def count_node(self, node):
    current = node

    if current == None:
      return 0

    self.count_node(current.left)
    self.count += 1
    self.count_node(current.right)

    return self.count - 1

  def count_leaf(self, node):
    current = node

    if current == None:
      return 0

    if current.left == None and current.right == None:
      return 1

    return self.count_leaf(current.left) + self.count_leaf(current.right)

  def count_depth(self, node):
    current = node

    if current == None:
      return 0

    left_depth = self.count_depth(current.left)
    right_depth = self.count_depth(current.right)

    if left_depth > right_depth:
      return left_depth + 1
    else:
      return right_depth + 1

  def search(self, data):
    current = self.root
    while True:
      if data < current.data:
        if current.left == None:
          return False
        current = current.left
      elif data > current.data:
        if current.right == None:
          return False
        current = current.right
      else:
        return current
  
  def find_min(self, node):
    current = node

    if current == None:
      return None

    while current.left != None:
      current = current.left

    return current

  def find_max(self, node):
    current = node

    if current == None:
      return None

    while current.right != None:
      current = current.right

    return current


def main():
  bst = BinarySearchTree(10)
  bst.insert(5)
  bst.insert(15)
  bst.insert(2)
  bst.insert(6)

  print("Nodes:", bst.count_node(bst.root))
  print("Leaf:", bst.count_leaf(bst.root))
  print("Depth:", bst.count_depth(bst.root))
  print("Search Node 5:", bst.search(5))


if __name__ == '__main__':
  main()
