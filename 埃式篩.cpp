#include <iostream>
using namespace std;

const int MAXN = 1000000;
bool isprime[MAXN + 1];
int prefix[MAXN + 1];

void sieve() 
{
    for (int i = 0; i <= MAXN; i++) isprime[i] = true;
    isprime[0] = isprime[1] = false;
    for (int i = 2; i * i <= MAXN; i++) 
    {
        if (isprime[i]) 
        {
            for (int j = i * i; j <= MAXN; j += i) 
            {
                isprime[j] = false;
            }
        }
    }
}

int digitSum(int x) 
{
    int s = 0;
    while (x) 
    {
        s += x % 10;
        x /= 10;
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    for (int i = 1; i <= MAXN; i++) 
    {
        int tal = digitSum(i);
        int good = (isprime[i] && isprime[tal]) ? 1 : 0;
        prefix[i] = prefix[i - 1] + good;
    }
    int n;
    cin >> n;
    while (n--) 
    {
        int a, b;
        cin >> a >> b;
        cout << prefix[b] - prefix[a - 1] << "\n";
    }
    return 0;
}
