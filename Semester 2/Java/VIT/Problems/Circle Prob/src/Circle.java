class Circle {
    double radius;
    Circle(){radius = 1;}
    Circle(double newRadius){radius = newRadius;}
    double getArea101(){
        return radius*radius*Math.PI;
    }
    double getCircumference(){
        return 2*radius*Math.PI;
    }
    void setRadius(double newRadius) {radius = newRadius;}
}
