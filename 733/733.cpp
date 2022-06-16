//
// Created by zhanghao on 2022/5/23.
//
#include <iostream>
#include <vector>
using namespace  std;

class Solution {
private:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    void dfs(vector<vector<int>> & grid,int curx,int cury,int oldColor,int newColor){
        int m = grid.size();
        int n = grid[0].size();
        if(curx < 0 || curx >= m || cury < 0 || cury >= n || grid[curx][cury] != oldColor){
            return;
        }
        grid[curx][cury] = newColor;
        for(int i = 0 ; i < 4; i++){
            int x = curx + dx[i];
            int y = cury + dy[i];
            dfs(grid,x,y,oldColor,newColor);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        cout<<"123"<<endl;
        int oldColor = image[sr][sc];
        if(oldColor == newColor)
            return image;
        dfs(image, sr,sc,oldColor,newColor);
        return image;
    }
};

int main(){
    vector<vector<int>> image = {{0,0,0},{0,0,0}};
    vector<vector<int>>ans = Solution().floodFill(image,0,0,2);
    for(auto & i : ans){
        for(auto & j : i){
            cout<< j <<" ";
        }
        cout<<endl;
    }
    return 0;
}