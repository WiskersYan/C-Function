/*
字典小于比较

如果范围[first1，last1]按字典顺序比较范围[first2，last2]，则返回true。

字典比较是一种比较，通常用于在字典中按字母顺序对单词进行排序;
它涉及顺序地比较两个范围中具有相同位置的元素彼此之间的比较，
直到一个元素不等同于另一个元素。 比较这些第一非匹配元素的结果是词典比较的结果。

如果两个序列比较相等直到其中一个结束，则较短的序列按字典顺序小于较长的序列。

使用operator <作为第一个版本比较元素，comp作为第二个版本。 
如果（！（a <b）&&！（b <a））或if（！comp（a，b）&&！comp（b，a）），
则认为两个元素a和b是等价的。

参数

    first1，last1
    将迭代器输入到第一个序列的初始和最终位置。 使用的范围是[first1，last1]，
    它包含first1和last1之间的所有元素，包括first1指向的元素，但不包括last1指向的元素。
    first2，last2
    将迭代器输入到第二个序列的初始和最终位置。 使用的范围是[first2，last2）。
    comp
    二进制函数，接受迭代器指向的两个类型的参数，并返回一个可转换为bool的值。 
    返回的值指示第一个参数是否在其定义的特定严格弱顺序中被认为是在第二个参数之前。
    该函数不得修改其任何参数。这可以是函数指针或函数对象。
*/
// lexicographical_compare example 
#include <iostream> // std::cout, std::boolalpha 
#include <algorithm> // std::lexicographical_compare 
#include <cctype> // std::tolower 
// a case-insensitive comparison function: 
bool mycomp (char c1, char c2) { 
return std::tolower(c1)<std::tolower(c2); 
} 
int main () {
char foo[]="Apple"; 
char bar[]="apartment"; 
std::cout << std::boolalpha; 
std::cout << "Comparing foo and bar lexicographically (foo<bar):\n"; 
std::cout << "Using default comparison (operator<): "; 
std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+9); 
std::cout << '\n'; std::cout << "Using mycomp as comparison object: "; 
std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp); 
std::cout << '\n'; return 0; 
}
