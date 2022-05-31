#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int bar[1000];

void main()
{
unsigned len = 60;
for (int i = 0; i < len + 1; ++i)
{
bar[i] = '#';
}
for (int i = 0; i < len; ++i)
{
printf("progress:[%s]%d%%r", bar+len-i, i+1);
usleep(100000);
}
printf("n");
return 0;
}
