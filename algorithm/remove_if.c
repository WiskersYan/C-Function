/*
从范围中删除元素
将范围[first，last]转换为一个范围，其中包含pred返回true的所有元素，并将迭代器返回到该范围的新结尾。
该函数不能改变包含元素范围的对象的属性（即，它不能改变数组或容器的大小）：
通过用下一个元素替换pred返回true的元素来完成删除。 没有，并通过将迭代器返回到应该被视为其新的过去元素的元素来发出缩短范围的新大小。
保留未删除元素的相对顺序，而返回的迭代器和last之间的元素保留在有效但未指定的状态。

参数
first，last:
将迭代器转发到一系列可移动赋值元素中的初始和最终位置。 
使用的范围是[first，last），它包含first和last之间的所有元素，包括first指向的元素，但不包括last指向的元素。
pred:
一元函数接受范围内的元素作为参数，并返回可转换为bool的值。 返回的值指示是否要删除元素（如果为true，则将其删除）。
该函数不得修改其参数。这可以是函数指针或函数对象。
返回值:
未删除的最后一个元素后面的元素的迭代器。
first和this迭代器之间的范围包括序列中pred不返回true的所有元素。
*/
// remove_if example
#include <iostream>     // std::cout
#include <algorithm>    // std::remove_if

bool IsOdd (int i) { return ((i%2)==1); }

int main () {
  int myints[] = {1,2,3,4,5,6,7,8,9};            // 1 2 3 4 5 6 7 8 9

  // bounds of range:
  int* pbegin = myints;                          // ^
  int* pend = myints+sizeof(myints)/sizeof(int); // ^                 ^

  pend = std::remove_if (pbegin, pend, IsOdd);   // 2 4 6 8 ? ? ? ? ?
                                                 // ^       ^
  std::cout << "the range contains:";
  for (int* p=pbegin; p!=pend; ++p)
    std::cout << ' ' << *p;
  std::cout << '\n';

  return 0;
}
