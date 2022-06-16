//
// Created by zhanghao on 2022/5/28.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    int dirx[4] = {-1,1,0,0};
    int diry[4] = {0,0,1,-1};
    void bfs(int i ,int j,vector<vector<int>>& mat,vector<vector<int>> & ans){
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false)) ;
        if(ans[i][j] == -1){
            ans[i][j] = 0;
            visited[i][j] = true;
            queue<pair<int,int>> q;
            q.emplace(i,j);
            while(!q.empty()){
                int qsize = q.size();   //一圈的数量（显然，这里qsize 最多为4）
                ans[i][j]++;
                while(qsize--){

                    auto cur = q.front();
                    q.pop();
                    for(int i = 0 ; i < 4;i++){
                        int x = cur.first + dirx[i];
                        int y = cur.second + diry[i];
                        if(x < 0 || x >= m || y < 0 || y >= n){ //越界了
                            continue;
                        }
                        if(mat[x][y] == 0){   //达到0了，直接返回
                            return;
                        }else if(visited[x][y] == false){
                            q.emplace(x,y);
                            visited[x][y] = true;
                        }
                    }
                }
            }
        }
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n,-1));

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n; j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                }else{
                    bfs(i,j,mat,ans);
                }
            }
        }

        return ans;
    }
};

int main(){
    vector<vector<int>> arr = {{1,1,1,1,0,1},{1,1,1,0,1,0},{0,1,0,0,1,1}};
    vector<vector<int>> ans = Solution().updateMatrix(arr);
    for(auto i : ans){
        for(auto j : i){
            cout<< j <<" ";
        }
        cout<<endl;
    }
    return 0;
}