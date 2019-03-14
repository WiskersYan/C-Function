/*
删除范围内的连续重复项
从[first，last]范围内的每个连续的等效元素组中删除除第一个元素之外的所有元素。
该函数不能改变包含元素范围的对象的属性（即，它不能改变数组或容器的大小）：
通过用下一个不重复的元素替换重复元素来完成删除，并且 通过将迭代器返回到应该被视为其新的past-the-end元素的元素来发信号通知缩短范围的新大小。
保留未删除元素的相对顺序，而返回的迭代器和last之间的元素保留在有效但未指定的状态。
该函数使用operator ==来比较元素对（或版本（2）中的pred）。

参数
first，last
将迭代器转发到move-assignable元素序列的初始和最终位置。 
使用的范围是[first，last），它包含first和last之间的所有元素，包括first指向的元素，但不包括last指向的元素。
pred
二进制函数，接受范围中的两个元素作为参数，并返回可转换为bool的值。 
返回的值指示两个参数是否被视为等效（如果为true，则它们是等效的，并且其中一个被删除）。
该函数不得修改其任何参数。这可以是函数指针或函数对象。
返回值
未删除的最后一个元素后面的元素的迭代器。first和this迭代器之间的范围包括序列中不被视为重复的所有元素。
*/
#include <iostream>     // std::cout
#include <algorithm>    // std::unique, std::distance
#include <vector>       // std::vector

bool myfunction (int i, int j) {
  return (i==j);
}

int main () {
  int myints[] = {10,20,20,20,30,30,20,20,10};           // 10 20 20 20 30 30 20 20 10
  std::vector<int> myvector (myints,myints+9);

  // using default comparison:
  std::vector<int>::iterator it;
  it = std::unique (myvector.begin(), myvector.end());   // 10 20 30 20 10 ?  ?  ?  ?
                                                         //                ^

  myvector.resize( std::distance(myvector.begin(),it) ); // 10 20 30 20 10

  // using predicate comparison:
  std::unique (myvector.begin(), myvector.end(), myfunction);   // (no changes)

  // print out content:
  std::cout << "myvector contains:";
  for (it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
