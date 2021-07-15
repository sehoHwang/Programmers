import sys
sys.setrecursionlimit(100000)

class Node:
    def __init__(self, root, left, right):
        self.value = root
        self.left = left
        self.right = right

def findIndex(inorder,idx, item):
    while True:
        if inorder[idx] == item:
            return idx
        idx+=1

def calc(inorder, postorder, iStart, pStart, size):
    if size<=0:
        return None
    pEnd = pStart+size-1
    parent = postorder[pEnd]

    rIdx = findIndex(inorder,iStart, parent)
    leftSize = rIdx-iStart
    rightSize = size-leftSize-1
    left = calc(inorder, postorder, iStart, pStart, leftSize)
    right = calc(inorder, postorder, rIdx+1, pStart+leftSize, rightSize) # pStart+leftSize
    return Node(parent, left, right)

def prePrint(tree):
    if tree == None:
        return
    print(tree.value, end=' ')
    prePrint(tree.left)
    prePrint(tree.right)

def solve():

    n = int(input())

    inorder = list(map(int, input().split())) # 왼 -> 뿌 -> 오
    postorder = list(map(int, input().split())) # 왼 -> 오 -> 뿌
    tree = calc(inorder, postorder, 0, 0, n)
    prePrint(tree)
solve()