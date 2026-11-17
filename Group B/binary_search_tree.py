class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def insert(root, data):
    if root is None:
        return Node(data)

    if data < root.data:
        root.left = insert(root.left, data)
    elif data > root.data:
        root.right = insert(root.right, data)
    else:
        print("Duplicate value")

    return root


def search(root, key):
    if root is None:
        return False
    if root.data == key:
        return True
    if key < root.data:
        return search(root.left, key)
    return search(root.right, key)


def delete(root, key):
    if root is None:
        return None

    if key < root.data:
        root.left = delete(root.left, key)
    elif key > root.data:
        root.right = delete(root.right, key)
    else:
        if root.left is None:
            return root.right
        if root.right is None:
            return root.left

        temp = root.right
        while temp.left:
            temp = temp.left

        root.data = temp.data
        root.right = delete(root.right, temp.data)

    return root


def inorder(root):
    if root:
        inorder(root.left)
        print(root.data, end=" ")
        inorder(root.right)


def depth(root):
    if root is None:
        return 0
    return 1 + max(depth(root.left), depth(root.right))


def mirror(root):
    if root:
        root.left, root.right = root.right, root.left
        mirror(root.left)
        mirror(root.right)


def copy_tree(root):
    if root is None:
        return None

    new = Node(root.data)
    new.left = copy_tree(root.left)
    new.right = copy_tree(root.right)
    return new


def parents(root):
    if root:
        if root.left or root.right:
            print(root.data, ":", end=" ")
            if root.left:
                print(root.left.data, end=" ")
            if root.right:
                print(root.right.data, end=" ")
            print()

        parents(root.left)
        parents(root.right)


def leaves(root):
    if root:
        if root.left is None and root.right is None:
            print(root.data, end=" ")
        leaves(root.left)
        leaves(root.right)


def level_wise(root):
    if root is None:
        return

    q = [root]
    while q:
        node = q.pop(0)
        print(node.data, end=" ")

        if node.left:
            q.append(node.left)
        if node.right:
            q.append(node.right)


root = None

while True:
    print("\n1. Insert")
    print("2. Delete")
    print("3. Search")
    print("4. Display Traversal")
    print("5. Display Depth")
    print("6. Display Mirror Image")
    print("7. Create a Copy")
    print("8. Display Parent Nodes with Children")
    print("9. Display Leaf Nodes")
    print("10. Display Tree Level Wise")
    print("11. Exit")

    ch = int(input("Enter choice: "))

    if ch == 1:
        x = int(input("Enter value: "))
        root = insert(root, x)
    elif ch == 2:
        x = int(input("Enter value: "))
        root = delete(root, x)
    elif ch == 3:
        x = int(input("Enter value: "))
        print("Value Found" if search(root, x) else "Value Not Found")
    elif ch == 4:
        inorder(root)
        print()
    elif ch == 5:
        print("Depth:", depth(root))
    elif ch == 6:
        mirror(root)
        print("Mirror Image:")
        level_wise(root)
        print()
    elif ch == 7:
        new_root = copy_tree(root)
        print("Copy Created:")
        inorder(new_root)
        print()
    elif ch == 8:
        parents(root)
    elif ch == 9:
        leaves(root)
        print()
    elif ch == 10:
        level_wise(root)
        print()
    elif ch == 11:
        break
    else:
        print("Invalid Choice")
