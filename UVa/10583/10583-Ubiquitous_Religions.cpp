#include<bits/stdc++.h>
const int len = 50000;
int stud[len+100]={0};
int count[len+100]={0};

void Init(int n)
{
	for(int i=1; i<=n; i++) stud[i] = i;
}

void Clear(int n)
{
	for(int i=1; i<=n; i++) {
		stud[i] = 0;
		count[i] = 0;
	}
}

int Find(int x)
{
	if(x==stud[x]) return x;
	else return stud[x] = Find(stud[x]);	
}

void Union(int x, int y)
{
	int X = Find(x);
	int Y = Find(y);
	stud[Y] = X;
}

void printArr(int n)
{
	for(int i=1; i<=n; i++) printf("%d ", stud[i]);
	putchar('\n');
}

int main()
{
	int n, m, i, j;
	int c = 0, kase = 0;
	while(scanf("%d %d", &n, &m) && !(n==0 && m==0)) {
		Init(n);
		c = 0;
		while(m--) {
			scanf("%d %d", &i, &j);
			Union(i, j);
		}
		for(int i=1; i<=n; i++) {
			count[Find(i)]++;
			if(count[Find(i)] == 1) c++;
		}
		printf("Case %d: %d\n", ++kase, c);
		Clear(n);
	}
}
