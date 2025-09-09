/*create a class Student with the instance variables name, rollNumber, and course to store data for each Student object.
 *The class should have a parameterized constructor to initialize the instance variables with values passed during object creation.
 *The class should also have a default constructor to create a Student object without providing initial values and setting default values for the instance variables
 * Define a method displayStudentDetails() which prints the details of a Student object to the console.
 * The class should also contain an updateCourse(String course) method which modifies the course instance variable of a Student object.
 * 
*/
import java.util.Scanner;
class Student
{
    int rollNumber;
    String Name;
    String course;

    Student()//Default Constructor 
    {
        rollNumber = 0;
        Name = "Student Name";
        course = "Course Name";
    }
    Student(int rno,String Sname,String coursename)//Parameterized Constructor 
    {
        rollNumber = rno;
        Name = Sname;
        course = coursename;
    }
    void displayStudentDetails()
    {
        System.out.println("Roll Number:"+rollNumber);
        System.out.println("Name: "+Name);
        System.out.println("Course: "+course);
    }
    void updateCourse(String newCourse)
     {
        this.course = newCourse;
    }
    public static void main(String[] args)
    {
        Scanner Sc = new Scanner(System.in);

        System.out.println("Student Detail  From  default constructor:");
        Student dStudent = new Student();
        dStudent.displayStudentDetails();

        // System.out.println("Enter Number of Students:")
        // int n =Sc.nextInt();

        // Student[] S = new Student[];
        // for(int i = 0;i < n ; i++)
        // {

        // }

        
        System.out.println("\nEnter details :");
        System.out.print("Enter Roll Number: ");
        int rollNumber = Sc.nextInt();
        Sc.nextLine(); 

        System.out.print("Enter Name: ");
        String name = Sc.nextLine();

        System.out.print("Enter Course: ");
        String course = Sc.nextLine();

        Student pStudent = new Student(rollNumber, name, course);

        System.out.println("\n----- Student Details ");
        pStudent.displayStudentDetails();

        // Update course
        System.out.println("\nUpdating course...");
        System.out.print("Enter new course: ");
        String newCourse = Sc.nextLine();
        pStudent.updateCourse(newCourse);

        System.out.println("\n----- Updated Student Details -----");
        pStudent.displayStudentDetails();

        Sc.close();
    }

}