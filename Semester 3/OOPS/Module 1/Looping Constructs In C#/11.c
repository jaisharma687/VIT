int main(){
    int n,count=0,ld,fd,rem;
    scanf("%d",&n);
    for(int i=0;n!=0;i++){
        rem = n%10;
        n=n/10;
        count++;
        if(i==0){
            ld = rem;
        }
        else if(n==0){
            fd = rem;
        }
    }
    printf("%d %d %d",count,fd,ld);
    return 0;
}