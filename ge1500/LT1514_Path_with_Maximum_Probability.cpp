
#include "../header/myheader.h"

class LT1514
{
public:

// D D

// vector<vector<pair<int, double>>>

//Bellman Ford


//	PriorityQueue<State> pq = new PriorityQueue<>((a, b) -> (((Double) b.prob).compareTo((Double) a.prob)));
//	pq.add(new State(start, 1.0));
//	while (!pq.isEmpty()) {
//		State state = pq.poll();
//		int parent = state.node;
//		double prob = state.prob;
//		if (parent == end) return prob;
//		for (double[] child : map.getOrDefault(parent, new ArrayList<>())) {
//			// add to pq only if: it can make a better prob
//			if (probs[(int) child[0]] >= prob * child[1]) continue;
//			pq.add(new State((int) child[0], prob * child[1]));
//			probs[(int) child[0]] = prob * child[1];
//		}
//
//	}





//Runtime: 524 ms, faster than 18.34% of C++ online submissions for Path with Maximum Probability.
//Memory Usage: 69.9 MB, less than 39.40% of C++ online submissions for Path with Maximum Probability.
    double lt1514a(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        double ans = 0.0;
        vector<double> rate(n);
        rate[start] = 1.0;
        unordered_map<int, vector<pair<int, double>>> map2;
        for (int i = 0; i < edges.size(); ++i)
        {
            vector<int>& vi = edges[i];
            double r = succProb[i];
            map2[vi[0]].push_back({vi[1], r});
            map2[vi[1]].push_back({vi[0], r});
        }

        queue<int> que1;
        que1.push(start);

        while (!que1.empty())
        {
            int fnt = que1.front();
            que1.pop();
            double r = rate[fnt];
            for (pair<int, double> p : map2[fnt])
            {
                int idx = p.first;
                double r2 = r * p.second;
                if (r2 > rate[idx])
                {
                    rate[idx] = r2;
                    que1.push(idx);
                }
            }
        }
        ans = rate[end];
        return ans;
    }

};

int main()
{

//    myvvi vv = {{0,1},{1,2},{0,2}};
//    vector<double> vd = {0.5, 0.5, 0.3};
    myvvi vv = {{1,0}};
    vector<double> vd = {0.5};
    int st{0}, en{2}, n{3};


    LT1514 lt;

    cout<<lt.lt1514a(n, vv, vd, st, en);

    return 0;
}
