// Base class
class Vehicle 
{
    void start() 
    {
        System.out.println("Vehicle started.");
    }

    void stop() 
    {
        System.out.println("Vehicle stopped.");
    }
}

// Derived class
class Car extends Vehicle 
{
    void honk()
    {
        System.out.println("Car horn is honking!");
    }
    public static void main(String[] args) 
    {
        Car myCar = new Car();
        
        myCar.start(); // inherited from Vehicle
        myCar.stop();  // inherited from Vehicle
        myCar.honk();  // defined in Car
        
    }
}
