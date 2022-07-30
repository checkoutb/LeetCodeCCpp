
#include "../header/myheader.h"

class LT2069
{
public:



};

// D D


//int st = 0, w = 0, h = 0, moved = false;
//Robot(int width, int height) : w(width - 1), h(height - 1) {}
//void move(int num) {
//    moved = true;
//    st = (st + num) % (2 * h + 2 * w);
//}
//vector<int> getPos() {
//    return { st < w ? st : st < w + h ? w : st < 2 * w + h ? 2 * w + h - st : 0,
//           st < w ? 0 : st < w + h ? st - w : st < 2 * w + h ? h : 2 * w + 2 * h - st };
//}
//string getDir() {
//    return (moved && (st > 2 * w + h || st == 0)) ? "South" : st <= w ? "East" : st <= w + h ? "North" : "West";
//}








//Runtime: 257 ms, faster than 85.41 % of C++ online submissions for Walking Robot Simulation II.
//Memory Usage : 120.5 MB, less than 35.14 % of C++ online submissions for Walking Robot Simulation II.
class Robot {
    string dirs[4] = {"East", "North", "West", "South"};
    int wd, hg, nowx, nowy, nowdir;
public:
    Robot(int width, int height) {
        this->wd = width;
        this->hg = height;      // [0,hg)
        this->nowx = 0;
        this->nowy = 0;
        this->nowdir = 0;
    }

    void step(int num) {
        num %= ((wd + hg - 2) << 1);

        if (num == 0)
        {
            if (nowx == 0 && nowy == 0)
                nowdir = 3;
            else if (nowx == (wd - 1) && nowy == 0)
                nowdir = 0;
            else if (nowx == (wd - 1) && nowy == (hg - 1))
                nowdir = 1;
            else if (nowx == 0 && nowy == (hg - 1))
                nowdir = 2;
        }

#ifdef __test
        cout << num << " - " << nowx << ", " << nowy << endl;
#endif

        int t2 = 0;
        while (num > 0)
        {
            switch (nowdir)
            {
            case 0:
                t2 = this->wd - this->nowx - 1;
                if (t2 >= num)
                {
                    this->nowx += num;
                    num = 0;
                }
                else
                {
                    num -= t2;
                    nowdir = 1;
                    nowx = wd - 1;
                }
                break;
            case 1:
                t2 = this->hg - nowy - 1;
                if (t2 >= num)
                {
                    this->nowy += num;
                    num = 0;
                }
                else
                {
                    num -= t2;
                    nowdir = 2;
                    nowy = hg - 1;
                }
                break;
            case 2:
                t2 = nowx;
                if (t2 >= num)
                {
                    this->nowx -= num;
                    num = 0;
                }
                else
                {
                    num -= t2;
                    nowdir = 3;
                    nowx = 0;
                }
                break;
            case 3:
                t2 = nowy;
                if (t2 >= num)
                {
                    this->nowy -= num;
                    num = 0;
                }
                else
                {
                    num -= t2;
                    nowdir = 0;
                    nowy = 0;
                }
                break;
            }
        }
#ifdef __test
        cout << "after move " << nowdir << ", " << nowx << ", " << nowy << endl;
#endif
    }

    vector<int> getPos() {
        return { nowx, nowy };
    }

    string getDir() {
        return this->dirs[nowdir];
    }
};


int main()
{

    LT2069 lt;

    //Robot robot(6, 3);
    //robot.step(2);  // It moves two steps East to (2, 0), and faces East.
    //robot.step(2);  // It moves two steps East to (4, 0), and faces East.
    //myvi v = robot.getPos(); // return [4, 0]
    //cout << endl << v[0] << " - " << v[1];
    //cout << endl << robot.getDir(); // return "East"
    //robot.step(2);  // It moves one step East to (5, 0), and faces East.
    //                // Moving the next step East would be out of bounds, so it turns and faces North.
    //                // Then, it moves one step North to (5, 1), and faces North.
    //robot.step(1);  // It moves one step North to (5, 2), and faces North (not West).
    //robot.step(4);  // Moving the next step North would be out of bounds, so it turns and faces West.
    //                // Then, it moves four steps West to (1, 2), and faces West.
    //v = robot.getPos(); // return [1, 2]
    //cout << endl << v[0] << " - " << v[1];
    //cout << endl << robot.getDir(); // return "West"

    //["Robot", "step", "getPos", "getDir", "step", "getPos", "getDir", "step", "step", "getPos", "getDir",
    //[[8, 11], [18], [], [], [24], [], [], [44], [36], [], [],
    Robot robot(8, 11);
    robot.step(18);
    //robot.getPos();
    robot.step(24);
    robot.step(44);
    robot.step(36);
    myvi v = robot.getPos();
    cout << "pos            " << v[0] << " - " << v[1] << endl;         // 4,10
    cout << "dir   " << robot.getDir() << endl;         // west


    return 0;
}
