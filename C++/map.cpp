#include <iostream>
#include <map>
#include <cassert>
#include <string>
using namespace std;

int main() {
    map<string, string> dict;

    dict["car"] = "vioture";
    dict["hello"] = "bonjour";
    dict["apple"] = "pomme";

    cout << "Printing simple dictionary" << endl;

    for(auto it : dict) {
        cout << it.first << ":\t" << it.second << endl;
    }

    multimap<string, string> mdict;

    mdict.insert(make_pair("car", "voiture"));
    mdict.insert(make_pair("car", "auto"));
    mdict.insert(make_pair("car", "wagon"));
    mdict.insert(make_pair("hello", "bonjour"));
    mdict.insert(make_pair("apple", "pomme"));

    cout << "\nPrinting all defs of \"car\"" << endl;

    for(multimap<string, string>::const_iterator it = mdict.lower_bound("car"); it != mdict.upper_bound("car"); it++) {
        cout << (*it).first << ": " << (*it).second << endl;        
    }
}