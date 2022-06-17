//
// Created by zhanghao on 2022/6/17.
//

/**
* 题目：
对于给定的正整数n和目标数key，能够通过拆分，使拆分得到的多个整数之和最接近key且不超过key。
如：n为1236，key为40，所能拆分的方案如下：
（1）1+2+3+6=12；
（2）1+2+36=39；
（3）1+23+6=30；
（4）1+236=237；
（5）12+3+6=21；
（6）12+36=38；
（7）123+6=129；
（8）1236=1236；
根据题目要求，第二种为最优方案。
如果所有方案都大于key，则输出none，如果有多个结果则打印many，如果只有一个，则打印该方案。
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        // 偶数个，则插入到前半部分，否则插入后半部分
        if (m_nums % 2 == 0) {//后半部分存储大的值，end不想要小的值，所以把小的值筛选出来，放到
            m_heapEnd.push(num);
            m_heapStart.push(m_heapEnd.top());
            m_heapEnd.pop();//end是小顶堆
        } else {
            m_heapStart.push(num);//start是大顶堆
            m_heapEnd.push(m_heapStart.top());
            m_heapStart.pop();
        }
        m_nums++;
    }

    double findMedian() {//static_cast 就是C++的强制类型转换。也没什么特别难理解的地方。
        return (m_nums % 2 == 0) ?
               static_cast<double>((m_heapStart.top() + m_heapEnd.top()) / 2.0) :
               static_cast<double>(m_heapStart.top());
    }

private:
    priority_queue<int> m_heapStart;  // 保存前半部分 //默认是大顶堆
    priority_queue<int, vector<int>, greater<int>> m_heapEnd;  // 保存后半部分
    int m_nums = 0;
};

int main(){
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    double ans = mf.findMedian();
    cout << ans <<endl;
    return 0;
}