#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        bool alice_win=false;
        int N, M;
        LL x, sumN=0, sumM=0, topN, topM;
        priority_queue<LL> PQM;
        priority_queue<LL> PQN;

        scanf("%d %d", &N, &M);

        for(int n=0; n<N; n++) {
            scanf("%lld", &x);
            PQN.push(x);
            sumN += x;
        }

        for(int m=0; m<M; m++) {
            scanf("%lld", &x);
            PQM.push(x);
            sumM += x;
        }

        if(sumN != sumM)
            alice_win = true;
        else {
            while(!PQN.empty() && !PQM.empty()) {
                topN = PQN.top();
                topM = PQM.top();
                if(topM == topN) {
                    PQN.pop(); PQM.pop();
                    sumN -= topN; sumM -= topM;
                } else {
                    if((topM > topN && topN == (sumM-1)) ||
                            (topN > topM && topM == (sumN-1)))
                        alice_win = false;
                    else
                        alice_win = true;
                    break;
                }
            }
        }

        printf("%s\n", alice_win? "Alice": "Bob");
    }
}
