#include <stdio.h>
#include <string.h>

int main(){
    char f[20][20], name[20];
    int n=0,ch,i,j,found;

    while(1){
        printf("\n1.Create 2.Delete 3.Search 4.Display 5.Exit: ");
        scanf("%d",&ch);

        if(ch==1){
            scanf("%s",name);
            for(found=0,i=0;i<n;i++) if(!strcmp(f[i],name)) found=1;
            if(found) printf("Exists\n");
            else strcpy(f[n++],name);
        }
        else if(ch==2){
            scanf("%s",name);
            for(found=0,i=0;i<n;i++)
                if(!strcmp(f[i],name)){
                    found=1;
                    for(j=i;j<n-1;j++) strcpy(f[j],f[j+1]);
                    n--;
                }
            if(!found) printf("Not Found\n");
        }
        else if(ch==3){
            scanf("%s",name);
            for(found=0,i=0;i<n;i++) if(!strcmp(f[i],name)) found=1;
            printf(found?"Found\n":"Not Found\n");
        }
        else if(ch==4){
            for(i=0;i<n;i++) printf("%s\n",f[i]);
        }
        else break;
    }
    return 0;
}
