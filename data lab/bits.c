/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return ~(~x & ~y) & ~(x & y);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {

  return 1 << 31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
    // 倒二行的算法理论应该是对的，但实际上好像因为出现了1 << 31 的字面量没法放入int的未定义行为导致出错。
    // 但这又和上一个函数tmin的做法冲突，我同样使用了移位，同样是int,但这个是正确的，只能归咎于神秘的编译器优化了。
    // int t1 = x+1;
    // int t2 = 1 << 31;
    // int ans = t1 ^ t2;
    // return !ans;
  // return !((x+1) ^ (1 << 31));
  return !(~(x+1) ^ x)&!!(x+1);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int t = 0xAA;
  int k = (t << 24) | (t << 16) | (t << 8) | t;
  return !((x & k) ^ k) ;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
    //范围类的判断可以尝试利用减法，减法的实现通过加负数。
  int a = !((x >> 4) ^ 0x3);
  int b = x & 0xf;
  int c = ~0xa + 1;
  int d = 1 << 15;
  int e = !!((b+c) & d);
  return a & e;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
    //要实现条件关键在于让x不为1时能够得到0xffffffff同时还得不影响0的表示,
    //利用补码取非后0不变而1能变为0xffffffff的特性即可实现
    //剩下就是提取出y或者z,然后同样取非，如果提取出来是0,那么应该返回的就是这个数
    //提取出来是这个数的非，那么这个数就应该被抵消，是一个逆向的思维。
  int a = !!(x ^ 0x0);
  int b = ~a+1;
  int c = ~(y & ~b) + 1;
  int d = ~(z & b) + 1;
  return y+c+z+d;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    //两个数的符号需要考虑，溢出需要考虑，总之就是耐心分类，然后利用相减为负的方法来判断
  int a = x >> 31 & 0x1;
  int b = y >> 31 & 0x1;
  int c1 = a & !b; //x- y+
  int c2 = !a & b; //x+ y-
  int d = (~x+1) + y;
  int e = d >> 31;
  return c1 | (!c2 & !e);
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  //重点在于区分0和非0,需要利用符号位和算术右移，以及全1加1后翻转为0的特性
  //就可以实现非0得到0，至于0本身，只需要加1即可，这个操作和前面的加1是一致的
  return (((~x+1) | x) >> 31) + 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
    //正数就是从右往左找最左的那个1,负数就是从符号位1开始连续的1的最后一个1
    //推断一下负数只需要取反需要的操作就和正数一样。
    //至于如何找到最左的1,本质就是一个查找算法题，从高位开始不断二分即可
    //至于具体数字如何计算，根据二分的过程模拟一下就行
  int b16,b8,b4,b2,b1,b0;
  int flag = x >> 31;
  int y = (x & ~flag) | (~x & flag);
  b16 = !!(y >> 16) << 4;
  y >>= b16;
  b8 = !!(y >> 8) << 3;
  y >>= b8;
  b4 = !!(y >> 4) << 2;
  y >>= b4;
  b2 = !!(y >> 2) << 1;
  y >>= b2;
  b1 = !!(y >> 1);
  y >>= b1;
  b0 = y;
  return b0+b1+b2+b4+b8+b16+1;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  unsigned exp = (uf & 0x7f800000) >> 23;
  unsigned sign = (uf >> 31) & 0x1;
  unsigned frac = uf & 0x7fffff;
  unsigned res;
  if(exp == 0xff) return uf;
  if(exp == 0) {
     frac <<= 1;
     res =  (sign << 31) | (exp << 23) | frac;
  } else {
     exp++;
     res = (sign << 31) | (exp << 23) | frac;
  }
  return res;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
    //尾数23位，实际就是尾数左移E位，需要的话舍入
    //然后再看左移时是否会溢出（即尾数的最高有效位都被放到符号位了）
  unsigned exp = (uf & 0x7f800000) >> 23;
  int sign = (uf >> 31) & 0x1;
  unsigned frac = uf & 0x7fffff;
  int E = exp - 127;
  if(E >= 31) return 0x80000000u;
  if(E < 0) return 0;
  else {
      frac = frac | 1 << 23;
      if(E<23) {
          frac >>= (23 - E);
      } else {
          frac <<= (E - 23);
      }
      if(sign) return -frac;
      else return frac;
  }
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    //根据阶码E的范围分类讨论即可
    if(x > 127) return 0xff << 23;
    if(x < -148) return 0;
    if(x >= -126) {
        int exp = x + 127;
        return exp << 23;
    } else {
        int t = 148 + x;
        return 1 << t;
    }
}
