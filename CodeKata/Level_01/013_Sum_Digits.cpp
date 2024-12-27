#include <iostream>

using namespace std;

int solution(int n)
{
    string s = to_string(n);
    int sum = 0;

    for (int i = 0; i < s.length(); i++)
    {
        sum += (s[i] - '0');
    }
    return sum;
}
