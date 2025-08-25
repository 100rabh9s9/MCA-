//Methods or Functions
//Syntax
// <returntype> MmthodName(<arguments>)
//{
 //   Body of Methods
//}
class Test 
{
    void testing()//Method Signature
    {
        System.out.println("Welcome to Method / Functions");//Method Definition
    }
}
class Testdemo
{
    public static void main(String[] args)
    {
            Test t1 = new Test();// Create object to call function 
            t1.testing();
    }
}
