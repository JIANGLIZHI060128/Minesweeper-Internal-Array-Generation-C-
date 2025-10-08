//2450987 计算机 蒋理智
#include<iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

int main() {
	int matrix[10][26] = { 0 };

	srand((unsigned int)(time(0)));

	for (int n = 0; n < 50; ) {
		int x0 = rand() % 26;
		int y0 = rand() % 10;
		int x[50];
		int y[50];
		bool exist = false;
		for (int t = 0; t < n; t++) {
			if (x0 == x[t] && y0 == y[t]) {
				exist = true;
				break;
			}
		}
		if (!exist) {
			x[n] = x0;
			y[n] = y0;
			matrix[y[n]][x[n]] = 100;
			n++;
		}
	}
	//计算第一行
	for (int n = 0; n < 26; n++) {
		if (matrix[0][n] == 100)
			continue;
		if (n == 0) {
			matrix[0][n] = (matrix[1][n] + matrix[0][n + 1] + matrix[1][n + 1]) / 100;
		}
		else if (n == 25) {
			matrix[0][n] = (matrix[1][n] + matrix[0][n - 1] + matrix[1][n - 1]) / 100;
		}
		else {
			matrix[0][n] = (matrix[0][n - 1] + matrix[0][n + 1] + matrix[1][n - 1]
				+ matrix[1][n] + matrix[1][n + 1]) / 100;
		}
	}
	//计算最后一行
	for (int n = 0; n < 26; n++) {
		if (matrix[9][n] == 100)
			continue;
		if (n == 0) {
			matrix[9][n] = (matrix[8][n] + matrix[9][n + 1] + matrix[8][n + 1]) / 100;
		}
		else if (n == 25) {
			matrix[9][n] = (matrix[8][n] + matrix[9][n - 1] + matrix[8][n - 1]) / 100;
		}
		else {
			matrix[9][n] = (matrix[9][n - 1] + matrix[9][n + 1] + matrix[8][n - 1]
				+ matrix[8][n] + matrix[8][n + 1]) / 100;
		}
	}
	//计算第一列
	for (int n = 1; n < 9; n++) {
		if (matrix[n][0] == 100)
			continue;
		matrix[n][0] = (matrix[n - 1][0] + matrix[n + 1][0] + matrix[n - 1][1]
			+ matrix[n][1] + matrix[n + 1][1]) / 100;
	}
	//计算最后一列
	for (int n = 1; n < 9; n++) {
		if (matrix[n][25] == 100)
			continue;
		matrix[n][25] = (matrix[n - 1][25] + matrix[n + 1][25] + matrix[n - 1][24]
			+ matrix[n][24] + matrix[n + 1][24]) / 100;
	}
	//计算中间区域
	for (int n = 1; n < 9; n++) {
		for (int m = 1; m < 25; m++) {
			if (matrix[n][m] == 100)
				continue;
			else
				matrix[n][m] = (matrix[n - 1][m - 1] + matrix[n - 1][m] + matrix[n - 1][m + 1]
					+ matrix[n][m - 1] + matrix[n][m + 1]
					+ matrix[n + 1][m - 1] + matrix[n + 1][m] + matrix[n + 1][m + 1])/100;
		}
	}
	
	
	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < 26; i++) {
			if (matrix[j][i] == 100) {
				cout << "*"<<" ";
			}
			else {
				cout << matrix[j][i] << " ";
			}
		}
		cout << endl;
	}

	return 0;
}