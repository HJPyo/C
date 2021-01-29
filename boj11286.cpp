#include<stdio.h>
#include<math.h>
#include<queue>
using namespace std;

int k, n;
priority_queue<pair<int,int> >pQ;

int main()
{
	scanf("%d", &k);
	while(k--){
		scanf("%d", &n);
		if(n == 0){
			if(pQ.size() == 0) printf("%d\n", 0);
			else{
				printf("%d\n", -pQ.top().second);
				pQ.pop();
			}
		}
		else{
			pQ.push({-abs(n),-n});
		}
	}
}
