#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string s)
{
    int number = 0;
    int positive = 1;

    if (s[0] == '-' || s[0] == '+')
    {
        s[0] == '-' ? positive = -1 : positive = 1;
        s = s.substr(1, s.length() - 1);
    }
    
    for (int i = 0; i < s.length(); i++)
    {
        int digit = s[i] - '0';
        number += digit * (pow(10, (s.length()-i))/10);
    }
    return number * positive;
}
