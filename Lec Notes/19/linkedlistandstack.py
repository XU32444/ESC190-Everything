# implement a linked list class in python
# use it to implement a stack iwth O(1) push and pop
class LL:
    def __init__(self):
        self.head = None

    def insert(self, loc, element):
        new_node = Node(element)  # new node now has element as data, next:None
        if loc == 0:
            new_node.next = self.head.next  # copy the address of new_node to new_node
            self.head = new_node
        else:
            curr = self.head
            for i in range(loc):
                curr = curr.next
            new_node.next = curr.next
            curr.next = new_node

    def delete(self, loc):  # wanna walk loc-1 times
        if loc == 0:
            self.head = self.head.next0llhnl
        curr = self.head
        for i in range(loc - 1):
            curr = curr.next
        # i want to delete curr.next , no need to delete, cuz in python, as long as somehting isnt referenced, its gone
        curr.next = curr.next.next


class stack:
    def __init__(self, data):
        self.stack = LL()  # self.stackis not a linked list wh head==None
    # push: insert at 0
    # pop: get the 0th element, and then delete the 0th element

    def push(self, elem):
        self.stack.insert(0, elem)

    def pop(self, elem):
        cur_node = self.stack.head
        self.stack.deelte(0)
        return cur_node.data


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


n = Node(52)

# n.data is 52, n.next is None
# n.asdsafbiasa = 12, it makes sense as well, its just n has attribute of 12lflasblasas with value of 12
