//
// Created by zhanghao on 2022/6/5.
//

#include <iostream>
#include <vector>
using  namespace std;

int search(vector<int>& nums, int target) {
    //二分查找左边界
    int left = 0,right = nums.size()-1;
    int mid = 0;
    while(left <= right){
        mid = left + (right - left)/2;
        if(nums[mid] >= target){
            right = mid - 1;
        }else{ //nums[mid] < target
            left = mid+1;
        }
    }
    if(left == nums.size()) return -1;
    return nums[left] == target ? left : -1;
}

int main(){
    vector<int> arr = {1,2,2,2,2,2,2,4,4,4,4,4};
    int ans = search(arr,4);
    cout<<ans<<endl;
    return 0;
}