#include <fstream>
#include <vector>
#include <climits>

using namespace std;

ifstream cin("cri.in");
ofstream cout("cri.out");

vector <int> v1, v2, v3, v4;
int s1, s2, s3, s4;

int main() {
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int x1;
			cin >> x1;
			if (i <= x && j <= y) {
				v1.push_back(x1);
				s1 += x1;
			}
			if (i <= x && j >= y) {
				v2.push_back(x1);
				s2 += x1;
			}
			if (i >= x && j <= y) {
				v3.push_back(x1);
				s3 += x1;
			}
			if (i >= x && j >= y) {
				v4.push_back(x1);
				s4 += x1;
			}
		}
	}
	int ans = 0, nrc = 0, zn = 0;
	// 1
	if (x % 2 || y % 2) {
		if (ans < s1) {
			ans = s1;
			nrc = x * y;
			zn = 1;
		}
	}
	else {
		int s = 0;
		bool ok = false;
		for (int i = 1; i < y; i++)
			s += v1[i];
		int l = 1, r = y, mini = INT_MAX;
		while (r < v1.size()) {
			mini = min(mini, s);
			s -= v1[l];
			s += v1[r];
			l++;
			r++;
		}
		s = 0;
		vector <int> v;
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				v.push_back(v1[y * j + i]);
				if (i == 0 && j)
					s += v1[y * j + i];
			}
		}
		l = 1;
		r = x;
		int m1 = mini;
		while (r < v1.size()) {
			if (mini > s)
				mini = ans;
			else if (mini == s && x < y)
				ok = true;
			s -= v[l];
			s += v[r];
			l++;
			r++;
		}
		if (mini != m1)
			ok = true;
		s1 -= mini;
		if (ans < s1) {
			ans = s1;
			if (ok)
				nrc = x * y - (x - 1);
			else
				nrc = x * y - (y - 1);
			zn = 1;
		}
	}
	// 2
	int ox = x, oy = m - y + 1;
	if (ox % 2 || oy % 2) {
		if (ans < s2) {
			ans = s2;
			nrc = ox * oy;
			zn = 2;
		}
		else if (ans == s2 && nrc > ox * oy) {
			nrc = ox * oy;
			zn = 2;
		}
	}
	else {
		int s = 0;
		bool ok = false;
		for (int i = 0; i < oy - 1; i++)
			s += v2[i];
		int l = 0, r = oy - 1, mini = INT_MAX;
		while (r < v2.size()) {
			if (!l || l >= oy) {
				if (!(r % ox) || r / ox < oy - 1)
					mini = min(mini, s);
			}
			s -= v2[l];
			s += v2[r];
			l++;
			r++;
		}
		mini = min(mini, s);
		s = 0;
		vector <int> v;
		for (int i = 0; i < oy; i++) {
			for (int j = 0; j < ox; j++) {
				v.push_back(v2[oy * j + i]);
				if (i == 0 && j < ox - 1)
					s += v2[oy * j + i];
			}
		}
		l = 0;
		r = ox - 1;
		int m1 = mini;
		while (r < v2.size()) {
			if (!(r % ox) || r / ox < oy - 1) {
				if (!l || l >= oy) {
					if (mini > s)
						mini = s;
					else if (mini == s && ox < oy)
						ok = true;
				}
			}
			s -= v[l];
			s += v[r];
			l++;
			r++;
		}
		if (mini > s)
			mini = s;
		else if (mini == s && ox < oy)
			ok = true;
		if (mini != m1)
			ok = true;
		s2 -= mini;
		int nrc1;
		if (ok)
			nrc1 = ox * oy - (ox - 1);
		else
			nrc1 = ox * oy - (oy - 1);
		if (ans < s2) {
			ans = s2;
			nrc = nrc1;
			zn = 2;
		}
		else if (ans == s2 && nrc < nrc1) {
			nrc = nrc1;
			zn = 2;
		}
	}
	// 3
	ox = n - x + 1, oy = y;
	if (ox % 2 || oy % 2) {
		if (ans < s3) {
			ans = s3;
			nrc = ox * oy;
			zn = 3;
		}
		else if (ans == s2 && nrc > ox * oy) {
			nrc = ox * oy;
			zn = 3;
		}
	}
	else {
		int s = 0;
		bool ok = false;
		for (int i = 0; i < oy - 1; i++)
			s += v3[i];
		int l = 0, r = oy - 1, mini = INT_MAX;
		while (r < v3.size()) {
			if (!(r % ox) || r / ox < oy - 1) {
				if (!l || l >= oy)
					mini = min(mini, s);
			}
			s -= v3[l];
			s += v3[r];
			l++;
			r++;
		}
		mini = min(mini, s);
		s = 0;
		vector <int> v;
		for (int i = 0; i < oy; i++) {
			for (int j = 0; j < ox; j++) {
				v.push_back(v3[oy * j + i]);
				if (i == 0 && j < ox - 1)
					s += v3[oy * j + i];
			}
		}
		l = 0;
		r = ox - 1;
		int m1 = mini;
		while (r < v3.size()) {
			if (!l || l >= oy) {
				if (!(r % ox) || r / ox < oy - 1) {
					if (mini > s)
						mini = s;
					else if (mini == s && ox < oy)
						ok = true;
				}
			}
			s -= v[l];
			s += v[r];
			l++;
			r++;
		}
		if (mini > s)
			mini = s;
		else if (mini == s && ox < oy)
			ok = true;
		if (mini != m1)
			ok = true;
		s3 -= mini;
		int nrc1;
		if (ok)
			nrc1 = ox * oy - (ox - 1);
		else
			nrc1 = ox * oy - (oy - 1);
		if (ans < s3) {
			ans = s3;
			nrc = nrc1;
			zn = 3;
		}
		else if (ans == s3 && nrc < nrc1) {
			nrc = nrc1;
			zn = 3;
		}
		//cout << ans << ' ' << nrc << ' ' << zn;
	}
	// 4
	ox = n - x + 1, oy = m - y + 1;
	if (ox % 2 || oy % 2) {
		if (ans < s4) {
			ans = s4;
			nrc = ox * oy;
			zn = 4;
		}
		else if (ans == s4 && nrc > ox * oy) {
			nrc = ox * oy;
			zn = 4;
		}
	}
	else {
		int s = 0;
		bool ok = false;
		for (int i = 1; i < oy; i++)
			s += v4[i];
		int l = 1, r = oy, mini = INT_MAX;
		while (r < v4.size()) {
			mini = min(mini, s);
			s -= v4[l];
			s += v4[r];
			l++;
			r++;
		}
		s = 0;
		vector <int> v;
		for (int i = 0; i < oy; i++) {
			for (int j = 0; j < ox; j++) {
				v.push_back(v4[oy * j + i]);
				if (i == 0 && j)
					s += v4[oy * j + i];
			}
		}
		l = 1;
		r = ox;
		int m1 = mini;
		while (r < v4.size()) {
			if (mini > s)
				mini = s;
			else if (mini == s && ox < oy)
				ok = true;
			s -= v[l];
			s += v[r];
			l++;
			r++;
		}
		if (mini != m1)
			ok = true;
		s4 -= mini;
		int nrc1;
		if (ok)
			nrc1 = ox * oy - (ox - 1);
		else
			nrc1 = ox * oy - (oy - 1);
		if (ans < s4) {
			ans = s4;
			nrc = nrc1;
			zn = 4;
		}
		else if (ans == s4 && nrc < nrc1) {
			nrc = nrc1;
			zn = 4;
		}
	}
	cout << zn << ' ' << ans << ' ' << nrc;
}