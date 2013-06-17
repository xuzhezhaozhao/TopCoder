#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <limits>

using namespace std;

#define STATE_SIZE 1024
#define MAX_SIZE 7
#define getPos(state) (state[7] + state[8] * 2 + state[9] * 4)
#define setPos(pos, state) state[7] = pos_table[pos][0]; \
		state[8] = pos_table[pos][1]; state[9] = pos_table[pos][2]

bool visited[STATE_SIZE];
long mintime = INT_MAX;
bitset <3> pos_table[7] = {0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6};

typedef struct State {
	bitset <10> state;
	long time;
	long finish_time;
	long dryedTime[MAX_SIZE];
	int count;
}State;

class ColorTheCells
{
public:
	int minimalTime(vector <int> dryingTime);
};

bool finished(bitset <10> state, int size);

int ColorTheCells::minimalTime(vector<int> dryingTime)
{
	queue <State> Q;
	State cus_state, next_state;
	int paint_size;
	int cus_pos, next_pos, paint_pos;

	paint_size = dryingTime.size();
	cus_state.state = 0x000;
	cus_state.time = 0;
	cus_state.finish_time = 0;
	cus_state.count = 0;
	for (int i = 0; i < MAX_SIZE; i++) {
		cus_state.dryedTime[i] = 0;
	}
	
	for (int i = 0; i < STATE_SIZE; i++) {
		visited[i] = false;
	}

	Q.push(cus_state);
	while (!Q.empty()) {
		cus_state = Q.front();
		Q.pop();
		cus_pos = getPos(cus_state.state);

		if (finished(cus_state.state, paint_size)) {
			if (cus_state.finish_time < mintime) {
				mintime = cus_state.finish_time;
			}
		}
		if (cus_state.count > 10) {
			break;
		}

		/* 左走 */
		next_state = cus_state;
		if (cus_pos - 1 >= 0) {
			++next_state.count;
			next_pos = cus_pos - 1;
			setPos(next_pos, next_state.state);
			/* 干燥最后时间 */
			if (cus_state.dryedTime[next_pos] > cus_state.time) {
				next_state.time = cus_state.dryedTime[next_pos];
			}
			next_state.time += 1;	/* 移动时间 */
			if (!visited[next_state.state.to_ullong()]) {
				//visited[next_state.state.to_ullong()] = true;
				Q.push(next_state);
			}
		}

		/* 右走 */
		next_state = cus_state;
		if (cus_pos + 1 <= paint_size) {
			++next_state.count;
			next_pos = cus_pos + 1;
			setPos(next_pos, next_state.state);
			if (cus_state.dryedTime[next_pos] > cus_state.time) {
				next_state.time = cus_state.dryedTime[next_pos];
			}
			next_state.time += 1;
			if (!visited[next_state.state.to_ullong()]) {
				//visited[next_state.state.to_ullong()] = true;
				Q.push(next_state);
			}
		}

		/* 左刷左走 */
		next_state = cus_state;
		if (cus_pos - 1 >= 0 && !cus_state.state.test(cus_pos-1)) {
			++next_state.count;
			next_pos = cus_pos - 1;
			setPos(next_pos, next_state.state);
			paint_pos = cus_pos - 1;

			next_state.state.set(paint_pos);	/* 刷，相应位置1 */
			next_state.time += 1;			/* 刷的时间 */
			next_state.finish_time = next_state.time;
			next_state.dryedTime[paint_pos] = next_state.time + dryingTime[paint_pos]; 

			next_state.time = next_state.dryedTime[paint_pos] + 1;

			if (!visited[next_state.state.to_ullong()]) {
				//visited[next_state.state.to_ullong()] = true;
				Q.push(next_state);
			}
		}

		/* 左刷右走 */
		next_state = cus_state;
		if (cus_pos + 1 <= paint_size-1 && cus_pos - 1 >= 0 
			&& !cus_state.state.test(cus_pos-1)) {
			++next_state.count;
			next_pos = cus_pos + 1;
			setPos(next_pos, next_state.state);
			paint_pos = cus_pos - 1;

			next_state.state.set(paint_pos);	/* 刷，相应位置1 */
			next_state.time += 1;			/* 刷的时间 */
			next_state.finish_time = next_state.time;
			next_state.dryedTime[paint_pos] = next_state.time + dryingTime[paint_pos]; 

			if (next_state.dryedTime[next_pos] > next_state.time) {
				next_state.time = next_state.dryedTime[next_pos];
			}
			next_state.time += 1;

			if (!visited[next_state.state.to_ullong()]) {
				//visited[next_state.state.to_ullong()] = true;
				Q.push(next_state);
			}
		}


		/* 右刷左走 */
		next_state = cus_state;
		if (cus_pos + 1 <= paint_size-1 && cus_pos - 1 >= 0 
			&& !cus_state.state.test(cus_pos+1)) {
				++next_state.count;
				next_pos = cus_pos - 1;
				setPos(next_pos, next_state.state);
				paint_pos = cus_pos + 1;

				next_state.state.set(paint_pos);	/* 刷，相应位置1 */
				next_state.time += 1;			/* 刷的时间 */
				next_state.finish_time = next_state.time;
				next_state.dryedTime[paint_pos] = next_state.time + dryingTime[paint_pos]; 

				if (next_state.dryedTime[next_pos] > next_state.time) {
					next_state.time = next_state.dryedTime[next_pos];
				}
				next_state.time += 1;

				if (!visited[next_state.state.to_ullong()]) {
					//visited[next_state.state.to_ullong()] = true;
					Q.push(next_state);
				}
		}

		/* 右刷右走 */
		next_state = cus_state;
		if (cus_pos + 1 <= paint_size-1 && !cus_state.state.test(cus_pos+1)) {
			++next_state.count;
			next_pos = cus_pos + 1;
			setPos(next_pos, next_state.state);
			paint_pos = cus_pos + 1;

			next_state.state.set(paint_pos);	/* 刷，相应位置1 */
			next_state.time += 1;			/* 刷的时间 */
			next_state.finish_time = next_state.time;
			next_state.dryedTime[paint_pos] = next_state.time + dryingTime[paint_pos]; 

			if (next_state.dryedTime[next_pos] > next_state.time) {
				next_state.time = next_state.dryedTime[next_pos];
			}
			next_state.time += 1;

			if (!visited[next_state.state.to_ullong()]) {
				//visited[next_state.state.to_ullong()] = true;
				Q.push(next_state);
			}
		}

		/* 左刷右刷左走 */
		next_state = cus_state;
		if (cus_pos + 1 <= paint_size-1 && cus_pos - 1 >= 0 
			&& !cus_state.state.test(cus_pos-1) && !cus_state.state.test(cus_pos+1)) {
				++next_state.count;
				next_pos = cus_pos - 1;
				setPos(next_pos, next_state.state);

				paint_pos = cus_pos - 1;
				next_state.state.set(paint_pos);	/* 刷，相应位置1 */
				next_state.time += 1;			/* 刷的时间 */
				next_state.dryedTime[paint_pos] = next_state.time + dryingTime[paint_pos]; 

				paint_pos = cus_pos + 1;
				next_state.state.set(paint_pos);	/* 刷，相应位置1 */
				next_state.time += 1;			/* 刷的时间 */
				next_state.finish_time = next_state.time;
				next_state.dryedTime[paint_pos] = next_state.time + dryingTime[paint_pos]; 


				if (next_state.dryedTime[next_pos] > next_state.time) {
					next_state.time = next_state.dryedTime[next_pos];
				}
				next_state.time += 1;

				if (!visited[next_state.state.to_ullong()]) {
					//visited[next_state.state.to_ullong()] = true;
					Q.push(next_state);
				}
		}

		/* 左刷右刷右走 */
		next_state = cus_state;
		if (cus_pos + 1 <= paint_size-1 && cus_pos - 1 >= 0 
			&& !cus_state.state.test(cus_pos-1) && !cus_state.state.test(cus_pos+1)) {
				++next_state.count;
				next_pos = cus_pos + 1;
				setPos(next_pos, next_state.state);

				paint_pos = cus_pos - 1;
				next_state.state.set(paint_pos);	/* 刷，相应位置1 */
				next_state.time += 1;			/* 刷的时间 */
				next_state.dryedTime[paint_pos] = next_state.time + dryingTime[paint_pos]; 

				paint_pos = cus_pos + 1;
				next_state.state.set(paint_pos);	/* 刷，相应位置1 */
				next_state.time += 1;			/* 刷的时间 */
				next_state.finish_time = next_state.time;
				next_state.dryedTime[paint_pos] = next_state.time + dryingTime[paint_pos]; 


				if (next_state.dryedTime[next_pos] > next_state.time) {
					next_state.time = next_state.dryedTime[next_pos];
				}
				next_state.time += 1;

				if (!visited[next_state.state.to_ullong()]) {
					//visited[next_state.state.to_ullong()] = true;
					Q.push(next_state);
				}
		}

		/* 右刷左刷左走 */
		next_state = cus_state;
		if (cus_pos + 1 <= paint_size-1 && cus_pos - 1 >= 0 
			&& !cus_state.state.test(cus_pos-1) && !cus_state.state.test(cus_pos+1)) {
				++next_state.count;
				next_pos = cus_pos - 1;
				setPos(next_pos, next_state.state);

				paint_pos = cus_pos + 1;
				next_state.state.set(paint_pos);	/* 刷，相应位置1 */
				next_state.time += 1;			/* 刷的时间 */
				next_state.dryedTime[paint_pos] = next_state.time + dryingTime[paint_pos]; 

				paint_pos = cus_pos - 1;
				next_state.state.set(paint_pos);	/* 刷，相应位置1 */
				next_state.time += 1;			/* 刷的时间 */
				next_state.finish_time = next_state.time;
				next_state.dryedTime[paint_pos] = next_state.time + dryingTime[paint_pos]; 

				if (next_state.dryedTime[next_pos] > next_state.time) {
					next_state.time = next_state.dryedTime[next_pos];
				}
				next_state.time += 1;

				if (!visited[next_state.state.to_ullong()]) {
					//visited[next_state.state.to_ullong()] = true;
					Q.push(next_state);
				}
		}

		/* 右刷左刷右走 */
		next_state = cus_state;
		if (cus_pos + 1 <= paint_size-1 && cus_pos - 1 >= 0 
			&& !cus_state.state.test(cus_pos-1) && !cus_state.state.test(cus_pos+1)) {
				++next_state.count;
				next_pos = cus_pos + 1;
				setPos(next_pos, next_state.state);

				paint_pos = cus_pos + 1;
				next_state.state.set(paint_pos);	/* 刷，相应位置1 */
				next_state.time += 1;			/* 刷的时间 */
				next_state.dryedTime[paint_pos] = next_state.time + dryingTime[paint_pos]; 

				paint_pos = cus_pos - 1;
				next_state.state.set(paint_pos);	/* 刷，相应位置1 */
				next_state.time += 1;			/* 刷的时间 */
				next_state.finish_time = next_state.time;
				next_state.dryedTime[paint_pos] = next_state.time + dryingTime[paint_pos]; 

				if (next_state.dryedTime[next_pos] > next_state.time) {
					next_state.time = next_state.dryedTime[next_pos];
				}
				next_state.time += 1;

				if (!visited[next_state.state.to_ullong()]) {
					//visited[next_state.state.to_ullong()] = true;
					Q.push(next_state);
				}
		}
	}

	return mintime;
}

bool finished(bitset <10> state, int size)
{
	for (int i = 0; i < size; i++) {
		if (!state.test(i)) {
			return false;
		}
	}
	return true;
}


/* Ueddy 的代码 */
class ColorTheCells_Ueddy
{
public:
	int N;
	int inf;
	vector <int> p;
	vector <int> d;
	vector <int> dryingTime;

	int calc (int b)
	{
		int t = 0;
		int x = 0;
		for (int i = 0; i < N; i++) {
			int f = b & 1;
			b /= 2;
			int nx = p[i] + 1;
			if (0 == f) {
				nx = p[i] - 1;
			}
			if (nx < 0 || nx >= N) {
				return inf;
			}
			int dx = 1;
			if (nx - x < 0) {
				dx = -1;
			}
			for (; x != nx; x += dx) {
				if (t < d[x + dx]) {
					t = d[x + dx];	
				}
				++t;
			}
			++t;
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
				ans = min(ans, calc(i));
			}
		} while (next_permutation(p.begin(), p.end()));
		
		return ans;
	}
};

int main()
{
	ColorTheCells_Ueddy color;
	vector <int> dryintTime;
	int dry[] = {35198, 26281, 72533, 91031, 44326, 43178, 85530};

	for (int i = 0; i < (int)( sizeof(dry)/sizeof(dry[0]) ); i++) {
		dryintTime.push_back(dry[i]);
	}

	cout << color.minimalTime(dryintTime) << endl;

	return 0;
}

