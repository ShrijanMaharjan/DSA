#include<iostream>
using namespace std;
int gcd(int a,int b){
if(b==0){
return a;
}else{
return gcd(b,a%b);
}
}
int main(){
int num1,num2;
cout<<"Enter two numbers to find their GCD:";
cin>>num1>>num2;
if(num1<0||num2<0){
cout<<"GCD is not defined for negative numbrs.";
}else{
cout<<"GCD of "<<num1<<" and "<<num2<<" is: "<<gcd(num1,num2);
}
return 0;
}
