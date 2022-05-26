#include <bits/stdc++.h>
using namespace std;
float value[1010][2] = {0,};
double s[1010][1010] = {0,};
double R[1010][1010] = {0,};
double A[1010][1010] = {0,};
vector<int> centers;
int exe[1010] = {0,};
int main() {
	int n;
	FILE *fp = fopen("test.txt", "r");
    fscanf(fp, "%d", &n);
	for(int i = 0; i<n; i++) {
		fscanf(fp, "%f %f", &value[i][0], &value[i][1]);
	}
	double sumval = 0;
	int cnt = 0;
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			if(i==j) continue;
			else {
				s[i][j] = -pow(value[i][0]-value[j][0], 2)-pow(value[i][1]-value[j][1], 2);
				sumval += s[i][j];
				cnt++;
			}
		}
	}
	for(int i = 0; i<n; i++) {
		s[i][i] = sumval/cnt;
	}
	int iter = 20;
	double lambda = 0.8;
	for(int r = 0; r<iter; r++) {
		for(int i = 0; i<n; i++) {
			int max = 0, max2 = 0, maxk = 0;
			if(s[i][0]+A[i][0]>s[i][1]+A[i][1]) {
				max = s[i][0]+A[i][0];
				max2 = s[i][1]+A[i][1];
				maxk = 0;
			}
			else {
				max = s[i][1]+A[i][1];
				max2 = s[i][0]+A[i][0];
				maxk = 1;
			}
			for(int k = 2; k<n; k++) {
				if(max<s[i][k]+A[i][k]) {
					max2 = max;
					max = s[i][k]+A[i][k];
					maxk = k;
				}
			}
			for(int j = 0; j<n; j++) {
				if(j==maxk) {
					R[i][j] = R[i][j]*lambda + (1-lambda)*(s[i][j] - max2);
				}
				else {
					R[i][j] = R[i][j]*lambda + (1-lambda)*(s[i][j] - max);
				}
			}
		}
		for(int j = 0; j<n; j++) {
			int sum = 0;
			for(int k = 0; k<n; k++) {
				sum += 0>R[k][j]?0:R[k][j];
			}
			for(int i = 0; i<n; i++) {
				if(i==j) {
					A[i][j] = A[i][j]*lambda + (1-lambda)*(sum - (0>R[i][j]?0:R[i][j]));
				}
				else {
					int imsi = sum - (0>R[i][j]?0:R[i][j]) - (0>R[j][j]?0:R[j][j]) + R[j][j];
					A[i][j] = A[i][j]*lambda + (1-lambda)*(imsi<0?imsi:0);
				}
			}
		}
	}
	vector<int> centers;
	for(int i = 0; i<n; i++) {
		float ma = -1e10;
		for(int j = 0; j<n; j++) {
			if(R[i][j]+A[i][j]>ma) {
				exe[i] = j;
				ma = R[i][j]+A[i][j];
			}
		}
		centers.push_back(exe[i]);
		printf("%d\n", exe[i]);
	}
	for(int j:centers) {
		exe[j] = j;
	}
	for(int i = 0; i<n; i++) {
		printf("%d ", exe[i]);
	}
}
