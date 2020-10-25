#include <iostream>

using namespace std;

int distance(int p1, int p2)
{
    if (p1 < p2)
        return p2 - p1;
    return p1 - p2;
}

int main()
{
    int num_houses, cover_dist;
    cin >> num_houses >> cover_dist;

    int houses[num_houses];
    for (int i = 0; i < num_houses; i++)
    {
        cin >> houses[i];
    }

    int routers[num_houses];
    int num_routers = 0;

    int first_uncovered = 0;
    int i = 0;
    while (first_uncovered < houses[num_houses - 1])
    {
        // Skip empty area
        for (; i < num_houses; i++)
        {
            int h = houses[i];
            if (h >= first_uncovered)
            {
                first_uncovered = h;
                break;
            }
        }
        // Find the furthest house
        // that still covers the first uncovered house
        int next_router = -1;
        for (; i < num_houses; i++)
        {
            int h = houses[i];
            if (first_uncovered + cover_dist < h)
            {
                break;
            }
            else
            {
                next_router = i;
            }
        }

        first_uncovered = houses[next_router] + cover_dist + 1;
        routers[num_routers++] = next_router;
    }

    cout << num_routers << endl;
    for (int i = 0; i < num_routers; i++)
    {
        if (i != 0)
        {
            cout << ' ';
        }
        cout << routers[i] + 1;
    }

    cout << endl;

    return 0;
}