
#include "../header/myheader.h"

class LT2029
{
public:



// g


// hint 2. 可以全部 % 3 。
// 第一步alice 不可能取 0。 所以1/2
// 后续的，应该是先取完0，不，但是不取完0，对面始终能活着。
// 关联的topic，是greedy。感觉 先取0 是可以的。。
// 当已移除1， 还剩0，1，2 各 数个的时候， 肯定不能选2， 0还是1
// 只要0的个数超过1半，bob必胜。 他只需要取0 就可以了。 不不不，alice 也会取0。来让bob 选择1/2，不然alice不取0，alice必输。
// 2 2 2 0 0 0 0 0 这种应该是alice 2， bob2， a0 b0 a0 b0 a0 b2   bob输。 a2 b0 a2 b0 a0 b0 a0 b2
// 总数能被3整除，谁拿最后一个数谁输。
// 不能被3整除，就看 alice 能不能拿到一个数，导致 剩余的数能被3整除，且 最后一个数是 bob拿，那么bob 必输。
// 1 2 2 0 0 0 0 0  a2 b2 a0 b0 a0 b0 a0 b1 不能被3整除，所以 bob win。    所以上面不对。 a1 b0 a0 b0 a0 b0 a2shu
// 取完，alice输，所以alice需要让 bob拿石头，并且 bob拿了以后，%3==0。 alice开始，所以她不能选0。。。所以当0大于3/4的时候 bob必胜，他只要一直取0就可以了。
// 并且 alice要让bob拿， 所以只能还剩一种 石头的时候 让bob 拿，并且拿了以后 %3==0 才赢。  所以 bob 需要尽量让剩余的1/2 的个数 够平均。

// 不管怎么说 alice 肯定第一个非0，后续的 先拿0，不然bob始终能靠0来躲过一劫。
// 而bob，不拿0，因为0可以救命。所以 他就只有1/2 可以拿，并且要%3!=0，只有一种可能。当然0是永远都可以的。
// 没有0以后，那就是 %3!=0 硬算，谁算不到谁输，或者取完后alice输。
// 还有个问题，alice先1还是先2。。。当然可以2种都算下。毕竟alice决定的。 应该得都算下，1，2，2，2 这种，alice取1， bob就输。 11112 这种 alice取2，bob输。
    bool lt2029a(vector<int>& stones)
    {
        bool awin = false;          // remove all，alice lose
        int arr[3] = {0};
        int arr2[3] = {0};
        int sz1 = stones.size();
        for (int& n : stones)
            arr[n % 3]++;
        for (int i = 0; i < 3; i++)
            arr2[i] = arr[i];

        // alice 1
        int mv = 1;
        bool nowA = false;
        if (arr[mv] > 0)
        {
            arr[mv]--;
            for (int i = 1; i < sz1; i++)
            {
                if (nowA)
                {
                    if (arr[0] > 0)           // 2者正好反过来，一个优先0，一个优先1/2
                    {
                        arr[0]--;
                    }
                    else
                    {
                        if (arr[mv] > 0)
                        {
                            arr[mv]--;
                            mv = (mv + mv) % 3;
                        }
                        else
                        {
                            awin = false;
                            break;
                        }
                    }
                }
                else
                {
                    if (arr[mv] > 0)
                    {
                        arr[mv]--;
                        mv = 3 - mv;
                    }
                    else
                    {
                        if (arr[0] > 0)
                        {
                            arr[0]--;
                        }
                        else
                        {
                            awin = true;
                            break;
                        }
                    }
                }
                nowA = !nowA;
            }
            if (awin)
                return true;
        }

        // alice 2
        mv = 2;
        if (arr2[mv] > 0)
        {
            arr2[mv]--;
            nowA = false;
            for (int i = 1; i < sz1; i++)
            {
                if (nowA)
                {
                    if (arr[0] > 0)
                        arr[0]--;
                    else
                    {
                        if (arr[mv] > 0)
                        {
                            arr[mv]--;
                            mv = 3 - mv;
                        }
                        else
                        {
                            awin = false;
                            break;
                        }
                    }
                }
                else
                {
                    if (arr[mv] > 0)
                    {
                        arr[mv]--;
                        mv = 3 - mv;
                    }
                    else
                    {
                        if (arr[0] > 0)
                        {
                            arr[0]--;
                        }
                        else
                        {
                            awin = true;
                            break;
                        }
                    }
                }
                nowA = !nowA;
            }
        }

        return awin;
//        return false;       // awin is false
    }

};

int main()
{

    LT2029 lt;

    myvi v = {20,3,20,17,2,12,15,17,4};     // true
    // 2 0 2 2 2 0 0 2 1
    // 1 0 0 0 alose
    // 2 2 1 0
    //                      2 2 1 2 0 0 0 2
    //                      2 2 0 1

    cout<<lt.lt2029a(v)<<endl;


    return 0;
}
