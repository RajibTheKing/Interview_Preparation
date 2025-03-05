// i want to calculate first 100 primes
// and store them in a vector
// and then print them

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    vector<int> primes;
    primes.push_back(2);
    int n = 3;
    while (primes.size() < 100)
    {
        bool isPrime = true;
        for (int i = 0; i < primes.size(); i++)
        {
            if (primes[i] > sqrt(n))
                break;
            if (n % primes[i] == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            primes.push_back(n);
        n += 2;
    }
    for (int i = 0; i < primes.size(); i++)
        cout << primes[i] << " ";
    cout << endl;
    return 0;
}