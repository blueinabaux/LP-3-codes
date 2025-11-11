#include <bits/stdc++.h>
using namespace std;

void displayArr(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int deterministicPartition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i<j){
        while(arr[i]<= pivot && i<high){
            i++;
        }
        while(arr[j]>=pivot && j>=low+1){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[low], arr[j]);
    return j;
}


int randomizedPartition(vector<int> &arr, int low, int high){
    
    int i=low, j=high;
    int random_index = low + rand() % (high-low+1);
    swap(arr[low], arr[random_index]);
    return deterministicPartition(arr,low,high);
    
}



void quickSort(vector<int> &arr, int low, int high, bool isRandom){

    if(low<high){
        int p_index;

        if(isRandom){
            p_index = randomizedPartition(arr, low, high);
        }
        else{
            p_index = deterministicPartition(arr, low, high);
        }

        quickSort(arr, low, p_index-1, isRandom);
        quickSort(arr, p_index+1, high, isRandom);

    }

}

int main(){

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int> arr;


    while(true){

        cout<<"Enter 1 to insert elements in the array"<<endl;
        cout<<"Enter 2 to perform Quick Sort using Deterministic Partition"<<endl;
        cout<<"Enter 3 to perform Quick Sort using Randomized Partition"<<endl;
        cout<<"Enter 4 to Display the Array"<<endl;
        cout<<"Enter 0 to Exit"<<endl;

        int op;
        cout<<"Enter option: ";
        cin>>op;

        switch (op)
        {
        case 1:{
            arr.resize(n);
            for(int i=0;i<n;i++){
                cout<<"Enter Element "<<i+1<<" : ";
                cin>>arr[i];
            }
            break;
        }

        case 2:{
            quickSort(arr, 0, n-1,false);
            cout<<"Sorting using Deterministic Partition"<<endl;
            break;
        }

        case 3:{
            quickSort(arr, 0, n-1,true);
            cout<<"Sorting using Randomized Partition"<<endl;
            break;
        }

        case 4:
            displayArr(arr);
            break;
        
        case 0:
            cout<<"Exiting..."<<endl;
            return 0;
        
        default:
            break;
        }


    }

    return 0;
}