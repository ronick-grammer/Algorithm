#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>
using namespace std;


int solution(vector<int> food_times, long long k) {
	int answer = 0;
	int sum_seconds = 0; // 음식을 먹는데 드는 총 시간
	priority_queue<pair<int, int> > pq;

	for (int i = 0; i < food_times.size(); i++) {
		pq.push(make_pair(food_times[i], i + 1)); // 음식처리시간이 가장 짧은 게 맨 위에 오도록
		sum_seconds += food_times[i]; // 각 음식들의 총 합
	}

	if (sum_seconds <= k) { // 음식을 전부 먹는 시간보다 중단 시간이 더 크면 -1 반환
		return -1;
	}

	int count_leftover= food_times.size(); // 남은 음식 갯수
	int cycle = 0; // 순환 수, 현재 순환을 한번도 하지 않았으므로 0
	sum_seconds = 0;
	while (k >= sum_seconds + (pq.top().first - cycle) * count_leftover) { // 
		
		sum_seconds += (pq.top().first - cycle) * count_leftover; // 직전 음식을 처리한 시간을 더해준다
		cycle = pq.top().first; // 직전 음식을 처리한 순환 횟수를 기록
		count_leftover--; // 음식 하나를 처리했으므로 하나를 빼준다.

		pq.pop(); // 다음으로 처리시간이 짧은 음식을 준비한다
	}

	vector<pair<int, int> > v;
	while (!pq.empty()) {
		v.push_back(make_pair(pq.top().second, pq.top().first));
		pq.pop();
	}
	
	sort(v.begin(), v.end());
	answer = v[(k - sum_seconds) % count_leftover].first;

	return answer;
}
