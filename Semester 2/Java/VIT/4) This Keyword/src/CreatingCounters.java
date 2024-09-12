class CreatingCounters{
    static int count =0;
    CreatingCounters(){
        count++;
        System.out.println(count);
    }
public static void main(String arg[]){
    CreatingCounters c1 = new CreatingCounters();
    CreatingCounters c2 = new CreatingCounters();
    CreatingCounters c3 = new CreatingCounters();
}}