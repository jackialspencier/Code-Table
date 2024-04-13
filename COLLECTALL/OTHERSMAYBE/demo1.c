#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>
#include <inttypes.h>
#define ONE 1
#define FIFTEEN 15
#define SEVENTY_NINE 79
 
int main() {
    printf("One byte = %d bits on this system.\n\n", CHAR_BIT);
 
    printf("char has a size of %zd byte.\n", sizeof(char));
    printf("Smallest char: %hhd\n", CHAR_MIN);
    printf("Biggest char: %hhd\n", CHAR_MAX);
    printf("Biggest unsigned char: %hhu\n\n", UCHAR_MAX);
 
    printf("short has a size of %zd bytes.\n", sizeof(short));
    printf("Smallest short: %hd\n", SHRT_MIN);
    printf("Biggest short: %hd\n", SHRT_MAX);
    printf("Biggest unsigned short: %hu\n\n", USHRT_MAX);
 
    printf("int has a size of %zd bytes.\n", sizeof(int));
    printf("Smallest int: %d\n", INT_MIN);
    printf("Biggest int: %d\n", INT_MAX);
    printf("Biggest unsigned int: %u\n\n", UINT_MAX);
 
    printf("long has a size of %zd bytes.\n", sizeof(long));
    printf("Smallest long: %ld\n", LONG_MIN);
    printf("Biggest long: %ld\n", LONG_MAX);
    printf("Biggest unsigned long: %lu\n\n", ULONG_MAX);
 
    printf("long long has a size of %zd bytes.\n", sizeof(long long));
    printf("Smallest long long: %lld\n", LLONG_MIN);
    printf("Biggest long long: %lld\n", LLONG_MAX);
    printf("Biggest unsigned long long: %llu\n\n", ULLONG_MAX);
 
 
    printf("float has a size of %zd bytes.\n", sizeof(float));
    printf("float s = %d bit, exp = %d bits, frac = %d bits.\n", ONE, sizeof(float) * CHAR_BIT - FLT_MANT_DIG, FLT_MANT_DIG - 1);
    printf("float min exponent = %d.\n", FLT_MIN_EXP - 1);
    printf("float max exponent = %d.\n", FLT_MAX_EXP - 1);
    printf("float precison = %d digits\n", FLT_DIG);
    printf("float epsilon = %.10E\n", FLT_EPSILON);
    printf("Smallest normal float: %.10E\n", FLT_MIN);
    printf("Largest normal float: %.10E\n\n", FLT_MAX);
 
    printf("double has a size of %zd bytes.\n", sizeof(double));
    printf("double s = %d bit, exp = %d bits, frac = %d bits.\n", ONE, sizeof(double) * CHAR_BIT - DBL_MANT_DIG, DBL_MANT_DIG - 1);
    printf("double min exponent = %d.\n", DBL_MIN_EXP - 1);
    printf("double max exponent = %d.\n", DBL_MAX_EXP - 1);
    printf("double precison = %d digits\n", DBL_DIG);
    printf("double epsilon = %.10lE\n", DBL_EPSILON);
    printf("Smallest double: %.10lE\n", DBL_MIN);
    printf("Largest double: %.10lE\n\n", DBL_MAX);
 
    printf("long double has a size of %zd bytes, but %d useful bits.\n", sizeof(long double), SEVENTY_NINE); // wasteful but useful for some things such as alignment
    printf("long double s = %d bit, exp = %d bits, frac = %d bits.\n", ONE, FIFTEEN, LDBL_MANT_DIG - 1);
    printf("long double min exponent = %d.\n", LDBL_MIN_EXP - 1);
    printf("long double max exponent = %d.\n", LDBL_MAX_EXP - 1);
    printf("long double precison = %d digits\n", LDBL_DIG);
    printf("long double epsilon = %.10LE\n", LDBL_EPSILON);
    printf("Smallest long double: %.10LE\n", LDBL_MIN);
    printf("Largest long double: %.10LE\n\n", LDBL_MAX);
	
    printf("long double +12345.0L = 00000000 00000000 00000000 00000000 00000000 00000000 /0/1000000 00001100/ 1/1000000 11100100 00000000 00000000 00000000 00000000 00000000 00000000\n");
    printf("long double -12345.0L = 00000000 00000000 00000000 00000000 00000000 00000000 /1/1000000 00001100/ 1/1000000 11100100 00000000 00000000 00000000 00000000 00000000 00000000\n");
	
    return 0;
}