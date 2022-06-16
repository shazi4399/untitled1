//
// Created by zhanghao on 2022/5/28.
//
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
private:
    int cal(string s){
        int ans = 0;
        for(auto i :s){
            if(i == ' '){
                ans++;
            }
        }
        ans++;
        return ans;
    }
    //判断字典序函数：
    bool judgeless(string A,string B){

    }
public:

    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int num = senders.size();
        unordered_map<string,int> mymap(num);
        for(int i = 0 ; i < num;i++){
            mymap[senders[i]] += cal(messages[i]);
        }
        int maxnum = -1;
        string ans;
        for(auto i : mymap){
            if(i.second == maxnum){//ans 和 i.first 判断字典序列
                if(i.first.compare(ans) > 0){
                    ans = i.first;
                }
            }
            if(i.second > maxnum){
                maxnum = i.second;
                ans = i.first;
            }
        }
        return ans;
    }
};
int main(){
    vector<string> messages = {"tP x M VC h lmD","D X XF w V","sh m Pgl","pN pa","C SL m G Pn v","K z UL B W ee","Yf yo n V U Za f np","j J sk f qr e v t","L Q cJ c J Z jp E","Be a aO","nI c Gb k Y C QS N","Yi Bts","gp No g s VR","py A S sNf","ZS H Bi De dj dsh","ep MA KI Q Ou"};
    vector<string> senders = {"OXlq","IFGaW","XQPeWJRszU","Gb","HArIr","Gb","FnZd","FnZd","HArIr","OXlq","IFGaW","XQPeWJRszU","EMoUs","Gb","EMoUs","EMoUs"};
    string ans = Solution().largestWordCount(messages,senders);
    cout<<ans<<endl;

    return 0;
}