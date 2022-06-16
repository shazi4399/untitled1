//
// Created by zhanghao on 2022/6/8.
//

#include "brass.h"

using std::cout;
using std::endl;
using std::string;

typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);
Brass::Brass(const string &s, long an, double bal){
    fullName=s; //客户姓名
    actNum=an;        //账号
    balance=bal;
}
void Brass::Deposit(double amt){
    if(amt<0){
        cout<<"Negative deposit is not allowed, it is cancelled";
    }else{
        balance+=amt;
    }
}
void Brass::Withdraw(double amt){
    format initialState=setFormat();
    precis prec=cout.precision(2);
    if(amt<0)
        cout<<"Withdraw amount has to be positive";
    else if (amt<balance)
        balance-=amt;
    else
        cout<<"Withdraw amount"<<amt<<" exceeds your balance"<<balance;
}
double Brass::Balance() const{
    return balance;
}
void Brass::ViewAcct() const{
    format initialState=setFormat();
    precis prec=cout.precision(2);
    cout<<"Client"<<fullName<<endl;
    cout<<"Account number"<<actNum<<endl;
    cout<<"Balance"<<balance<<endl;
    restore(initialState,prec);
}

BrassPlus::BrassPlus(
        const string& s,
        long an,
        double bal,
        double ml,
        double r
):Brass(s,an,bal){
    maxLoan=ml;
    owesBank=0.0;
    rate=r;
}

BrassPlus::BrassPlus(
        const Brass& ba,
        double ml,
        double r
):Brass(ba){
    maxLoan=ml;
    owesBank=0.0;
    rate=r;
}
void BrassPlus::ViewAcct() const{
    format initialState=setFormat();
    precis prec=cout.precision(2);
    Brass::ViewAcct();
    cout<<"Maximum loan"<<maxLoan<<endl;
    cout<<"Owed to bank"<<owesBank<<endl;
    cout.precision(3);
    cout<<"Loan rate:"<<100*rate;
    restore(initialState,prec);
}

void BrassPlus::Withdraw(double amt){
    format initialState=setFormat();
    precis prec=cout.precision(2);
    double bal=Balance();
    if(amt<=bal)
        Brass::Withdraw(amt);
    else if (amt<=bal+maxLoan-owesBank){
        double advance = amt -bal;
        owesBank+=advance*(1.0+rate);
        cout<<"Bank advance"<<advance<<endl;
        cout<<"Finance charge:"<<advance*rate<<endl;
        Deposit(advance);
        Brass::Withdraw(amt);
    }
    else
        cout<<"Credit limit exceeded. Transaction cancelled";
    restore(initialState,prec);
}

format setFormat(){
    return cout.setf(std::ios_base::fixed,std::ios_base::floatfield);
}

void restore(format f,precis p){
    cout.setf(f,std::ios_base::floatfield);
    cout.precision(p);
}