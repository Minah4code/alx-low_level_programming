#include <stdio.h>

/*
 * This program demonstrates the use of pointers in C.
 * The main function declares an integer variable called 'n',
 * an integer array called 'a' with a size of 5, and an integer
 * pointer variable called 'p'. It assigns the value 1024 to
 * the third element of the 'a' array, and assigns the memory
 * address of the 'n' variable to the 'p' pointer variable.
 * It then assigns the value 98 to the memory location pointed
 * to by the 'p' pointer variable, which is the memory location
 * of the 'n' variable. Finally, it prints the value of the
 * third element of the 'a' array, which is 1024.
 */
int (void)
{
int n;
int a[5];
int *p;

a[2] = 1024;
p = &n;
*p = 98;

printf("a[2] = %d\n", a[2]);

return (0);
}
