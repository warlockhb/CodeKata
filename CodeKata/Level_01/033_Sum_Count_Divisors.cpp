#include <string>
#include <vector>

using namespace std;

int solution(int left, int right)
{
    int sum = 0;

    for (int i = left; i <= right; i++)
    {
        int sign = 1;
        
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
                sign *= -1;
        }
        sum += (sign * i);
    }
    
    return sum;
}
