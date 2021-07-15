class Node:
    def __init__(self, root, left, right):
        self.value = root
        self.left = left
        self.right = right

def prePrint(tree):
    if tree == None:
        return
    print(tree.value, end=' ')
    prePrint(tree.left)
    prePrint(tree.right)

def preorder(node):  # 전위 순회
    print(node.value, end='')
    if node.left != '.':
        preorder(tree[node.left])
    if node.right != '.':
        preorder(tree[node.right])

def inorder(node):
    
    if node.left!='.':
        inorder(tree[node.left])
    print(node.value, end='')
    if node.right!='.':
        inorder(tree[node.right])

def postorder(node):
    if node.left!='.':
        postorder(tree[node.left])
    if node.right!='.':
        postorder(tree[node.right])
    print(node.value, end='')

n = int(input())
tree = {}
for _ in range(n):
    parent, left_child, right_child = map(str,input().split())
    tree[parent] = Node(parent, left_child, right_child)
    
preorder(tree['A'])
print()
inorder(tree['A'])
print()
postorder(tree['A'])