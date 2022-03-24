#include <stdio.h>
#include <stdlib.h>

double fibo(int max)
{
    if (max==0)
        return 0;
    else if (max==1)
        return 1;
    else
        return fibo(max-1)+fibo(max-2);

}

int main()
{
    int max;

    printf("Digite o n-esimo\n");
    scanf("%d",&max);
    printf("%.0f",fibo(max));
    return 0;
}

