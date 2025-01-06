class StudentByMethodMain {
  
    public static void main(String args[])    {
    StudentByMethod[] arr = new StudentByMethod[2];
    arr[0] = new StudentByMethod();
    arr[1] = new StudentByMethod();
  
     arr[0].setData(1701289270, "Satyabrata");
     arr[1].setData(1701289219, "Omm Prasad");
     
     System.out.println("Student data in student arr 0: ");                             
     arr[0].display();
 System.out.println(   "Student data in student arr 1: ");
        arr[1].display();
    }
}

