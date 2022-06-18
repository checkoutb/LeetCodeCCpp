
#include "../header/myheader.h"

class LT1105
{
public:

    // D D







//Runtime: 7 ms, faster than 75.94 % of C++ online submissions for Filling Bookcase Shelves.
//Memory Usage : 8.2 MB, less than 79.14 % of C++ online submissions for Filling Bookcase Shelves.
    int lt1105a(vector<vector<int>>& books, int shelfWidth)
    {
        vector<int> vi(books.size());           // [0, idx] books' min height
        vi[0] = books[0][1];
        for (int i = 1; i < books.size(); ++i)
        {
            int upMin = vi[i - 1];
            int nowMax = books[i][1];
            int thick = books[i][0];
            int t2 = upMin + nowMax;
            for (int j = i - 1; j >= 0; --j)
            {
                if (thick + books[j][0] <= shelfWidth)
                {
                    thick += books[j][0];
                    nowMax = max(nowMax, books[j][1]);
                    upMin = j > 0 ? vi[j - 1] : 0;
                    t2 = min(t2, upMin + nowMax);
                }
                else
                {
                    break;
                }
            }
            vi[i] = t2;
        }

        return vi[vi.size() - 1];
    }

};

int main()
{

    LT1105 lt;

    //myvvi vv = { {1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2} };
    //int w = 4;

    myvvi vv = { {1,3},{2,4},{3,2} };
    int w = 6;

    cout << lt.lt1105a(vv, w) << endl;

    return 0;
}
