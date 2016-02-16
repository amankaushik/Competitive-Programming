#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int QAbsDisAux[999][999] = {0};


map<pair<int, pair<int, int> >, make_pair<int, int> > dp;

void getDis(int query, int N, int cDis, int *minDis, int prevR1, int prevR2, 
            int **Q, int *QAbsDis) {
    if(query == N) {
        if(cDis < *minDis)
            *minDis = cDis;
    }
    else {
        if(!(cDis >= *minDis)) {
            if(dp.find(make_pair( query, make_pair(prevR1, prevR2) )) != dp.end()) {
                cDis = dp[make_pair( query, make_pair(prevR1, prevR2) )].first;
                
            }
            else {
                dp[make_pair( query, make_pair(prevR1, prevR2) )] = cDis + QAbsDis[query] + 
                    QAbsDisAux[prevR1][Q[query][0]];
            getDis(query + 1, N, cDis + QAbsDis[query] + QAbsDisAux[prevR1][Q[query][0]], 
                   minDis, Q[query][1], prevR2, Q, QAbsDis);
                
                dp[make_pair( query, make_pair(prevR1, prevR2) )] = cDis + QAbsDis[query] + 
                    QAbsDisAux[prevR2][Q[query][0]];
            getDis(query + 1, N, cDis + QAbsDis[query] + QAbsDisAux[prevR2][Q[query][0]], 
                   minDis, prevR1, Q[query][1], Q, QAbsDis);
            }
        }
    }
}


int main() {
    int test;
    scanf("%d", &test);
    while(test--) {
        int M, N;
        scanf("%d%d", &M, &N);
        
        int **Q = new int *[N];
        
        for(int i = 0; i < N; i++)
            Q[i] = new int[2];
        
        for(int i = 0; i < N; i++) {
            int mA, mB;
            scanf("%d%d", &mA, &mB);
            Q[i][0] = mA;
            Q[i][1] = mB;
        }
        
        int QAbsDis[N];
        for(int i = 0; i < N; i++) 
            QAbsDis[i] = abs(Q[i][0] - Q[i][1]);
                     
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(i == 0) {
                    QAbsDisAux[i][Q[j][0]] = 0;
                    QAbsDisAux[Q[i][1]][Q[j][0]] = abs(Q[i][1] - Q[j][0]);
                }
                else if(i != j) {
                    QAbsDisAux[Q[i][1]][Q[j][0]] = abs(Q[i][1] - Q[j][0]);
                }
            }
        }
        
        int minDis = 0;
        int prev = 0;
        minDis += QAbsDis[0];
        prev = Q[0][1];
        for(int i = 0; i < N; i++) { 
            minDis += QAbsDisAux[prev][Q[i][0]];
            minDis += QAbsDis[i];
            prev = Q[i][1];
        }
        
        getDis(1, N, abs(Q[0][0] - Q[0][1]), &minDis, Q[0][1], 0, Q, QAbsDis);
        printf("%d\n",minDis);
    }
    return 0;
}