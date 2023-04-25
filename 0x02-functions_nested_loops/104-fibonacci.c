#include <stdio.h>

long long fibonacci(int n, long long* memo);

int main(void)
{
long long memo[100] = { 0 }; 
printf("%lld, %lld", fibonacci(1, memo), fibonacci(2, memo)); 

for (int i = 3; i <= 98; i++) 
{ 
printf(", %lld", fibonacci(i, memo)); 
}

printf("\n");

return (0);
}

long long fibonacci(int n, long long* memo)
{
if (n <= 0) {
return (0);
}
if (n == 1 || n == 2) {
return 1;
}
if (memo[n] != 0) 
{ 
return memo[n];
}
memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo); 
return memo[n];
}
