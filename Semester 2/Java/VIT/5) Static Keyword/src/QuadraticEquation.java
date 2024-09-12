public class QuadraticEquation {
    public static void main(String arg[]){
        if(QuadraticEquationN.getDiscriminant()>0){
        System.out.println("Root 1 is: "+ QuadraticEquationN.getroot1());
        System.out.println("Root 2 is: "+ QuadraticEquationN.getroot2());
        }
        else if(QuadraticEquationN.getDiscriminant()==0){
            System.out.println("Root 1 is: "+ QuadraticEquationN.getroot1());
            System.out.println("Root 2 is: "+ QuadraticEquationN.getroot1());
        }
        else{
            System.out.println("Root 1 is imaginary");
            System.out.println("Root 2 is imaginary");
        }
    }
}
