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

int knapsack(vector<int> &weight, vector<int> &profit, int W, vector<int> &selectedItems){

    int n = weight.size();

    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i=1;i<=n;i++){
        for(int w=1;w<=W;w++){
            if(weight[i-1] <= w){
                dp[i][w] = max(dp[i][w], profit[i-1]+dp[i-1][w-weight[i-1]]);
            }
            else{
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    printTable(dp, n, W);

    int maxProfit = dp[n][W];

    int w = W;
    for(int i=n;i>=1 && maxProfit>0;i--){
        if(maxProfit != dp[i-1][w]){
            selectedItems.push_back(i);
            maxProfit -= profit[i-1];
            w -= weight[i-1];
        }
    }

    return dp[n][W];

}

int main(){

    while(true){
        cout<<"Enter 1 to perform 0/1 Knapsack problem"<<endl;
        cout<<"Enter 0 to Exit"<<endl;

        int op;
        cout<<"Enter option: ";
        cin>>op;

        switch (op)
        {
        case 1:{
            int n;
            cout<<"Enter the number of items: ";
            cin>>n;

            vector<int> weight(n), profit(n);
            for(int i=0;i<n;i++){
                cout<<"Enter the weight of item "<<i+1<<" : ";
                cin>>weight[i];
                cout<<"Enter the profit of item "<<i+1<<" : ";
                cin>>profit[i];
                cout<<endl;
            }

            int W;
            cout<<"Enter the max weight of Knapsack: ";
            cin>>W;

            vector<int> selectedItems;
            int res = knapsack(weight, profit, W, selectedItems);
            cout<<endl;

            cout<<"Result of 0/1 Knapsack (Max profit): "<<res<<endl;

            cout<<"Selected Items: "<<endl;

            for(auto x: selectedItems){
                cout<<x<<" ";
            }
            cout<<endl;

            break;
        }
            
        case 0:
            cout<<"Exiting..."<<endl;
            return 0;
        default:
            break;
        }

    }

    return 0;
}