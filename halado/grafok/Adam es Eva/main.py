#!/usr/bin/env python3

class PERSON:
    A = 'A'
    B = 'B'

INFINITY = 2 ** 31

class Node:
    def __init__(self, id=-1):
        self.id = id
        self.routes = set()
        self.path_to = {}
        self.distance_from = {}

num_nodes, num_connections, start_A, start_B = list(map(int, input().strip().split(' ')))

start_A -= 1
start_B -= 1

nodes = []
for i in range(num_nodes):
    nodes.append(Node(i))

for _ in range(num_connections):
    p1, p2 = list(map(int, input().strip().split(" ")))
    p1 -= 1
    p2 -= 1
    n1 = nodes[p1]
    n2 = nodes[p2]
    n1.routes.add((n1, n2))

def calc_route(person_id, start_node):
    for node in nodes:
        node.distance_from[person_id] = INFINITY

    start_node.distance_from[person_id] = 0

    available_routes = start_node.routes.copy()

    while len(available_routes) > 0:
        next_available_routes = set()

        for route in available_routes:
            n1, n2 = route
            old_distance = n2.distance_from[person_id]
            new_distance = n1.distance_from[person_id] + 1
            if  new_distance < old_distance:
                n2.distance_from[person_id] = new_distance
                n2.path_to[person_id] = n1

                for next_route in n2.routes:
                    next_available_routes.add(next_route)

        available_routes = next_available_routes

calc_route(PERSON.A, nodes[start_A])
calc_route(PERSON.B, nodes[start_B])

best_node = nodes[0]
for node in nodes:
    if INFINITY in (best_node.distance_from[PERSON.A], best_node.distance_from[PERSON.B]):
        # No solution found (yet)
        best_node = node
    elif node.distance_from[PERSON.A] < best_node.distance_from[PERSON.A]:
        # Target 1: Best for person.A
        best_node
    elif node.distance_from[PERSON.A] == best_node.distance_from[PERSON.A]:
        # Target 2: Best for person.A
        if node.distance_from[PERSON.B] < best_node.distance_from[PERSON.B]:
            best_node = node

print(str(best_node.id + 1) + ' ' + str(best_node.distance_from[PERSON.A]) + ' ' + str(best_node.distance_from[PERSON.B]))

def route_from_home(start_node, person_id):
    next_node = start_node
    route = [start_node]
    while next_node.distance_from[person_id] != 0:
        next_node = next_node.path_to[person_id]
        route.insert(0, next_node)
    
    return ' '.join(list(map(lambda x: str(x.id + 1), route)))

print(route_from_home(best_node, PERSON.A))
print(route_from_home(best_node, PERSON.B))