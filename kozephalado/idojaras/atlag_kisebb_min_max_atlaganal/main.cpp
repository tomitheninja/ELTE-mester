#include <iostream>

using namespace std;

double get_avg(int * arr, int arr_length) {
    double sum = 0;
    for (int i = 0; i < arr_length; i++)
    {
        sum += arr[i];
    }

    return sum / arr_length;
}

int get_max(int *arr, int arr_length)
{
    double max = arr[0];
    for (int i = 1; i < arr_length; i++)
    {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

int get_min(int *arr, int arr_length)
{
    double min = arr[0];
    for (int i = 1; i < arr_length; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    return min;
}

int main() {
    int n, m;
    cin >> n >> m;

    bool is_result[n];
    int cnt_results = 0;

    for (int i = 0; i < n; i++)
    {
        int data[m];
        for (int j = 0; j < m; j++)
        {
            cin >> data[j];
        }
        double avg = get_avg(data, m);
        int min = get_min(data, m);
        int max = get_max(data, m);

        if (max - avg > avg - min)
        {
            cnt_results++;
            is_result[i] = true;
        }
        else
        {
            is_result[i] = false;
        }
    }

    cout << cnt_results;
    for (int i = 0; i < n; i++)
    {
        if (is_result[i]) {
            cout << ' ' << i + 1;
        }
    }
    cout << endl;

    return 0;    
}