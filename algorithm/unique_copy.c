/*
复制范围删除重复项
将[first，last]范围内的元素复制到从result开始的范围，但连续重复项（比较前面的元素的元素除外）。
仅复制[first，last]范围内每个连续的等效元素组中的第一个元素。
元素之间的比较是通过在它们之间应用operator ==或模板参数pred（对于第二个版本）来执行的。
参数
first，last
将迭代器转发到序列中的初始位置和最终位置。使用的范围是[first，last），它包含first和last之间的所有元素，包括first指向的元素，但不包括last指向的元素。
如果InputIterator是单通道迭代器，它指向的类型应该是可复制构造和可复制分配的。
result
将迭代器输出到存储结果值范围的范围的初始位置。
指向的类型应支持赋值[first，last]范围内的元素值。
pred
二进制函数，接受范围中的两个元素作为参数，并返回可转换为bool的值。返回的值指示两个参数是否被视为等效（如果为true，则它们是等效的，并且其中一个被删除）。
该函数不得修改其任何参数。这可以是函数指针或函数对象。

范围不得重叠。
返回值
指向复制范围末尾的迭代器，它不包含连续的重复项。
*/
// unique_copy example
#include <iostream>     // std::cout
#include <algorithm>    // std::unique_copy, std::sort, std::distance
#include <vector>       // std::vector

bool myfunction (int i, int j) {
  return (i==j);
}

int main () {
  int myints[] = {10,20,20,20,30,30,20,20,10};
  std::vector<int> myvector (9);                            // 0  0  0  0  0  0  0  0  0

  // using default comparison:
  std::vector<int>::iterator it;
  it=std::unique_copy (myints,myints+9,myvector.begin());   // 10 20 30 20 10 0  0  0  0
                                                            //                ^

  std::sort (myvector.begin(),it);                          // 10 10 20 20 30 0  0  0  0
                                                            //                ^

  // using predicate comparison:
  it=std::unique_copy (myvector.begin(), it, myvector.begin(), myfunction);
                                                            // 10 20 30 20 30 0  0  0  0
                                                            //          ^

  myvector.resize( std::distance(myvector.begin(),it) );    // 10 20 30

  // print out content:
  std::cout << "myvector contains:";
  for (it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
