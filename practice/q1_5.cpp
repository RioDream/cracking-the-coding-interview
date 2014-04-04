//压缩字符串 aaab->a3b1, 现在只有我自己的解法 
//**注意：使用VS和g++编译结果不同，代码中进行了分析。

#include <iostream>

using namespace std;


void printArr(char* str){
	int i = 0;
	while (true){
		char c = str[i];
		if (c == '\0'){
			break;
		}
		cout << c << " ";
		i++;
	}
	cout << endl;
}


//compressedArr 不能在参数中被改变，所以要返回一个 char*,其实可以改成compressedArr在函数内动态申请内存。
char* myCompress(char* arr, char* compressedArr){
	int i = 0;
	const int ASCII_NUMBER_ZERO = 48;
	char lastChar = arr[0];
	int curCharCount = 0;
	int cursor = 0; //指向compressArr的下一个待写入位置
	while (true){
		char temp = arr[i];

		cout<<"i is :"<<i<<endl;
		cout<<"cursor is :"<<cursor<<endl;
		cout<<"lastChar is :"<<lastChar<<endl;
		printArr(arr);
		if (temp != lastChar){
			compressedArr[cursor++] = lastChar;
			//假设最多不超多100个,也即是只有两位
			if (curCharCount / 10 != 0){
				compressedArr[cursor++] = curCharCount / 10 + ASCII_NUMBER_ZERO; //十位
			}
			compressedArr[cursor++] = curCharCount % 10 + ASCII_NUMBER_ZERO; //个位
			lastChar = temp;

			curCharCount = 1; //开始新的字符,并且已经有一个，记上1
		}
		else{
			curCharCount++; //当前字符数+1, 最开始的时候执行这里
		}

		/*
		使用g++编译器的时候，内存是这样的
		compressedArr 之后紧跟着 arr.
		这样在cursor超过compressedArr本身长度的时候，
		通过 compressedArr[cursor]更改compressedArr,就会导致更改arr，导致错误。
		解决办法目前有两个： 
		1. 分配足够大的compressArr 
		2. 在更改compressedArr[cursor]的时候检查原来的值是不是'\0'，防止把compressedArr的尾巴覆盖，跑到arr的区域
		*/
		printArr(arr); 

		//到arr结尾的时候，给compressArr结尾
		if (temp == '\0'){
			compressedArr[cursor] = '\0';
			if (cursor > i){ //如果压缩之后长度更长了，就抛弃压缩
				compressedArr = arr;
			}
			break;
		}

		printArr(arr);
		printArr(compressedArr);
		cout<<"-----"<<endl;
		i++;
	}
	return compressedArr;

}


int main(int argc, char const *argv[])
{
	const int len = 10;
	char charArr[len] = { 'a', 'b', 'a', 'b', 'b', 'a', 'b', 'a', 'b','\0' }; 
	char charArr_compressed[len] = {'a', 'b', 'a', 'b', 'b', 'a', 'b', 'a', 'b','\0'}; 
	//char charArr_compressed[2*len] = {'a', 'b', 'a', 'b', 'b', 'a', 'b', 'a', 'b','\0'}; 
	char* charArr_comp = myCompress(charArr, charArr_compressed);
	cout << "-----" << endl;
	printArr(charArr);
	printArr(charArr_comp);

	//getchar();

	return 0;
}