#pragma once
#include<vector>
#include<map>
#include<exception>
#include<string>
#include<numeric>
#include<iostream>
using namespace std;

class NSGP2{
    public:
    int a,b,Frobenius,genus;
    vector<int> apery_a;
    NSGP2(int a1,int b1){
        if(gcd(a,b)>1){
            throw (to_string(a)+" "+to_string(b)+" do not generate a numerical semigroup.");
        }
        this->a = min(a,b);
        this->b = max(a,b);
        apery_a=vector<int>(a,0);
        for(int i=1;i<a;i++){
            apery_a[(b*i)%a]=b*i;
        }
        Frobenius = a*b-a-b;
        genus = ((a-1)*(b-1))/2;
    }
    void print_gap(ostream &out=cout){
        for(int i=1;i<a;i++){
            int M=apery_a[(b*i)%a];
            while(M>a){
                M-=a;
                out<<M<<", ";
            }
            out<<endl;
        }
    }
};
ostream &operator<<(ostream &out,NSGP2 &S){
    out<<"a: "<<S.a<<"\tb: "<<S.b<<endl;
    out<<"Frobenius: "<<S.Frobenius<<"\tgenus: "<<S.genus<<endl;
    out<<"{ ";
    for(int i=0;i<S.Frobenius;i++){
        if(i>=S.apery_a[i%S.a])
        out<<i<<", ";
    }
    return out<<(S.Frobenius+1)<<", -> }";
}