#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector<string> v;
    while (1) {
        string op;
        v.clear();
        while (cin>>op){
            if(op=="QUIT") return 0;
            if(op=="END") break;
            if(op=="NUM"){
                string num;
                cin>>num;
                v.push_back(op+num);
            }
            else v.push_back(op);
        }

        int n; cin>>n;
        long long num, tmp1, tmp2;
        for(int i=0; i<n; i++){
            stack<long long> s; int flg=1;
            cin>>num; s.push(num);
            for(int i=0; i<v.size(); i++){
                if(v[i].substr(0,3)=="NUM")
                    s.push(stoi(v[i].substr(3)));
                else if(v[i]=="POP"){
                    if(s.empty()){
                        flg=0; cout<<"ERROR"<<'\n'; break;
                    }
                    else s.pop();
                }
                else if(v[i]=="INV"){
                    if(s.empty()){
                        flg=0; cout<<"ERROR"<<'\n'; break;
                    }
                    tmp1 = s.top(); tmp1*=(-1);
                    s.pop(); s.push(tmp1);
                }
                else if(v[i]=="DUP"){
                    if(s.empty()){
                        flg=0; cout<<"ERROR"<<'\n'; break;
                    }
                    tmp1 = s.top();
                    s.push(tmp1);
                }
                else if(v[i]=="SWP"){
                    if(s.size()<2){
                        flg=0; cout<<"ERROR"<<'\n'; break;
                    }
                    tmp1 = s.top(); s.pop();
                    tmp2 = s.top(); s.pop();
                    s.push(tmp1); s.push(tmp2);
                }
                else if(v[i]=="ADD"){
                    if(s.size()<2){
                        flg=0; cout<<"ERROR"<<'\n'; break;
                    }
                    tmp1 = s.top(); s.pop();
                    tmp2 = s.top(); s.pop();
                    if(1e9<abs(tmp1+tmp2)){
                        flg=0; cout<<"ERROR"<<'\n'; break;
                    }
                    s.push(tmp1+tmp2);
                }
                else if(v[i]=="SUB"){
                    if(s.size()<2){
                        flg=0; cout<<"ERROR"<<'\n'; break;
                    }
                    tmp1 = s.top(); s.pop();
                    tmp2 = s.top(); s.pop();
                    if(1e9<abs(tmp2-tmp1)){
                        flg=0; cout<<"ERROR"<<'\n'; break;
                    }
                    s.push(tmp2-tmp1);
                }
                else if(v[i]=="MUL"){
                    if(s.size()<2){
                        flg=0; cout<<"ERROR"<<'\n'; break;
                    }
                    tmp1 = s.top(); s.pop();
                    tmp2 = s.top(); s.pop();
                    if(1e9<abs(tmp1*tmp2)){
                        flg=0; cout<<"ERROR"<<'\n'; break;
                    }
                    s.push(tmp1*tmp2);
                }
                else if(v[i]=="DIV"){
                    if(s.size()<2){
                        flg=0; cout<<"ERROR"<<'\n'; break;
                    }
                    tmp1 = s.top(); s.pop();
                    if(tmp1==0){
                        flg=0; cout<<"ERROR"<<'\n'; break;
                    }
                    tmp2 = s.top(); s.pop();
                    if(tmp1<0 && tmp2<0){
                        long long res = abs(tmp2)/abs(tmp1);
                        s.push(res);
                    }
                    else if(tmp1<0){
                        long long res = tmp2/abs(tmp1);
                        res*=(-1); s.push(res);
                    }
                    else if(tmp2<0){
                        long long res = abs(tmp2)/tmp1;
                        res*=(-1); s.push(res);
                    }
                    else{
                        long long res = tmp2/tmp1;
                        s.push(res);
                    }
                }
                else if(v[i]=="MOD"){
                    if(s.size()<2){
                        flg=0; cout<<"ERROR"<<'\n'; break;
                    }
                    tmp1 = s.top(); s.pop();
                    if(tmp1==0){
                        flg=0; cout<<"ERROR"<<'\n'; break;
                    }
                    tmp2 = s.top(); s.pop();
                    if(tmp1<0 && tmp2<0){
                        long long res = abs(tmp2)%abs(tmp1);
                        res*=(-1); s.push(res);
                    }
                    else if(tmp1<0){
                        long long res = tmp2%abs(tmp1);
                        s.push(res);
                    }
                    else if(tmp2<0){
                        long long res = abs(tmp2)%tmp1;
                        res*=(-1); s.push(res);
                    }
                    else{
                        long long res = tmp2%tmp1;
                        s.push(res);
                    }
                }
            }
            if(flg){
                if(s.size()!=1) cout << "ERROR" <<'\n';
                else cout << s.top() <<'\n';
            }
        }
        cout <<'\n';
    }
}