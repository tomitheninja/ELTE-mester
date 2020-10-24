#include <iostream>

using namespace std;

int main() {
    const int WARM_TRESHOLD = 30;
    int num_cities, num_days;
    cin >> num_cities >> num_days;

    int cnt_filtered[num_days];
    std::fill(cnt_filtered, cnt_filtered + num_days, 0);

    for (int i = 0; i < num_cities; i++)
    {
        for (int j = 0; j < num_days; j++)
        {
            int value;
            cin >> value;

            if (value >= WARM_TRESHOLD)
            {
                cnt_filtered[j] += 1;
            }
        }
    }

    bool is_result[num_days];
    int cnt_results = 0;

    for (int j = 0; j < num_days; j++)
    {
        if (cnt_filtered[j] >= (float)num_cities / 2)
        {
            cnt_results++;
            is_result[j] = true;
        }
        else
        {
            is_result[j] = false;
        }
    }

    cout << cnt_results;
    for (int j = 0; j < num_days; j++)
    {
        if (is_result[j])
        {
            cout << ' ' << j + 1;
        }
    }
    cout << endl;
    

    return 0;
}