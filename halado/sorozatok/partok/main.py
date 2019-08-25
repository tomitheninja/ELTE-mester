#/usr/bin/env python3

# README
# Description of the algorithm used here:
#  0) Reads data from console, parses it into list of (partyID, date)
#  1)  If same party gets re-elected, it is merged into one - merge_same_party
#  2)  It trims start, so the 2 parties start at once - use_same_latest_first_election
#  3)  Get every date, when election happened (with merged data, see step 1)
#  4)  Simulate

from datetime import date
from datetime import timedelta

# UTIL
def stringify_date(d):
    return str(d.year) + " " + str(d.month) + " " + str(d.day)

def party_from(start_date, country):
    for x in country:
        party, election_date = x
        if election_date == start_date:
            return party
    raise Exception("No entry for date " + stringify_date(start_date))

# STEP 0: Read and parse data
def parse_date(date_str): # side-effect: finds smallest date
    year, month, day = list(map(int, date_str.split(" ")))
    m_date = date(year, month ,day)
    return m_date

now = parse_date(input())

def read_country_data():
    num_lines = int(input())
    results = []
    for _ in range(0, num_lines):
        line = input() # [J 2000 10 17]
        party = 1 if line[0] == 'J' else 2 
        start_date = line[2:]
        result = (party,  parse_date(start_date))
        last_party = party
        results.append(result)
    return results


# STEP 1: Merge two dates, on re-election
def merge_same_party(country_data):
    results = []
    last_party = None
    for x in country_data:
        party, election_date = x
        if party != last_party:
            results.append(x)
        last_party = party
    return results

country1 = merge_same_party(read_country_data())
country2 = merge_same_party(read_country_data())


# STEP X: Add end date

country1.append((None, now))
country2.append((None, now))

# STEP 2: Start from latest first election of all countries
def first_date(country_data):
    first_date = None
    for x in country_data:
        party, election_date = x
        if first_date is None or first_date > election_date:
            first_date = election_date
    return first_date

def use_same_latest_first_election(c1, c2):
    c1_first_election = first_date(c1)
    c2_first_election = first_date(c2)
    first, second = None, None
    if c1_first_election < c2_first_election:
        first, second = c1, c2
    else: first, second = c2, c1

    party_of_first = first[0][0]
    date_of_second = second[0][1]

    first.pop(0)
    first.insert(0, (party_of_first, date_of_second))


use_same_latest_first_election(country1, country2)

# STEP 3: get every unique date# STEP 3: get every unique date

def get_every_unique_dates(c_list):
    all_dates = set()
    for c in c_list:
        for entry in c:
            election_date = entry[1]
            all_dates.add(election_date)
    
    return sorted(list(all_dates))

all_unique_dates = get_every_unique_dates([country1, country2])

# STEP 4: Start simulation
c1_party = country1[0][0]
c2_party = country2[0][0]

same_party = None
same_party_start_date = None

c1_dates = list(map(lambda c: c[1], country1))
c2_dates = list(map(lambda c: c[1], country2))

results = []

for d in all_unique_dates:
    # update parties
    if d in c1_dates:
        c1_party = party_from(d, country1)
    if d in c2_dates:
        c2_party = party_from(d, country2)
    
    # re-calc same_party
    prev_same_party = same_party
    same_party = (c1_party == c2_party) and (c1_party != None and c2_party != None)

    if not same_party and prev_same_party:
        results.append(stringify_date(same_party_start_date) + " " + stringify_date(d + + timedelta(days=-1))) # TODO: d -=1 day

    if same_party and not prev_same_party:
        same_party_start_date = d

print(len(results))
print("\n".join(results))
