#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//
//char* convert(char* s, int numRows) {
//	if (numRows >= (int)strlen(s)) { return s; }
//	if (numRows == 1) { return s; }
//	int i = 0, j = 0, k = 0; //i表示行，j表示列
//	char arr[1001][1001] = { 0 };//放元素的二维数组
//	char *arr1 = (char *)malloc(sizeof(char) * 1001);//返回的一维数组
//	memset(arr1, 0, 1001);
//	while (s[k]) {
//		while (i < numRows && s[k]) { arr[i++][j] = s[k++]; }
//		i -= 2;
//		j++;
//		while (i && s[k]) { arr[i--][j++] = s[k++]; }
//	}
//	int ret = 0;
//	for (int m = 0; m < numRows; m++) {
//		for (int n = 0; n < j; n++) {
//			if (arr[m][n]) {
//				arr1[ret++] = arr[m][n];
//			}
//		}
//	}
//	return arr1;
//}

char* convert(char* s, int numRows)
{
	if (numRows < 2) { return s; }
	int len = strlen(s);
	char *arr = (char *)malloc(sizeof(char) * (len + 1));
	int k = 0;
	int pos = 0;
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < len / (2 * numRows - 2) + 2; j++)
		{
			pos = j * (2 * numRows - 2) + i;
			int pos1 = pos - 2 * i;
			if (pos1 >= 0 && pos1 < len && i != 0 && i != numRows - 1)
			{
				arr[k++] = s[pos1];
			}
			if (pos < len)
			{
				arr[k++] = s[pos];
			}
			
		}
	}
	arr[k] = 0;
	return arr;
}

int main()
{
	char *s = "ABCDE";
	printf("%s\n", convert(s, 4));
	system("pause");
	return 0;
}