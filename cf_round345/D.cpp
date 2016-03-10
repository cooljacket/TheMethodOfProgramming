#include <stdio.h>
#include <vector>
using namespace std;


vector<int> forward(char* dir, int n, int time, int a, int b) {
	vector<int> ans;
	int index = 0, ori_time = time;

	for (int i = 0; i < n && time > 0; ++i) {
		int cost = 1;
		if (i > 0)
			cost += a;
		if (dir[i] == 'w')
			cost += b;
		if (time < cost)
			break;
		time -= cost;
		ans.push_back(ori_time-time);
	}
	
	return ans;
}

void print(vector<int>& v) {
	for (int i = 0; i < v.size(); ++i)
		printf("i=%d, time=%d\n", i, v[i]);
	printf("\n");
}

int binary_search(const vector<int>& v, int beg, int end, int upper) {
	while (beg < end) {
		int mid = (beg+end) / 2;
		if (v[mid] > upper)
			end = mid;
		else
			beg = mid;
		if (end-beg == 1) {
			if (v[beg] <= upper && v[end] > upper)
				return beg;
			if (v[beg] <= upper && v[end] <= upper)
				return end;
		}
	}

	return beg;
}

int solve(const vector<int>& go, const vector<int>& back, int n, int T, int a) {
	int maxN = 0;
	for (int i = 0; i < go.size(); ++i) {
		int step_go = i + 1, key = T - go[i] - (i+1)*a;
		if (key > 0 && !back.empty() && key >= back[0]) {
			int tail = min(int(n-step_go), int(back.size())) - 1;
			int index = 233;
			if (tail > 0) {
				index = binary_search(back, 0, tail, key);
				step_go += index + 1;
			}
			// printf("huhu, tail=%d, index=%d, step_go=%d\n", tail, index, step_go);
		}

		// printf("\ti=%d, step_go=%d, key=%d, maxN=%d\n", i, step_go, key, maxN);

		if (step_go > maxN)
			maxN = step_go;
	}

	return maxN;
}

int main() {
	int n, a, b, T;
	scanf("%d%d%d%d", &n, &a, &b, &T);
	char* dir = new char[n];
	char* rdir = new char[n];
	char buf;
	scanf("%c", &buf);
	for (int i = 0; i < n; ++i) {
		scanf("%c", &dir[i]);
		rdir[n-i-1] = dir[i];
	}

	vector<int> go = forward(dir, n, T, a, b);
	vector<int> back = forward(rdir, n, T-a, a, b);
	// print(go);
	// print(back);

	int pos = solve(go, back, n, T, a);
	int neg = solve(back, go, n, T-a, a);
	printf("%d\n", max(pos, neg));
	// int neg = solve(back, go, n, T-a, a);

	return 0;
}