// packing/unpacking tuples
#include <iostream>     // std::cout
#include <tuple>        // std::tuple, std::make_tuple, std::tie
#include <vector>

int main ()
{
  int myint;
  char mychar;

  std::tuple<int,float,char> t;
  std::vector<int> v;

  t = std::make_tuple (10, 2.6, 'a');          // packing values into tuple

  std::tie (myint, std::ignore, mychar) = t;   // unpacking tuple into variables

  std::tuple_cat = 

  auto it = v.iterator(); // ha ha ha WRONG
  std::vector<int>::iterator it = v.begin();

  std::cout << "myint contains: " << myint << '\n';
  std::cout << "mychar contains: " << mychar << '\n';

  return 0;
}