#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;

//problem link: https://www.acmicpc.net/problem/16234

int N, L, R;
int map[51][51];
int visited[51][51]; // 방문 여부
bool unioned; // 연합 여부
int result; // 인구 이동 횟수

// 상 하 좌 우
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

void bfs(int row, int column) {
	if (visited[row][column]) { // 방문 한적 있으면 종료
		return;
	}

	vector < pair<int, int> > v;
	queue<pair<int, int> > q;
	
	q.push(make_pair(row, column));
	v.push_back(make_pair(row, column));
	visited[row][column] = true;
	int sum = map[row][column];

	while (!q.empty()) {
		int current_row = q.front().first;
		int current_column = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) { // 상 하 좌 우 
			int next_row = current_row + dr[i];
			int next_column = current_column + dc[i];
			
			if (next_row < 1 || next_row > N || next_column < 1 || next_column > N) { // 범위 체크
				continue;
			}

			if (!visited[next_row][next_column]) { // 방문 체크
				int offset = abs(map[current_row][current_column] - map[next_row][next_column]);

				if (offset >= L && offset <= R) { // 인구 차이 체크
					q.push(make_pair(next_row, next_column));
					v.push_back(make_pair(next_row, next_column));
					sum += map[next_row][next_column]; // 연합의 인구수
					visited[next_row][next_column] = true;
				}
			}
		}
	}

	if (!unioned && v.size() > 1) { // 연합 여부 체크
		unioned = true;
	}
	
	int divided = sum / v.size(); // (연합의 인구수 / 연합을 이루고 있는 칸 수)
	for (int i = 0; i < v.size(); i++) { // 연합의 인구수 업데이트
		int row = v[i].first;
		int column = v[i].second;

		map[row][column] = divided; 
	}
}

int main()
{
	cin >> N >> L >> R;

	for (int row = 1; row <= N; row++) {
		for (int column = 1; column <= N; column++) {
			int x;
			cin >> x;
			map[row][column] = x;
		}
	}

	
	do  {
		unioned = false;
		fill(&visited[0][0], &visited[N+1][N+1], false);

		for (int row = 1; row <= N; row++) {
			for (int column = 1; column <= N; column++) {
				bfs(row, column);
			}
		}

		if (unioned) {
			result++; //  인구 이동횟수 증가
		}
		
	} while (unioned);

	cout << result << endl;
}
