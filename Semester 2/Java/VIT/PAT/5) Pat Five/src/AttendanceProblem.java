class AttendaceException extends Exception{
    AttendaceException(String n){
        super(n);
    }
}
public class AttendanceProblem {
    public static void main(String[] args) {
        try{
            int Att = 50;
            if(Att<75){
                throw new AttendaceException("Attendance must be greater than 75%");
            }
        }
        catch(AttendaceException e){
            System.out.println(e);
        }
        catch(Exception e){
            System.out.println(e);
        }
    }
}
