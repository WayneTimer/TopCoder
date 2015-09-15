#line 83 "Cyclemin.cpp"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Cyclemin
{
    public:
    string bestmod(string s, int k)
    {		
        string s_origin,a,ret;
        s_origin = s;
        ret = s;
        do
        {
            a = s;
            int j = k;
            int i = 0;
            while (j && i<a.length())
            {
                if (a[i] > 'a')
                {
                    j--;
                    a[i] = 'a';
                }
                i++;
            };
            if (ret.compare(a) > 0) ret = a;
            s = s.substr(1,s.length()-1) + s[0];
        } while (s.compare(s_origin) != 0);
        return ret;
    }
};
