#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n)
{

    string s = to_string(n);
    vector<int> v;

    for (int i = s.length() - 1; i >= 0; i--)
        v.push_back(s[i] - '0');
    return v;
}
