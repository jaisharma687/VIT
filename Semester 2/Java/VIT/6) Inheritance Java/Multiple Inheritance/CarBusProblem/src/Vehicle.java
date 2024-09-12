public class Vehicle implements Car, Bus{
    int distancetravelled;
    int avgspeed;
    public void distancetravelled(){
        distancetravelled = speed*distance;
        System.out.println(distancetravelled);
    }
    public void speed(){
        avgspeed = distancetravelled/speed;
        System.out.println(avgspeed);
    }
}
