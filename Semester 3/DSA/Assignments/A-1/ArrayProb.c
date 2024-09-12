#include <stdio.h>
int a[10];
int i,n,pos,key,x,s;

void insert(){
    scanf("%d %d", &pos, &key);
    for(i=n-1; i>=pos;i--)
    {    
        a[i+1]=a[i];
    }
    a[pos]=key;
    n++;
}

void display(){
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void delete(){
    scanf("%d",&x);
    int posx;
    for(i=0;i<n;i++){
        if(x == a[i]){
            posx = i;
        }
    }
    for(i=posx;i<n;i++)
    {
        a[i]=a[i+1];
    }
    n--;
}

void search(){
    scanf("%d",&s);
    for(i=0;i<n;i++)
    {
        if(a[i]==s)
        {
            printf("Item %d Found in position:%d",s,i+1);
        }
    }
}

void inputs(){
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main()
{
    scanf("%d",&n);
    inputs();
    insert();
    display();
    delete();
    display();
    search();
    return 0;
}