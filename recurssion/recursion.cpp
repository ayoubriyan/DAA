#include<iostream>
using namespace std;
void conv(int n);
int main(){
    // int n=6;
    // int rem;
    // int a[10];
    // int i=0;
    // while(n){
    //     rem=n%2;
    //     n=n/2;
    //     a[i]=rem;
    //     i++;
    // }
    // for(int j=i-1;j>=0;j--){
    //     cout<<a[j];
    // }
    conv(10);
    return 0;
}
void conv(int n){
    if(n==0||n==1){
        cout<<n;
        return;
    }
    conv(n/2);
    cout<<n%2;
}

