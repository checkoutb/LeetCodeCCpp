
#include "../header/myheader.h"

class LT0841
{
public:


// D D
// dfs
//        int visited[n];
//        memset(visited,0,sizeof(visited));
// int *visited



// 是不是 遍历， key!=自己下标的 key 放到arr1中， 然后看arr1中是否 有0？ 不是 : {{},{2},{1}}
//Runtime: 20 ms, faster than 57.52% of C++ online submissions for Keys and Rooms.
//Memory Usage: 10.6 MB, less than 44.83% of C++ online submissions for Keys and Rooms.
    bool lt0841a(vector<vector<int>>& rooms)
    {
        int arr1[1001] = {0};
        arr1[0] = 1;
        queue<int> que2;
        for (int& i : rooms[0])
            que2.push(i);

        while (!que2.empty())
        {
            int key = que2.front();
            que2.pop();
            if (!arr1[key])
            {
                for (int& i : rooms[key])
                {
                    if (!arr1[i])
                        que2.push(i);
                }
                arr1[key] = 1;
            }
        }
        for (int i = 0; i < rooms.size(); i++)
        {
            if (!arr1[i])
            {
                return false;
            }
        }
        return true;
    }

};

int main()
{

//    vector<vector<int>> r = {{1},{2},{3},{}};
    vector<vector<int>> r = {{1,3},{3,0,1},{2},{0}};

    LT0841 lt;

    cout<<lt.lt0841a(r)<<endl;

    return 0;
}
