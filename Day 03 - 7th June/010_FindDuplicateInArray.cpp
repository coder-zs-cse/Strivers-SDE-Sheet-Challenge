#include <bits/stdc++.h>
//this approach is better visualized with linked lists
int findDuplicate(vector<int> &nums, int n){
	// Write your code here.
	int slow = nums[0];
    int fast = nums[0];
    
    // Move slow and fast pointers until they meet
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    
    // Reset slow pointer to the start and move both pointers one step at a time
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    
    return slow; // Return the duplicate element
}
