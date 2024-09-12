# include <stdio.h>
int main()
{
    int n;
    int arrival[10],burst[10],arrivalsorted[10];
    scanf("%d",&n);
    for(int i = 0; i<n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        arrival[i] = a;
        burst[i] = b;
    }
    for(int i = 0; i<n;i++){
        arrivalsorted[i]=arrival[i];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(arrivalsorted[j]>arrivalsorted[j+1]){
                int temp = arrivalsorted[j];
                arrivalsorted[j]=arrivalsorted[j+1];
                arrivalsorted[j+1]=temp;
            }
        }
    }
    int p[10];
    for(int i = 0;i<n;i++){
        for(int j = 0; j<n;j++){
            if(arrivalsorted[i]==arrival[j]){
                printf("P%d ",j+1);
                p[i]= j;
            }
        }
    }
    int c = arrival[p[0]];
    int ct[10],tat,wt,atat=0,awt=0;
    for(int i = 0;i<n;i++){
        int k = p[i];
        c += burst[k];
        ct[k] = c;
    }
    for(int i = 0;i<n;i++){
        tat = ct[i] - arrival[i];
        atat += tat;
        wt = tat - burst[i];
        awt += wt;
        printf("\nP%d %d %d",i+1,tat,wt);
    }
    float avgtat = (float)atat / n;
    float avgwt = awt / n;
    // printf("\n%d",atat);
    printf("\n%.1f %.0f",avgtat,avgwt);
}
