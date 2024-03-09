#pragma once
#include<vector>
#include<map>
#include<exception>
#include<string>
#include "utils.h"
#include<iostream>
#include "NSGP2.cpp"
using namespace std;

//on adding c to an NSGP2
class NSGP3{
    public:
    int a,b,c,Frobenius,genus,Delta,s;
    vector<int> apery_a;
    NSGP3(NSGP2 S1,int c){
        this->a = S1.a;
        this->b = S1.b;
        this->c = c;
        if(c<2){
            throw "Not those c!! Please anything but those c.";
        }
        apery_a = vector(S1.apery_a);
        genus = S1.genus;
        Delta=0;
        reduce_apery();
    }
    void reduce_apery(){
        if(c>apery_a[c%a]){
            throw to_string(c)+" is not in gap(<"+to_string(a)+", "+to_string(b)+">).";
        }
        if(a%c==0){
            throw to_string(a)+" is not in gap(<"+to_string(c)+">).";
        }
        for(int i=1,c_i=c;i<a;i++,c_i+=c){
            if((c-b*i)%a==0)s=i;
            if((c_i-b)%a==0 && c_i<=b)
            throw to_string(b)+" is not in gap(<"+to_string(a)+", "+to_string(c)+">).";
            for(int j=0;j<a;j++){
                if(c_i+b*j<apery_a[(c_i+b*j)%a]){
                    Delta += (apery_a[(c_i+b*j)%a]-(c_i+b*j))/a;
                    apery_a[(c_i+b*j)%a] = c_i+b*j;
                }
                else break;
            }
        }
        Frobenius=-1;
        for(int i=0;i<a;i++){
            if(apery_a[i]>Frobenius+a){
                Frobenius = apery_a[i]-a;
            }
        }
        genus-=Delta;
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

ostream &operator<<(ostream &out,NSGP3 &S){
    out<<"a: "<<S.a<<"\tb: "<<S.b<<"\tc: "<<S.c<<endl;
    out<<"Frobenius: "<<S.Frobenius<<"\tgenus: "<<S.genus<<endl;
    out<<"{ ";
    for(int i=0;i<S.Frobenius;i++){
        if(i>=S.apery_a[i%S.a])
        out<<i<<", ";
    }
    return out<<(S.Frobenius+1)<<", -> }";
}
