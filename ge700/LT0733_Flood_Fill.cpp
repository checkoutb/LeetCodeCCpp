
#include "../header/myheader.h"

class LT0733
{
public:


// discuss
// bfs, dfs
// filla1中 第二个if条件取反，合并到第一个if中。


//Runtime: 20 ms, faster than 95.73% of C++ online submissions for Flood Fill.
//Memory Usage: 8 MB, less than 100.00% of C++ online submissions for Flood Fill.
    vector<vector<int>> lt0733a(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor)
            return image;
        filla1(image, sr, sc, image[sr][sc], newColor);
        return image;
    }

    void filla1(vector<vector<int>>& image, int r, int c, int orgCol, int newCol)
    {
        if (r >= image.size() || r < 0 || c >= image[0].size() || c < 0)
            return;

        if (image[r][c] == orgCol)
        {
            image[r][c] = newCol;
            filla1(image, r - 1, c, orgCol, newCol);
            filla1(image, r + 1, c, orgCol, newCol);
            filla1(image, r, c - 1, orgCol, newCol);
            filla1(image, r, c + 1, orgCol, newCol);
        }
    }


};

int main()
{

    LT0733 lt;

    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int r = 1;
    int c = 1;
    int col = 2;

    vector<vector<int>> arr = lt.lt0733a(image, r, c, col);

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout<<arr[i][j]<<", ";
        }
        cout<<endl;
    }

    return 0;
}
