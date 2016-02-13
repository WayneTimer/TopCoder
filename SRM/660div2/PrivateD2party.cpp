#line 4 "PrivateD2party.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

class PrivateD2party
{
public:
    int s[51];
    bool del[50];

    bool check_loop(int y,vector<int> a)
    {
        bool mark[50];
        int x;
        x = y;
        memset(mark,true,sizeof(mark));
        mark[x]=false;
        while (!del[a[x]] && mark[a[x]])
        {
            x = a[x];
            mark[x] = false;
        }
        if (x==a[x] || del[a[x]]) return false;

        s[a[x]]++;
        for (int i=a[a[x]];i!=a[x];i=a[i])
        {
            s[i]++;
        }
        return true;
    }

    int getsz(vector <int> a)
    {		
        int res,n;
        n = a.size();
        res = n;
        memset(del,false,sizeof(del));
        do
        {
            memset(s,0,sizeof(s));
            for (int i=0;i<n;i++)
                if (!del[i])
                {
                    check_loop(i,a);
                }
            int maxs,y;
            maxs=0;
            for (int i=0;i<n;i++)
                if (!del[i])
                {
                    if (s[i]>maxs)
                    {
                        maxs=s[i];
                        y=i;
                    }
                }
            if (maxs>0) 
            {
                del[y]=true;
                res--;
            }
            else
                break;
        } while (true);
        return res;
    }
};
