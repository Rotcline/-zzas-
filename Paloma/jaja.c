#include <stdio.h>

int main (){
    int a;
    int n;
    int m=0;
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        scanf("%d",&a);
        if(a>m){
            m=a;
        }
    }
    printf("%d",m);

    return 0;
}

