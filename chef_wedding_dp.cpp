#include<bits/stdc++.h>
using namespace std;

int cost(int s, int n, int k, vector<int> &family, vector<int> &dp)
{
    if(s == n) return 0;
    if(dp[s] != -1)    return dp[s];

    int min_cost= INT_MAX, result= 0, t_cost=0;
    map<int, int> same;

    for(int i= s; i<n; i++)
    {

        if(same.insert(make_pair(family[i],1)).second == 0) 
        {
            same[family[i]]++;
            if(same[family[i]] == 2) t_cost+=2;
            else t_cost++;
            //cout<<"/";
        }

        result = t_cost + k + cost(i+1, n, k, family, dp);
        min_cost= min(min_cost, result);
    }

    dp[s] = min_cost;
    return min_cost;
}

int main()
{
    int T=0, n=0, k=0, f=0, result=0;
    cin>>T;
    while(T!=0)
    {
        cin>>n;
        cin>>k;
        vector<int> family;
        vector<int> dp(n,-1);

        int temp= n;
        while(temp--)
        {
            scanf("%d",&f);
            family.push_back(f);
        }

        result = cost(0, n, k,  family, dp);

        cout<<result<<endl;

        T--;
    }
    return 0;
}