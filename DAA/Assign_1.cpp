#include <bits/stdc++.h>
using namespace std;


int fibRec(int n){
    if(n<0){
        return -1;
    }

    if(n==0 || n==1){
        return n;
    }
    else{
        return fibRec(n-1) + fibRec(n-2);
    }
}

int fibIter(int n){
    if(n<0){
        return -1;
    }
    if(n==0 || n==1){
        return n;
    }
    
    int a=0, b=1;
    int c;
    for(int i=2;i<=n;i++){
        c = a+b;
        a = b;
        b = c;
    }

    return  b;
}

void printFibonacci(int n){

    if(n<0){
        cout<<"Enter positive number"<<endl;
        return;
    }
    if(n==0 || n==1){
        cout<<n<<" ";
        return;
    }

    int a = 0, b=1;
    int c;
    cout<<a<<" "<<b<<" ";
    for(int i=2;i<=n;i++){
        c = a+b;
        cout<<c<<" ";
        a = b;
        b = c;
    }
    cout<<endl;

}



int main(){

    while(true){
        cout<<"Enter 1 to print nth Fibonacci number using recursion "<<endl;
        cout<<"Enter 2 to print nth Fibonacci number using iteration "<<endl;
        cout<<"Enter 3 to print Fibonacci Series"<<endl;
        cout<<"Enter 0 to Exit"<<endl;


        int op;
        cout<<"Enter option: ";
        cin>>op;

        if(op==1){
            int n1;
            cout<<"Enter the value of n: ";
            cin>>n1;
            int res = fibRec(n1);
            cout<< n1 <<"th Fibonacci number using recursion: "<< res <<endl;

        }
        else if(op==2){
            int n2;
            cout<<"Enter the value of n: ";
            cin>>n2;
            int res = fibIter(n2);
            cout<< n2 <<"th Fibonacci number using iteration: "<< res <<endl;

        }
        else if(op==3){
            int n3;
            cout<<"Enter the value of n: ";
            cin>>n3;
            printFibonacci(n3);
        }
        else if(op==0){
            cout<<"Exiting..."<<endl;
            break;
        }
        else{
            cout<<"Invalid option"<<endl;
        }



    }

    return 0;
}