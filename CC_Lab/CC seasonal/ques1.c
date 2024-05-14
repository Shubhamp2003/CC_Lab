#include<stdio.h>

int main(){
    int p[10],at[10],bt[10],ct[10],tat[10],wt[10],temp=0,i,j,n;
    printf("Enter number of process:");
    scanf("%d",&n);
    printf("Enter process number:");
    for(i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    printf("Enter %d Arrival time:",n);
    for(i=0;i<n;i++){
        scanf("%d",&at[i]);
    }
    printf("Enter %d Brust time:",n);
    for(i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<(n-i);j++)
        {
            if(at[j]>at[j+1])
            {
                temp=p[j+1];
                p[j+1]=p[j];
                p[j]=temp;
                temp=at[j+1];
                at[j+1]=at[j];
                at[j]=temp;
                temp=bt[j+1];
                bt[j+1]=bt[j];
                bt[j]=temp;
            }
        }
    }
    ct[0]=at[0]+bt[0];
    for(i=1;i<n;i++)
    {  
        if(ct[i-1]<at[i])
        {
            temp=0;
            temp=at[i]-ct[i-1];
        }
        ct[i]=ct[i-1]+bt[i]+temp;
    }
    printf("\nP\t CT\t TAT\t WT");
    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }
    for(i=0;i<n;i++)
    {
      printf("\nP%d \t %d \t %d \t %d",p[i],ct[i],tat[i],wt[i]);
    }
    float atat=0, awt=0;
    for(i=0;i<n;i++)
    {
        atat+=tat[i];
        awt+=wt[i];
    }
    atat=atat/n;
    awt=awt/n;
    printf("\naverage turnaround time = %f",atat);
    printf("\naverage wating timme = %f",awt);
    return 0;
}