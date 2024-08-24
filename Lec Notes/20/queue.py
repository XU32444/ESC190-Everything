# What is a queue?
# first in, first out

q = [7, 4, 5, 6]
# enqueue
# enqueue: add object to the queue
# dequeue: remove the first object in line from the queue


class Queue:
    def __init__(self):
        self.q = []

    def enqueue(self, elem):
        self.q.insert(0, elem)

    def dequeue(self):
        return self.q.pop()

    def __repr__(self):
        return f"Queue: LAST IN -> {self.q} <- FIRST IN"


q1 = Queue()
q1.enqueue(10)
q1.enqueue(20)
q1.dequeue()
q1.enqueue(5)
print(q1)



# Idea 0: O(1) for enqueue suing append, O(n) for dequeue using pop(0)

# Idea 1: for 0(1) enqueue and dequeue
# Linekd List: 
    # A ->B->C->D->E (needs to doubly linked, as that D has a link to C)
    # To enqueue, add to the end (0(1) if you keep track of the node before last at the end currently)
    # To dequeue, remove the first node(O(n) if you keep track of the head node currently)

# Idea 2: for O(1) (almost) enqueue and dequeue
    # use a circular arrary
    [, , , , , , F,G,H,X]
    # keep track of the last and first index
    # to enqueue Y at the end, wrap around
    [Y, , ,, , , , F,G,H,J,X]





