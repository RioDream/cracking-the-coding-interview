//q1_1
#include <iostream>

using namespace std;

//$使用一个长度256的bool数组当箱子，一次遍历，看哪个箱子里面的球多于1个
bool haveSameChar1(char* arr,const int length){
	bool char_set[256] = {false};
	for(int i=0;i<length;i++){
		char c= arr[i];
		int index = (int)c;
		if(char_set[index]){

			return true;
		}else{

			char_set[index] = true;
		}
	}
	return false;
}

//$不使用bool数组，使用 bit vector 
bool haveSameChar2(char* arr,const int length){
	//TODO
}

//$不使用额外的数据结构，最直接的方法，时间复杂度O(n)，空间复杂度O(1)
bool haveSameChar3(char* arr,const int length){
	for(int i=0;i<length;i++){
		char c1= arr[i];
		//这里只需要 j=i，即从i后面开始，因为前面的已经比较过了，再比较就多了一次。
		//这样可以减少一半的比较，从 n(n-1) --> n(n-1)/2
		for(int j=i;j<length;j++){ 
			char c2 = arr[j];
			if(c1==c2){
				return true;
			}

		}

	}
	return false;
}

int main(){
	const int len =5;
	char charArr[len] = {'a','b','c','d','a'};

	cout<<haveSameChar1(charArr,len)<<endl;
	cout<<haveSameChar3(charArr,len)<<endl;


	return 0;
}