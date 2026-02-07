#include <stdio.h>
#include <string.h>

struct user{
    char uname[20], file[10][20];
    int fc;
}u[10];

int main(){
    int uc=0,ch,i,j,ui=-1;
    char un[20], fn[20];

    while(1){
        printf("\n1.User 2.CreateFile 3.Search 4.Display 5.Exit: ");
        scanf("%d",&ch);

        if(ch==1){
            scanf("%s",un);
            for(i=0;i<uc;i++) if(!strcmp(u[i].uname,un)) {printf("Exists\n"); goto skip;}
            strcpy(u[uc].uname,un); u[uc].fc=0; uc++;
            skip:;
        }
        else if(ch==2){
            scanf("%s%s",un,fn);
            for(ui=-1,i=0;i<uc;i++) if(!strcmp(u[i].uname,un)) ui=i;
            if(ui==-1) printf("No User\n");
            else strcpy(u[ui].file[u[ui].fc++],fn);
        }
        else if(ch==3){
            scanf("%s%s",un,fn);
            for(ui=-1,i=0;i<uc;i++) if(!strcmp(u[i].uname,un)) ui=i;
            if(ui==-1) printf("No User\n");
            else{
                for(i=0;i<u[ui].fc;i++) if(!strcmp(u[ui].file[i],fn)) break;
                printf(i<u[ui].fc?"Found\n":"Not Found\n");
            }
        }
        else if(ch==4){
            for(i=0;i<uc;i++){
                printf("\n%s:\n",u[i].uname);
                for(j=0;j<u[i].fc;j++) printf("%s\n",u[i].file[j]);
            }
        }
        else break;
    }
    return 0;
}
