
#include "../header/myheader.h"

class LT2452
{
public:

    // D D

    //vector<string> res;
    //for (auto& query : queries)
    //{
    //    auto max2edits = [&query](const string& word)
    //    {
    //        int count = 0;
    //        for (int i = 0; i < word.size() and count <= 3; i++)
    //            if (word[i] != query[i])
    //                count++;
    //        return count < 3;
    //    };
    //    if (any_of(begin(dictionary), end(dictionary), max2edits))
    //        res.push_back(query);
    //}
    //return res;




//Runtime19 ms
//Beats
//91.40 %
//Memory8.9 MB
//Beats
//99.81 %
    // 修改2个char 后，能在 字典中找到。
    vector<string> lt2452a(vector<string>& queries, vector<string>& dictionary)
    {
        vector<string> ans;
        int sz1 = queries.size();
        int sz2 = dictionary.size();
        int sz3 = queries[0].size();
        for (int i = 0; i < sz1; ++i)
        {
            string& s2 = queries[i];
            for (int j = 0; j < sz2; ++j)
            {
                int cnt = 0;

                for (int k = 0; k < sz3 && cnt <= 2; ++k)
                {
                    if (s2[k] != dictionary[j][k])
                    {
                        ++cnt;
                    }
                }

                if (cnt <= 2)
                {
                    ans.push_back(s2);
                    break;
                }
            }
        }

        return ans;
    }

};

int main()
{

    LT2452 lt;


    return 0;
}
