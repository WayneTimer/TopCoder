#line 4 "Powerit.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Powerit
{
public:

#define MAXN 1000010

    int calc(int n, int k, int m)
    {		
        long long sum,mod,a,ans;
        long long f[MAXN];
        bool flag[MAXN];
        memset(flag,false,sizeof(flag));
        mod = m;
        sum = 1%mod;
        f[1] = 1%mod;
        flag[1] = true;

        for (int x=2;x<=n;x++)
        {
            if (flag[x]) 
            {
                sum = (sum+f[x])%mod;
                continue;
            }

            ans = 1;
            a = x;
            for (int i=0;i<k;i++)
            {
                ans = ans*a%mod;
                a = a*a%mod;
            }
            f[x] = ans;
            flag[x] = true;
            sum = (sum+ans)%mod;

            for (long long y=2;y<=x;y++)
            {
                if (y*x>n) break;
                if (flag[y*x]) continue;
                f[y*x] = f[y]*f[x]%mod;
                flag[y*x] = true;
            }
        }
        return (int)sum;
    }
};
