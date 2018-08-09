#include<stdio.h>

int main(){

    int n,i,j,k;
    printf("Enter the number of rows upto middle row.\n");
    scanf("%d",&n);
    for(i=0;i<=n;i++){
        k=i;
        int flag=0;
        for(j=0;j<2*n+1;j++){
            if(j<2*n-2*i){
                printf(" ");
            }
            else{
                printf("%d",k);
                if(k>0 && flag==0){
                    k--;
                    if(k==0){
                        flag=1;
                    }
                }
                else
                    k++;
            }
        }
        printf("\n");
    }
    for(i=0;i<=n;i++){
        k=n-1-i;
        int flag=0;
        for(j=0;j<2*n+1;j++){
            if(j<=2*i+1){
                printf(" ");
            }
            else{
                printf("%d",k);
                if(k>0 && flag==0){
                    k--;
                    if(k==0){
                        flag=1;
                    }
                }
                else
                    k++;
            }
        }
        printf("\n");
    }
    return 0;
}
