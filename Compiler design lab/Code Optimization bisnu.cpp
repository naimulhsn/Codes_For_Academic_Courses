#include<bits/stdc++.h>

using namespace std;
/**
********************************************************************
******************* Author:Bisnu sarkar ****************************
********************************************************************
**/

#define ull            unsigned long long
#define ll             long long
#define vi             vector<int>
#define pb             push_back
#define mp             make_pair
#define pii            pair<int,int>
#define vit            vector<int> :: iterator
#define sit            set<int> :: iterator
#define vrit           vector<int> :: reverse iterator
#define ff             first
#define ss             second

#define what_is(x)     cerr << #x << " is " << x << endl;

///*....Debugger....*/

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it)
{
    cout << endl ;
}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << ' ' ;
    err(++it, args...);
}

int dx[8]= {1,0,-1,0,-1,-1,1,1};
int dy[8]= {0,1,0,-1,-1,1,-1,1};
int ini()
{
    int x;
    scanf("%d",&x);
    return x;
}
long long inl()
{
    long long x;
    scanf("%lld",&x);
    return x;
}

const int N = (int) 1e6 + 5;
const int M = (int) 1e9 + 7;
const double pi=2* acos(0.0);

struct op
{
	char l;
	char r[20];
}op[10], res[10];

int main()
{
	int a, i, k, j, z = 0, m, q;
	char *p, *l;
	char temp, t;
	char *tem;
	int n;
	cin>>n;

	for (i = 0; i < n; i++)
	{
		printf("left: ");
		scanf(" %c", &op[i].l);
		printf("right: ");
		scanf(" %s", &op[i].r);
	}

    // Dead code elimination
	for (i = 0; i < n - 1; i++)
	{
		temp = op[i].l;
		for (j = i; j < n; j++)
		{
			p = strchr(op[j].r, temp);

			if (p)
			{
				res[z].l = op[i].l;
				strcpy(res[z].r, op[i].r);
				z++;
			}
		}
	}
	res[z].l = op[n - 1].l;
	strcpy(res[z].r, op[n - 1].r);
	z++;


	//Common subexpression elimination
	for (i = 0; i < z; i++)
	{
		for (j = i + 1; j < z; j++)
		{
			q = strcmp(res[i].r, res[j].r);
			if ((res[i].l == res[j].l) && !q)
			{
				res[i].l = '\0';
			}
		}
	}
	printf("Optimized Code\n");
	for (i = 0; i < z; i++)
	{
		if (res[i].l != '\0')
		{
			printf("%c=", res[i].l);
			printf("%s\n", res[i].r);
		}
	}

    return 0;
}
