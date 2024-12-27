#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> solution(int n, vector<string> words)
{
    vector<int> answer;

    int wordsCount = size(words);
    
    for (int i = 0; i < wordsCount - 1; i++)
    {
        // 순서 판단
        int order = ((i % n) + 1);
        int cycle = int(float(i) / float(n) + 1);

        int next_order = (((i+1) % n) + 1);
        int next_cycle = int(floor(float(i+1) / float(n)) + 1);

        // 현재 단어
        string currentWord = words[i];
        // 현재 단어 끝 글자
        char currentWord_last = NULL;
        if (currentWord.empty() == false)
        {
            currentWord_last = currentWord.back();
        }

        // 다음 단어
        string nextWord = words[i+1];
        char nextWord_front = NULL;
        // 현재 단어 끝 글자
        if (nextWord.empty() == false)
        {
            nextWord_front = nextWord.front();
        }

        // 끝말잇기 오류 체크
        if (nextWord_front != currentWord_last)
        {
            answer = {next_order, next_cycle};
            return answer;
        }

        // 끝말잇기 중복체크
        for (int j = 0; j < i; j++)
        {
            if (words[j] == words[i+1])
            {
                answer = {next_order, next_cycle};
                return answer;
            }
        }
    }
    answer = {0, 0};
    
    return answer;
}
