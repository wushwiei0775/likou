#include <stdio.h>
#include<time.h>
void swap(int* a ,int* b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
int quick_sort(int a[],int l , int h)
{
    int v,i=l,j=h;
    v = a[l];
    if(l==h)
        {return v;}
    while (l!=h)
    {
        for( ; a[h]>=v&&h>l;h--)
        {}
        if(h>l)
            swap(a+h,a+l);
        for( ; a[l]<=v&&h>l;l++)
        {}
        if(h>l)
            swap(a+h,a+l);
    }
    if(i<l-1)
        quick_sort(a,i,l-1);
    if(l+1<j)
        quick_sort(a,l+1,j);
}

int main()
{
    time_t timep;
    long double seconds1 = time(&timep);
    int iter=0;
    int arr[] = {3,3};

    quick_sort(arr,0,sizeof(arr)/sizeof(int)-1);    
    //注意，第二个参数必须减一，否则超出缓冲区
    
    for(iter=0;iter<sizeof(arr)/sizeof(int);iter++)
        printf("%d\t",arr[iter]);

    return 0;
}










// int main()
// {
//     int number,b=1,c=3;
//     number=b+c;
//     // printf() 输出字符串
//     printf("输入一个整数: ");  
    
//     // scanf() 格式化输入
//    // scanf("%d", &number);  
    
//     // printf() 显示格式化输入
//     printf("你输入的整数是: %d", number);
//     return 0;
// }