#include "stack.hpp"

using namespace dsa;

/*
 * 递归实现进制转换
 */
void convert(Stack<char>& S, long n, int base) {
  static char digit[] = {'0', '1', '2', '3', '4', '5'
    ,'6','7','8','9','A','B','C','D','E','F'};
  if ( 0 < n ) {
    S.push(digit[ n % base ]);
    convert(S, n / base, base);
  }
}


