#include <string>

using namespace std;

string solution(string n)
{
    for (int i = 0; i < n.length(); i++)
        n[i] = i < (n.length() - 4) ? '*' : n[i];
    
    return n;
}
