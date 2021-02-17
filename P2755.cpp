#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int subjectN; cin>>subjectN; double ans, totalcredit=0;
    while (subjectN--){ cout<<fixed; cout.precision(2);
        string subject, grade; int credit; cin>>subject>>credit>>grade; totalcredit+=credit;
        if(grade=="A+") ans+=credit*4.3; else if(grade=="A0") ans+=credit*4.0; else if(grade=="A-") ans+=credit*3.7;
        else if(grade=="B+") ans+=credit*3.3; else if(grade=="B0") ans+=credit*3.0; else if(grade=="B-") ans+=credit*2.7;
        else if(grade=="C+") ans+=credit*2.3; else if(grade=="C0") ans+=credit*2.0; else if(grade=="C-") ans+=credit*1.7;
        else if(grade=="D+") ans+=credit*1.3; else if(grade=="D0") ans+=credit*1.0; else if(grade=="D-") ans+=credit*0.7;
    } ans/=totalcredit; cout << round(ans * 100)/100;
}