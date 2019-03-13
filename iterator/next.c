/*
获取下一个元素的迭代器
返回一个迭代器，指向如果高级n位置它将指向的元素。
它没有被修改。
如果它是随机访问迭代器，则该函数仅使用一次operator +或operator-。 
否则，该函数在复制的迭代器上重复使用增加或减少运算符（operator ++或operator–），直到n个元素被提前。
*/
#include <iostream>     // std::cout
#include <iterator>     // std::next
#include <list>         // std::list
#include <algorithm>    // std::for_each

int main () {
  std::list<int> mylist;
  for (int i=0; i<10; i++) mylist.push_back (i*10);

  std::cout << "mylist:";
  std::for_each (mylist.begin(),
                 std::next(mylist.begin(),5),
                 [](int x) {std::cout << ' ' << x;} );

  std::cout << '\n';

  return 0;
}
