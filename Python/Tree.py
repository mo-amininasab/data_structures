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
  
  def inorder_traversal(self, node):
    if node == None:
      return None

    self.inorder_traversal(node.left)
    self.count += 1
    self.inorder_traversal(node.right)

  def contains(self, data):
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
  
  def level_order_traversal(self, node):
    if node == None:
      return None

    queue = []
    queue.append(node)
    list_of_nodes = []

    while len(queue) > 0:
      current = queue.pop(0)
      # print(current.data)
      list_of_nodes.append(current.data)

      if current.left != None:
        queue.append(current.left)
      if current.right != None:
        queue.append(current.right)

    return list_of_nodes

def main():
  my_tree = BinarySearchTree(4)
  my_tree.insert(2)
  my_tree.insert(1)
  my_tree.insert(3)

  print(my_tree.root.data)
  # print(my_tree.root.left.data)
  # print(my_tree.root.right.data)
  my_tree.inorder_traversal(my_tree.root)
  print(my_tree.count)
  print('Level Order:')
  print(my_tree.level_order_traversal(my_tree.root))


if __name__ == '__main__':
  main()
