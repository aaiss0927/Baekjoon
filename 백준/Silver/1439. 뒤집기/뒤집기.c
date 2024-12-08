#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char str[1000000];
	scanf("%s", str);
	
	int cont[2] = { 0, 0 };
	int cur = str[0] - '0';

	if (cur == 0)
		cont[0]++;
	else
		cont[1]++;

	for (int i = 1; i < strlen(str); i++) {
		if ((str[i] - '0') != cur) {
			cur = !cur;
			cont[cur]++;
		}
	}

	int ans = (cont[0] < cont[1]) ? cont[0] : cont[1];
	printf("%d", ans);
}