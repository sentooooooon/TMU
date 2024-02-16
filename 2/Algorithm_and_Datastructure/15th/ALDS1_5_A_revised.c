#include <stdio.h>

int n, A[50];

int solve(int i, int m){
	int res;
	
	if (m == 0) return 1;
	if (i >= n) return 0;
	res = solve(i + 1, m) || solve(i + 1, m - A[i]);
	return res;
}

int main() {
	int q, M, i;
	FILE *fp;
	
	fp=fopen("data.txt","r");
	fscanf(fp,"%d", &n);
	for (i = 0; i <  n; i++ ) fscanf(fp,"%d", &A[i]);
	fclose(fp);
	
	printf("A[0..%d] =",n-1);
	for (i = 0; i <  n; i++ ) printf(" %d", A[i]);
	printf("\n");
	
	printf("Input the number of queries q: ");
	scanf("%d", &q);
	
	for (i = 0; i <  q; i++ ) {
		printf("Query %d\n",i+1);
		printf("Input a target value M: ");
		scanf("%d", &M);
		if ( solve(0, M) ) printf("Answer: yes\n");
		else printf("Answer: no\n");
	}

	return 0;
}
