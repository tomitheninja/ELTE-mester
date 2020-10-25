#include <iostream>

using namespace std;

unsigned long long int fibonacci(int n)
{
    if (n <= 1)
        return n;
    unsigned long long int a = 0, b = 1;
    for (int i = 2; i <= n; i++)
    {
        // a = b; b = a + b
        unsigned long long int sum = a + b;
        a = b;
        b = sum;
    }
    return b;
}

int main()
{
    int n;
    cin >> n;

    cout << fibonacci(n + 1) << endl;
    return 0;
}