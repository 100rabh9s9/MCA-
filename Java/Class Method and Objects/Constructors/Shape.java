//Create a class Shape which contains the methods to calculate the area of Triangle, Rectangle, Circle and Square
import java.util.Scanner;

class Shape 
{
    // Area of Triangle
    public double area(double base, double height)
    {
        return 0.5 * base * height;
    }
    // Area of Rectangle
    public double area(double length, double width, boolean isRectangle)
    {
        return length * width;
    }
    // Area of Circle
    public double area(float radius) 
    {
        return Math.PI * radius * radius;
    }
    // Area of Square
    public int area(int side) 
    {
        return side * side;
    }
    public static void main(String[] args)
    {
        Scanner Sc = new Scanner(System.in);
        Shape shape = new Shape();

        System.out.println("Choose Shape to Calculate Area:");
        System.out.println("1. Triangle");
        System.out.println("2. Rectangle");
        System.out.println("3. Circle");
        System.out.println("4. Square");
        System.out.print("Enter your choice (1-4): ");
        int choice = Sc.nextInt();
        switch (choice)
         {
            case 1: // Triangle
                System.out.print("Enter base: ");
                double base = Sc.nextDouble();
                System.out.print("Enter height: ");
                double height = Sc.nextDouble();
                System.out.println("Area of Triangle: " + shape.area(base, height));
                break;

            case 2: // Rectangle
                System.out.print("Enter length: ");
                double length = Sc.nextDouble();
                System.out.print("Enter width: ");
                double width = Sc.nextDouble();
                System.out.println("Area of Rectangle: " + shape.area(length, width));
                break;

            case 3: // Circle
                System.out.print("Enter radius: ");
                float radius = Sc.nextFloat();
                System.out.println("Area of Circle: " + shape.area(radius));
                break;

            case 4: // Square
                System.out.print("Enter side: ");
                int side = Sc.nextInt();
                System.out.println("Area of Square: " + shape.area(side));
                break;

            default:
                System.out.println("Invalid choice!");
        }
        Sc.close();
    }
}

