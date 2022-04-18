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
string S;
ll nb, ns, nc;
ll pb, ps, pc;
ll rs;
ll b, s, c;
bool good(ll x){

	ll expected_b = b * x, expected_s = s * x, expected_c = c * x;

	ll req_b = (expected_b - nb < 0)? 0 :  expected_b - nb;
	ll req_s = (expected_s - ns < 0)? 0 :  expected_s - ns;
	ll req_c = (expected_c - nc < 0)? 0 :  expected_c - nc;

	ll req_rs = req_b*pb + req_s*ps + req_c*pc;
	
	return req_rs <= rs;
}
int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	sj07();//jom 

	cin >> S;
	cin >> nb >> ns >> nc;
	cin >> pb >> ps >> pc;
	cin >> rs;


	b = count(S.begin(), S.end(), 'B');
	s = count(S.begin(), S.end(), 'S');
	c = count(S.begin(), S.end(), 'C');

	ll l = 0, r = 2*1e12;

	while(l+1 < r){
		ll mid = l+(r-l)/2;

		if(good(mid))
			l = mid;
		else
			r = mid;
	}

 	cout << l;



	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
