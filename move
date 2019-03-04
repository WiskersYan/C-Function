# 移动元素范围
# 将[first，last]范围内的元素移动到从result开始的范围。
# [first，last]中元素的值被传递给result指向的元素。 调用之后，[first，last]范围内的元素将保持未指定但有效的状态。
# 范围不应以结果指向[first，last]范围内的元素的方式重叠。 对于此类情况，请参阅move_backward。

#include <iostream>     // std::cout
#include <algorithm>    // std::move (ranges)
#include <utility>      // std::move (objects)
#include <vector>       // std::vector
#include <string>       // std::string

int main () {
  std::vector<std::string> foo = {"air","water","fire","earth"};
  std::vector<std::string> bar (4);

  // moving ranges:
  std::cout << "Moving ranges...\n";
  std::move ( foo.begin(), foo.begin()+4, bar.begin() );

  std::cout << "foo contains " << foo.size() << " elements:";
  std::cout << " (each in an unspecified but valid state)";
  std::cout << '\n';

  std::cout << "bar contains " << bar.size() << " elements:";
  for (std::string& x: bar) std::cout << " [" << x << "]";
  std::cout << '\n';

  // moving container:
  std::cout << "Moving container...\n";
  foo = std::move (bar);

  std::cout << "foo contains " << foo.size() << " elements:";
  for (std::string& x: foo) std::cout << " [" << x << "]";
  std::cout << '\n';

  std::cout << "bar is in an unspecified but valid state";
  std::cout << '\n';

  return 0;
}
