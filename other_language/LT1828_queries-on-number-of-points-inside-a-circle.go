package main			// 同一个文件夹下，所有go都是一个包的，所以包的名字都得一样。并且所有的go只能有一个main。这玩什么。。
// package asd

import "fmt"

// D
// result := []int{}
// result = append(result, count)
// distance := math.Sqrt(math.Pow(float64(val2[0])-px, 2) + math.Pow(float64(val2[1])-py, 2))
// px := float64(val1[0])


// We can improve our runtime if we sort points by x coordinate. That way, we only process points in [qx - r, qx + r] interval. We use binary search to find the start of that interval.
// vector<int> res;
// vector<array<int, 2>> sp;
// for (auto &p : ps)
// 	sp.push_back({p[0], p[1]});
// sort(begin(sp), end(sp));
// for (auto &q : queries) {
// 	int cnt = 0, rr = q[2] * q[2];
// 	auto it = lower_bound(begin(sp), end(sp), array<int, 2>{q[0] - q[2], 0});
// 	for (; it != end(sp) && (*it)[0] <= q[0] + q[2]; ++it)
// 		cnt += (q[0] - (*it)[0]) * (q[0] - (*it)[0]) + (q[1] - (*it)[1]) * (q[1] - (*it)[1]) <= rr;
// 	res.push_back(cnt);
// }
// return res;



// 都是样本太少，所以100%
// Runtime: 28 ms, faster than 100.00% of Go online submissions for Queries on Number of Points Inside a Circle.
// Memory Usage: 6.2 MB, less than 100.00% of Go online submissions for Queries on Number of Points Inside a Circle.
func countPoints(points [][]int, queries [][]int) []int {
	// sz3 := len(queries)
    // var ans []int; 		// 估计[len]int != []int, 那么数组元素怎么增加？add？push？这个是数组啊。不是可变的吧。..嗯，不可变的。下面直接越界了。
				// 炸裂， []int ，方括号里不能放变量，len(queries)，说 non-constant....

	var ans = make([]int, len(queries))			// ennnn, 好像还行。。。  c的 calloc ,没有映像

	for idx, arr := range queries {
		// how to conver to float ?
		cnt := 0
		for _, arr2 := range points {
			// std::sqrt? .math.sqrt..  but .
			dis := (arr[0] - arr2[0]) * (arr[0] - arr2[0]) + (arr[1] - arr2[1]) * (arr[1] - arr2[1]);
			if dis <= arr[2] * arr[2] {
				cnt++;
			}
		}
		ans[idx] = cnt;
	}
	return ans;
}

func main1828() {			// ...方法 和 另一个文件的冲突了。。但是package也换不了。。

	// var arr1 [][]int = [][]int{{1,3},{3,3},{5,3},{2,2}}
	// var arr2 [][]int = [][]int{{2,3,1},{4,3,1},{1,1,2}}

	arr1 := [][]int{{1,1},{2,2},{3,3},{4,4},{5,5}}
	arr2 := [][]int{{1,2,2},{2,2,2},{4,3,2},{4,3,3}}

	var arr []int = countPoints(arr1, arr2);

	for _, v := range arr {
		fmt.Printf("%d, ", v);
	}
}

