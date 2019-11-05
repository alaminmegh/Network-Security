#include<iostream>
#include<math.h>
using namespace std;

int gcd(int a, int b){
    int t;
    while(1){
        t = a%b;
        if(t==0)
            return b;
        a = b;
        b= t;
    }
}

int main(){
    //Two Prime Number
    double p;
    double q;
    cout<<"Enter 1st Prime Number: ";
    cin>>p;
    cout<<"Enter 2nd Prime Number: ";
    cin>>q;

    //Calculate n
    double n = p * q;
    double track;
    //Calculate Phi
    double phi= (p-1)*(q-1);
    double e;
    cout<<"Enter Public Key: ";
    cin>>e;

    while(e < phi){
        track = gcd(e,phi);
        if(track == 1)
            break;
        else
            e++;
    }

    double d1 = 1/e;
    double d =fmod(d1,phi);
    double message;
    cout<<"Enter Your Message: ";
    cin>>message;
    double c = pow(message,e);
    double m = pow(c,d);
    c=fmod(c,n);
    m=fmod(m,n);

    cout<<"Original Message: "<<message;
    cout<<endl<<"1st Prime Number: "<<p;
    cout<<endl<<"2nd Prime Number: "<<q;
    cout<<endl<<"The value of n: "<<n;
    cout<<endl<<"The value of Phi: "<<phi;
    cout<<endl<<"Public Key: "<<e;
    cout<<endl<<"Private Key: "<<d;
    cout<<endl<<"Encrypted message: "<<c;
    cout<<endl<<"Decrypted message: "<<m;
    return 0;
}
