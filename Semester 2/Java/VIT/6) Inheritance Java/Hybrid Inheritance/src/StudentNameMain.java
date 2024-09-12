interface StudentName { 
    void Name(); 
} 
interface StudentADD  { 
    void Institute(); 
} 
interface StudentStd extends StudentName, StudentADD  
{ 
    void Branch(); 
} 
public class StudentNameMain implements StudentStd 
{ 
    public void Name() 
    { 
        System.out.println("Rohan"); 
    } 
    public void Institute() 
    { 
        System.out.println("Technology"); 
    } 
public void Branch() 
    { 
        System.out.println("SELECT"); 
    } 
    public static void main (String[] args) 
    { 
        StudentNameMain ob1 = new StudentNameMain();
        ob1.Name(); 
        ob1.Institute(); 
        ob1.Branch(); 
    } 
}
