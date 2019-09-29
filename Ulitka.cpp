#include<stdio.h>
#include<stdlib.h>
void func(int n);
int main(void){
	int n;
	while(1){
		printf("Input n: ");
		scanf("%d", &n);
		func(n);
		printf("\n\n");
	}
	return 0;
}
void func(int n){
	if (n==1){
		printf("1");
		return;
	}
	int **A, cur=2;
	int x=0, y=0;
	int up=0, down=n, left=0, right=n;
	A = (int**)calloc(n,sizeof(int*));
	for(int i = 0; i<n; i++)
		A[i] = (int*)calloc(n,sizeof(int));
	A[0][0]=1;
	while(1){
		while(y+1<right){
			y++;
			A[x][y]=cur;
			if(cur==n*n) goto end;
			cur++;
		}
		up++;
		while(x+1<down){
			x++;
			A[x][y]=cur;
			if(cur==n*n) goto end;
			cur++;
		}
		right--;
		while(y>left){
			y--;
			A[x][y]=cur;
			if(cur==n*n) goto end;
			cur++;
		}
		down--;
		while(x>up){
			x--;
			A[x][y]=cur;
			if(cur==n*n) goto end;
			cur++;

		}
		left++;
	}
	goto end;
	end:
	for (int i = 0; i<n; i++){
		for(int j = 0; j<n; j++)
			printf("%d ", A[i][j]);
		printf("\n");
	}
}
