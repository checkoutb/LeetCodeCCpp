
#include "../header/myheader.h"

class LT1861
{
public:

// D D

//    for (int i = 0; i < m; ++i)
//        for (int j = n - 1, k = n - 1; j >= 0; --j)
//            if (box[i][j] != '.') {
//                k = box[i][j] == '*' ? j : k;
//                res[k--][m - i - 1] = box[i][j];
//            }




//Runtime: 220 ms, faster than 100.00% of C++ online submissions for Rotating the Box.
//Memory Usage: 52.6 MB, less than 28.57% of C++ online submissions for Rotating the Box.
//    A stone '#'
//    A stationary obstacle '*'
//    Empty '.'
// 顺时针90
    vector<vector<char>> lt1861a(vector<vector<char>>& box)
    {
        int sz1 = box.size();
        int sz2 = box[0].size();

        vector<vector<char>> vvc(sz2, vector<char>(sz1, '.'));

        for (int i = 0; i < sz1; ++i)
        {
            int st = sz2 - 1;
            for (int j = sz2 - 1; j >= 0; --j)
            {
                if (box[i][j] == '*')
                {
                    st = j - 1;
                    vvc[j][sz1 - 1 - i] = '*';
                }
                else if (box[i][j] == '#')
                {
                    vvc[st][sz1 - 1 - i] = '#';
                    st--;
                }
            }
        }

        return vvc;
    }

};

int main()
{
//    vector<vector<char>> box = {{'#','.','#'}};

//    vector<vector<char>> box = {{'#','.','*','.'},{'#','#','*','.'}};

    vector<vector<char>> box = {{'#','#','*','.','*','.'},{'#','#','#','*','.','.'},{'#','#','#','.','#','.'}};

    LT1861 lt;

    vector<vector<char>> vvc = lt.lt1861a(box);

    for (vector<char>& vc : vvc)
    {
        for (char& ch : vc)
        {
            cout<<ch<<", ";
        }
        cout<<endl;
    }

    return 0;
}
