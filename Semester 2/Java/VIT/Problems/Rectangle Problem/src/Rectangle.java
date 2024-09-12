public class Rectangle {
double height;
double width;
Rectangle(){
    height = 1;
    width = 1;
}
Rectangle(double w, double h){
    height = h;
    width = w;
}
void getArea1(){
    System.out.println(height*width);
}
void getPerimeter(){
    System.out.println(2*(height+width));
}
}
