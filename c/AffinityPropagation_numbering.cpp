#include <bits/stdc++.h>
using namespace std;
const int N = 20;
long double S[N][N] = {0};
long double R[N][N] = {0}; // Responsibility
long double A[N][N] = {0}; //
int loop = 100;
long double lambda = 0.5;
const char* dataFileName = "Data.txt";
void readS() {
    ifstream myFile("Data.txt");
    vector<long double> cord[2];
    cord[0].resize(N);
    cord[1].resize(N);
    mt19937 engine((unsigned int)time(NULL));
    uniform_real_distribution<long double> distribution(0,10000);
    auto gen = bind(distribution, engine);

    for(int i = 0; i < N; i++) {
        myFile >> cord[0][i] >> cord[1][i];
        //cin >> cord[0][] >> cord[i][1];
        //cord[0][i] = gen();
        //cord[1][i] = gen();
        //cord[0][i] = (i%3)*500;
        //cord[1][i] = (i%3)*500;
    }
    cout << "input :\n";
    for(int i = 0 ; i < N; i++) {
        //cout << i <<"th Point\n";
        //cout << cord[0][i] << ' ' << cord[1][i] << '\n';
    }
    myFile.close();
    vector<long double> dis_list;
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            long double dis = (cord[0][i]-cord[0][j])*(cord[0][i]-cord[0][j])+(cord[1][i]-cord[1][j])*(cord[1][i]-cord[1][j]);
            S[i][j] = S[j][i] = -dis;
            dis_list.push_back(-dis);
        }
    }
    sort(dis_list.begin(),dis_list.end());
    int sz = N*(N-1)/2;
    double mid = 0;
    if(sz%2==0) mid = (dis_list[sz/2]+dis_list[sz/2-1])/2;
    else mid = dis_list[sz/2];
    for(int i = 0; i < N; i++) S[i][i] = mid;
}
signed main() {
    clock_t st = clock();
    readS();
    for(int loop1 = 1; loop1 <= loop; loop1++) {
        for(int i = 0; i < N; i++) {
            vector<long double> pref_ma(N);
            vector<long double> suff_ma(N);
            pref_ma[0] = S[i][0] + A[i][0];
            for(int j = 1; j < N; j++) {
                pref_ma[j] = max(pref_ma[j-1],S[i][j]+A[i][j]);
            }
            suff_ma[N-1] = S[i][N-1] + A[i][N-1];
            for(int j = N-2; j >= 0; j--) {
                suff_ma[j] = max(suff_ma[j+1],S[i][j]+A[i][j]);
            }
            for(int j = 0; j < N; j++) {
                long double ma = max((j==0?-1e100:pref_ma[j-1]),(j==N-1?-1e100:suff_ma[j+1]));
                R[i][j] = (1-lambda) * (S[i][j] - ma) + lambda * R[i][j];
            }
        }
        vector<long double> R_sum(N);
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                R_sum[j] += max((long double)0,R[i][j]);
            }
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(i==j) {
                    A[i][j] = (1-lambda) * (R_sum[j]-max((long double)0,R[j][j])) + lambda * A[i][j];
                }
                else {
                    A[i][j] = (1-lambda) * min((long double)0,R[j][j]+R_sum[j]-max((long double)0,R[i][j])-max((long double)0,R[j][j])) + lambda * A[i][j];
                }
            }
        }
    }
    vector<int> center;
    for(int i = 0; i < N; i++) {
        if(R[i][i]+A[i][i]>0) center.push_back(i);
    }
    vector<int> par(N);
    for(int i=0;i<N;i++) {
        int id = -1;
        int ma = 0;
        for(int j = 0; j < center.size();j++) {
            int c = center[j];
            if(j==0) {
                ma = S[i][c];
                id = c;
            }
            if(S[i][c] > ma) {
                ma = S[i][c];
                id = c;
            }
        }
        par[i] = id;
    }
    for(int j = 0; j < center.size();j++) {
        par[center[j]] = center[j];
    }
    for(int i = 0; i < N; i++) {
        cout << par[i] << ' ';
    }
    cout <<"Centers\n";
    for(int c : center) {
        cout << c << '\n';
    }
    cout << clock() - st << "ms\n";
}
