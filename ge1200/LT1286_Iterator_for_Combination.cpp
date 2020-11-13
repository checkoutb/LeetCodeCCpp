
#include "../header/myheader.h"

class LT1286
{
public:



};


// D D

//set<string>GenaretallComb(string s,int len){
//    int mask = 1<<s.length();
//    set<string>hold;
//    string comString = "";
//    for(int no=1;no<mask;no++){
//        int num = no,i = 0;
//        while(num){
//            if(num&1)comString = comString + s[i];
//            i++,num>>=1;
//        }
//        if(comString.length()==len)hold.insert(comString);
//        comString = "";
//    }
//    return hold;
//}
// 构造器 生成全部。。。


//    void traverse(string& s, string path, int start, int len, int total){
//        if(path.size()==len){v.push_back(path); return;}
//        for(int j=start;j<total; j++){
//            traverse(s, path+s[j], j+1, len, total);
//        }
//    }
// 生成全部。


//    Stack<Character> st; // stack to store the characters leading to the creation of a single combination
//	Map<Character, Integer> ch2Idx; // map to store character to index
//    String result, str; // str - same as characters. result -- the result string representing a combination
//    int combLength; // same as combinationLength
// 方法 太长了。




//Runtime: 8 ms, faster than 99.64% of C++ online submissions for Iterator for Combination.
//Memory Usage: 12.6 MB, less than 69.98% of C++ online submissions for Iterator for Combination.
class CombinationIterator {
    vector<int> vi;
    int len;
    string chs;
    string last;
    bool finish;
public:
    CombinationIterator(string characters, int combinationLength) {
        this->len = characters.size();
        this->finish = false;
        this->chs = characters;
        this->vi = vector<int>(combinationLength, 0);
        for (int i = 0; i < vi.size(); ++i)
            vi[i] = i;
        this->last = chs.substr(len - vi.size());
        #ifdef __test
        cout<<"this last : "<<this->last<<endl;
        #endif // __test
    }

    string next() {
        string ans;
        for (int i : vi)
            ans += chs[i];
        if (ans == this->last)
        {
            finish = true;
        }
        else
        {
            for (int i = vi.size() - 1; i >= 0; --i)
            {
                int t1 = vi[i] + 1;
                if (t1 < len - (vi.size() - 1 - i))
                {
                    vi[i] = t1;
                    for (int j = i + 1; j < vi.size(); ++j)
                    {
                        vi[j] = ++t1;
                    }
                    break;
                }
            }
        }
        return ans;
    }

    bool hasNext() {
        return !finish;
    }
};




// error
// wori, lexicographical order.

// 1 5 4 3 2
// 2 1 3 4 5

// 1 7 6 5 4
// 2 1 3 4 5
// 进位后，后续从小到大。

class CombinationIteratora1 {

    vector<int> vi;
    int len;
    string chs;
    string last;
    bool finish;

public:
    CombinationIteratora1(string characters, int combinationLength) {
        this->len = characters.size();
        this->finish = false;
        this->chs = characters;
        this->vi = vector<int>(combinationLength, 0);
        for (int i = 0; i < vi.size(); ++i)
        {
            vi[i] = i;
            this->last += chs[len - 1 - i];
        }
    }

    string next() {
        string ans;
        for (int i : vi)
            ans += chs[i];

        if (ans == this->last)
            finish = true;
        else
        {
            unordered_set<int> set2(begin(vi), end(vi));
            for (int i = vi.size() - 1; i >= 0; --i)
            {
                int t1 = vi[i] + 1;
                while (t1 < len)
                {
                    if (set2.find(t1) == set2.end())
                    {
                        vi[i] = t1;
                        set2.insert(t1);
                        for (int j = i + 1; j < vi.size(); ++j)
                        {
                            for (int k = 0; k < len; k++)
                            {
                                if (set2.find(k) == set2.end())
                                {
                                    set2.insert(k);
                                    vi[j] = k;
                                    break;
                                }
                            }
                        }
                        goto AAA;
                    }
                    t1++;
                }
                set2.erase(vi[i]);
            }
        }
        AAA:
        return ans;
    }

    bool hasNext() {
        return !finish;
    }
};


int main()
{

    LT1286 lt;

    CombinationIterator ci("abc", 2);
    cout<<ci.next()<<endl;
    cout<<ci.hasNext()<<endl;
    cout<<ci.next()<<endl;
    cout<<ci.hasNext()<<endl;
    cout<<ci.next()<<endl;
    cout<<ci.hasNext()<<endl;


    return 0;
}
