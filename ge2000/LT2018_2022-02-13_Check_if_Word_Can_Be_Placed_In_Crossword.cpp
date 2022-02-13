
#include "../header/myheader.h"

class LT2018
{
public:

// D D


//string(rbegin(word), rend(word))


//bool check(vector<vector<char>>& board, string word) {
//    int m = board.size(), n = board[0].size();
//    vector<vector<int>> h(m, vector<int>(n, -1));
//    for (int i = 0; i < m; ++i)
//        for (int j = 0; j < n; ++j)
//            if (j == 0 || board[i][j - 1] == '#' || (j > 0 && h[i][j - 1] != -1)) {
//                int pos = j == 0 ? 0 : h[i][j - 1] + 1;
//                if (board[i][j] == ' ' || board[i][j] == word[pos]) {
//                    if (pos == word.size() - 1) {
//                        if (j == n - 1 || board[i][j + 1] == '#')
//                            return true;
//                    }
//                    else
//                       h[i][j] = pos;
//                }
//            }
//    return false;
//}
// dp



//Runtime: 196 ms, faster than 91.27% of C++ online submissions for Check if Word Can Be Placed In Crossword.
//Memory Usage: 59.7 MB, less than 60.54% of C++ online submissions for Check if Word Can Be Placed In Crossword.
// 外面再刷一圈#， 就变成了 水平或垂直的 2个 # 间的 单词 要匹配 word。 RE？
// 遍历，对每段进行匹配。。。
    bool lt2018a(vector<vector<char>>& board, string word)
    {
        int sz1 = board.size();
        int sz2 = board[0].size();
        int idx = 0;
        bool skip = false;
        string wd2 = word;
        reverse(begin(wd2), end(wd2));
        bool b1, b2;

        for (int j = 0; j < sz2; j++)
        {
            for (int i = 0; i < sz1; i++)
            {
                if (board[i][j] != '#' && (i == 0 || board[i - 1][j] == '#'))
                {
                    idx = 0;
                    b1 = b2 = true;
                    for (; i < sz1; i++)
                    {
                        if (board[i][j] == '#')
                            break;
                        if (board[i][j] != ' ')
                        {
//                            if (b1)
//                                if (board[i][j] != word[idx])
//                                    b1 = false
                            if (b1 && (board[i][j] != word[idx]))
                                b1 = false;
                            if (b2 && (board[i][j] != wd2[idx]))
                                b2 = false;
                        }
                        if (!b1 && !b2)
                            break;
                        if (++idx == word.size())
                            break;
                    }
                    if (idx == word.size() && ((i + 1) == sz1 || board[i + 1][j] == '#'))
                        return true;
                }
            }
        }

        for (int i = 0; i < sz1; i++)
        {
            for (int j = 0; j < sz2; j++)
            {
//            cout<<j<<endl;
                if (board[i][j] != '#' && (j == 0 || board[i][j - 1] == '#'))
                {
//                    cout<<i<<", "<<j<<endl;
                    idx = 0;
                    b1 = b2 = true;
                    for (; j < sz2; j++)
                    {
                        if (board[i][j] == '#')
                        {
                            break;
                        }
                        if (board[i][j] != ' ')
                        {
                            if (b1)
                            {
                                if (board[i][j] != word[idx])
                                {
                                    b1 = false;
                                }
                            }
                            if (b2)
                            {
                                if (board[i][j] != wd2[idx])
                                    b2 = false;
                            }
                        }
                        if (!b1 && !b2)
                            break;
                        idx++;
                        if (idx == word.size())
                            break;

//                        if ((j + 1) == sz2 || board[i][])
                    }
//                    cout<<idx<<", "<<j<<endl;
                    if (idx == word.size() && ((j + 1) == sz2 || board[i][j + 1] == '#'))
                    {
                        return true;
                    }
//                    for (int k = j; k < sz2; k++)
//                    {
//
//                    }
                }
//                cout<<" ? "<<j<<endl;
            }
        }

//        // mei hang
//        for (int i = 0; i < sz1; i++)
//        {
//            for (int j = 0; j < sz1; j++)
//            {
//                if (board[i][j] != '#')
//                {
//                    if (skip)
//                        continue;
//
//                    if (board[i][j] == word[idx])
//                    {
//
//                    }
//                }
//                else
//                {
//                    idx = 0;
//                    skip = false;
//                }
//            }
//        }
        return false;
    }

};

int main()
{

//    string s1 = "1234";
//    string s2 = s1;
//    cout<<&s1<<", "<<&s2<<endl;
////    string s3 =
//    reverse(begin(s1), end(s1));
//    cout<<s1<<", "<<s2<<endl;

    LT2018 lt;

//    vector<vector<char>> vvc = {{'#',' ','#'},{' ',' ','#'},{'#','c',' '}};
////    vector<vector<char>> vvc = {{' ',' ','c'}};
//    string w = "abc";

//    vector<vector<char>> vvc = {{' ','#','a'},{'#',' ','c'},{' ','#','a'}};
//    string w = "ac";

    vector<vector<char>> vvc = {{'a',' ','#',' ',' ','c'}};
    string w = "abc";

    cout<<lt.lt2018a(vvc, w)<<endl;

    return 0;
}
