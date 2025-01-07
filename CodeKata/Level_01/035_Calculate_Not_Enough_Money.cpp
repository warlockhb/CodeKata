using namespace std;

long long solution(int price, int money, int count)
{
    long long weightedPrice = price;
    long long total = 0;
    for (int i = 1; i <= count; i++)
    {
        weightedPrice = price * i;
        total += weightedPrice;
    }
    return  (money - total < 0) ? ((long long)(money * -1) + total) : 0;
}
