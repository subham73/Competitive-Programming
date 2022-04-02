#include<bits/stdc++.h>
using namespace std;

//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;

#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define pb 				push_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				make_pair
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

void sj07(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}

int maxSmallest(vector<int>v, int n, int x){
	int l = -1;
	int r = n;
	while(l+1 < r){
		int mid = l + (r-l)/2;
		if(x > v[mid])
			l = mid;
		else
			r = mid;
	}
	return l;
}
int minLargest(vector<int>v, int n, int x){
	int l =-1;
	int r = n;
	while(l+1 < r){
		int mid = l + (r-l)/2;
		if(x >= v[mid])
			l = mid;
		else
			r = mid;
	}
	return r;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	sj07();//jom 

		int n;
		cin >> n;
		vector<int>v(n);
		loop(i, 0, n-1)
			cin >> v[i];
		sort(v.begin(), v.end());
		// loop(i, 0, n-1)
		// 	cout << v[i]<<" ";
		// cout << endl;
		int k;
		cin >> k;
		while(k--){
			int l, r;
			cin >> l >> r;
			int x = maxSmallest(v, n, l);
			int y = minLargest(v, n, r);
			// cout <<x <<"  " <<y<<" ";
			cout << y-x-1 <<" ";
		}



	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}