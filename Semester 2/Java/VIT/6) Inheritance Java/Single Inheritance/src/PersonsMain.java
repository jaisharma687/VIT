class Person{
    int age;
    int id;
    void setage(int a){age = a;}
    void setid(int i){id = i;}
    int getage(){return age;}
    int getid(){return id;}
}
class Emp extends Person{
    String name;
    void setname(String n){name = n;}
    String getname(){return name;}
}
public class PersonsMain {
    public static void main (String arg[]){
        Emp em = new Emp();
        em.setage(54);
        em.setid(1458);
        em.setname("HJgdkj");
        System.out.println(em.getage());
        System.out.println(em.getid());
        System.out.println(em.getname());
    }
}
