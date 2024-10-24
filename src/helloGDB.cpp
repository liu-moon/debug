#include <stdio.h>

int helloGDB(int i){
    if (i > 4)
    {
        printf("Hello GDB\n");
    }
}

int main()
{
    helloGDB(5);
    helloGDB(6);

    helloGDB(2);

    return 0;
}