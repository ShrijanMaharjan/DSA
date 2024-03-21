#include<iostream>
using namespace std;
int fact(int n){
if(n==0){
return 1;
}else{
return n*fact(n-1);
}
}
int main(){
int num;
cout<<"Enter a non-negative integer to find its factorial:";
cin>>num;
if(num<0){
cout<<"Factorial is not defined for non negative integers:";
}else{
cout<<"Factorial of "<<num<<" is: "<<fact(num);
}
return 0;
}
