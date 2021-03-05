#include<iostream>
#include<string>
using namespace std;

int len, cnt = 0, num[31], opr[31];
string str;

int main()
{
	cin >> str;
	len = str.length();
	
	for(int i = 0, j = 0; i < len; i++){
		if(str[i] == '+' || str[i] == '-'){
			while(i > j){
				num[cnt] *= 10;
				num[cnt] += str[j] - '0';
				j++;
			}
			opr[cnt] = (str[i] == '+' ? 1 : 2);
			j = i+1;
			cnt++;
		}
		if(i == len-1){
			while(i >= j){
				num[cnt] *= 10;
				num[cnt] += str[j] - '0';
				j++;
			}
			cnt++;
		}
	}
	
	for(int i = 0, j = 0; i < cnt-1; i++){
		if(opr[i] == 2) j = 1;
		if(j == 1) opr[i] = 2;
	}
	
	for(int i = 0; i < cnt-1; i++){
		if(opr[i] == 1) num[0] += num[i+1];
		else num[0] -= num[i+1];
	}
	
	printf("%d", num[0]);
}
