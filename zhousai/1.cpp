//
// Created by zhanghao on 2022/5/28.
//
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool digitCount(string num) {
        unordered_map<int,int> mymap(10);
        for(auto i : num){
            mymap[i-'0']++;
        }
        int n = num.size();
        for(int i = 0 ; i < n ; i++){
            if( mymap[i] != num[i]-'0'){
                return false;
            }
        }
        return true;
    }
};
int main(){
    string num = "030";
    bool flag = Solution().digitCount(num);
    if(flag){
        cout<< "True"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}