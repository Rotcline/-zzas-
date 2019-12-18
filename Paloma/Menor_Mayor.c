#include <stdio.h>

int main (){
    int a[1000];
    int n;
    int m=-100000;
    int M=-100000;
    int var1=0;
    int var2=0;
    int pos1=0;
    int pos2=0;
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
        if(a[i]>m){
            m=a[i];
            pos1=i;
        }
        if(a[i]<M){
            M=a[i];
            pos2=i;
        }
    }
    var1=a[0];
    var2=a[n-1];
    a[0]=m;
    a[n-1]=M;
    a[pos1]=var1;
    a[pos2]=var2;

    for (int i=0; i<n; i++){
        printf("%d \n",a[i]);
    }

    return 0;
}
