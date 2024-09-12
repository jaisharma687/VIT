public class RootMain {
    public static void main(String arg[]){
        RootProblem roo = new RootProblem(1,5,6);
        System.out.println(roo.getDiscriminant());
        if(roo.getDiscriminant()==0){
            System.out.println(roo.getRoot1());
        }
        else if(roo.getDiscriminant()>0){
            System.out.println(roo.getRoot1() + " " + roo.getRoot2());
        }
        else{
            System.out.println("Imaginary");
        }
    }
}
