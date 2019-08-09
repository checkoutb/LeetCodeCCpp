
#include "../header/myheader.h"

class LT0423
{


// discuss
//    for (int i = 0; i < s.length(); i++){
//        char c = s.charAt(i);
//        if (c == 'z') count[0]++;
//        if (c == 'w') count[2]++;
//        if (c == 'x') count[6]++;
//        if (c == 's') count[7]++; //7-6
//        if (c == 'g') count[8]++;
//        if (c == 'u') count[4]++;
//        if (c == 'f') count[5]++; //5-4
//        if (c == 'h') count[3]++; //3-8
//        if (c == 'i') count[9]++; //9-8-5-6
//        if (c == 'o') count[1]++; //1-0-2-4
//    }
//    count[7] -= count[6];
//    count[5] -= count[4];
//    count[3] -= count[8];
//    count[9] = count[9] - count[8] - count[5] - count[6];
//    count[1] = count[1] - count[0] - count[2] - count[4];
// 只记录关键char


//        int[] count = new int[128];
//        for(int i=0;i<s.length();i++)  count[s.charAt(i)]++;
//        int[] num = new int[10];
//        num[0] = count['z'];
//        num[2] = count['w'];
//        num[4] = count['u'];
//        num[6] = count['x'];
//        num[8] = count['g'];
//        num[1] = count['o']-count['z']-count['w']-count['u'];
//        num[3] = count['h']-count['g'];
//        num[5] = count['v']-count['s']+count['x'];
//        num[7] = count['s']-count['x'];
//        num[9] = count['i']-count['x']-count['g']-count['v']+count['s']-count['x'];
// 累加全部，只计算关键char



//Runtime: 32 ms, faster than 35.67% of C++ online submissions for Reconstruct Original Digits from English.
//Memory Usage: 11.3 MB, less than 100.00% of C++ online submissions for Reconstruct Original Digits from English.

// zero, one, two, three, four, five, six, seven, eight, nine,

public:
    string lt0423a(string s)
    {
        int arr2[][5] = {{'z','e','r','o'},{'o','n','e'},{'t','w','o'},{'t','h','r','e','e'},
            {'f','o','u','r'},{'f','i','v','e'},{'s','i','x'},{'s','e','v','e','n'},
            {'e','i','g','h','t'},{'n','i','n','e'}
        };
        int arr3[][2] = {{0,'z'},{2,'w'},{4,'u'},{6,'x'},{7,'s'},{8,'g'},{1,'o'},{3,'r'},{5,'v'},{9,'e'}};
        int arr[128] = {0};
        int arr4[10] = {0};
        for (auto& p : s)
        {
            arr[p]++;
        }
        for (auto& p : arr3)
        {
            int n = p[0];
            int cnt = arr[p[1]];
            arr4[n] = cnt;
            if (cnt != 0)
            {
                for (auto& p2 : arr2[n])
                {
                    arr[p2] -= cnt;
                }
            }
        }
        string ans;
        for (int i = 0; i < 10; i++)
        {
            int cnt = arr4[i];
            while (cnt > 0)
            {
                cnt--;
                ans += to_string(i);
            }
        }
        return ans;
    }
};

int main()
{
    string s = "owoztneoer";

    LT0423 lt;
    cout<<endl<<lt.lt0423a(s)<<endl;

    return 0;
}
