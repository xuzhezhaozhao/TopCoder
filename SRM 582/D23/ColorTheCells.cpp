#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

class ColorTheCells
{
private:
	vector <int> dryingTime;	/* 需要干燥的时间  */
	vector <long> dryedTime;	/* 正好干燥的时间，0表示还没有paint */
	vector <int> paint_order;	/* paint格子的顺序 */
public:
	long calc(int seq);
	int minimalTime(vector <int> dryingTime);
};

#define MOVE_TIME 1L
#define PAINT_TIME 1L
#define INFINITY_TIME LONG_MAX 

/* 参考Ueddy代码实现 */
int ColorTheCells::minimalTime(vector<int> dryingTime)
{
	int num = dryingTime.size();
	long minTime = INFINITY_TIME;
	int i, j;

	this->dryingTime = dryingTime;
	paint_order.clear();		/* paint 的顺序 */
	dryedTime.clear();

	for (i = 0; i < num; i++) {
		paint_order.push_back(i);
		dryedTime.push_back(0);
	}

	/* brute force，枚举所有的情况，选出最小时间 */
	do {
		for (i = 0; i < (1<<num); i++) {
			for (j = 0; j < num; j++) {
				dryedTime[j] = 0;
			}
			minTime = min(minTime, calc(i));
		}
	} while (next_permutation(paint_order.begin(), paint_order.end()));

	return minTime;
}

/**
 * seq为一个序列，0表示在被paint位置左边paint, 1表示在右边paint，paint的顺序由
 * paint_order指定。
 */
long ColorTheCells::calc(int seq)
{
	long time;			/* 所用时间 */
	int num = dryingTime.size();
	int paint_dir;			/* paint方向，在被paint位置左边还是右边paint */
	int cur_pos;			/* 当前位置 */
	int paint_pos;			/* paint位置，不是被paint的位置 */
	int bias;			/* 从当前位置向左走还是向右走 */
	
	cur_pos = 0;
	time = 0;
	for (int i = 0; i < num; i++) {
		paint_dir = seq & 1;
		seq /= 2;
		paint_dir = paint_dir ? 1 : -1;
		paint_pos = paint_order[i] + paint_dir;
		if (paint_pos < 0 || paint_pos >= num) {	/* 位置不合法 */
			return INFINITY_TIME;
		}

		bias = 1;			/* 从当前位置向右走 */
		if (cur_pos - paint_pos > 0) {	/* 从当前位置向左走 */
			bias = -1;
		}
		
		/* 用for循环到达paint位置，中间遇到还没有干燥的格子要等待 */
		for (; cur_pos != paint_pos; cur_pos += bias) {
			if (dryedTime[cur_pos+bias] > time) {	/* 等待干燥 */
				time = dryedTime[cur_pos+bias];
			}
			time += MOVE_TIME;		/* 移动时间 */
		}
		time += PAINT_TIME;		/* 到达目的地，paint时间 */
		dryedTime[paint_order[i]] = time + dryingTime[paint_order[i]];	/* 更新该格子干燥时间  */
	}

	return time;
}

int main()
{
	ColorTheCells color;
	vector <int> dryingTime;
	int dry[] = {35198, 26281, 72533, 91031, 44326, 43178, 80000};

	for (int i = 0; i < (int)( sizeof(dry)/sizeof(dry[0]) ); i++) {
		dryingTime.push_back(dry[i]);
	}

	cout << color.minimalTime(dryingTime) << endl;

	return 0;
}

/* Ueddy 的代码 */
class ColorTheCells_Ueddy
{
public:
	int N;
	int inf;
	vector <int> p;
	vector <int> d;			/* dryedTime */
	vector <int> dryingTime;

	int calc (int b)
	{
		int t = 0;		/* time */
		int x = 0;		/* 当前位置 */
		int f;			/* 在左边刷，在右边刷的标志 */
		int dx;			/* 向左走-1, 向右走1 */
		int nx;			/* nx为下一个要刷的位置 */
		for (int i = 0; i < N; i++) {
			f = b & 1;		/* b的最低位, 0表示在左边刷，1表示在右边刷 */
			b /= 2;			/* b = b / 2 */
			nx = p[i] + 1;		/* 从右边刷 */
			if (0 == f) {
				nx = p[i] - 1;
			}
			if (nx < 0 || nx >= N) {
				return inf;
			}
			dx = 1;
			if (nx - x < 0) {
				dx = -1;
			}
			for (; x != nx; x += dx) {
				if (t < d[x + dx]) {
					t = d[x + dx];	
				}
				++t;
			}
			++t;		/* 刷是时间为1 */
			d[p[i]] = t + dryingTime[p[i]];
		}
		return t;
	}

	int minimalTime(vector <int> dryingTime)
	{
		inf = 100000000;
		int ans = inf;
		this->dryingTime = dryingTime;
		N = dryingTime.size();
		p.clear();
		d.clear();
		for (int i = 0; i < N; i++) {
			p.push_back(i);
			d.push_back(0);
		}
		do {
			for (int i = 0; i < (1 << N); i++) {
				for (int j = 0; j < N; j++) {
					d[j] = 0;
				}
				/* d[] 为0 */
				ans = min(ans, calc(i));
			}
		} while (next_permutation(p.begin(), p.end()));

		return ans;
	}
};
