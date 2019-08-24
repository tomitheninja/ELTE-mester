# /usr/bin/env python3

N = int(input())

def calc_routes(depth = 0, num_routes = 0):
    if depth == N: # filled
        num_routes += 1
    # elif depth > N: # overflow
    #     pass
    elif depth < N: # not enough
        num_routes += calc_routes(depth + 1)
        num_routes += calc_routes(depth + 2)
    
    return num_routes

print(str(calc_routes()))