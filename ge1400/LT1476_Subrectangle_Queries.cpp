
#include "../header/myheader.h"

class LT1476
{
public:



};

// D D

//vector<vector<int>> rect, subs;
//SubrectangleQueries(vector<vector<int>>& rectangle) {
//    swap(rect, rectangle);
//}
//void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
//    subs.push_back({row1, col1, row2, col2, newValue});
//}
//int getValue(int row, int col) {
//    for (int i = subs.size() - 1; i >= 0; --i)
//        if (subs[i][0] <= row && subs[i][1] <= col && row <= subs[i][2] && col <= subs[i][3])
//            return subs[i][4];
//    return rect[row][col];
//}



//Runtime: 60 ms, faster than 71.53% of C++ online submissions for Subrectangle Queries.
//Memory Usage: 19.2 MB, less than 14.13% of C++ online submissions for Subrectangle Queries.
class SubrectangleQueries {
    vector<vector<int>> vv;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        this->vv = rectangle;
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int i = row1; i <= row2; ++i)
        {
            for (int j = col1; j <= col2; ++j)
            {
                vv[i][j] = newValue;
            }
        }
    }

    int getValue(int row, int col) {
        return vv[row][col];
    }
};


int main()
{

    vector<vector<int>> vv = {{1,2,1},{4,3,4},{3,2,1},{1,1,1}};
    SubrectangleQueries sq(vv);
    cout<<endl<<sq.getValue(0,2);
    sq.updateSubrectangle(0,0,3,2,5);
    cout<<endl<<sq.getValue(0,2);
    cout<<endl<<sq.getValue(3,1);
    sq.updateSubrectangle(3,0,3,2,10);
    cout<<endl<<sq.getValue(3,1);
    cout<<endl<<sq.getValue(0,2);

    LT1476 lt;

    return 0;
}
