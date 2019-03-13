/*
返回迭代器之间的距离
计算第一个和最后一个之间的元素数。
如果它是随机访问迭代器，则函数使用operator-来计算它。 
否则，该函数重复使用增量运算符（operator ++）。
*/
#include <iostream>     // std::cout
#include <iterator>     // std::distance
#include <list>         // std::list

int main () {
	std::list<int> mylist;
	for (int i=0; i<10; i++) mylist.push_back (i*10);

	std::list<int>::iterator first = mylist.begin();
	std::list<int>::iterator last = mylist.end();

	std::cout << "The distance is: " << std::distance(first,last) << '\n';

	return 0;
}
