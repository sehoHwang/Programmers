/** 솔루션 **/

/*
    1. dp 문제라 생각했으나 그냥 이중 for문으로 가지치기를 하면서 돌면 된다.
*/


#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

    
int solution(int n) {
	int answer = 0;
	int sum;
	for (int i = 1; i <= n; i++) {
		sum = 0;
		for (int j = i; j <= n; j++) {
			sum += j;
			if (sum == n) {
				answer++;
				break;
			}
			else if (sum > n)
				break;
		}
	}
	return answer;
}
    
