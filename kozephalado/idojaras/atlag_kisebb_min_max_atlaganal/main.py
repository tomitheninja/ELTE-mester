# /usr/bin/env python3
num_cities, num_measurements = list(map(int, input().split(" ")))

INFINITY = 999

results = []

for i in range(0, num_cities):
  xs = list(map(int, input().split(" ")))

  sum_of_city = 0
  min_of_city = +INFINITY
  max_of_city = -INFINITY
  for x in xs:
    sum_of_city += x
    min_of_city = min(x, min_of_city)
    max_of_city = max(x, max_of_city)

  avg_of_city = float(sum_of_city) / num_measurements


  # # criteria:
  # #  A=diff(avg, min)
  # #  B=diff(avg, max)
  # #  A < B
  if avg_of_city - min_of_city < max_of_city - avg_of_city:
    results.append(str(i + 1))

result1 = str(len(results)) # number of results
result2 = " ".join(results) # the results joined by space
print(result1 + " " + result2)