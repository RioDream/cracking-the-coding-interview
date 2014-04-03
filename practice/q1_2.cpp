//q1_2：原地反转char数组
//启发：原地反转列表结构，一般都需要两个指针，一个指向头一个指向尾
#include <iostream>

using namespace std;

void swapValueByIndex(char* str, int i, int j){
	char temp;
	temp = str[i];
	str[i] = str[j];
	str[j] = temp;
}

void reverse(char* str){
	int i = 0;
	while (true){
		char c = str[i];
		if (c == '\0'){
			break;
		}
		i++;
	}

	i--; //得到最后一个非'\0'元素的索引
	int j = 0;
	while (j != i && i != j + 1){ //注意这个终止条件  ,书上是while(j<i)
		swapValueByIndex(str, i, j);
		i--;
		j++;
	}
}

void printArr(char* str){
	int i = 0;
	while (true){
		char c = str[i];
		if (c == '\0'){
			break;
		}
		cout << c << endl;
		i++;
	}
}


int main(){
	char charArr[6] = { 'a', 'b', 'c', 'd', 'e', '\0' };
	printArr(charArr);
	reverse(charArr);
	printArr(charArr);
	return 0;
}