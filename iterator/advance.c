/*
推进迭代器
通过n个元素位置推进迭代器。
如果它是随机访问迭代器，则该函数仅使用一次operator +或operator-。 
否则，该函数重复使用增加或减少运算符（运算符++或运算符 - ），直到n个元素被提前。
*/
#include <iostream>     // std::cout
#include <iterator>     // std::advance
#include <list>         // std::list

int main () {
  std::list<int> mylist;
  for (int i=0; i<10; i++) mylist.push_back (i*10);

  std::list<int>::iterator it = mylist.begin();

  std::advance (it,5);

  std::cout << "The sixth element in mylist is: " << *it << '\n';

  return 0;
}
