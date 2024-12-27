#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n)
{
    vector<long long> numbers(n);

    int sum = x;
    for (int i = 0; i < n; i++)
    {
        numbers[i] = sum;
        sum += x;
    }
    return numbers;
}
