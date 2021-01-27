#include<iostream>
using namespace std;
int main(){
    string name[100]; int dd[100]{}, mm[100]{}, yy[100]{}; int n, max=0, min=0; cin>>n;
    for(int i=0; i<n; i++){
        cin>>name[i]>>dd[i]>>mm[i]>>yy[i];
    }
    for(int i=1; i<n; i++){
        if(yy[min]<yy[i]) min=i;
        else if(yy[min]==yy[i]){
            if(mm[min]<mm[i]) min=i;
            else if(mm[min]==mm[i]){
                if(dd[min]<dd[i]) min=i;
            }
        }
        if(yy[i]<yy[max]) max=i;
        else if(yy[max]==yy[i]){
            if(mm[i]<mm[max]) max=i;
            else if(mm[max]==mm[i]){
                if(dd[i]<dd[max]) max=i;
            }
        }
    } 
    cout<<name[min]<<'\n'<<name[max];
}