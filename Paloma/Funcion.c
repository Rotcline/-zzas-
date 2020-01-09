#include <stdio.h>

int main(){
	int x;
	scanf("%d",&x);
	x=loquesea(x);
	printf("%d",x);
}	
int loquesea (int z){
	z++;
	return z;
}

