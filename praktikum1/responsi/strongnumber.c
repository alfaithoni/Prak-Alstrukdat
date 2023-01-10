#include <stdio.h>

int main(){
	int x;
	scanf("%d", &x);
	int total = 0;
	int temp = x;
	while(x){
		int i=1;
		int fact=1;
		int last = x % 10;
		while(i<=last){
			fact *= i;
			i++;
		}
		total += fact;
		x /= 10;
	}
	if (total==temp){
		printf("Y\n");
	} else {
		printf("N\n");
	}
	return 0;
}
