/*
复制范围删除值
将[first，last]范围内的元素复制到从result开始的范围，但pred返回true的元素除外。
得到的范围比[第一个，最后一个]短的匹配元素数量被“移除”。

参数
first，last;
将迭代器转发到序列中的初始位置和最终位置。 
使用的范围是[first，last），它包含first和last之间的所有元素，包括first指向的元素，但不包括last指向的元素。
result；
将迭代器输出到存储结果序列的范围的初始位置。
指向的类型应支持赋值[first，last]范围内的元素值。
pred:
一元函数接受范围内的元素作为参数，并返回可转换为bool的值。 返回的值指示是否要从副本中删除元素（如果为true，则不会复制该元素）。
该函数不得修改其参数。这可以是函数指针或函数对象。
范围不得重叠。
返回值
指向复制范围末尾的迭代器，其中包括[first，last]中的所有元素，但pred返回true的元素除外。
*/
// remove_copy_if example
#include <iostream>     // std::cout
#include <algorithm>    // std::remove_copy_if
#include <vector>       // std::vector

bool IsOdd (int i) { return ((i%2)==1); }

int main () {
  int myints[] = {1,2,3,4,5,6,7,8,9};
  std::vector<int> myvector (9);

  std::remove_copy_if (myints,myints+9,myvector.begin(),IsOdd);

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
