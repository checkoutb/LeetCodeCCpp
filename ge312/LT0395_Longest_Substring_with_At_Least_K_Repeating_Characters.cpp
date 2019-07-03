
#include "../header/myheader.h"

class LT0395
{
public:



// details
// map<char, int>记录个数

//        for(int i=0;i<s.length();i++){
//            if(cnt[s[i]-'a']!=0&&cnt[s[i]-'a']<k){
//                max_len=max(max_len,longestSubstring(s.substr(start,i-start),k));
//                start=i+1;
//            }
//        }
//        if(start<s.length()){
//            max_len=max(max_len,longestSubstring(s.substr(start,s.length()-start),k));
//        }
// 直接substring。然后递归 xx(substr, k)

//        set<string> sv;
//        string tmp;
//        for (int i = 0; i < s.length(); i++) {
//            if (m[s[i]] < k) {
//                sv.insert(tmp);
//                tmp = "";
//            }
//            else {
//                tmp += s[i];
//            }
//        }
//        sv.insert(tmp);
// 先分裂完，然后foreach substr



//        int j, i, unique, nolessthank,h, index;
//        int  maxl=0;
//
//        for(h=1; h<=26; ++h){
//            vector<int> count(26, 0);
//            i = 0;
//            j = 0;
//            unique = 0;
//            nolessthank = 0;
//            while(j < s.length()){
//                if(unique <= h){
//                    index = s[j] - 'a';
//                    if(count[index] == 0) unique++;
//                    count[index]++;
//                    if(count[index] == k) nolessthank++;
//                    j++;                                              // j++++
//                }
//                else{
//                    index = s[i] - 'a';
//                    if(count[index] == k) nolessthank--;
//                    count[index]--;
//                    if(count[index] == 0) unique--;
//                    i++;                                         // i++++++++++++
//                }
//                if(unique == h && unique == nolessthank) maxl = max(maxl, j - i);
//            }
//        }
//        return maxl;
// ?????
// discuss 中有这个代码的 java版本
// For each h, apply two pointer technique to find the longest substring with at least K repeating characters and the number of unique characters in substring is h.
// 2个指针i,j， [i,j]内的字符种类必须==h，且每种字符个数必须>=k..当h变成26的时候，就结束了。
// 头位置i，尾指针j，j指向下一个会加入的char。i代表substr的首字符。
// 当字符种类没有超过上限的时候(unique <= h),查看尾指针，没有出现过(count==0)，种类++，出现过且个数==k，满足>=k的char种类++，尾指针j++，
// 当char种类超过上限时，查看头指针，并剔除它及它的信息，i++


// discuss
// 直接二分，而不是n分。





//Runtime: 12 ms, faster than 46.23% of C++ online submissions for Longest Substring with At Least K Repeating Characters.
//Memory Usage: 77.5 MB, less than 5.96% of C++ online submissions for Longest Substring with At Least K

    // 三维数组？start,end,char
    int lt0395b(string s, int k)
    {
        int sz1 = s.size();
        int ans = 0;
        int arr2[sz1 + 1][26] = {{0}};
        for (int i = 0; i < sz1; i++)
        {
            int t1 = s[i] - 'a';
            for (int j = 0; j < 26; j++)
            {
                if (j == t1)
                {
                    arr2[i + 1][j] = arr2[i][j] + 1;
                }
                else
                {
                    arr2[i + 1][j] = arr2[i][j];
                }
            }
        }

        #ifdef __test
//        for (int ij = 0; ij <= sz1; ij++)
//        {
//            for_each(begin(arr2[ij]), end(arr2[ij]), fun_cout);
//            cout<<endl;
//        }
        #endif // __test

        ans = recursionb1(s, arr2, 0, sz1, k);
        return ans;
    }

// start && end are arr2's index.
    int recursionb1(string s, int arr2[][26], int start, int end, int k)
    {
        #ifdef __test
//        cout<<start<<", "<<end<<endl;
        #endif // __test

        if (end - start < k)
            return 0;

        bool arr[26];
        bool flag1 = true;
        for (int i = 0; i < 26; i++)
        {
            int t1 = arr2[end][i] - arr2[start][i];

            #ifdef __test
//            cout<<t1<<endl;
            #endif // __test

            if (t1 != 0 && t1 < k)
            {
                arr[i] = false;
                flag1 = false;
            }
            else
            {
                arr[i] = true;
            }
        }

        #ifdef __test
//        cout<<"flag1 : "<<flag1<<endl;
        #endif // __test

        if (flag1)
        {
            return end - start;
        }
        else
        {
            int ans = 0;
            int t1 = start;
            for (int i = start; i < end; i++)
            {
                if (!arr[s[i] - 'a'])
                {
                    #ifdef __test
//                    cout<<"    "<<t1<<", "<<i<<endl;
                    #endif // __test
                    ans = max(ans, recursionb1(s, arr2, t1, i, k));     // t1是取不到的。
                    t1 = i + 1;         // str -> arr
                }
            }
            ans = max(ans, recursionb1(s, arr2, t1, end, k));
            return ans;
        }
    }


    // 28/28 tle
    int lt0395a(string s, int k)
    {
        int sz1 = s.size();
        int ans = 0;
        int arr2[sz1 + 1][26] = {{0}};
        for (int j = 0; j < sz1; j++)
        {
            int t1 = s[j] - 'a';
            for (int i = 0; i < 26; i++)
            {
                if (i == t1)
                {
                    arr2[j + 1][i] = arr2[j][i] + 1;
                }
                else
                {
                    arr2[j + 1][i] = arr2[j][i];
                }
            }
        }

        #ifdef __test
        for (int ij = 0; ij <= sz1; ij++)
        {
            for_each(begin(arr2[ij]), end(arr2[ij]), fun_cout);
            cout<<endl;
        }
        #endif // __test

        int t1 = 0;
        for (int i = 0; i <= sz1; i++)
        {
            t1 = max(k, ans);
            for (int j = sz1; j >= i + t1; j--)
            {
                bool flag1 = true;
                int t2 = 0;
                for (int k2 = 0; k2 < 26; k2++)
                {
                    t2 = arr2[j][k2] - arr2[i][k2];

                    #ifdef __test
//                    cout<<t2<<endl;
                    #endif // __test

                    if (t2 != 0 && t2 < k)
                    {
                        flag1 = false;
                        break;
                    }
                }
                if (flag1)
                {
                    #ifdef __test
                    cout<<t2<<", "<<ans<<", "<<j - i<<endl;
                    #endif // __test
                    ans = max(ans, j - i);
                }
            }
        }
        return ans;
    }
};

int main()
{
//    string s = "aaabb";
//    int k = 3;

//    string s = "ababbc";
//    int k = 2;

    string s = "bbaaacbd";
    int k = 3;


    LT0395 lt;
    cout<<lt.lt0395b(s, k)<<endl;

    return 0;
}
