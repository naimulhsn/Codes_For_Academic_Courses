********************************************************************************

                      //  Algorithm Lab Exam Code in C++   //

******************************************************************************

                   //   Dynamic Programming   //


1. Longest Common Subsequence

int N = 100;
string s, t;

int dp[N][N];
pii par[N][N];

int lcs(int n, int m) {
    if(n == -1 || m == -1) return 0;
    if(dp[n][m] != -1) return dp[n][m];
    if(s[n] == t[m]) {
    	 par[n][m] = {n - 1, m - 1};
    	 return dp[n][m] = 1 + lcs(n - 1, m - 1);
    }
    int l = lcs(n, m -1), u = lcs(n - 1, m);
    if(l > u) {
         par[n][m] = {n, m - 1};
         return dp[n][m] = l;
    }
    else {
    	 par[n][m] = {n - 1, m};
         return dp[n][m] = u;
    }
}

void path(int n, int m) {
     if(n == -1 || m == -1) return;
     path(par[n][m].ff, par[n][m].ss);
     if(s[n] == t[m]) printf("%c", s[n]);
}

int solve() {
    cin >> s >> t;
    int n = (int)s.size() - 1, m = (int)t.size() - 1;
    memset(dp, -1, sizeof dp);
    printf("%d\n", lcs(n, m));
    path(n, m);
    printf("\n");
    return 0;
}


2. Matrix Chain Multiplication :

int N = 100;
int row[N], col[N];
int dp[N][N];

int call(int l, int r) {
    if(l >= r) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    int res = INT_MAX;
    for(int mid = l; mid < r; mid++) {
        res = min(res, call(l, mid) + call(mid + 1, r) + row[l] * col[mid] * col[r]);
    }
    return dp[l][r] = res;
}

int solve() {
    int n ;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &row[i], &col[i]);
    }
    memset(dp, -1, sizeof dp);
    printf("%d\n", call(1, n));
    return 0;
}





**********************************************************************************




                          //   Computational Geometry  //





1. Intersection Point of two Line :


int call(int a1, int b1, int a2, int b2) {
    return a1 * b2 - a2 * b1;
}

int solve() {
    int a1, b1, c1, a2, b2, c2;
    scanf("%d %d %d", &a1, &b1, &c1);
    scanf("%d %d %d", &a2, &b2, &c2);
    double x, y;
    x = (double)call(c1, b1, c2, b2) / call(a1, b1, a2, b2);
    y = (double)call(a1, c1, a2, c2) / call(a1, b1, a2, b2);
    x = -x;
    y = -y;
    printf("%.2f %.2f\n", x, y);
    return 0;
}


2. Common Area of overlapping two Rectangle



int area(int a, int b, int c, int d) {
    return (c - a) * (d - b);
}

int solve() {
    int a1, b1, c1, d1, a2, b2, c2, d2;
    scanf("%d %d %d %d", &a1, &b1, &c1, &d1);
    scanf("%d %d %d %d", &a2, &b2, &c2, &d2);
    printf("%d\n", area(max(a1, a2), max(b1, b2), min(c1, c2), min(d1, d2)));
    return 0;
}




******************************************************************************************




                                     //  Greedy Algorithm  //






1. Activity Selecting Problem :

int N = 100;
pair<int, int> t[N];

bool cmp(pii a, pii b) {
    if(a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

int call(int n) {
	sort(t + 1, t + n + 1, cmp);
	int ans = 0;
	int cur = -1;
	for(int i = 1; i <= n; i++) {
	    if(t[i].first >= cur) ans++, cur = t[i].second;
	}
	return ans;
}

int solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &t[i].first);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &t[i].second);
    }
    printf("%d\n", call(n));
    return 0;
}


2. Fractional Knapsack Problem :

int N = 100;
pair<int, int> a[N];

bool cmp(pii a, pii b) {
	return a.first * b.second > a.second * b.first;
}

double frac_knapsack(int n, int wt) {
    sort(a + 1, a + n + 1, cmp);
    double ans = 0.0;
    for(int i = 1; i <= n; i++) {
    	int w =  min(wt, a[i].second);
        ans += (double)a[i].first * w / a[i].second;
        wt -= w;
    }
    return ans;
}

int solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i].first);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i].second);
    }
    int capacity;
    scanf("%d", &capacity);
    printf("%.2f\n", frac_knapsack(n, capacity));
    return 0;
}




****************************************************************************************



                                //  Brance & Bound Section  //




1. 0 - 1 Knapsack Problem :



int N = 100;
int val[N], wt[N];
int dp[1000][1000];

int call(int w, int n) {
    if(n == 0 || w == 0) return 0;
    if(dp[n][w] != -1) return dp[n][w];
    if(w < wt[n]) return call(w, n - 1);
    return max(call(w, n - 1), val[n] + call(w - wt[n], n - 1));
}

int solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &val[i]);
    }
    for(int i = 1; i <= n; i++) {
       scanf("%d", &wt[i]);
    }
    scanf("%d", &capacity);
    memset(dp, -1, sizeof dp);
    printf("%d\n", call(capacity, n));
    return 0;
}





*********************************************************************************************




                          //    Graph Theory   //





1. Constraction a Graph From discovery and Finish time of every node :

int N = 100;

int dp[N];
stack<int> par;
vector< pair<int, int > > edge;

int solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
       int t;
       scanf("%d", &t);
       dp[t] = i;
    }
    for(int i = 1; i <= n; i++) {
       int t;
       scanf("%d", &t);
       dp[t] = i;
    }
    for(int i = 1; i <= n * 2; i++) {
        if(par.empty()) par.push(dp[i]);
        else if(dp[i] == par.top()) par.pop();
        else {
        	int u = par.top();
        	int v = dp[i];
        	edge.pb({u, v});
        	par.push(dp[i]);
        }
    }
    for(int i = 0; i < n - 1; i++) {
        printf("%d --- %d\n", edge[i].first, edge[i].second);
    }
    return 0;
}


2. Finding number of cycle in a Graph (Undirected Graph) :

int N = 100;

vi g[N];
int vis[N];

int cycle(int u) {
	vis[u] = 1;
	int cnt = 0;
	for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(!vis[v]) cnt += cycle(v);
        else if(vis[v] == 2) cnt++;
	}
	vis[u] = 2;
	return cnt;
}

int solve() {
    int n , m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        int u , v;
        scanf("%d %d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) ans += cycle(i);
    }
    printf("%d\n", ans);
    return 0;
}



****************************************************************************************




                                 // Recursion Section //




 1. Check Palindrome :

string s;

bool palindrome(int i, int j) {
    if(i >= j) return true;
    if(s[i] != s[j]) return false;
    return palindrome(i + 1, j - 1);
}

int solve() {
	cin >> s;
	int n = (int)s.size();
	if(palindrome(0, n - 1)) printf("Palindrome\n");
	else printf("Not Palindrome\n");
        return 0;
}


2. Finding Largest in the Array :


int N = 100;
int a[N];

int largest(int n) {
	if(n == 1) return a[n];
	return max(a[n], largest(n - 1));
}

int solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    printf("%d\n", largest(n));
    return 0;
}

3. Finding Secong Largest in the Array :

int N = 100;
int a[N];

void largest_2nd(int n, int &mx, int &mx2) {
    if(n == 1) {
    	mx = a[n], mx2 = -1000000;
    	return;
    }
    largest_2nd(n - 1, mx, mx2);
    if(a[n] > mx) mx2 = mx, mx = a[n];
    else if(a[n] > mx2 && a[n] < mx) mx2 = a[n];
}

int solve() {
    int n ;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int mx, mx2;
    largest_2nd(n, mx, mx2);
    printf("%d\n", mx2);
    return 0;
}

4. Finding Smallest and Second Smallest in the array

Try yourself (Almost Same to Problem 2 & 3)

************************************************************************************

