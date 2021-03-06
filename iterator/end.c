/*
迭代器结束
返回指向序列中的past-the-end元素的迭代器：
（1）容器
该函数返回cont.end（）。
（2）数组
该函数返回arr + N.
如果序列为空，则返回的值将与begin返回的值相等，并使用相同的参数。
这些函数模板在多个头文件中定义：这些头文件中的每一个都包含所有容器和数组类型的通用模板，而不仅仅是特定的重载。 
头文件是：<iterator>，<array>，<deque>，<forward_list>，<list>，<*map>*，<regex>，<set>，<string>，<unordered_map>，<unordered_set>和<vector>。
相反，在头<initializer_list>和<valarray>中，end被重载（具有不同的定义）。
*/
#include <iostream>     // std::cout
#include <vector>       // std::vector, std::begin, std::end

int main () {
  int foo[] = {10,20,30,40,50};
  std::vector<int> bar;

  // iterate foo: inserting into bar
  for (auto it = std::begin(foo); it!=std::end(foo); ++it)
    bar.push_back(*it);

  // iterate bar: print contents:
  std::cout << "bar contains:";
  for (auto it = std::begin(bar); it!=std::end(bar); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
