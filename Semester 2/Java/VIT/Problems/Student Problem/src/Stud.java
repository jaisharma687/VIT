class Stud {
int registerNum;
String name;
int marks1;
int marks2;
int marks3;
int marks4;
int marks5;
double cgpa;
void getInput(int r, String n, int m1, int m2, int m3, int m4, int m5){
    registerNum = r;
    name = n;
    marks1 = m1;
    marks2 = m2;
    marks3 = m3;
    marks4 = m4;
    marks5 = m5;
}
double getCgpa() {
    return cgpa = (marks1+marks2+marks3+marks4+marks5)/5;
}
void printfun(){
    System.out.println(registerNum+" "+name+" "+marks1+" "+marks2+" "+marks3+" "+marks4+" "+ marks5+" "+cgpa);
}
}
