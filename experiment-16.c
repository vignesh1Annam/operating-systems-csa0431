#include <stdio.h>

struct emp{
    int id;
    char name[20];
    float sal;
};

int main(){
    FILE *fp=fopen("emp.dat","wb+");
    struct emp e;
    int n,i,sid,found=0;

    printf("n: "); scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d%s%f",&e.id,e.name,&e.sal);
        fwrite(&e,sizeof(e),1,fp);
    }

    printf("Search ID: "); scanf("%d",&sid);

    rewind(fp);
    while(fread(&e,sizeof(e),1,fp)){
        if(e.id==sid){
            found=1;
            printf("ID:%d Name:%s Salary:%.2f\n",e.id,e.name,e.sal);
            break;
        }
    }
    if(!found) printf("Not Found\n");

    fclose(fp);
    return 0;
}
