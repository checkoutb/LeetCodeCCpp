
#include "../header/myheader.h"

class LT0752
{
public:

// D D


//    int rot(int d, int n){
//        return (10+d+n)%10;
//    }
//    int toValue(int a[4]){
//        return 1000*a[3]+100*a[2]+10*a[1]+a[0];
//    }




//Runtime: 220 ms, faster than 82.53% of C++ online submissions for Open the Lock.
//Memory Usage: 29.4 MB, less than 78.44% of C++ online submissions for Open the Lock.
    int lt0752a(vector<string>& deadends, string target)
    {
        string s = "0000";
        if (target == s)
            return 0;
        unordered_set<string> set2(begin(deadends), end(deadends));
        if (set2.find(s) != set2.end())
            return -1;
        set2.insert(s);
        int ans = 0;
        queue<string> que1;
        que1.push(s);
        while (!que1.empty())
        {
            ans++;
            int sz1 = que1.size();
            while (sz1-- > 0)
            {
                string s2 = que1.front();
                que1.pop();
                for (int i = 0; i < 4; ++i)
                {
                    string s3(s2);
                    s3[i] = s3[i] == '9' ? '0' : char (s3[i] + 1);
                    if (s3 == target)
                        goto AAA;
                    if (set2.find(s3) == set2.end())
                    {
                        set2.insert(s3);
                        que1.push(s3);
                    }

                    string s4(s2);
                    s4[i] = s4[i] == '0' ? '9' : char (s4[i] - 1);
                    if (s4 == target)
                        goto AAA;
                    if (set2.find(s4) == set2.end())
                    {
                        set2.insert(s4);
                        que1.push(s4);
                    }
                }
            }
        }
        return -1;

        AAA:
        return ans;
    }

};

int main()
{
//    vector<string> vs = {"0201","0101","0102","1212","2002"};
//    string tar = "0202";

//    vector<string> vs = {"8888"};
//    string tar = "0009";

    vector<string> vs = {"8887","8889","8878","8898","8788","8988","7888","9888"};
    string tar = "8888";

    LT0752 lt;

    cout<<lt.lt0752a(vs, tar);

    return 0;
}
