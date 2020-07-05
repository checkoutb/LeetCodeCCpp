
#include "../header/myheader.h"

class LT0946
{
public:


// D D
//        int i = 0, j = 0;
//        for (int x : pushed) {
//            pushed[i++] = x;
//            while (i > 0 && pushed[i - 1] == popped[j])
//                --i, ++j;
//        }
//        return i == 0;

//        Deque<Integer> stack = new ArrayDeque<>();
//        int index = 0;
//        for(int p : pushed){
//            stack.push(p);
//            while (!stack.isEmpty() && stack.peek() == popped[index]){
//                stack.pop();
//                index++;
//            }
//        }
//        return stack.isEmpty();

// xian push, zai pop, 就不需要额外的一个while了。


//Runtime: 24 ms, faster than 21.81% of C++ online submissions for Validate Stack Sequences.
//Memory Usage: 15.5 MB, less than 27.70% of C++ online submissions for Validate Stack Sequences.
    bool lt0946a(vector<int>& pushed, vector<int>& popped)
    {
        stack<int> stk1;
        int popi = 0;
        int pushi = 0;
        while (pushi < pushed.size())
        {
            if (stk1.size() > 0)
            {
                while (stk1.size() > 0)
                {
                    int top2 = stk1.top();
                    if (top2 == popped[popi])
                    {
                        stk1.pop();
                        popi++;
                    }
                    else
                    {
                        break;
                    }
                }
//                int top2 = stk1.top();
//                if (top2 == popped[popi])
//                {
//                    stk1.pop();
//                    popi++;
//                }
            }
            stk1.push(pushed[pushi]);
            pushi++;
        }

        #ifdef __test
        show_stack_int(stk1);
        #endif // __test

        while (stk1.size() > 0)
        {
            int top2 = stk1.top();
            stk1.pop();

            #ifdef __test
            cout<<top2<<" ==? "<<popped[popi]<<endl;
            #endif // __test

            if (top2 != popped[popi])
            {
                return false;
            }
            popi++;
        }
        return true;
    }

};

int main()
{

//    vector<int> psh = {1,2,3,4,5};
//    vector<int> pp = {4,5,3,2,1};

    vector<int> psh = {2,1,0};
    vector<int> pp = {1,2,0};


    LT0946 lt;

    cout<<lt.lt0946a(psh, pp)<<endl;

    return 0;
}
