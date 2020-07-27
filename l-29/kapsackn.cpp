// kapsackn
#include <iostream>
using namespace std;


int maxprofit(int price[],int weigth[],int n,int capacity){

	if(n==0 || capacity==0){
		return 0;
	}

	int inc=0,exc=0;


	if(capacity>=weigth[n-1]){
		inc = price[n-1] + maxprofit(price,weigth,n-1,capacity-weigth[n-1]); 
	}
	exc =  0 +  maxprofit(price,weigth,n-1,capacity);


	return max(inc,exc);

}

int topdow(int price[],int weigth[],int n,int capacity,int dp[][100]){

	if(n==0 || capacity==0){
		dp[n][capacity] = 0;
		return 0;
	}



	if(dp[n][capacity]!=-1){
		return dp[n][capacity];
	}

	int inc=0,exc=0;


	if(capacity>=weigth[n-1]){
		inc = price[n-1] + maxprofit(price,weigth,n-1,capacity-weigth[n-1]); 
	}
	exc =  0 +  maxprofit(price,weigth,n-1,capacity);


	dp[n][capacity] = max(inc,exc);
	return max(inc,exc);

}



int main()
{
	int price[]={10,20,10,15};
	int weigth[]={2,2,3,1};

	int capacity;
	cin>>capacity;

int dp[100][100];
for(int i=0;i<100;i++){
	for(int j=0;j<100;j++){
		dp[i][j]=-1;
	}
}

	int n = 4;
	cout<<maxprofit(price,weigth,n,capacity)<<endl;
	cout<<topdow(price,weigth,n,capacity,dp);
	return 0;
}