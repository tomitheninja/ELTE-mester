#!/usr/bin/env python3

# N: Number of points
# H: Distance of signal
N, H = list(map(int, input().split(' ')))

# R: Distance of points
R = list(map(int, input().split(' ')))

# Utils
def find_gt(x, start_index = 0):
    point_index = start_index
    while point_index + 1 < len(R) and R[point_index] <= x:
        point_index += 1
    return point_index

def find_max(x, start_index = 0):
    point_index = start_index
    while point_index + 1 < len(R) and R[point_index + 1] <= x:
        point_index += 1
    return point_index

results = []

next_uncovered_index = 0
while True:
    candidate_index = find_max(R[next_uncovered_index] + H, next_uncovered_index)
    results.append(str(candidate_index + 1))

    covered_until_val = R[candidate_index] + H
    if (covered_until_val >= R[-1]):
        break
    next_uncovered_index = find_gt(covered_until_val, candidate_index)

print(len(results))
print(" ".join(results))