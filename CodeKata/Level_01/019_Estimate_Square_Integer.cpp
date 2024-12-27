#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n)
{
    return pow((float)sqrt(n),2) - n != 0 ? -1 : pow(sqrt(n)+1,2);
}
