/*
将范围转换为下一个排列

将[first，last]范围内的元素重新排列为下一个按字典顺序排列的更大排列。

排列是N中的每一个！元素可以采取的可能安排（其中N是范围内元素的数量）。
可以根据他们如何比较词典相互比较来排序不同的排列;第一个这样排序的可能排列
（将字典比较小于所有其他排列的那个排列）是使其所有元素按升序排序的排序，并且最大排列的所有元素按降序排序。

各个元素的比较使用operator <用于第一个版本，或comp用于第二个版本。

如果函数可以确定下一个更高的排列，它会重新排列元素并返回true。
如果那是不可能的（因为它已经处于最大可能的排列），它会根据第一个排列重新排列元素（按升序排序）并返回false。

参数
第一，最后
双向迭代器到序列的初始和最终位置。 使用的范围是[first，last），
它包含first和last之间的所有元素，包括first指向的元素，但不包括last指向的元素。
BidirectionalIterator应指向正确定义交换的类型。

补偿
二进制函数，接受BidirectionalIterator指向的类型的两个参数，并返回一个可转换为bool的值。 
返回的值指示第一个参数是否在其定义的特定严格弱顺序中被认为是在第二个参数之前。
该函数不得修改其任何参数。这可以是函数指针或函数对象。

返回值
如果函数可以将对象重新排列为字典顺序更大的排列，则为true。
否则，该函数返回false以指示排列不大于前一个，但最低可能（按升序排序）。
*/
#include <iostream> // std::cout 
#include <algorithm> // std::next_permutation, std::sort 
int main () { 
int myints[] = {1,2,3}; 
std::sort (myints,myints+3); 
std::cout << "The 3! possible permutations with 3 elements:\n"; 
do { 
std::cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n'; 
} while ( std::next_permutation(myints,myints+3) ); 
std::cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n'; return 0; 
}
