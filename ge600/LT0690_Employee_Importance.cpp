
#include "../header/myheader.h"

class LT0690
{
public:

// D D

// queue bfs.


//Runtime: 40 ms, faster than 75.80% of C++ online submissions for Employee Importance.
//Memory Usage: 14.3 MB, less than 34.00% of C++ online submissions for Employee Importance.
    int lt0690a(vector<Employee*> employees, int id)
    {
        unordered_map<int, Employee*> map2;
        for (Employee* e : employees)
        {
            map2[e->id] = e;
        }
        return dfsa1(map2[id], map2);
    }

    int dfsa1(Employee* e, unordered_map<int, Employee*>& map2)
    {
        int ans = e->importance;
        for (int id : e->subordinates)
        {
            ans += dfsa1(map2[id], map2);
        }
        return ans;
    }
};

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/


int main()
{

    LT0690 lt;


    return 0;
}
