#include <iostream>

/*this implementation uses an array instead of data structures because this is more efficient*/

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void Heapify(int *arr,int now){             //this function places the new number on the right place of max heap
    while(now){
        if(arr[(now-1)/2]<arr[now]){
            swap(arr+(now-1)/2,arr+now);
            now=(now-1)/2;
        }
        else return;
    }
}

//Create Max Heap function inserts elements one by one to an empty heap
void Create_Max_Heap(int *arr,int n){ 
    for(int i=1;i<n;i++){
        Heapify(arr,i);
    }
}

void print_array(int *arr,int n){
    for(int *i=arr;i<arr+n;i++)std::cout<<*i<<" ";
    std::cout<<std::endl;
}

int main(){
    int n,result;
    std::cin>>n;                            //entering array size and number to be searched in the right order
    int a[n];
    for(int *i=a;i<a+n;i++)std::cin>>*i;    //entering array
    
    Create_Max_Heap(a,n);
    swap(a,a+n-1);

    /*after creating max heap we are sorting the array 
    by putting the biggest number in the heap to last place,
    reducing its size by one and heapifying it again until the heap is gone*/
    for(int i=n-1;i>1;i--){   
        Heapify(a,i,1);
        swap(a,a+i-1);
    }


    print_array(a,n);
    
}


