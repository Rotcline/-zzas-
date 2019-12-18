#include <stdio.h>

int main (){
    int a[500][500];
    int n;
    int x;

    scanf("%d""%d",&n,&x);

    for (int i=0; i<n; i++){
        for (int j=0; j<x; j++){
            scanf("%d",&a[i][j]);
        }
    }
    for (int i=n-1; i>=0; i--){
        for (int j=0; j<x; j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

return 0;
}
