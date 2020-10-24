#include <iostream>

using namespace std;

int main()
{
    const int WATER_LEVEL = 0;
    int num_measurements;
    cin >> num_measurements;

    int data[num_measurements];

    int start = -1, end = -1;

    for (int i = 0; i < num_measurements; i++)
    {
        int height;
        cin >> height;
        data[i] = height;

        if (start == -1 && height == WATER_LEVEL)
        {
            // leaving the continent
            start = i;
        }

        if (height == WATER_LEVEL)
        {
            // find the last water
            end = i;
        }
    }

    int result = 0;
    for (int i = start; i <= end; i++)
    {
        bool on_island = data[i] != WATER_LEVEL;
        if (on_island)
        {
            result++;
        }
    }

    cout << result << endl;

    return 0;
}