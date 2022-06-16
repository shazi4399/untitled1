//
// Created by zhanghao on 2022/3/24.
//

#include <iostream>

#include "testFunc.h"

void func(int data)
{
    for(int i = 0 ; i < 10; ++i){
        std::cout<<"这是第"<<i<<"遍"<<std::endl;
        std::cout<<"data is : "<<data<<std::endl;
    }

}