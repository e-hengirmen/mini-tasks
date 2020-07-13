#include <iostream>

using namespace std;

void merge_sort(int *arr,int n){
    if(n==2){             
        if(arr[0]<arr[1]){
            return;
        }
        int x=arr[0];
        arr[0]=arr[1];
        arr[1]=x;
    }
    else if(n<=1){
        return;
    }
    else{
        merge_sort(arr,n/2);
        merge_sort(arr+n/2,n-n/2);
        int arr2[n],*p,*p1=arr,*p2=arr+n/2;
        p=arr2;
        for(;p1<arr+n/2&&p2<arr+n;p++){
            if(*p1<*p2){
                *p=*p1;
                p1++;
            }
            else{
                *p=*p2;
                p2++;
            }
        }
        for(;p1<arr+n/2;p1++,p++){
            *p=*p1;
        }
        for(;p2<arr+n;p2++,p++){
            *p=*p2;
        }

        p1=arr;
        p2=arr2;
        for(;p1<arr+n;p1++,p2++){
            *p1=*p2;
        }

    }
}

void print_array(int *arr,int n){
    for(int *i=arr;i<arr+n;i++)cout<<*i<<" ";
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    int array[n];
    for(int *i=array;i<array+n;i++)cin>>*i;
    merge_sort(array,n);
    print_array(array,n);
}