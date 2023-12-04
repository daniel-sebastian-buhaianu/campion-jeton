#include <fstream>
#include <cstring>
#define VMIN 1
#define VMAX 50000
using namespace std;
int main()
{
	bool a[VMAX+1], b[VMAX+1];
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	ifstream f("jeton.in");
	int m, n, i;
	f >> m >> n;
	for (i = 0; i < m; i++)
	{
		int x;
		f >> x;
		a[x] = 1;
	}
	for (i = 0; i < n; i++)
	{
		int x;
		f >> x;
		b[x] = 1;
	}
	f.close();
	int minc, maxc;
	for (i = VMIN; i <= VMAX; i++)
		if (a[i] && b[i])
		{
			minc = i;
			break;
		}
	for (i = VMAX; i >= VMIN; i--)
		if (a[i] && b[i])
		{
			maxc = i;
			break;
		}
	int na = m, nb = n;
	for (i = minc; i <= maxc; i++)
	{
		if (a[i]) na--;
		if (b[i]) nb--;
	}
	int c;
	if (na > nb) c = 1;
	else if (nb > na) c = 2;
	else c = 0;
	ofstream g("jeton.out");
	g << minc << ' ' << maxc << ' ' << c;
	g.close();
	return 0;
}

