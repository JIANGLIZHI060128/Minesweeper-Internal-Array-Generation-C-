//Monica Jiang 2025.5.11
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	char cin_matrix[10][26] = { '\0' };
	int my_matrix[10][26] = { 0 };
	int demo_matrix[10][26] = { 0 };
	int count = 0;
	for (int line = 0; line < 10;line++) {
		for (int row = 0; row < 26; row++) {
			scanf(" %c", &cin_matrix[line][row]);
			if (cin_matrix[line][row] == '*') {
				my_matrix[line][row] = '*';
				count++;
			}
			else
				my_matrix[line][row] = cin_matrix[line][row] - '0';
		}
	}
	if (count != 50)
		printf("错误1\n");
	else {
		for (int n = 0; n < 26; n++) {
			if (cin_matrix[0][n] == '*')
				continue;
			if (n == 0) {
				if (cin_matrix[1][n] == '*') {
					demo_matrix[0][n]++;
				}
				if (cin_matrix[0][n + 1] == '*') {
					demo_matrix[0][n]++;
				}
				if (cin_matrix[1][n + 1] == '*') {
					demo_matrix[0][n]++;
				}
			}
			else if (n == 25) {
				if (cin_matrix[1][n] == '*') {
					demo_matrix[0][n]++;
				}
				if (cin_matrix[0][n - 1] == '*') {
					demo_matrix[0][n]++;
				}
				if (cin_matrix[1][n - 1] == '*') {
					demo_matrix[0][n]++;
				}
			}
			else {
				if (cin_matrix[0][n-1] == '*') {
					demo_matrix[0][n]++;
				}
				if (cin_matrix[0][n + 1] == '*') {
					demo_matrix[0][n]++;
				}
				if (cin_matrix[1][n - 1] == '*') {
					demo_matrix[0][n]++;
				}
				if (cin_matrix[1][n] == '*') {
					demo_matrix[0][n]++;
				}
				if (cin_matrix[1][n+1] == '*') {
					demo_matrix[0][n]++;
				}
			}
		}
		//计算最后一行
		for (int n = 0; n < 26; n++) {
			if (cin_matrix[9][n] == '*')
				continue;
			if (n == 0) {
				if (cin_matrix[8][n] == '*') {
					demo_matrix[9][n]++;
				}
				if (cin_matrix[9][n + 1] == '*') {
					demo_matrix[9][n]++;
				}
				if (cin_matrix[8][n + 1] == '*') {
					demo_matrix[9][n]++;
				}
			}
			else if (n == 25) {
				if (cin_matrix[8][n] == '*') {
					demo_matrix[9][n]++;
				}
				if (cin_matrix[9][n - 1] == '*') {
					demo_matrix[9][n]++;
				}
				if (cin_matrix[8][n - 1] == '*') {
					demo_matrix[9][n]++;
				}
			}
			else {
				if (cin_matrix[9][n-1] == '*') {
					demo_matrix[9][n]++;
				}
				if (cin_matrix[9][n + 1] == '*') {
					demo_matrix[9][n]++;
				}
				if (cin_matrix[8][n - 1] == '*') {
					demo_matrix[9][n]++;
				}
				if (cin_matrix[8][n] == '*') {
					demo_matrix[9][n]++;
				}
				if (cin_matrix[8][n + 1] == '*') {
					demo_matrix[9][n]++;
				}
			}
		}
		//计算第一列
		for (int n = 1; n < 9; n++) {
			if (cin_matrix[n][0] == '*')
				continue;
			if (cin_matrix[n-1][0] == '*') {
				demo_matrix[n][0]++;
			}
			if (cin_matrix[n + 1][0] == '*') {
				demo_matrix[n][0]++;
			}
			if (cin_matrix[n - 1][1] == '*') {
				demo_matrix[n][0]++;
			}
			if (cin_matrix[n][1] == '*') {
				demo_matrix[n][0]++;
			}
			if (cin_matrix[n + 1][1] == '*') {
				demo_matrix[n][0]++;
			}
		}
		//计算最后一列
		for (int n = 1; n < 9; n++) {
			if (cin_matrix[n][25] == '*')
				continue;
			if (cin_matrix[n - 1][25] == '*') {
				demo_matrix[n][25]++;
			}
			if (cin_matrix[n + 1][25] == '*') {
				demo_matrix[n][25]++;
			}
			if (cin_matrix[n - 1][24] == '*') {
				demo_matrix[n][25]++;
			}
			if (cin_matrix[n][24] == '*') {
				demo_matrix[n][25]++;
			}
			if (cin_matrix[n + 1][24] == '*') {
				demo_matrix[n][25]++;
			}
		}
		//计算中间区域
		for (int n = 1; n < 9; n++) {
			for (int m = 1; m < 25; m++) {
				if (cin_matrix[n][m] == '*')
					continue;
				else {
					if (cin_matrix[n - 1][m - 1] == '*')
						demo_matrix[n][m]++;
					if (cin_matrix[n - 1][m] == '*')
						demo_matrix[n][m]++;
					if (cin_matrix[n - 1][m + 1] == '*')
						demo_matrix[n][m]++;
					if (cin_matrix[n][m - 1] == '*')
						demo_matrix[n][m]++;
					if (cin_matrix[n][m + 1] == '*')
						demo_matrix[n][m]++;
					if (cin_matrix[n + 1][m - 1] == '*')
						demo_matrix[n][m]++;
					if (cin_matrix[n + 1][m] == '*')
						demo_matrix[n][m]++;
					if (cin_matrix[n + 1][m + 1] == '*')
						demo_matrix[n][m]++;
				}
			}
		}
		int match = 1;
		for (int j = 0; j < 10; j++) {
			for (int i = 0; i < 26; i++) {
				if (cin_matrix[j][i] == '*')
					continue;
				else if (my_matrix[j][i] != demo_matrix[j][i]) {
					match = 0;
					break;
				}
			}
		}
		if (!match) {
			printf("错误2\n");
		}
		else
			printf("正确\n");
	}

	

	/*仅供检验时使用
	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < 26; i++) {
			if (cin_matrix[j][i] == '*') {
				printf("* ");
			}
			else {
				printf("%d ",demo_matrix[j][i]);
			}
		}
		printf("\n");
	}
	printf("%d",count);*/
	return 0;
}
