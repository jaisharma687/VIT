public class StudentByConstructorMain {
        public static void main(String args[])    {
            StudentByConstructor[] arr = new StudentByConstructor[2];
          arr[0] = new StudentByConstructor(1701289270, "Satyabrata");
          arr[1] = new StudentByConstructor(1701289219, "Omm Prasad");
          System.out.println( "Student data in student arr 0: ");
              arr[0].display();
               System.out.println(  "Student data in student arr 1: ");
                  arr[1].display();
      }
}
