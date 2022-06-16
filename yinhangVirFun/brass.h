//
// Created by zhanghao on 2022/6/8.
//




#ifndef BRASS_H_
#define BRASS_H_
#include <iostream>
#include <string>

class Brass{
private:
    std::string fullName; //客户姓名
    long actNum;        //账号
    double balance;     //当前结余
public:
    Brass(
            const std::string &s ="Nullbody",
            long an=-1,
            double bal=0.0
    );//创建账户
    void Deposit(double amt); //存款
    virtual void Withdraw(double amt);  //取款
    double Balance() const;
    virtual void ViewAcct() const;//查看账户
    virtual ~Brass(){}
};

class BrassPlus:public Brass{

private:
    double maxLoan;
    double rate;
    double owesBank;
public:
    BrassPlus(
            const std::string &s ="Nullbody",
            long an=-1,
            double bal=0.0,
            double ml=500,
            double r=0.11125
    );//创建账户
    BrassPlus(
            const Brass &ba,
            double ml=500,
            double r=0.11125
    );
    virtual void ViewAcct() const;//查看账户
    virtual void Withdraw(double amt);  //取款
    void ResetMax(double m){ maxLoan=m;}
    void ResetRate(double r){rate=r;}
    void ResetOwes(){owesBank=0;}
};


#endif
