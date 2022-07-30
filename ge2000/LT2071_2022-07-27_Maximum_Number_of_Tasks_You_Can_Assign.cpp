
#include "../header/myheader.h"

class LT2071
{
public:


    // D

    // 要求最低的x个任务， 最强壮的x个人 。  认为 这x个 必然能形成配对。
    // 如果不能，就+药，如果药不够，就 x降低。   二分搜索




    // g


    // 是吃，还是跳过？
    // index>=m 的task 是无意义的。
    // 吃，但是后续再判断。
    // ？
    // 但是如果 要求 < 吃药后 < 不吃药，  这种时候，选 吃药的话， 可能会 少的。   10 < 5+6 < 12 ,   还有一个任务 15，还有一个人13的力量。
    //      不，但是 人不可能多于 任务的。。
    int lt2071a(vector<int>& tasks, vector<int>& workers, int pills, int strength)
    {
        int sz1 = tasks.size();
        int sz2 = workers.size();

        sort(begin(tasks), end(tasks));
        sort(begin(workers), end(workers));

        priority_queue<int> priq;           // who eat pills

        int tki = 0;
        int wki = 0;

        for (int mxtki = min(sz1, sz2); tki < mxtki; ++tki)
        {

        }

    }


    // a single task。。。 想成 串行执行了。。

    // 任务有力量要求， 工人有力量属性。  工人>=任务
    // 。。。魔药。 增加 strength的力量。。 一个人最多吃一个。
    // ？没有时间要求，直接给 力量最大的 吃一个， 然后 全让他干 就可以了啊。。。
    // 力量会被消耗。
    // 先把相等的 互相消除。
    // 然后。。 不不不
    // 先把 消耗最小的活 干了。 用 力量>=要求的 最小的工人。
    // 然后继续找 要求-strength 的人。
    int lt2071a(vector<int>& tasks, vector<int>& workers, int pills, int strength)
    {
        sort(begin(tasks), end(tasks));
        sort(begin(workers), end(workers));

        int tki = 0;
        int wki = 0;
        for (; tki < tasks.size(); ++tki)
        {
            int t2 = tasks[tki];
            while (wki < workers.size() && workers[wki] < t2)
            {
                wki++;
            }
            if (wki == workers.size())
                break;

            workers[wki] -= t2;
            tasks[tki] = -1;
        }

        wki = 0;
        for (; tki < tasks.size() && pills > 0; ++tki)
        {
            if (tasks[tki] == -1)
                continue;

            int t2 = tasks[tki];
            while (wki < workers.size() && workers[wki] + strength < t2)
            {
                wki++;
            }
            if (wki == workers.size())
                break;

            pills--;
            workers[wki] -= t2;
            tasks[tki] = -1;
        }
        return tki;
    }

};

int main()
{

    LT2071 lt;

    //myvi t = { 3,2,1 };
    //myvi w = { 0,3,3 };
    //int p = 1;
    //int s = 1;


    myvi t = { 74, 41, 64, 20, 28, 52, 30, 4, 4, 63 };
    myvi w = { 38 };
    int p = 0;
    int s = 68;


    cout << lt.lt2071a(t, w, p, s) << endl;

    return 0;
}
