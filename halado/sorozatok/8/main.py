N = int(raw_input())

db = {}

for _ in range(0, N):
    row = map(int, raw_input().split(" "))
    for i in range(1, len(row), 2):
        id = row[i]
        amount = row[i + 1]
        prev_value = 0
        if (db.has_key(id)):
            prev_value = db[id]
        
        new_value = prev_value + amount
        if (new_value != 0):
            # db.pop(id)
        # else:
            db[id] = new_value

print(str(len(db)))

for key in sorted(db.keys()):
    amount = db[key]
    print(str(key) + " " + str(amount))
