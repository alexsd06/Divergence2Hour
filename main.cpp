#include <iostream>
#include <algorithm> // For remove
#include <string>    // For string
#include <sstream>

#define ll long long

using namespace std;

/*
millis      ....  1000*3600*24
divergence  ....  2000000 (first 7 cifs of divergence)
*/

const ll maxMillis=1000*3600*24;
const ll maxDiverg=2000000;

string padDivergence(string div)
{
    while (div.size()<7) {
        div = "0"+div;
    }
    return div;
}

string padTime(int timp)
{
    string t = to_string(timp);
    while (t.size()<2) {
        t = "0" + t;
    }
    return t;
}

string div2hour (string div)
{
    div.erase(remove(div.begin(), div.end(), '.'), div.end());
    ll divergence=stoi(div);
    ll millis=(divergence*maxMillis)/maxDiverg;
    ll secs=millis/1000;
    int hour = secs / 3600;             // Get the number of hours
    int minute = (secs % 3600) / 60;    // Get the remaining minutes
    int second = secs % 60;
    stringstream ss;
    ss<<padTime(hour)<<":"<<padTime(minute)<<":"<<padTime(second);
    string timp=ss.str();
    return timp;
}

string hour2div (string timp)
{
    stringstream ss(timp);
    char colon;
    int hour, minute, second;
    ss >> hour >> colon >> minute >> colon >> second;
    ll secs = (hour * 3600) + (minute * 60) + second;
    ll millis = secs*1000;
    ll divergance = (millis*maxDiverg)/maxMillis;
    string div = to_string(divergance);
    div=padDivergence(div);
    div.insert(1, ".");
    return div;
}

int main()
{
    cout<<"Welcome to Divergence2Hour!"<<endl;
    cout<<"You can either input the divergence like this: 1.234567..."<<endl;
    cout<<"Or the hour like this: 12:34:56..."<<endl;
    cout<<"Or exit..."<<endl<<endl;
    while (true) {
        string input, rez;
        cout<<"Input: ";
        cin>>input;
        if (input.find('.') != std::string::npos) {
            rez=div2hour(input);
        }
        else if (input.find(':') != std::string::npos){
            rez=hour2div(input);
        }
        else if (input=="exit") {
            return 0;
        }
        cout<<"Output: "<<rez<<endl<<endl;
    }
    return 0;
}
