#include <iostream>
#include <algorithm>

int Iterative_Binary_Search(int *arr,int n,int k){
    int *lower=arr,*upper=arr+n-1,*middle=arr+n/2;
    while(lower<upper){
        if(k==*middle)return middle-arr+1;
        else if(k<*middle){
            upper=middle-1;
            middle=lower+(upper-lower+1)/2;
        }
        else{
            lower=middle+1;
            middle=lower+(upper-lower+1)/2;
        }
    }
    if(k==*lower)return lower-arr+1;
    return -1;

}



int main(){
    int n,k,result,sum=0;
    std::cin>>n>>k;                             //entering array size and number to be searched in the right order
    int a[n];
    for(int *i=a;i<a+n;i++)std::cin>>*i;     //entering array
    std::sort(a,a+n);                        //sorting using STL libraries because this implementation is about searching
    result=Iterative_Binary_Search(a,n,k);
    if(result==-1)std::cout<<"The array does not contain "<<k<<std::endl;
    else std::cout<<k<<" is in position "<<result<<std::endl;
}