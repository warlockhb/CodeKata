#include <string>
#include <vector>

using namespace std;

bool solution(string s)
{
    if (s.length() == 4 or s.length() == 6)
    {
        for (char c : s)
        {
            if (isalpha(c) and not isdigit(c))
                return false;
        }
        return true;
    }
    return false;
}
