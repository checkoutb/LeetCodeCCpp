
#include "../header/myheader.h"

class LT1897
{
public:

// D D

//        return all_of(begin(char_count), end(char_count),
//                      [&](int c) { return c % words.size() == 0; });


//        int[] counts = new int[26];
//        Arrays.stream(words).forEach(w -> w.chars().forEach(c -> counts[c - 'a']++));
//        return Arrays.stream(counts).allMatch(c -> c % words.length == 0);





// after D D
//Runtime: 124 ms, faster than 5.00% of C++ online submissions for Redistribute Characters to Make All Strings Equal.
//Memory Usage: 78.4 MB, less than 6.99% of C++ online submissions for Redistribute Characters to Make All Strings Equal.
    bool lt1897b(vector<string>& words)
    {
        int sz1 = words.size();
        vector<int> arr(26, 0);
        vector<int> vi = std::accumulate(begin(words), end(words), arr, [](vector<int>& arr, string& s){
                                return std::accumulate(begin(s), end(s), arr, [](vector<int>& arr, char& ch){
                                                            arr[ch - 'a']++;
                                                            return arr;
                                                       });
                          });
        return std::all_of(begin(vi), end(vi), [&sz1](int i){ return i % sz1 == 0; });
    }



//Runtime: 12 ms, faster than 94.23% of C++ online submissions for Redistribute Characters to Make All Strings Equal.
//Memory Usage: 11.6 MB, less than 65.28% of C++ online submissions for Redistribute Characters to Make All Strings Equal.
    bool lt1897a(vector<string>& words)
    {
        int sz1 = words.size();
        int arr[123] = {0};
//        std::accumulate()     // .. xiebulai
        for (string& s : words)
        {
            for (char& ch : s)
                arr[ch]++;
        }
        for (int i = 'a'; i <= 'z'; ++i)
        {
            if (arr[i] % sz1 != 0)
                return false;
        }
        return true;
    }

};

int main()
{
    vector<string> vs = {"abc", "aaa", "bbb"};
//    int arr[123] = {0};
    vector<int> arr(123, 0);

    // no match for xxxx
//    std::accumulate(begin(vs), end(vs), arr, [](string& s, vector<int>& arr){           // 哪个在前面？
//                        std::accumulate(begin(s), end(s), arr, [](char& ch, vector<int>& arr){
//                                            arr[ch]++;
//                                        });
//                    });

//    std::accumulate(begin(vs[0]), end(vs[1]), arr, [](vector<int>& arr, char& ch){
//                        cout<<"ok"<<endl;
//                    });

//    int a = std::accumulate(begin(vs[0]). end(vs[1]), 0, [](char& ch, int val){
//                        cout<<ch<<endl;
//                    });
//    cout<<a<<endl;

//    myvi v = {1,2,3,4,5};
//    int a = std::accumulate(begin(v), end(v), 0, [](int& i, int& s){
//                                cout<<i<<", "<<s<<endl;
//                                return 123;                 // ... 上面都没有加这个。。。
//                            });

//    std::accumulate(begin(vs[0]), end(vs[0]), 0, [&arr](int& s, char& ch){          // 前面是 和， 后面是 元素。。。
//                        cout<<ch<<", "<<s<<", "<<arr.size()<<endl;
//                        return 123;
//                    });

//    std::accumulate(begin(vs), end(vs), 0, [](int))


    myvi v2 = std::accumulate(begin(vs[0]), end(vs[0]), arr, [](vector<int>& arr, char& ch){          // 前面是 和， 后面是 元素。。。
                        cout<<ch<<", "<<", "<<arr.size()<<endl;
                        arr[0] = 222;
                        arr[1] = 432;
                        return arr;
                    });
    cout<<arr[0]<<", "<<arr[1]<<endl;           // 0.0 ....  初始值不会被修改。
    cout<<v2[0]<<", "<<v2[1]<<endl;

    myvi v3 = std::accumulate(begin(vs), end(vs), arr, [](vector<int>& arr, string& s){
                                    return std::accumulate(begin(s), end(s), arr, [](vector<int>& arr, char& ch){
                                                                arr[ch]++;
                                                                return arr;
                                                           });
                              });
    for (int i = 'a'; i <= 'c'; ++i)
    {
        cout<<v3[i]<<endl;
    }

    LT1897 lt;

    cout<<endl<<endl<<"====================="<<endl;

    vector<string> vss = {"abc","aabc","bc"};

    cout<<lt.lt1897b(vss)<<endl;

    return 0;
}
