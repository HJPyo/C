#include<iostream>
#include<string>
using namespace std;

int query;

class Deque{
	public:
		int ar[10001] = {}, size = 0;
		
		void PushFront(int x){
			if(size>0){
			for(int i = size; i > 0; i--)
				ar[i] = ar[i-1];
			}
			ar[0] = x;
			size++;
		}
		void PushBack(int x){
			ar[size] = x;
			size++;
		}
		void PopFront(){
			if(size==0){
				cout << "-1\n";
				return;
			}
			cout << ar[0] << '\n';
			for(int i = 0; i < size; i++)
				ar[i] = ar[i+1];
			size--;
		}
		void PopBack(){
			if(size==0){
				cout << "-1\n";
				return;
			}
			cout << ar[size-1] << '\n';
			size--;
		}
		void Size(){
			cout << size << '\n';
		}
		void Empty(){
			cout << (size == 0 ? 1 : 0) << '\n';
		}
		void Front(){
			if(size==0) cout << "-1\n";
			else cout << ar[0] << '\n';
		}
		void Back(){
			if(size==0) cout << "-1\n";
			else cout << ar[size-1] << '\n';
		}
};

int main()
{
	scanf("%d", &query);
	
	Deque Dq;
	
	for(int i = 0; i < query; i++){
		int X;
		string Q;
		cin >> Q;
		
		if(Q == "push_front"){
			cin >> X;
			Dq.PushFront(X);
		}
		if(Q == "push_back"){
			cin >> X;
			Dq.PushBack(X);
		}
		if(Q == "pop_front"){
			Dq.PopFront();
		}
		if(Q == "pop_back"){
			Dq.PopBack();
		}
		if(Q == "size"){
			Dq.Size();
		}
		if(Q == "empty"){
			Dq.Empty();
		}
		if(Q == "front"){
			Dq.Front();
		}
		if(Q == "back"){
			Dq.Back();
		}
	}
}
