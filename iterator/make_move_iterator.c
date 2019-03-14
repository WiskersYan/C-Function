/*
构造移动迭代器
从中构造一个move_iterator对象，
move_iterator是一个迭代器适配器，它适配迭代器（it），
以便取消引用它产生右值引用（就好像应用了std :: move），而所有其他操作的行为相同。
*/
#include <iostream>     // std::cout
#include <iterator>     // std::make_move_iterator
#include <vector>       // std::vector
#include <string>       // std::string
#include <algorithm>    // std::copy

int main () {
  std::vector<std::string> foo (3);
  std::vector<std::string> bar {"one","two","three"};

  std::copy ( make_move_iterator(bar.begin()),
              make_move_iterator(bar.end()),
              foo.begin() );

  // bar now contains unspecified values; clear it:
  bar.clear();

  std::cout << "foo:";
  for (std::string& x : foo) std::cout << ' ' << x;
  std::cout << '\n';

  return 0;
}
