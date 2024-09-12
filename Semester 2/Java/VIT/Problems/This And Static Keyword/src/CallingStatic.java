class Stat{
    int multiply(int a, int b){
        return a*b;
    }
    static int add(int a, int b){
        return a+b;
    }
}
class CallingStatic {
    public static void main(String arg[]){
        Stat s = new Stat();
        System.out.println(s.multiply(3, 4));
        System.out.println(Stat.add(2, 5));
    }
}
