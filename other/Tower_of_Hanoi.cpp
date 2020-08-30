#include <iostream>
#include <vector>

void create_tower(std::vector<int>*,int);
void print_tower(std::vector<int>*);
void solve(std::vector<int>*);
void move(std::vector<int>*,int,int);
void move_all(std::vector<int>*,int,int,int);

int main()
{
    std::vector<int>stack[3];
    int length;
    std::cout<<"Enter length of the hanoi tower: ";
    std::cin>>length;
    std::cout<<std::endl;
    create_tower(stack,length);

    std::cout<<"INITIAL STATE"<<std::endl;
    print_tower(stack);

    solve(stack);

    std::cout<<"LAST STATE"<<std::endl;
    print_tower(stack);
}

void solve(std::vector<int>*stack){
    int how_many=stack[0].size();
    if(how_many>0){
        move_all(stack,0,1,how_many-1);
        move(stack,0,2);
        print_tower(stack);
        move_all(stack,1,2,how_many-1);
    }
}

void move_all(std::vector<int>*stack,int from,int to,int how_many){
    if(how_many>0){
        int third_loc=3-from-to;
        move_all(stack,from,third_loc,how_many-1);
        move(stack,from,to);
        print_tower(stack);
        move_all(stack,third_loc,to,how_many-1);
    }
}

void move(std::vector<int>*stack,int a,int b){
    stack[b].push_back(stack[a][stack[a].size()-1]);
    stack[a].pop_back();
}

void create_tower(std::vector<int>*stack,int n){
    for(int i=n;i>0;i--){
        stack[0].push_back(i);
    }
}

void print_tower(std::vector<int>*stack){
    for(int i=0;i<3;i++){
        std::cout<<"stack["<<i<<"]= ";
        for(int hoop:stack[i]){
            std::cout<<hoop<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}