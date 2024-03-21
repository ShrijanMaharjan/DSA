#include<iostream>
#include<math.h>
using namespace std;


int hanoi(int n, char Source, char Dest, char temp){

if(n == 0){
return 1;
}
hanoi(n-1,Source,temp,Dest);

cout<<"Moved disk "<<n<<" from "<<Source<<" to "<<Dest<<endl;
hanoi(n-1,temp,Dest,Source);
}
int main(){
int a;
cout<<"Enter the number of disks: ";
cin>>a;
int steps = pow(2,a) -1 ;
cout<<"For "<<a<<" disks we have "<<steps<<" steps"<<endl;
hanoi(a,'S','T','D');
return 0;
}
