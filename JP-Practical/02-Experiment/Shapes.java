class Shape {
    double area;
    public void calculateArea() {
        System.out.println("Area of the shape is: " + area);  // Base Class
    }
}

class Square extends Shape {
    double side;

    Square(double side) {
        this.side = side;
    }
    public void calculateArea() {
        super.area = side * side;
        System.out.println("Area of the square is: " + super.area);
    }
}

class Circle extends Shape {
    double radius;

    Circle(double radius) {
        this.radius = radius;
    }
    public void calculateArea() {
        super.area = Math.PI * radius * radius;
        System.out.println("Area of the circle is: " + super.area);
    }
}

class Rectangle extends Shape {
    double length, width;

    Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }
    public void calculateArea() {
        super.area = length * width;
        System.out.println("Area of the rectangle is: " + super.area);
    }
}

public class Shapes {
    public static void main(String[] args) { 
        Square square = new Square(5);
        square.calculateArea();
        Circle circle = new Circle(3);
        circle.calculateArea();
        Rectangle rectangle = new Rectangle(4, 6);
        rectangle.calculateArea();
    }
}