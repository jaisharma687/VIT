class Studen{
    int rollno;
    String name;
    float fee;
    Studen(int rollno, String name, float fee){
        this.rollno = rollno;
        this.name = name;
        this.fee = fee;
    }
void display(){
    System.out.println(rollno+" "+name+" "+ fee);
}
}
class StudentProb {
    public static void main(String[] args) throws Exception {
        Studen obj = new Studen(111,"Jai",4526.0045f);
        obj.display();
    }
}
