/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 */

/* Instructions to Students:

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  long Funct(long arg1, long arg2, ...) {
      // brief description of how your implementation works
      long var1 = Expr1;
      ...
      long varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. (Long) integer constants 0 through 255 (0xFFL), inclusive. You are
      not allowed to use big constants such as 0xffffffffL.
  2. Function arguments and local variables (no global variables).
  3. Local variables of type int and long
  4. Unary integer operations ! ~
     - Their arguments can have types int or long
     - Note that ! always returns int, even if the argument is long
  5. Binary integer operations & ^ | + << >>
     - Their arguments can have types int or long
  6. Casting from int to long and from long to int

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting other than between int and long.
  7. Use any data type other than int or long.  This implies that you
     cannot use arrays, structs, or unions.

  You may assume that your machine:
  1. Uses 2s complement representations for int and long.
  2. Data type int is 32 bits, long is 64.
  3. Performs right shifts arithmetically.
  4. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31 (int) or 63 (long)

EXAMPLES OF ACCEPTABLE CODING STYLE:
  //
  // pow2plus1 - returns 2^x + 1, where 0 <= x <= 63
  //
  long pow2plus1(long x) {
     // exploit ability of shifts to compute powers of 2
     // Note that the 'L' indicates a long constant
     return (1L << x) + 1L;
  }

  //
  // pow2plus4 - returns 2^x + 4, where 0 <= x <= 63
  //
  long pow2plus4(long x) {
     // exploit ability of shifts to compute powers of 2
     long result = (1L << x);
     result += 4L;
     return result;
  }

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

CAUTION:
  Do not add an #include of <stdio.h> (or any other C library header)
  to this file.  C library headers almost always contain constructs
  that dlc does not understand.  For debugging, you can use printf,
  which is declared for you just below.  It is normally bad practice
  to declare C library functions by hand, but in this case it's less
  trouble than any alternative.

  dlc will consider each call to printf to be a violation of the
  coding style (function calls, after all, are not allowed) so you
  must remove all your debugging printf's again before submitting your
  code or testing it with dlc or the BDD checker.  */

extern int printf(const char *, ...);

/* Edit the functions below.  Good luck!  */
// 2
/*
 * copyLSB - set all bits of result to least significant bit of x
 *   Examples:
 *     copyLSB(5L) = 0xFFFFFFFFFFFFFFFFL,
 *     copyLSB(6L) = 0x0000000000000000L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
long copyLSB(long x) {
    long ret = 0x1L;
    /* determine the lowest bit value */
    /**
     *    0xFFFFFFFFFFFFFFF5L
     * &  0x0000000000000001L
     * --------------------------
     *    0x0000000000000001L
     */
    ret = ret & x;
    /* if the lowest bit value is 1, return 0xFFFFFFFFFFFFFFFFL
     * otherwise 0xFFFFFFFFFFFFFFFFL + 0x1L becomes 0
     */
    /*
     * !  0x0000000000000001L
     *    0x0000000000000000L
     *
     *    0xFFFFFFFFFFFFFFFFL
     * +  0x0000000000000000L
     * --------------------------
     *    0xFFFFFFFFFFFFFFFFL
     */
    ret = !ret;
    return 0xFFFFFFFFFFFFFFFFL + ret;
}
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 63 (most significant)
 *   Examples: allOddBits(0xFFFFFFFDFFFFFFFDL) = 0L,
 *             allOddBits(0xAAAAAAAAAAAAAAAAL) = 1L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 14
 *   Rating: 2
 */
long allOddBits(long x) {
    long ret = 0xAAAAAAAAAAAAAAAAL;
    /* if x is allOddBits otherwise ret == 0xAAAAAAAAAAAAAAAAL*/
    ret = ret & x;
    /* determine whether ret is euqal to 0xAAAAAAAAAAAAAAAAL */
    /// ret == 0xAAAAAAAAAAAAAAAAL ret = 0
    /// ret != 0xAAAAAAAAAAAAAAAAL ret != 0
    ret = (ret ^ 0xAAAAAAAAAAAAAAAAL);
    return !ret;
}
/*
 * isNotEqual - return 0 if x == y, and 1 otherwise
 *   Examples: isNotEqual(5L, 5L) = 0L, isNotEqual(4L, 5L) = 1L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
long isNotEqual(long x, long y) {
    return !!(x ^ y);
}
/*
 * dividePower2 - Compute x/(2^n), for 0 <= n <= 62
 *  Round toward zero
 *   Examples: dividePower2(15L,1L) = 7L, dividePower2(-33L,4L) = -2L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
long dividePower2(long x, long n) {
    // is negative
    long neg = 0x8000000000000000L;
    neg = x & neg;
    neg = neg >> 63;
    // biasing
    long biasing = ((1L << n) - 1) & neg;

    return (x + biasing) >> n;
}
// 3
/*
 * remainderPower2 - Compute x%(2^n), for 0 <= n <= 30
 *   Negative arguments should yield negative remainders
 *   Examples: remainderPower2(15L,2L) = 3, remainderPower2(-35L,3L) = -3L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
long remainderPower2(long x, long n) {
    /*
     * Observe:
     * For nonnegative x, return x & (2^n - 1)
     * For negative x and remainder is not 0,
     * return x & (2^n - 1) with upper 32 - n bits set to 1
     */

    long ones = ~0; // All bits are set to 1 or decimal -1

    long remainder_mask = (1L << n) + ones;
    long remainder = x & remainder_mask;

    long sign_mask = x >> 63 << n;
    long remainder_is_not_0_mask = !remainder + ones;

    return (sign_mask & remainder_is_not_0_mask) | remainder;
}
/*
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 63
 *   Examples:
 *      rotateLeft(0x8765432187654321L,4L) = 0x7654321876543218L
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3
 */
long rotateLeft(long x, long n) {
    long high_mask, low_mask; // n-bit-wide masks for high order, low order bits
    long save_bits;  // high order bits to save and rotate onto beginning of x
    long mask_shift; // will hold 64-n, i.e., distance to shift left_mask
    mask_shift = 65L + ~n; // 64-n == 64+(-n) == 64+(~n+1)
    high_mask =
        ~0L << mask_shift;  // used to save high order bits that wrap to front
    low_mask = ~(~0L << n); // n-bit-wide low order mask, for zapping potential
                            // leading 1s after right-shift
    save_bits =
        ((x & high_mask) >> mask_shift) &
        low_mask; // save n high-order bits, move them to right, zap leading 1s
    return (x << n) |
           save_bits; // shift n left, paste in wraparound bits on right
}
/*
 * bitMask - Generate a mask consisting of all 1's
 *   between lowbit and highbit
 *   Examples: bitMask(5L,3L) = 0x38L
 *   Assume 0 <= lowbit < 64, and 0 <= highbit < 64
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
long bitMask(long highbit, long lowbit) {
    long negOne = ~0;
    long highPart = (negOne << highbit) << 1;
    long lowPart = negOne << lowbit;

    return (highPart ^ lowPart) & lowPart;
}
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5L) = 0L, isPower2(8L) = 1L, isPower2(0) = 0L
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
long isPower2(long x) {
    /* if x is negative */
    long ret = 0x8000000000000000L;
    ret = ret & x;
    ret = ret >> 63;
    ret = !ret;
    /* if x is zero */
    long zero = 0x0000000000000000L;
    zero = zero ^ x;
    zero = !!zero;
    /*
     * example: 8 -> 1000
     *          7 -> 0111
     */
    return zero & ret & !(x & (x - 1));
}
// 4
/*
 * allAsciiDigits - return 1 if each byte b in x satisfies
 *   0x30 <= b <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: allAsciiDigits(0x3031323536373839L) = 1L.
 *            allAsciiDigits(0x4031323536373839L) = 0L.
 *            allAsciiDigits(0x0031323536373839L) = 0L.
 *   Legal ops: ! ~ & ^ | << >>
 *   Max ops: 30
 *   Rating: 4
 */
long allAsciiDigits(long x) {
    // 0x3030303030303030L;
    // 0x3131313131313131L;
    // 0x3232323232323232L;
    // 0x3333333333333333L;
    // 0x3434343434343434L;
    // 0x3535353535353535L;
    // 0x3636363636363636L;
    // 0x3737373737373737L;
    // 0x3838383838383838L;
    // 0x3939393939393939L;
    long a = 0x3030303030303030L;
    long b = 0x3131313131313131L;
    long c = 0x3232323232323232L;
    long d = 0x3333333333333333L;
    long e = 0x3434343434343434L;
    long f = 0x3535353535353535L;
    long g = 0x3636363636363636L;
    long h = 0x3737373737373737L;
    long i = 0x3838383838383838L;
    long j = 0x3939393939393939L;

    return !((x ^ a) & (x ^ b) & (x ^ c) & (x ^ d) & (x ^ e) & (x ^ f) &
             (x ^ g) & (x ^ h) & (x ^ i) & (x ^ j));
}
/*
 * trueThreeFourths - multiplies by 3/4 rounding toward 0,
 *   avoiding errors due to overflow
 *   Examples:
 *    trueThreeFourths(11L) = 8
 *    trueThreeFourths(-9L) = -6
 *    trueThreeFourths(4611686018427387904L) = 3458764513820540928L (no
 * overflow) Legal ops: ! ~ & ^ | + << >> Max ops: 20 Rating: 4
 */
long trueThreeFourths(long x) {

    long xl1 = x & 0x3;
    long xl2 = (x & 1L) << 1;
    long mask = x >> ((8 << 3) - 1);
    long biasing = mask & 3;
    long increment = (xl2 + xl1 + biasing) >> 2;
    long division_1 = x >> 1;
    long division_2 = x >> 2;
    return division_1 + division_2 + increment;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5L) = 2, bitCount(7L) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Rating: 4
 */
long bitCount(long x) {
    long mask_1 = 0x5555555555555555L;
    long mask_2 = 0x3333333333333333L;
    long mask_3 = 0x0F0F0F0F0F0F0F0FL;
    long mask_4 = 0x00FF00FF00FF00FFL;
    long mask_5 = 0x0000FFFF0000FFFFL;
    long mask_6 = 0x00000000FFFFFFFFL;

    x = (x & mask_1) + ((x >> 1) & mask_1);
    x = (x & mask_2) + ((x >> 2) & mask_2);
    x = (x & mask_3) + ((x >> 4) & mask_3);
    x = (x & mask_4) + ((x >> 8) & mask_4);
    x = (x & mask_5) + ((x >> 16) & mask_5);
    x = (x & mask_6) + ((x >> 32) & mask_6);
    return x;
}
