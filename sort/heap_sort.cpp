#include <iostream>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void Heapify(int *arr,int now){
    while(now){
        if(arr[(now-1)/2]<arr[now]){
            swap(arr+(now-1)/2,arr+now);
            now=(now-1)/2;
        }
        else return;
    }
}

void Create_Max_Heap(int *arr,int n,int now){
    if(now==n)return;
    Heapify(arr,now);
    Create_Max_Heap(arr,n,now+1);
}

void print_array(int *arr,int n){
    for(int *i=arr;i<arr+n;i++)std::cout<<*i<<" ";
    std::cout<<std::endl;
}

int main(){
    int n,result;
    std::cin>>n;                           //entering array size and number to be searched in the right order
    int a[n];
    for(int *i=a;i<a+n;i++)std::cin>>*i;     //entering array
    
    Create_Max_Heap(a,n,1);
    swap(a,a+n-1);

    for(int i=n-1;i>1;i--){
        Heapify(a,i,1);
        swap(a,a+i-1);
    }
    print_array(a,n);
    
}


