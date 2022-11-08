#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int month, day; 
    cin >> day >> month;

    string DayOfWeek[] = {"Wednesday", "Thursday", "Friday", "Saturday", "Sunday",  "Monday", "Tuesday"};
    int daysOfMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sumOfDay = day;
    for(int i=0; i<month-1; i++) sumOfDay+=daysOfMonth[i];
    
    sumOfDay%=7;
    cout << DayOfWeek[sumOfDay];
}