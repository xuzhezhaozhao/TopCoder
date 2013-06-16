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

int main()
{
	ColorTheCells color;
	vector <int> dryintTime;
	int dry[] = {35198, 26281, 72533, 91031, 44326, 43178, 85530};

	for (int i = 0; i < (int)( sizeof(dry)/sizeof(dry[0]) ); i++) {
		dryintTime.push_back(dry[i]);
	}

	cout << color.minimalTime(dryintTime) << endl;

	return 0;
}

