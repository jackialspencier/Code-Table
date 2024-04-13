// #include <stdio.h>
// int main(void)
// {
//     int ch;
    
//     while ((ch = getchar()) != EOF)
//         putchar(ch);
    
//     return 0;
// }

//小小好奇一下main里面用main的返回值会怎样
#include <stdio.h>
void guess(void);
int main(void)
{
    guess();

    return 0;
}
void guess(void)
{
    int a;

    a = main();
    printf("%d\n", a);
}