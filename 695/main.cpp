//
// Created by zhanghao on 2022/5/20.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int dfs(vector<vector<int>>& grid,int cur_i,int cur_j){
        if(cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 1){
            return 0;
        }
        grid[cur_i][cur_j] = 0;
        int di[4] = {0,0,1,-1};
        int dj[4] = {1,-1,0,0};
        int ans = 1;
        for(int index = 0; index != 4;++index){
            int next_i = cur_i + di[index];
            int next_j = cur_j + dj[index];
            ans += dfs(grid,next_i,next_j);
        }
        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid,vector<int> & arr) {
        int ans = 0;
        for(int i = 0; i != grid.size(); ++i){
            for(int j = 0 ; j != grid[0].size();++j){
                if(grid[i][j] == 0)
                    continue;
                else{
                    int temp = dfs(grid,i,j);
                    arr.push_back(temp);
                    ans = max(ans,temp);
                }
            }
        }
        return ans;
    }
};
int main() {
    vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    vector<int> arr;
    int ans = Solution().maxAreaOfIsland(grid,arr);
    for(auto i : arr){
        cout<<i<<endl;
    }

    cout<<arr.size()<<" " << ans<<endl;
    return 0;
}