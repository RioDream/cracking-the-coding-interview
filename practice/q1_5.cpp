#include <iostream>

using namespace std;

//compressedArr不能在参数中被改变，所以要返回一个 char*
char* compress(char* arr, char* compressedArr){
	int i = 0;
	const int ASCII_NUMBER_ZERO = 48;
	char lastChar = arr[0];
	//char lastChar = (arr[0] + 1) % 256;
	int curCharCount = 0;
	int cursor = 0; //指向compressArr的下一个待写入位置
	while (true){
		char temp = arr[i];



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
			curCharCount++; //当前字符数+1
		}

		if (temp == '\0'){
			compressedArr[cursor] = '\0';
			if (cursor > i){
				compressedArr = arr;
			}

			break;
		}

		i++;
	}
	return compressedArr;

}

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

int main(int argc, char const *argv[])
{
	const int len = 10;
	char charArr[len] = { 'a', 'b', 'a', 'b', 'b', 'a', 'b', 'a', 'b','\0' }; //9个a
	//char charArr[len] = { 'a', 'a', 'a', 'a', 'b', 'a', 'a', 'a', 'a' }; //9个a
	char charArr_compressed[len] = {}; //9个a
	char* charArr_comp = compress(charArr, charArr_compressed);
	printArr(charArr);
	cout << "-----" << endl;
	printArr(charArr_comp);

	//getchar();

	return 0;
}