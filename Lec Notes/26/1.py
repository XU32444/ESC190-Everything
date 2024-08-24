import numpy


class Node:
    def __init__(self, value):
        self.value = value
        self.neighbours = set()  # O(1) look up and insert an averagea
        # O(n) in the worst case


def are_nodes_linked(node1, node2):
    # node 1 and node 2 are linked if there is an edge between them
    # assume graph is undirected

    return node2 in node1.neighbours
    # we dont have to check if node1 is in node2.neighbours
    # because we are assuming the graph is undirected


# def get_node_by_str(nodes, node_str):
#     for node in nodes:
#         if node.value == node_str:
#             return node
#     return None
def get_node_by_str(nodes, node_str):
    return nodes.get(node_str, None)


def are_airports_linked(airports, airport1_str, airport2_str):
    airport1 = get_node_by_str(airport1_str)
    airport2 = get_node_by_str(airport2_str)
    if airport1 is None or airport2 is None:
        return False
    return are_nodes_linked


def make__airport_graph():
    yyz = Node('YYZ')
    yvr = Node('YVR')
    yul = Node('YUL')
    whitehorse = Node('Whitehorse')

    yyz.neighbour = set([yvr, yul])
    yvr.neighbour = set([yyz, yul, whitehorse])
    yul.neighbour = set([yyz, yvr])
    whitehorse.neighbour = set([yvr])

    airport_dict = {}
    for airport in [yyz, yvr, yul, whitehorse]:
        airport_dict[airport.value] = airport

    return airport_dict


def convert_to_adj_matrix(airports):
    adj_matrix = np.zeros((len(airports), len(airports)))
    airport_callsigns = sorted(list(airports.keys()))
    airport_callsigns_idx = {}
    for i, airport_callsign in enumerate(airport_callsigns):
        airport_callsigns_idx[airport_callsign] = i

    for airport_callsign, airport in airports.items():
        for neighbour in airport.neighbours:
            adj_matrix[airport_callsigns_idx[airport_callsigns],
                       airport_callsigns_idx[neighbour.value]] = 1
            # d
    return adj_matrix, airport_callsigns_idx


if __name__ == '__main__':
    airports = make__airport_graph()
    print("Toronro (YYZ) is connnected to Montreal (YUL)",
          are_airports_linked(airports, "YYZ", "YUL"))
    # Complexity of are_airports_linked:
    # Need
    # Final airport1 (0(n)), n is the num of airport , assuming airport names are limited to e.g. 100 chars
    # Find airport2 (O(n))
    # Are the nodes linked? Look up in set O(1)

    # Total runtimes: 2*c1*n + c2*d <= 2*c1*n + c2*n // d<=n since cannot have more than n neighboiuts out of a

    # In C, could think of neighbour as an array of pointers to nodes

# Calculating the complexity of finding out whether yvr has an edge to yyz?
# O(n) where n is the number of nodes in the graph
