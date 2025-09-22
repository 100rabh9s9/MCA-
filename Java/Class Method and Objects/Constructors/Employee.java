/*Write a java program which creates a class Person with the instance variable name and method getName() to return the name. 
 * The class should have a parameterised constructor which takes name as the argument and assign it in the instance variable. 
 * Derive a class Employee from the class Person and the derived class should have an instance variable id.
 * The class should have a method getId() to return the id and a parameterised constructor which takes id and name
 *  as the parameters to assign the values in the corresponding instance variables of the classes using its constructors.
 *  Display the assigned values using the getName() and getId() methods.
 */
//22/09/2025 Monday
class Person
{
    String name;
    public String getName()
    {
        return name;
    }
    Person(String name)
    {
        this.name = name ; //Refer to current Object 
        //System.out.println("The Name is :"+name);
    }
}
class Employee extends Person
{
    int id;
    Employee(int id, String name) 
    {
        super(name);  
        this.id = id; 
    }
    int getId() 
    {
        return id;
    }
//public class Main 
//{
    public static void main(String[] args)
     {
        Employee emp = new Employee(101, "John Doe");
        System.out.println("Employee Name: " + emp.getName());
        System.out.println("Employee ID: " + emp.getId());
    }
}