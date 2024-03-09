#pragma once
int gcd(int a,int b){
    int temp;
    while(a>0){
        temp=b%a;
        b = a;
        a = temp;
    }
    return b;
}