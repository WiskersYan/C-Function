/*
从范围中删除值
[注意：这是算法删除的参考。 请参阅删除的删除。]
将范围[first，last]转换为一个范围，其中所有比较等于val的元素被移除，并将迭代器返回到该范围的新结尾。
该函数不能改变包含元素范围的对象的属性（即，它不能改变数组或容器的大小）：
删除是通过将下一个不匹配的元素替换为val的元素来完成的。 通过将迭代器返回到应该被视为新的past-the-end元素的元素来发出缩短范围的新大小的信号。
保留未删除元素的相对顺序，而返回的迭代器和last之间的元素保留在有效但未指定的状态。
该函数使用operator ==将各个元素与val进行比较。

参数
first，last:
将迭代器转发到一系列move-assignable元素中的初始和最终位置，支持与T类型的值进行比较。
使用的范围是[first，last]，它包含first和last之间的所有元素，包括指向的元素 首先但不是最后指向的元素。
val:
要删除的值。
返回值:
未删除的最后一个元素后面的元素的迭代器。
first和this迭代器之间的范围包括序列中不比较等于val的所有元素。
*/
// remove example
#include <iostream>     // std::cout
#include <algorithm>    // std::remove

int main () {
  int myints[] = {10,20,30,30,20,10,10,20};      // 10 20 30 30 20 10 10 20

  // bounds of range:
  int* pbegin = myints;                          // ^
  int* pend = myints+sizeof(myints)/sizeof(int); // ^                       ^

  pend = std::remove (pbegin, pend, 20);         // 10 30 30 10 10 ?  ?  ?
                                                 // ^              ^
  std::cout << "range contains:";
  for (int* p=pbegin; p!=pend; ++p)
    std::cout << ' ' << *p;
  std::cout << '\n';

  return 0;
}
