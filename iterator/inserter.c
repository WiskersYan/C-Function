/*
构造插入迭代器
构造一个插入迭代器，它将新元素插入到从其指向的位置开始的连续位置的x中。
插入迭代器是一种特殊类型的输出迭代器，旨在允许通常覆盖元素（例如复制）的算法自动在容器中的特定位置插入新元素。
x的类型需要具有插入成员函数（例如大多数标准容器）。
在返回的迭代器上使用赋值运算符（取消引用或不引用）会导致在容器上调用insert，尝试在当前插入位置插入一个元素并赋值。这有效地将容器扩展一个元素。
返回的迭代器支持输出迭代器的所有其他典型操作但不起作用：
分配的所有值都插入到当前插入位置 - 这是在调用此函数之后，并且在每次新插入后由迭代器赋值引起的递增。
*/
#include <iostream>     // std::cout
#include <iterator>     // std::front_inserter
#include <list>         // std::list
#include <algorithm>    // std::copy

int main () {
  std::list<int> foo,bar;
  for (int i=1; i<=5; i++)
  { foo.push_back(i); bar.push_back(i*10); }

  std::list<int>::iterator it = foo.begin();
  advance (it,3);

  std::copy (bar.begin(),bar.end(),std::inserter(foo,it));

  std::cout << "foo contains:";
  for ( std::list<int>::iterator it = foo.begin(); it!= foo.end(); ++it )
	  std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
