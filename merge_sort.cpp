#include <iostream>

using namespace std;

void merge_sort(int *arr,int n){
    if(n==2){             	//if array size is 2 swap if neccessary
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
        merge_sort(arr,n/2);			//sort first half of the array recursively
        merge_sort(arr+n/2,n-n/2);		//sort second half of the array recursively
        int arr2[n],*p,*p1=arr,*p2=arr+n/2;
        p=arr2;

	/*from this point on combine first part and second part of the array to arr2 sequentially
	*/

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
	
	//after this point transfer the array from arr2 to our main array

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
    cin>>n;					//enter array size
    int array[n];
    for(int *i=array;i<array+n;i++)cin>>*i;	//enter array
    merge_sort(array,n);
    print_array(array,n);
}
