#include <iostream>
#include <string.h>
using namespace std;

string add(string str1, string str2){
    string ans=""; int idx1= str1.size()-1, idx2=str2.size()-1, tmp=0, carry=0;
    while (idx1>=0 && idx2>=0){
        tmp = (str1.at(idx1)-48) + (str2.at(idx2)-48) + carry; carry=0;
        if(tmp>9){
            ans.insert(0, to_string((tmp+carry)%10)); carry=1;
        }
        else ans.insert(0, to_string(tmp+carry));
        idx1--; idx2--;
    }
    if(idx1<0){
        while (idx2>=0){
            tmp = carry + (str2.at(idx2)-48); carry=0;
            if(tmp>9){
                ans.insert(0, to_string((tmp+carry)%10)); carry=1;
            }
            else ans.insert(0, to_string(tmp+carry));
            idx2--;
        }
    }
    else if(idx2<0){
        while (idx1>=0){
            tmp = carry + (str1.at(idx1)-48); carry=0;
            if(tmp>9){
                ans.insert(0, to_string((tmp+carry)%10)); carry=1;
            }
            else ans.insert(0, to_string(tmp+carry));
            idx1--;
        }
    }
    if(carry!=0) ans.insert(0, to_string(carry));
    return ans;
}

int main() {
    string a,b;
    cin >> a >> b;
    cout << add(a,b);
}