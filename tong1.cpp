#include<iostream>
using namespace std;
class Sum{
	private:
		int A;
		int B;
	public:
		Sum(int a, int b){
			A=a;
			B=b;
		}
		int Tinhtong(){
			int sum=0;
			sum=A+B;
			return sum;
		}
};
int main(){
	int A,B;
	cin>>A>>B;
	Sum s(A,B);
	cout<<s.Tinhtong();
}
