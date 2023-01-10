#include <stdio.h>
#include <string.h>

int main(){
	char array[10]; //input berupa string (array of 10 char)
	scanf("%s", array);
	int sum[10]; 
	int n=0;
	for (n;n<10;n++){
		sum[n] = 0;
	}
	int i=0;
	for(i;i<=strlen(array);i++){
		if (array[i]=='0'){
			sum[0]+=1;
		} else if (array[i]=='1'){
			sum[1]+=1;
		} else if (array[i]=='2'){
			sum[2]+=1;
		} else if (array[i]=='3'){
			sum[3]+=1;
		} else if (array[i]=='4'){
			sum[4]+=1;
		} else if (array[i]=='5'){
			sum[5]+=1;
		} else if (array[i]=='6'){
			sum[6]+=1;
		} else if (array[i]=='7'){
			sum[7]+=1;
		} else if (array[i]=='8'){
			sum[8]+=1;
		} else if (array[i]=='9'){
			sum[9]+=1;
		}
	} printf("%d%d%d%d%d%d%d%d%d%d\n", sum[0],sum[1],sum[2],sum[3],sum[4],sum[5],sum[6],sum[7],sum[8],sum[9] );
	return 0;
}