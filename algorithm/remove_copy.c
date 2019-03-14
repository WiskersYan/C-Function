/*
复制范围删除值
将[first，last]范围内的元素复制到从result开始的范围，除了那些比较等于val的元素。
得到的范围比[第一个，最后一个]短了与序列中的匹配一样多的元素，这些元素被“移除”。
该函数使用operator ==将各个元素与val进行比较。

参数
first，last:
将迭代器转发到元素序列中的初始位置和最终位置，支持与类型T的值进行比较。
使用的范围是[first，last]，其中包含first和last之间的所有元素，包括第一个指向的元素但是 不是最后指向的元素。
result:
将迭代器输出到存储结果序列的范围的初始位置。
指向的类型应支持赋值[first，last]范围内的元素值。
val:
要删除的值。
范围不得重叠。
返回值
指向复制范围末尾的迭代器，其中包括[first，last]中的所有元素，除了那些比较等于val的元素。
*/
// remove_copy example
#include <iostream>     // std::cout
#include <algorithm>    // std::remove_copy
#include <vector>       // std::vector

int main () {
  int myints[] = {10,20,30,30,20,10,10,20};               // 10 20 30 30 20 10 10 20
  std::vector<int> myvector (8);

  std::remove_copy (myints,myints+8,myvector.begin(),20); // 10 30 30 10 10 0 0 0

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
