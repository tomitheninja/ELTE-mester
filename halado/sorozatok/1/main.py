# read N items into P
N = int(raw_input())
P = {}

for _ in range(0, N):
    id, count_of_str = raw_input().split(" ")
    P[id] = int(count_of_str)

# read M items into Q
M = int(raw_input())
Q = {}

for i in range(0, M):
    id, count_of_str = raw_input().split(" ")
    Q[id] = int(count_of_str)

# read additional props
K = int(raw_input()) # min number of items on both side to exchange
L = int(raw_input()) # min number from someone to donate

# calculate exchangables
exchangables = []
for id, n_amount in P.items():
    m_amount = Q[id] if Q.has_key(id) else 0
    if n_amount > K and m_amount > K:
        exchangables.append(id)

print(" ".join(sorted(exchangables)))

# calculate donations
def donations(a, b):
    results = []
    for id, amount in a.items():
        if amount >= L and not b.has_key(id):
            results.append(id)
    return results

print(" ".join(sorted(donations(P, Q))))
print(" ".join(sorted(donations(Q, P))))