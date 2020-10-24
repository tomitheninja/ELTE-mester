#include <iostream>

using namespace std;

double get_avg(int *arr, int arr_length)
{
    double sum = 0;
    for (int i = 0; i < arr_length; i++)
    {
        sum += arr[i];
    }

    return sum / arr_length;
}

int main() {
    const double INFINITY = 9999;
    int n, m;

    cin >> n >> m;

    double max_avg = -INFINITY;
    int max_avg_idx = -1;

    for (int i = 0; i < n; i++)
    {
        int data[m];
        for (int j = 0; j < m; j++)
        {
            cin >> data[j];
        }
        
        double avg = get_avg(data, m);

        if (avg > max_avg) {
            max_avg = avg;
            max_avg_idx = i;
        }
    }

    cout << max_avg_idx + 1 << endl;

    return 0;
}