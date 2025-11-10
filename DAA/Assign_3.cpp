#include <bits/stdc++.h>
using namespace std;

void printTable(vector<vector<int>> &dp, int n, int W){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            cout<<setw(3)<<dp[i][j];
        }
        cout<<endl;
    }
}

int knapsack(vector<int>  &weights,vector<int> &profits,int W, vector<int> &selectedItems){

    int n = weights.size();

    vector<vector<int>>dp(n+1, vector<int>(W+1, 0));
    
    for(int i=1;i<=n;i++){
        for(int w = 1;w<=W;w++){
            if(weights[i-1] <= w){
                dp[i][w] = max(dp[i-1][w], profits[i-1]+dp[i-1][w-weights[i-1]]);
            }
            else{
                dp[i][w] = dp[i-1][w];
            }
        }

    }

    printTable(dp, n, W);

    int maxProfit = dp[n][W];

    int w= W;
    for(int i=n;i>=0 && maxProfit>0 ;i--){
        if(maxProfit != dp[i-1][w]){
            selectedItems.push_back(i);
            maxProfit -=  profits[i-1];
            w-=weights[i-1];
        }
    }

    return dp[n][W];

}

int main(){

    while(true){
        cout<<"Enter 1 to perform 0/1 knapsack problem"<<endl;
        cout<<"Enter 0 to exit"<<endl;

        int op;
        cout<<"Enter option: ";
        cin>>op;

        switch (op)
        {
        case 1:
            int n;
            cout<<"Enter the number of items: ";
            cin>>n;

            vector<int> weights(n), profits(n);
            for(int i=0;i<n;i++){
                cout<<"Enter the weight of"<< i+1 << "item: ";
                cin>>weights[i];
                cout<<endl;
                cout<<"Enter the price of"<< i+1 << "item: ";
                cin>>profits[i];
            }

            // max weight
            int W;
            cout<<"Enter the max weight of Knapsack: ";
            cin>>W;

            vector<int> selectedItems;

            int res = knapsack(weights, profits, W, selectedItems);
            cout<<endl;
            cout<<"Result of 0/1 Knapsack (Max profit): "<<res<<endl;

            cout<<"Selected Items: "<<endl;

            for(auto x: selectedItems){
                cout<<x<<" ";
            }
            cout<<endl;

            break;
        case 0:
            cout<<"Exiting..."<<endl;
    
            break;

        default:
        cout<<"Invalid option"<<endl;
            break;
        }
    }

    return 0;
}