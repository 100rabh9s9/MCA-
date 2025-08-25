import java.util.Scanner;
class Employees
{
	int empno;
	String empname,desig,dept;
}
class Empdemo
{
  public static void main(String args[])
  {
       
	Scanner sc = new Scanner(System.in);
	//int [] arr = new int[10];
	//arr[0] = 10;
	Employees[] emp = new Employees[5];
	 for(int i =0;i<5;i++)
	   {
	      emp[i] = new Employees();
		System.out.println("Enter Employee No:");
	      emp[i].empno = sc.nextInt();
		System.out.println("Enter Employee Name:");
	      emp[i].empname = sc.next();
		System.out.println("Enter Designation:");
	      emp[i].desig =sc.next();
		System.out.println("Enter Department:");
	      emp[i].dept = sc.next();
           }
		System.out.println("\nEmployee Details:");
       // for (int i = 0; i < 5; i++) 
	   for(Employees Empdemo: emp ) //For each Loop 
		{
            System.out.println("Employee No: " + Empdemo.empno);
			//System.out.println("Employee No:"+ emp[i].empno);
            System.out.println("Name: " + Empdemo.empname);
            System.out.println("Designation: " + Empdemo.desig);
            System.out.println("Department: " + Empdemo.dept);
			System.out.println("\n");
		}
		sc.close();
    }
  }
	//Employees e1 = new Employees();//constructor