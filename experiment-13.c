#include <stdio.h>

void alloc(int b[], int m, int p[], int n, int type) {
    int a[n], i, j, idx;
    for(i=0;i<n;i++) a[i]=-1;

    for(i=0;i<n;i++){
        idx=-1;
        for(j=0;j<m;j++){
            if(b[j]>=p[i]){
                if(idx==-1) idx=j;
                else if(type==2 && b[j]<b[idx]) idx=j;
                else if(type==3 && b[j]>b[idx]) idx=j;
                else if(type==1) {idx=j; break;}
            }
        }
        if(idx!=-1){ a[i]=idx; b[idx]-=p[i]; }
    }

    printf("\nPNo Size Block\n");
    for(i=0;i<n;i++)
        printf("%d   %d    %s%d\n",i+1,p[i],a[i]==-1?"NA ":"",a[i]+1);
}

int main(){
    int m,n,i;
    printf("Blocks: "); scanf("%d",&m);
    int b[m],b1[m],b2[m],b3[m];
    for(i=0;i<m;i++){ scanf("%d",&b[i]); b1[i]=b2[i]=b3[i]=b[i]; }

    printf("Processes: "); scanf("%d",&n);
    int p[n]; for(i=0;i<n;i++) scanf("%d",&p[i]);

    printf("\nFirst Fit"); alloc(b1,m,p,n,1);
    printf("\nBest Fit");  alloc(b2,m,p,n,2);
    printf("\nWorst Fit"); alloc(b3,m,p,n,3);

    return 0;
}
