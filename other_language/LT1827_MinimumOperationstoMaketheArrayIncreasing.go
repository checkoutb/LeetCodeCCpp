package main
// package asd			// go run: cannot run non-main package ， 只能是main包。。

import "fmt"

func main2() {
//	var arr = [...]int{1,1,1};			// 这个类型是 [3]int， 不能传给 []int........?????
	// var arr []int;			// not used ...
	// arr = []int{1,1,1};
//	arr = [...]int{1,1,1};			// [3]int != []int ...

	// var arr2 = []int{1,1,1};
	// var arr2 = []int{1,5,2,4,1}		// ;;;
	var arr2 = []int{8};
 
	ans := minOperations(arr2);

	fmt.Println(ans);

}


// for _, n := range nums {			// index, value
// 	if prev >= n {
// 		prev++
// 		count += prev - n
// 	} else {
// 		prev = n
// 	}
// }


// Runtime: 20 ms, faster than 100.00% of Go online submissions for Minimum Operations to Make the Array Increasing.
// Memory Usage: 6.2 MB, less than 100.00% of Go online submissions for Minimum Operations to Make the Array Increasing.
func minOperations(nums []int) int {
    var ans int = 0;
	var t2 int = nums[0];
	for i := 1; i < len(nums); i++ {			// no ++i ...
		if nums[i] <= t2 {
			t2++;
			ans += (t2 - nums[i]);
		} else {
			t2 = nums[i]
		}
	}
	return ans;
}
