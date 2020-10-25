#include <iostream>
#include <map>

using namespace std;

int main()
{
    int num_students, num_competitions;
    cin >> num_students >> num_competitions;

    int min_scores[num_competitions];
    for (int i = 0; i < num_competitions; i++)
    {
        cin >> min_scores[i];
    }

    int num_draws[num_competitions];

    for (int i = 0; i < num_competitions; i++)
    {
        int num_attendees;
        cin >> num_attendees;

        int scores[101] = {};
        for (int j = 0; j < num_attendees; j++)
        {
            int _, score;
            cin >> _ >> score;
            scores[score] += 1;
        }

        num_draws[i] = 0;
        for (int j = min_scores[i]; j < 101; j++)
        {
            if (scores[j] > 1)
            {
                num_draws[i] += scores[j];
            }
        }
    }

    int max_draws = 0;
    for (int i = 0; i < num_competitions; i++)
    {
        max_draws = std::max(num_draws[i], max_draws);
    }

    if (max_draws == 0)
    {
        cout << '0' << endl;
    }
    else
    {

        int num_max_draws = 0;
        for (int i = 0; i < num_competitions; i++)
        {
            if (num_draws[i] == max_draws)
            {
                num_max_draws += 1;
            }
        }

        cout << num_max_draws;

        for (int i = 0; i < num_competitions; i++)
        {
            int val = num_draws[i];

            if (val == max_draws)
            {
                cout << ' ' << i + 1;
            }
        }

        cout << endl;
    }
    return 0;
}