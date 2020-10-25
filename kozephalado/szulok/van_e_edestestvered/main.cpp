#include <iostream>

using namespace std;

struct Person {
    int parent1;
    int parent2;
};

int main()
{
    int num_people;
    cin >> num_people;

    Person people[num_people];
    for (int i = 0; i < num_people; i++)
    {
        people[i].parent1 = -1;
        people[i].parent2 = -1;
    }

    int num_connections;
    cin >> num_connections;

    for (int i = 0; i < num_connections; i++)
    {
        int parent_id, child_id;
        cin >> parent_id >> child_id;
        Person& child = people[child_id];
       
        if (child.parent1 == -1)
        {
            child.parent1 = parent_id;
        } else {
            // make p1 < p2
            int p1 = child.parent1;
            int p2 = parent_id;
            if (p1 < p2) {
                child.parent2 = parent_id;
            } else {
                child.parent1 = parent_id;
                child.parent2 = p1;
            }
        }
    }

    int child_id;
    cin >> child_id;

    Person child = people[child_id];
    bool found = false;
    bool has_parents = child.parent1 != -1 && child.parent2 != -1;
    for (int i = 0; i < num_people && !found && has_parents; i++)
    {
        if (i == child_id)
            continue;

        Person p = people[i];

        found = p.parent1 == child.parent1 && p.parent2 == child.parent2 && p.parent1 != -1 && p.parent2 != -1;
    }

    cout << (found && has_parents ? "Van" : "Nincs") << endl;

    return 0;
}