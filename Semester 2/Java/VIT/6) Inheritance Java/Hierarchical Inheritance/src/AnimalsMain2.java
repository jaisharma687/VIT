class Animal{
    void eat(){System.out.println("eating...");}
    }
    class Dog extends Animal{
    void bark(){System.out.println("barking...");}
    }
    class Cat extends Animal{
    void meow(){System.out.println("meowing...");}
    }
public class AnimalsMain2 {
    public static void main(String[] args) throws Exception {
        Cat c=new Cat();
        c.meow();
        c.eat();
        //c.bark();//C.T.Error
    }
}
