//
// Created by zhanghao on 2022/5/22.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool dfs(vector<vector<int>> & grid1 ,vector<vector<int>> & grid2,int m,int n,int x,int y){
        if(x < 0 || x >= m || y < 0 || y >= n || grid2[x][y] == 0){
            return false;
        }
        if()
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int ans = 0;
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n; j++){
                ans += dfs(grid1,m,n);
            }
        }
    }
};
template<class _Ty,
        _Ty _Val>
struct integral_constant
{   // convenient template for integral constant types
    static constexpr _Ty value = _Val;

    typedef _Ty value_type;
    typedef integral_constant<_Ty, _Val> type;

    constexpr operator value_type() const noexcept
    {   // return stored value
        return (value);
    }

    constexpr value_type operator()() const noexcept
    {   // return stored value
        return (value);
    }
};

typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;

template<class _Ty>
struct is_const
        : false_type
{   // determine whether _Ty is const qualified
};

template<class _Ty>
struct is_const<const _Ty>
        : true_type
{   // determine whether _Ty is const qualified
};
int main() {

    static_assert(is_const<int>::value,"error");//error
    static_assert(is_const<const int>::value, "error");//ok
    return 0;
}