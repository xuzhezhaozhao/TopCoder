#include <iostream>
#include <vector>

using namespace std;

class TransportCounting
{
public:
	int countBuses(int speed, vector <int> positions, vector <int> velocities, int time);
};

int TransportCounting::countBuses(int speed, vector<int> positions, vector<int> velocities, int time)
{
	int size = positions.size();

	int yourDis, carDis, count;

	yourDis = speed * time;
	count = 0;
	for (int i = 0; i < size; i++) {
		if (0 == positions[i]) {
			++count;
		} else {
			carDis = positions[i] + velocities[i] * time;
			if (yourDis >= carDis) {
				++count;
			}
		}

		
	}
	return count;
}

int main()
{
	TransportCounting T;
	int speed, time;
	vector <int> positions, velocities;
	int p[] = {
		10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 
		150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 260, 
		270, 280, 290, 300, 310, 320, 330, 340, 350, 360, 370, 380, 
		390, 400, 410, 420, 430, 440, 450, 460, 470, 480, 490, 500
	};
	int v[] = {
		10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 
		140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 
		260, 270, 280, 290, 300, 310, 320, 330, 340, 350, 360, 370, 
		380, 390, 400, 410, 420, 430, 440, 450, 460, 470, 480, 490, 
		500
	};

	speed = 564;
	time = 607;

	for (int i = 0; i < sizeof(p) / sizeof(int); i++) {
		positions.push_back(p[i]);
		velocities.push_back(v[i]);
	}
	cout << T.countBuses(speed, positions, velocities, time) << endl;
}