// Input:
// s = Geeks
// Output: skeeG

// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}

// } Driver Code Ends


//User function Template for C++

string reverseWord(string str){

//   string s="";

//   for(int i=str.size()-1;i>=0;i--){

//       s+=str[i];

//   }

//   return s;

int i=0,l=str.size()-1;
for(i;i<l;)
{
    swap(str[i],str[l]);
    i++;
    l--;
}
return str;
}