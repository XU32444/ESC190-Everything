class Node:
    def __init__(self, value):
        self.value = value
        self.neighbour = []


def make__airport_graph():
    yyz = Node('YYZ')
    yvr = Node('YVR')
    yul = Node('YUL')
    whitehorse = Node('Whitehorse')

    yyz.neighbour = [yvr, yul]
    yvr.neighbour = [yyz, yul, whitehorse]
    yul.neighbour = [yyz, yvr]
    whitehorse.neighbour = [yvr]

    # In C, could think of neighbour as an array of pointers to nodes

# Calculating the complexity of finding out whether yvr has an edge to yyz?
# O(n) where n is the number of nodes in the graph
