
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
//交换数组的元素
int swap_array_value(int *a,int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/*QuickSort*/
//注意，该函数使用了递归，请小心你的堆栈空间的大小、空间复杂度dd
int quick_sort(int left,int right,int arr[])
{
    int i = left;        //记录需要排序的区间范围
    int j = right;
    int base = left;     //记录基准数的索引位置，这里选择第一个元素作为基准
    int base_value;      //准备记录基准数的值

    if(NULL == arr){     //参数安全检测
        return -1;
    }

    if(i >= j){          //递归结束条件：当左迭代器越过右迭代器时，表明本段排序已完成
        return 1;
    }

    base_value = arr[base];     //(在每一次递归的数组中)取得基准数值

    while(i != j)   //左右两侧的'哨兵'相遇的时候，停止，因为此时已经成功令基准就位
    {
        for(;arr[j] >= base_value && i < j;--j);    //让非基准一侧的哨兵先走
        for(;arr[i] <= base_value && i < j;++i);    //注意判断条件，不能让基准一侧的哨兵越过了另一侧的哨兵
        //由上两个for的条件限定，i是不可能大于j的，但是可能会等于j,因此这里需要判断
        if(i < j){   
            swap_array_value(arr+i,arr+j);      
        //当i!=j的时候才交换i和j,i和j相等的时候交换基准和i(当然因为这个时候i==j，所以交换基准和j也是ok的)
        }       /*跳出while循环，此时i == j*/
    }
   
    /*将基准放到它应该在的位置，将基准与i做交换*/
    swap_array_value(arr+base,arr+i);
    /*可以实现同样的交换功能的代码：*/
    //arr[base] = arr[i];
    //arr[i] = base_value;
    /*相同：*/
    //swap_array_value(arr+base,arr+j);

    //递归，将基准左侧的所有元素作为一个新的范围再进行一次步骤相同的快速排序
    quick_sort(left,i-1,arr);    //注意，此时基准的位置就是i的位置，不再是base了下修改
    quick_sort(i+1,right,arr);

    return 0;
}

int main(int argc,char *argv[])
{
    time_t timep;
    long double seconds1 = time(&timep);
    int iter=0;
    int arr[] = {6,1,2,7,9,3,4,5,10,8};

    quick_sort(0,sizeof(arr)/sizeof(int)-1,arr);    
    //注意，第二个参数必须减一，否则超出缓冲区
    for(iter=0;iter<sizeof(arr)/sizeof(int);++iter)
        printf("%d\t",arr[iter]);
    long double seconds2 = time(&timep);
    printf("%e\t",seconds2-seconds1);
    return 0;
}
