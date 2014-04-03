//q1.4 题目中提到了，“在字符串尾部有足够的空间”，解答中直接对 char数组进行扩充
//怀疑合法性，测试如下


#include <iostream>
#include <string>


using namespace std;


int main(){
	string str = "adf safd sadf sfd sadf     ";

	char charArr1[5] = { 'a', 'a', 'a', 'a', 'a' };
	char charArr2[5] = { 'a' }; //实际是{ 'a', '\0', '\0', '\0', '\0' };
	cout << charArr1[4] << endl;

	//以下两种语法合法，但是无意义
	cout << charArr1[5] << endl;
	cout << charArr1[50] << endl;

}

//结论：虽然合法，但是实际操作中，不可取，空间应该是之前定好的，也就是说解答中的length不是定义的数组的长度