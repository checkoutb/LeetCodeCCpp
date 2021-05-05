
#include "../header/myheader.h"

class LT1733
{
public:





// 。。。。
    int lt1733b(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships)
    {
        unordered_map<int, vector<int>> map2;
        unordered_map<int, vector<int>> map3;
        for (int i = 0; i < languages.size(); ++i)
            for (int lan : languages[i])
                map2[lan].push_back(i);
        for (int i = 0; i < friendships.size(); ++i)
        {
            vector<int>& v1 = map2[friendships[i][0] - 1];
            vector<int>& v2 = map2[friendships[i][1] - 1];
            bool can = false;
            for (int& i1 : v1)
                for (int i2 : v2)
                    if (i1 == i2)
                    {
                        can = true;
                        goto AAA;
                    }

            AAA:
            if (!can)
            {
                map3[friendships[i][0] - 1].push_back(friendships[i][1] - 1);
                map3[friendships[i][1] - 1].push_back(friendships[i][0] - 1);
            }
        }
        int ans = 0;

        // ...
        // .... 写不出，看了discuss。。。md，原来 我只会教一种语言，可以教多个人。。
        // 原本想的是： 我什么语言都会， 某个人+他不能交流的朋友，最少需要教多少个人(可以教不同的语言)，他们就都能交流了。 ，
        // 然后对 每个 人+不能交流的朋友(可能之前教了，所以现在能交流了)，都计算一遍， 返回总和最小的值。。。。


        return ans;
    }


// ??? 第二个Example 过不了啊。
// 英语太难了。。。是教会一种语言，以便他能和所有朋友交流。。。 而不是： 用他会的语言告诉他一些信息，然后让他传播出去。。
    int lt1733a(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships)
    {
        vector<int> arr(languages.size());
        int ans = 0;
        unordered_map<int, vector<int>> map2;           // language : persons
        unordered_map<int, vector<int>> map3;           // person : friends
        for (int i = 0; i < languages.size(); ++i)
        {
            for (int lang : languages[i])
            {
                map2[lang].push_back(i);
            }

        }
        for (int i = 0; i < friendships.size(); ++i)
        {
            // ... friend but cannot communicate
            vector<int> v1 = map2[friendships[i][0] - 1];
            vector<int> v2 = map2[friendships[i][1] - 1];
            bool can = false;

            for (int& i1 : v1)
            {
                for (int& i2 : v2)
                {
                    if (i1 == i2)
                    {
                        can = true;
                        goto AAA;
                    }
                }
            }
            AAA:
            if (can)
            {
                map3[friendships[i][0] - 1].push_back(friendships[i][1] - 1);
                map3[friendships[i][1] - 1].push_back(friendships[i][0] - 1);           // frindships's user start from 1
            }
            else
            {
//                cout<<"cannot "<<i<<endl;
            }
        }
        for (int i = 0; i < arr.size(); ++i)
        {
            if (arr[i] == 0)
            {
                ans++;
                arr[i] = 1;
//                unordered_set<int> set2;
//                set2.insert(i);
                queue<int> que1;
                que1.push(i);
                while (!que1.empty())
                {
                    int t2 = que1.front();
                    que1.pop();
                    for (int fri : map3[t2])
                    {
                        if (arr[fri] == 0)
                        {
                            arr[fri] = 1;
                            que1.push(fri);
                        }
                    }
//                    for (int lang : languages[t2])
//                    {
//                        for (int person : map2[lang])
//                        {
//                            if (arr[person] == 0)
//                            {
//                                arr[person] = 1;
//                                que1.push(person);
//                            }
//                        }
//                    }
                }
            }
            #ifdef __test
            showVectorInt(arr);
            #endif // __test
        }

        return ans;
    }

};

int main()
{
//    int lang = 2;
//    myvvi vv1 = {{1},{2},{1,2}};
//    myvvi vv2 = {{1,2},{1,3},{2,3}};

    int lang = 3;
    myvvi vv1 = {{2},{1,3},{1,2},{3}};
    myvvi vv2 = {{1,4},{1,2},{3,4},{2,3}};

    LT1733 lt;

    cout<<lt.lt1733a(lang, vv1, vv2)<<endl;

    return 0;
}
