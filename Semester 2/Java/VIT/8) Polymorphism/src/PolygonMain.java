class Polygon{void render(){System.out.println("Polygon");}}
class Square extends Polygon{void render(){System.out.println("Square");}}
class Circle extends Polygon{void render(){System.out.println("Circle");}}
class PolygonMain{
    public static void main(String arg[]){
        new Square().render();
        new Circle().render();
        new Polygon().render();
    }
}