#include <iostream>

using namespace std;

//将一个16位的每一位转换成10进制的数 p35
int digit2Value(char c){
	if(c>='0'&&c<='9'){
		return c-'0';
	}
	else if(c>='A'&&c<='F')
	{
		return 10+c-'A';
	}
	else if(c>='a'&&c<='f')
	{
		return 10+c-'a';
	}
}


int main(){
	char c = 'a';
	cout<<"a is : "<<(int)('a')<<endl;
	cout<<digit2Value(c)<<endl;
	return 0;
}