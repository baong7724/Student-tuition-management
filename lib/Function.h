#pragma once
#include<bits/stdc++.h>
using namespace std;
void printLine(int n)
{
    cout<< endl;
    for (int i = 1; i <= n; i++) {
        cout << "_";
    }
    cout << endl;
}
string ChuanHoa(string name)
{
	stringstream ss(name);
	string res="";
	string token;
	while(ss>>token)
	{
		res+=toupper(token[0]);
		for(int i=1;i<=token.length();i++)
			res+=tolower(token[i]);
		res+=" ";
	}
	res.erase(res.length()-1);
	return res;
}