
#include "../header/myheader.h"

class LT0621
{
public:

// D D

//        Queue<Integer> queue = new PriorityQueue<>((i1, i2) -> i2 - i1);
//        for (char c : taskToCount.keySet()) queue.offer(taskToCount.get(c));
//
//        Map<Integer, Integer> coolDown = new HashMap<>();
//        int currTime = 0;
//        while (!queue.isEmpty() || !coolDown.isEmpty()) {
//            if (coolDown.containsKey(currTime - n - 1)) {
//                queue.offer(coolDown.remove(currTime - n - 1));
//            }
//            if (!queue.isEmpty()) {
//                int left = queue.poll() - 1;
//        	if (left != 0) coolDown.put(currTime, left);
//            }
//            currTime++;
//        }



//        int[] counter = new int[26];
//        int max = 0;
//        int maxCount = 0;
//        for(char task : tasks) {
//            counter[task - 'A']++;
//            if(max == counter[task - 'A']) {
//                maxCount++;
//            }
//            else if(max < counter[task - 'A']) {
//                max = counter[task - 'A'];
//                maxCount = 1;
//            }
//        }
//
//        int partCount = max - 1;
//        int partLength = n - (maxCount - 1);
//        int emptySlots = partCount * partLength;
//        int availableTasks = tasks.length - max * maxCount;
//        int idles = Math.max(0, emptySlots - availableTasks);
//
//        return tasks.length + idles;
//https://leetcode.com/problems/task-scheduler/discuss/104500/Java-O(n)-time-O(1)-space-1-pass-no-sorting-solution-with-detailed-explanation
// 。。。这个写了好多，但是是英文。。。
// max 是最多次数， maxCount是多少个char 是最多次数。
// partCount, 多少段，(最多次数是点，点-1就是线段)，或者就是 宽/长
// partLength, 每段有多少个 空格， 就是，maxCount个是必然直接占用掉的，剩下的空格填充 非maxCount的 task。
//  段 就是指 n。
// 空格就是 每段中的空闲(partLength) * 多少段(partCount)
// 剩下的task 就是 avalableTasks。
//
// 好像没有办法证明这种，就是有多出来的(idles < 0 (emptySlots < availableTasks)的那种)，也满足 间隔n.,应该可以，就是 反写。


//        unordered_map<char,int>mp;
//        int count = 0;
//        for(auto e : tasks)
//        {
//            mp[e]++;
//            count = max(count, mp[e]);
//        }
//
//        int ans = (count-1)*(n+1);
//        for(auto e : mp) if(e.second == count) ans++;
//        return max((int)tasks.size(), ans);


//// (c[25] - 1) * (n + 1) + 25 - i  is frame size
//// when inserting chars, the frame might be "burst", then tasks.length takes precedence
//// when 25 - i > n, the frame is already full at construction, the following is still valid.
//public class Solution {
//    public int leastInterval(char[] tasks, int n) {
//
//        int[] c = new int[26];
//        for(char t : tasks){
//            c[t - 'A']++;
//        }
//        Arrays.sort(c);
//        int i = 25;
//        while(i >= 0 && c[i] == c[25]) i--;
//
//        return Math.max(tasks.length, (c[25] - 1) * (n + 1) + 25 - i);
//    }
//}
// (c25 - 1) 就是 多少段， (n+1)就是 2次task的长度(段的长度)，  25-i就是 maxCount的 作用 (多个max时，会出头)。




//Runtime: 316 ms, faster than 17.03% of C++ online submissions for Task Scheduler.
//Memory Usage: 43.7 MB, less than 20.16% of C++ online submissions for Task Scheduler.
// 或者 map 保存上一次出现
    int lt0621b(vector<char>& tasks, int n)
    {
        priority_queue<int, vector<int>, std::less<int>> que1;
        queue<int> que2;
        int sz0 = 0;
        int ans = 0;
        int arr['a'] = {0};
        for (char& ch : tasks)
            arr[ch]++;
        for (int i = 'A'; i <= 'Z'; ++i)
            if (arr[i] != 0)
                que1.push(arr[i]);
        while (true)
        {
            #ifdef __test
//            cout<<que1.size()<<", "<<sz0<<", "<<que2.size()<<endl;
//            getchar();
            #endif // __test
            int t2 = -1;
            if (!que1.empty())
            {
                t2 = que1.top();
                que1.pop();
                t2--;
            }
            que2.push(t2);
            if (t2 <= 0)
                sz0++;
            if (que1.empty() && sz0 == que2.size())
                break;
            if (que2.size() > n)
            {
                int t1 = que2.front();
                que2.pop();
                if (t1 > 0)
                    que1.push(t1);
                else
                    sz0--;
            }
            ans++;
        }
        return ans + 1;
    }

// error
// priority_queue, + 冷却队列。
    int lt0621a(vector<char>& tasks, int n)
    {
        priority_queue<pair<int, char>> que1;
        queue<pair<int, char>> que2;
        pair<int, char> nil = {-1, 'a'};
        int szNil = 0;
        int arr['Z'] = {0};
        for (char& ch : tasks)
        {
            arr[ch]++;
        }
        for (int i = 'A'; i <= 'Z'; ++i)
        {
            if (arr[i] != 0)
            {
                que1.push({arr[i], (char) i});
            }
        }
        int ans = 0;
        while (!que1.empty() || szNil != que2.size())
        {
            #ifdef __test
            cout<<que1.size()<<", "<<szNil<<", "<<que2.size()<<endl;
//            getchar();
            #endif // __test
//            bool put22 = false;
            if (!que1.empty())
            {
                pair<int, char> p = que1.top();
                que1.pop();
                p.first--;
                if (p.first > 0)
                {
                    que2.push(p);
//                    put22 = true;
                }
                else
                {
                    que2.push(nil);
                    szNil++;
                }
            }
            else
            {
                que2.push(nil);
                szNil++;
            }
//            if (!put22)
//            {
//                que2.push(nil);
//            }
            if (que2.size() >= n)
            {
                pair<int, char> p = que2.front();
                que2.pop();
                if (p.first > 0)
                    que1.push(p);
                else
                    szNil--;
            }
//            else
//            {
//                if (que1.empty())
//                {
//
//                }
//            }
            ans++;
            if (szNil == que2.size())
                break;
        }
        return ans;
    }

};

int main()
{
    vector<char> vc = {'A','A','A','B','B','B'};
    int n = 2;
//    int n{0};

//    vector<char> vc = {'A','A','A','A','A','A','B','C','D','E','F','G'};
//    int n{2};

    LT0621 lt;

    cout<<lt.lt0621b(vc, n);

    return 0;
}
