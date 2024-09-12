public class StudentCons {
    int roll;
    String nam;
    Double salary;
    StudentCons(int r, String na, Double s){
        roll = r;
        nam = na;
        salary = s;
    }
    void Disp(){
        System.out.println(roll+" "+ nam+" "+salary);
    }
}
