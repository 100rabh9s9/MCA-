import java.util.Scanner; //

class Employee
{
    int emno; // Instance Variables declared within the class but outside a function
    String empname;
    String designation;
}
class Employeedetails
{
    public static void main(String [] args)
    {
        Scanner sc = new Scanner(System.in); // sc is object name can be anything 

        Employee emp1 = new Employee(); //Employee 1
        System.out.println("Enter Employee Number:");
        emp1.emno=sc.nextInt();//nextInt for storing in integer values 
        System.out.println("Enter Employee Name:");
        emp1.empname=sc.next(); //
        System.out.println("Enter Designation:");
        emp1.designation=sc.next();
        //System.out.println("Employee 1");
        System.out.println(emp1.emno);
        System.out.println(emp1.empname);
        System.out.println(emp1.designation);

        Employee emp2 = new Employee();//Employee 2
        emp2.emno = 102;
        emp2.empname = "Scott";
        emp2.designation = "Engineer";
       // System.out.println("Employee 2");
        System.out.println(emp2.emno);
        System.out.println(emp2.empname);
        System.out.println(emp2.designation);
        
        Employee emp3 = new Employee(); //Employee 3 
        emp3.emno = 103;
        emp3.empname = "Will";
        emp3.designation ="Officer";
        //System.out.println("Employee 3");
        System.out.println(emp3.emno);
        System.out.println(emp3.empname);
        System.out.println(emp3.designation);
        sc.close();
    }
}