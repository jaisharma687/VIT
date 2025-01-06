# include <stdio.h>
void eval(int r,float *a,float *p){
    *a = 3.14*r*r;
    *p = 3.14*2*r;
}
int main(){
    float area,perimeter;
    int radius = 5;
    eval(radius,&area,&perimeter);
    printf("%f %f ",area,perimeter);
    return 0;
}