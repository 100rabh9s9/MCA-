// Write down a java program to define a class bank with instance vairables accno,name,acctype and balamt. 
// Define a method to sotre  the values into the variables and another method to display the same.
// Define an object and call the method
import java.util.Scanner;

//import org.omg.CORBA.TypeCodePackage.BadKind;
class bank
{
    int accno;
    String name,acctype;
    float balamt;

    public static void main(String[] args)
     {
         bank B = new bank();
         B.inputdetail();
         B.printdetails();
        
    }
    public void inputdetail()
    {
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Enter Account Number:");
        accno = sc.nextInt();
        System.out.println("Enter Name : ");
        name = sc.next();
        System.out.println("Enter Account Type:");
        acctype = sc.next();
        System.out.println("Enter Balance:");
        balamt = sc.nextFloat();
        sc.close();
    }
    public void printdetails()
    {
        System.out.println("\n");
        System.out.println("Details: ");
        System.out.println("\n");
        System.out.println("Account Number:"+this.accno);
        System.out.println("Name:"+this.name);
        System.out.println("Account Type:"+this.acctype);
        System.out.println("Balance in Account :"+this.balamt);
    }
}
