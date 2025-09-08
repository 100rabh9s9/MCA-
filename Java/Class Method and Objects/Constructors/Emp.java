/*create a Class named Emp with a method to display a message.
Write down a java program to invoke the method and display the message */
/*08/09/2025 Monday*/ 

class Emp
{
    int empno;
    String empname;

    Emp() //Default Constructor
    {
        empno = 0;
        empname = "Name Please";
    }

    Emp(int no, String name) // Parameterized Constructor
    {
        empno = no;
        empname =name;
        System.out.println("From constructor");
    }
    public void display()//Method
    {
        System.out.println("Welcome  "+empno+" , "+empname);
    }
    public static void main(String[] args)
    {
    Emp e1 = new Emp(101,"Mujeeb"); //Default Constructor 
    e1.display();

    Emp e2 = new Emp(102,"Shyam");
    e2.display();
    
    Emp e3 = new Emp();
    e3.display();
    }

}