#include <iostream>
#include <algorithm>

int Binary_Search(int *arr,int n,int k){
    int x=arr[n/2];
    if(n==1){
        if(*arr==k)return 1;
        else return -1;                     //-1 means that this array does not have searched number
    }
    if(n<1){
        return -1;
    }
    if(k==x){
        return n/2+1;
    }
    else if(k<x){                           
        int y=Binary_Search(arr,n/2,k);
        if(y==-1)return -1;
        return y;
        
    }
    else{
        int y=Binary_Search(arr+n/2+1,n-n/2-1,k);
        if(y==-1)return -1;
        return n/2+1+y;

    }

}



int main(){
    int n,k,result;
    std::cin>>n>>k;                           //entering array size and number to be searched in the right order
    int a[n];
    for(int *i=a;i<a+n;i++)std::cin>>*i;     //entering array
    std::sort(a,a+n);                        //sorting using STL libraries because this implementation is about searching
    result=Binary_Search(a,n,k);
    if(result==-1)std::cout<<"The array does not contain "<<k<<std::endl;
    else std::cout<<k<<" is in position "<<result<<std::endl;
}