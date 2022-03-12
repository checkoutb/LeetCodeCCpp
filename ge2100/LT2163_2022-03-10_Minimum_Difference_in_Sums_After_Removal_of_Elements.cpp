
#include "../header/myheader.h"

class LT2163
{
public:


// D


//    for (int i = n; i <= 2 * n; ++i) {
//        diffs[i - n] = sum_first;
//        if (pq_l.top() > nums[i]) {
//            sum_first += nums[i] - pq_l.top();
//            pq_l.pop();
//            pq_l.push(nums[i]);
//        }
//    }



// tle...
// 第一眼以为是 2部分的 |差|最小，后来发现是最小差。。那就是 最大 - 最小啊。
// 。。。 好吧， 移除以后 位置不变的。。 所以应该前面尽可能小，后面尽可能大。
// ok，那就是 随便一个下标，这个下标是 2部分的 边界，然后 前面删除 最大的x个， 后面删除最小的y个。  这个下标应该只能在 [n,n*2] 之间。
// 并且如果 [n] > [n+1] 的话，可以跳过。 不不不，跳不了。
// 可以用 heap，，但是，看不了前n个。。  stack 可以，保存最大的 x个。可以用在前面， ok，先mono stack下，计算 后半部分， 好像不行。。 最大的x个 好像也不好用。。 先来个tle吧。
// nth_element, priority_q, partial_sort ... 会改变位置。。
// multiset ... or map
    long long lt2163a(vector<int>& nums)
    {
        int sz1 = nums.size() / 3;
        multiset<int> leftset(begin(nums), begin(nums) + sz1);
        multiset<int> rightset(begin(nums) + sz1, end(nums));
        long long suml = std::accumulate(begin(nums), begin(nums) + sz1, 0LL);
        long long sumr = std::accumulate(begin(nums) + sz1, end(nums), 0LL);
        long long ans = INT_MAX;
        #ifdef __test
        cout<<suml<<", "<<sumr<<endl;
        cout<<accumulate(begin(leftset), end(leftset), 0)<<", "<<accumulate(begin(rightset), end(rightset), 0)<<endl;
        for (int i : leftset)
        {
            cout<<i<<", ";
        }
        cout<<endl<<"-----"<<endl;
        for (int i : rightset)
            cout<<i<<", ";
        cout<<endl<<" ======== "<<endl;
        #endif // __test
        for (int i = 0; i <= sz1; i++)
        {
            int t2 = i;
            int t3 = sz1 - i;

            long long leftmxsum = 0LL;
            long long rightmnsum = 0LL;
            multiset<int>::reverse_iterator it = rbegin(leftset);
            for (int j = 0; j < t2; ++j)
            {
                leftmxsum += (*it);
                it++;
                #ifdef __test
//                cout<<leftmxsum<<", ";
                #endif // __test
            }
            #ifdef __test
//            cout<<endl<<endl;
            #endif // __test

            multiset<int>::iterator it2 = begin(rightset);
            for (int j = 0; j < t3; ++j)
            {
                rightmnsum += (*it2);
                #ifdef __test
//                cout<<rightmnsum<<", "<<(*it2)<<" - ";
                #endif // __test
                it2++;
            }
            #ifdef __test
//            cout<<endl<<" --- "<<i<<endl;
            #endif // __test

            /// 。。。。。
//            long long leftmxsum = std::accumulate(rbegin(leftset), rbegin(leftset) + (std::incrementable_traits<Iter>::difference_type) i, 0LL);
//            long long rightmnsum = std::accumulate(begin(rightset), begin(rightset) + (std::incrementable_traits<Iter>::difference_type) t3, 0LL);
////            long long leftmxsum = std::accumulate(rbegin(leftset), rend(leftset), 0LL);
////            long long rightmnsum = std::accumulate(begin(rightset), end(rightset), 0LL);
            ans = min(ans, (suml - leftmxsum) - (sumr - rightmnsum));

            leftset.insert(nums[i + sz1]);
//            rightset.erase(nums[i + sz1]);              // Removes all elements with the key equivalent to key.
            rightset.erase(rightset.find(nums[i + sz1]));
            suml += nums[i + sz1];
            sumr -= nums[i + sz1];

//            cout<<suml<<", "<<sumr<<", "<<(suml + sumr)<<", "<<nums[i + sz1]<<endl;
        }
        return ans;
    }

};

int main()
{

    LT2163 lt;

//    myvi v = {3,1,2};
//    myvi v = {7,9,5,8,1,3};


    // -254
    myvi v = {24,32,19,29,8,44,5,38,26,42,19,20,31,48,32,37,17,28,47,7,29,46,41,1,17,24,48,12,48,10,26,44,50,16,32,46,28,37,44};

    cout<<lt.lt2163a(v)<<endl;

    return 0;
}
