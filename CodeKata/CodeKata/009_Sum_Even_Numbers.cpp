#include <string>
#include <vector>

int solution(int n)
{
    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
            result += i;
    }
    return result;
}
