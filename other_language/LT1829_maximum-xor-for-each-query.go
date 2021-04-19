package main

import (
	"fmt"
	"math"
	// "sort"		//imported and not used: "sort"
)



// int val = (1 << maximumBit) - 1;
// for (int i = 0; i < n.size(); ++i)
// 	res[n.size() - i - 1] = val ^= n[i];
// return res;




// Runtime: 196 ms, faster than 100.00% of Go online submissions for Maximum XOR for Each Query.
// Memory Usage: 9.5 MB, less than 100.00% of Go online submissions for Maximum XOR for Each Query.
func getMaximumXor(nums []int, maximumBit int) []int {
    ans := []int{};
	// t2 := 1;
	// for i := 1; i < maximumBit; i++ {
	// 	t2 
	// }

	// t2 := math.Pow(2, (maximumBit + 1)) - 1;		//cannot use maximumBit + 1 (type int) as type float64 in argument to math.Pow
	// t2 := maximumBit + 1;
	t2 := maximumBit;
	t2 = int(math.Pow(float64(2), float64(t2)) - 1);			// ......hao nan...

	t4 := 0;
	for _, val := range nums {
		t4 ^= val;
		ans = append(ans, t4 ^ t2);		// 不知道有没有 加在头部的方法。。。
	}
	// sort.Reverse(sort.Ints(ans))		// meiyou reverse...

	// for l := 0, r := len(ans) - 1; l < r; l++, r-- {		// syntax error: unexpected :=, expecting {
	// 	t1 := ans[l];			// std::swap  ?
	// 	ans[l] = ans[r];
	// 	ans[r] = t1;
	// }

	l := 0
	r := len(ans) - 1;
	for l < r {
		t1 := ans[l];
		ans[l] = ans[r];
		ans[r] = t1;
		l++;
		r--;
	}

	return ans;
}

func main1829() {
	// arr := []int{0,1,1,3};
	// mx := 2;

	arr := []int{2,3,4,7}
	mx := 3

	arr2 := getMaximumXor(arr, mx);

	for _, val := range arr2 {
		fmt.Printf("%d, ", val);
	}
	fmt.Printf("\n");
}
