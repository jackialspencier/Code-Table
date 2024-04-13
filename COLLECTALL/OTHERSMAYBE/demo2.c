#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef unsigned char* byte_pointer;
 
void char_out();
void unsigned_char_out();
void short_out();
void unsigned_short_out();
void int_out();
void unsigned_int_out();
void long_out();
void unsigned_long_out();
void long_long_out();
void unsigned_long_long_out();
void float_out();
void double_out();
void long_double_out();
void print_question();
void switch_data_type(char data_type);
void show_bytes(byte_pointer start, size_t len);
 
int main() {
    print_question();
    char data_type;
    while (scanf("%c", &data_type)) {
        if (data_type == 'q')
            return 0;
        data_type = toupper(data_type);
        printf("Now enter your number: ");
        switch_data_type(data_type);
        print_question();
        while (getchar() != '\n') {}
    }
    return 0;
}
 
void print_question() {
    printf("Please choose a data type:(q to quit)\n");
    printf("1)char      2)unsigned char\n");
    printf("3)short     4)unsigned short\n");
    printf("5)int       6)unsigned int\n");
    printf("7)long      8)unsigned long\n");
    printf("9)long long A)unsigned long long\n");
    printf("B)float     C)double\n");
    printf("D)long double\n\n");
    printf("Enter your data type: ");
}
 
void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    printf("Your number is represented in hexadecimal:\n\n");
    for (i = 0; i < len; i++)
        printf(" %.2X", start[i]);
    printf("\n\n");
}
 
void switch_data_type(char data_type) {
    switch (data_type) {
    case '1':
        char_out();
        break;
    case '2':
        unsigned_char_out();
        break;
    case '3':
        short_out();
        break;
    case '4':
        unsigned_short_out();
        break;
    case '5':
        int_out();
        break;
    case '6':
        unsigned_int_out();
        break;
    case '7':
        long_out();
        break;
    case '8':
        unsigned_long_out();
        break;
    case '9':
        long_long_out();
        break;
    case 'A':
        unsigned_long_long_out();
        break;
    case 'B':
        float_out();
        break;
    case 'C':
        double_out();
        break;
    case 'D':
        long_double_out();
        break;
    default:
        break;
    }
    return;
}
 
void char_out() {
    char number;
    scanf("%hhd", &number);
    show_bytes((byte_pointer)&number, sizeof(char));
}
 
void unsigned_char_out() {
    unsigned char number;
    scanf("%hhu", &number);
    show_bytes((byte_pointer)&number, sizeof(unsigned char));
}
 
void short_out() {
    short number;
    scanf("%hd", &number);
    show_bytes((byte_pointer)&number, sizeof(short));
}
 
void unsigned_short_out() {
    unsigned short number;
    scanf("%hu", &number);
    show_bytes((byte_pointer)&number, sizeof(unsigned short));
}
 
void int_out() {
    int number;
    scanf("%d", &number);
    show_bytes((byte_pointer)&number, sizeof(int));
}
 
void unsigned_int_out() {
    unsigned int number;
    scanf("%u", &number);
    show_bytes((byte_pointer)&number, sizeof(unsigned int));
}
 
void long_out() {
    long number;
    scanf("%ld", &number);
    show_bytes((byte_pointer)&number, sizeof(long));
}
 
void unsigned_long_out() {
    unsigned long number;
    scanf("%lu", &number);
    show_bytes((byte_pointer)&number, sizeof(unsigned long));
}
 
void long_long_out() {
    long long number;
    scanf("%lld", &number);
    show_bytes((byte_pointer)&number, sizeof(long long));
}
 
void unsigned_long_long_out() {
    unsigned long long number;
    scanf("%llu", &number);
    show_bytes((byte_pointer)&number, sizeof(unsigned long long));
}
 
void float_out() {
    float number;
    scanf("%f", &number);
    show_bytes((byte_pointer)&number, sizeof(float));
}
 
void double_out() {
    double number;
    scanf("%lf", &number);
    show_bytes((byte_pointer)&number, sizeof(double));
}
 
void long_double_out() {
    long double number;
    scanf("%Lf", &number);
    show_bytes((byte_pointer)&number, sizeof(long double));
}