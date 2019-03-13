/*
构造后插入迭代器
构造一个后插入迭代器，在x的末尾插入新元素。
back-insert迭代器是一种特殊类型的输出迭代器，旨在允许通常覆盖元素（例如复制）的算法在容器的末尾自动插入新元素。
x的类型需要有一个push_back成员函数（例如标准容器向量，双端队列和列表）。
在返回的迭代器上使用赋值运算符（取消引用或不引用），使容器扩展一个元素，该元素初始化为指定的值。
返回的迭代器支持输出迭代器的所有其他典型操作，但不起作用：分配的所有值都插入容器的末尾。
*/
#include <iostream>     // std::cout
#include <iterator>     // std::back_inserter
#include <vector>       // std::vector
#include <algorithm>    // std::copy

int main () {
  std::vector<int> foo,bar;
  for (int i=1; i<=5; i++)
  { foo.push_back(i); bar.push_back(i*10); }

  std::copy (bar.begin(),bar.end(),back_inserter(foo));

  std::cout << "foo contains:";
  for ( std::vector<int>::iterator it = foo.begin(); it!= foo.end(); ++it )
	  std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
