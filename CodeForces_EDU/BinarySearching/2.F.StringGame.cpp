#include <bits/stdc++.h>

#define MOD  (int)(1e9+7)
#define SIZE (int)(1e5+5)
#define all(x) x.begin(),x.end()
#define lb     lower_bound
#define ub     upper_bound
#define pb     push_back
#define F      first
#define S      second
using namespace std;

vector<int> arr;
bool check(string s,string t,int mid)
{
  for(int i=0;i<=mid;i++)
    s[arr[i]]='@';
	// cout << s<< endl;
  //int match = 0;
  int ind=0;
  for(int i=0;i<s.size();i++)
  {
    if(t[ind] == s[i] )
    {
      ind++;
      if(ind == t.size())
        return true;
    }  
  }
  return false; 
}
 
int main()
{
  // IOfast;
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
  #endif   
  

   string s,t;
   cin>>s>>t;
   arr.resize(s.size());
   for(int i=0;i<s.size();i++) cin>>arr[i],arr[i]--;
     
	int del=0;
	int i=0;
	int start =0 ,end = arr.size() - 1;  

	while(start<=end)
	{
		int mid = (start+end)/2;
		if(check(s,t,mid) == true){
			del = mid+1;
			start = mid+1; 
		}
		else
			end = mid-1;
		// cout << start << "  "<< end << endl;
	}
	cout<<start;

  
  #ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
  #endif  
  
  return 0;
}