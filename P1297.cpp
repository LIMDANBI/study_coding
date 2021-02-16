#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int diagonal, height, width; cin>>diagonal>>height>>width;
    double dratio=pow(diagonal,2)/(pow(height,2)+pow(width,2)); dratio=sqrt(dratio);
    height*=dratio; width*=dratio; cout<<height<<" "<<width;
}