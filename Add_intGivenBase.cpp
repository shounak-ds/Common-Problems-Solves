#include<bits/stdc++.h>

using namespace std;

//works for base<=10;
int main()
{
    int one=223;           //Integer 1
    int two=773;          //Integer 2
    int base=8;          //Base
    int sum=0;
    int carry=0;
    int bitone=0;
    int bittwo=0;
    int bitsum=0;
    int n=1;
    int lastbitcarry=1;

    cout<<"Sum of "<<one<<" and "<<two<<" is:"<<endl;

    while((one!=0 || two!=0)|| lastbitcarry==1)
    {
        bitone=one%10;
        bittwo=two%10;
        bitsum=bitone+bittwo+carry;
        carry=0;
        if(bitone>=base ||bittwo >=base)
        {
            cout<<"Error in base";
            getchar();
            exit(0);
        }
        else if(bitsum>=base) 
        {
            carry=1;
            bitsum= bitsum- base;
        }
        sum+= bitsum*n;
        n*=10;
        one/=10;
        two/=10;
        if(one==0 && two==0 && carry==0)
        {
            lastbitcarry=0;
        }
    }

    cout<<sum<<endl;

    return 1;

}