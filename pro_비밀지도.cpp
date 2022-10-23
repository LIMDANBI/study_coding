#include <string>
#include <vector>
#include <iostream>
using namespace std;

string get_str(int num, int n){
    string res = "";
    while (num){
        res = to_string(num%2) + res;
        num/=2;
    }
    while(res.size()<n) res = "0" + res;
    return res;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i=0; i<n; i++){
        string m1 = get_str(arr1[i], n);
        string m2 = get_str(arr2[i], n);

        string res = "";
        for(int j=0; j<n; j++){
            if(m1[j]=='1' || m2[j]=='1') res+='#';
            else res+=' ';
        }
        answer.push_back(res);
    }
    return answer;
}