class Counter{
    static int count = 0;
    Counter(){
        count++;
        System.out.println(count);
    }
}
public class CounterProblem {
    public static void main(String arg[]){
        Counter c1 = new Counter();
        Counter c2 = new Counter();
        Counter c3 = new Counter();
    }
}
