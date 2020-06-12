
#include "../header/myheader.h"

class ExamRoom {



// gg...

//priority_queue<pair<int, int>>           pair<distance, seat> 。。 但是删除就。。。

    vector<tuple<int, int, int>> vp2;

    int n;

public:
    ExamRoom(int N) {
        n = N;
        vp2.push_back(std::make_tuple(N, -1, -1));
    }

    int seat() {
        if (vp2.size() == 1)
        {
            if (std::get<1>(vp2[0]) == -1)
            {
                vp2[0]
            }
            if (std::get<2>(vp2[0]) == -1)
            {

            }
        }
    }

    void leave(int p) {

    }
};

class LT0855
{
public:



};

int main()
{

    LT0855 lt;


    return 0;
}
