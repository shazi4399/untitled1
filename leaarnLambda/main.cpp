//
// Created by zhanghao on 2022/5/21.
//
#include <iostream>
using namespace std;

int main()
{
    int a = 123;
    auto f = [&a] { cout << a << endl; };
    a = 321;
    f(); // 输出：123

    //或通过“函数体”后面的‘()’传入参数
    //auto x = [](int a){cout << a << endl;}(123);
}