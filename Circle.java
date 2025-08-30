import java.util.Scanner;
public class Circle
{
    int radius;

    public void getradius()
    {
        Scanner Sc = new Scanner(System.in);
        System.out.println("Enter Radius of Circle:");
        radius = Sc.nextInt(); //Read in Radius of Circle 
        Sc.close();
    }

    public double CircleArea()
    {
        double Area = Math.PI*radius*radius;
        return Math.round(Area* 100.0 ) / 100.0; //Round up two decimal Places 
    }
    public double CircleCircum()
    {
        double circumference = Math.PI*2*radius;
        return Math.round(circumference * 100.0) / 100.0; //Round up to two Decimal Places
    }
    public static void main(String[] args)
    {
        Circle C = new Circle();
        C.getradius();
        double area = C.CircleArea();
        System.out.println("The Area of the Circle is: " + area); //Print Area
        double circumference = C.CircleCircum();
        System.out.println("The Circumference of Circle is: " + circumference); //Prints Circumference
    }

}