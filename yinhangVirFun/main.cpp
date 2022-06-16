//
// Created by zhanghao on 2022/6/8.
//



#include <iostream>
#include <string>
#include "brass.h"
const int CLIENTS =2;
int main(){
    using std::cout;
    using std::endl;
    using std::cin;


    Brass * p_clients [CLIENTS];
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;

    p_clients[0]=new Brass("neil", 6217167, 199.0);
    p_clients[1]=new BrassPlus("sam", 6217168, 199.0, 10000.0, 0.1);

    p_clients[0]->ViewAcct();
    p_clients[1]->ViewAcct();

    delete p_clients[0]; //free memory
    delete p_clients[1]; //free memory

    return 0;
}