#include <iostream>

using namespace std;

void swap(int *p1,int *p2){
    int temp=*p1;
    *p1=*p2;
    *p2=temp;
}

void quick_sort(int *arr,int n){
   if(n<=1){
       return;
   }
   else if(n==2){             //if array size is 2 swap if neccessary
        if(arr[0]<arr[1]){
            return;
        }
        swap(arr,arr+1);
    }
    else{
	//reshape the array so that 
	//every number that is smaller then the separator is on the left side of the separator
	//and every number that is bigger then the separator is on the right side of the separator
        int *separator=arr+n-1,*p;
        for(p=arr;p<separator;){	
            if(*p<=*separator){
                p++;
            }
            else{
                if(p+1==separator){
                    swap(p,separator);
                    separator--;
                }
                else{
                    int temp=*separator;
                    *separator=*p;
                    *p=*(separator-1);
                    *(separator-1)=temp;
                    separator--;
                }
            }
        }
        p++;
        quick_sort(arr,separator-arr);		//sort left half of the array recursively
        quick_sort(p,n-(separator-arr)-1);	//sort right half of the array recursively
    }
}

void print_array(int *arr,int n){
    for(int *i=arr;i<arr+n;i++)cout<<*i<<" ";
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;					//enter array size
    int array[n];
    for(int *i=array;i<array+n;i++)cin>>*i;	//enter array
    quick_sort(array,n);
    print_array(array,n);
}
