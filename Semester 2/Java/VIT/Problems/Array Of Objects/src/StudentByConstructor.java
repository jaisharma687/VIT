class StudentByConstructor {
    public int id;
  public String name;
  StudentByConstructor(int i, String n)    {
      id = i;
      name = n;
  }
public void display()    {
      System.out.println("Student id is: " + id + " " + "and Student name is: "    + name);
      System.out.println();
  }
}

