
#include "../header/myheader.h"

class LT2284
{
public:

// D D

//for (int i = 0; i < n; i++) {
//    mp[senders[i]] += count(messages[i]);
//    if (mp[senders[i]] > mp[ans] || (mp[senders[i]] == mp[ans] && senders[i] > ans))
//        ans = senders[i];
//}

//int words = count(begin(messages[i]), end(messages[i]), ' ') + 1;





//Runtime: 288 ms, faster than 50.00 % of C++ online submissions for Sender With Largest Word Count.
//Memory Usage : 71.8 MB, less than 50.00 % of C++ online submissions for Sender With Largest Word Count.
    string lt2284a(vector<string>& messages, vector<string>& senders)
    {
        string ans = "";
        int cnt = 0;
        unordered_map<string, int> map2;
        for (int i = 0; i < messages.size(); ++i)
        {
            map2[senders[i]] += std::count_if(begin(messages[i]), end(messages[i]), [](char ch) { return ch == ' '; }) + 1;
        }
        for (unordered_map<string, int>::iterator it = begin(map2); it != end(map2); it++)
        {

            if (it->second > cnt || (it->second == cnt && it->first > ans))
            {
                ans = it->first;
                cnt = it->second;
            }
        }
        return ans;
    }

};

int main()
{

    LT2284 lt;

    vector<string> vs1 = { "Hello userTwooo","Hi userThree","Wonderful day Alice","Nice day userThree" };
    vector<string> vs2 = { "Alice","userTwo","userThree","Alice" };

    cout << lt.lt2284a(vs1, vs2) << endl;

    return 0;
}
