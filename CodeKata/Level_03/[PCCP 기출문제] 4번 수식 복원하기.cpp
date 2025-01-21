#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// expressions의 원소는 "A + B = C" 혹은 "A - B = C" 형태의 문자열입니다. A, B, C와 연산 기호들은 공백 하나로 구분되어 있습니다.
// A, B는 음이 아닌 두 자릿수 이하의 정수입니다.
// C는 알파벳 X 혹은 음이 아닌 세 자릿수 이하의 정수입니다. C가 알파벳 X인 수식은 결괏값이 지워진 수식을 의미하며, 이러한 수식은 한 번 이상 등장합니다.
// 결괏값이 음수가 되거나 서로 모순되는 수식은 주어지지 않습니다.

// 진법
int to_decimal(int num, int base)
{
    int result = 0;
    int pow = 1;
    int temp = num;
    
    // 진법 자릿수 검사
    while (temp > 0)
    {
        int digit = temp % 10;
        if (digit >= base)
            return -1;
        temp = temp / 10;
    }
    
    while (num > 0)
    {
        result += (num % 10) * pow;
        num /= 10;
        pow *= base;
    }
    return result;
}

int form_decimal(int num, int base)
{
    if (num == 0) return 0;
    int result = 0;
    int pow = 1;
    while (num > 0)
    {
        result += (num % base) * pow;
        num /= base;
        pow *= 10;
    }
    return result;
}

bool is_valid_Expression(const string& expression, int base)
{
    stringstream ss(expression);
    string a, op, b, eq, result;
    ss >> a >> op >> b >> eq >> result;
    // 숫자 변환
    int num_a = stoi(a);
    int num_b = stoi(b);
    
    //각 숫자를 10진수로 변환
    int decimal_a = to_decimal(num_a, base);
    int decimal_b = to_decimal(num_b, base);

    // a,b 인자 자릿값 검사
    if (decimal_a == -1 || decimal_b == -1) return false;
    
    // 결과 값 X의 경우 패싱
    if (result == "X") return true;

    // 결과 값
    int num_result = stoi(result);
    int decimal_result = to_decimal(num_result, base);

    // 진법 자릿수 유효성 검사
    if (decimal_a == -1 || decimal_b == -1 || decimal_result == -1) return false;

    // 오퍼레이터 분류
    if      (op == "+")
        return decimal_a + decimal_b == decimal_result;
    else if (op == "-")
        return decimal_a - decimal_b == decimal_result;

    // - +가 아닌 오퍼레이터
    return false;
}


// 사용 가능한 진수들 찾기
vector<int> search_base(const vector<string>& expressions)
{
    vector<int> result;
    
    for (int b = 2; b <= 9; b++)
    {
        bool valid = true;
        for (const string& expression : expressions)
        {
            if (not is_valid_Expression(expression, b))
            {
                valid = false;
                break;
            }
        }
        if (valid) result.push_back(b);;
    }
    return result;
}


vector<string> caculate_expression(const vector<string>& expressions)
{
    vector<string> new_expressions;
    vector<int> possible_bases = search_base(expressions);
    
    for (const string& expression : expressions)
    {
        stringstream ss(expression);
        string a, op, b, eq, result;
        ss >> a >> op >> b >> eq >> result;

        if (result != "X") continue;

        // 중복 없는 숫자의 컨테이너 set
        set<int> possible_results;

        for (int base : possible_bases)
        {
            int num_a = stoi(a);
            int num_b = stoi(b);
            
            int decimal_a = to_decimal(num_a, base);
            int decimal_b = to_decimal(num_b, base);
            int decimal_result;
            
            if      (op == "+")
                decimal_result = decimal_a + decimal_b;
            else if (op == "-")
                decimal_result = decimal_a - decimal_b;

            possible_results.insert(form_decimal(decimal_result, base));
        }
        
        string new_expression;

        if (possible_results.size() == 1)
            new_expression = a + " " + op + " " + b + " = " + to_string(*possible_results.begin());
        else
            new_expression = a + " " + op + " " + b + " = " + "?";

        new_expressions.push_back(new_expression);
    }
    return new_expressions;
}


vector<string> solution(vector<string> expressions) 
{
    return caculate_expression(expressions);
}

