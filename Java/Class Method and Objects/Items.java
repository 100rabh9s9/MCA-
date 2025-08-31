//Write down a javaprogram to declare a class Items with the instance variables itemno,itename,quantity and price
//Define method input to store the values into the variables amd another method to print the Same
//Store 3 item details 
import java.util.Scanner;

public class Items 
{
    int itemno;
    String itemname;
    int quantity;
    Double price;

    public void inputItems(Scanner sc) //Input details 
    {
        System.out.print("Enter Item No: ");
        itemno = sc.nextInt();
        sc.nextLine(); // For  newline
        System.out.print("Enter Item Name: ");
        itemname = sc.nextLine();
        System.out.print("Enter Quantity: ");
        quantity = sc.nextInt();
        System.out.print("Enter Price: ");
        price = sc.nextDouble();
    }

    public void printItemDetail() 
    {
        System.out.println("Item No: " + itemno);
        System.out.println("Item Name: " + itemname);
        System.out.println("Quantity: " + quantity);
        System.out.println("Price: " + price);
        System.out.println();
    }

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        final int ITEM_COUNT = 3;
        Items[] items = new Items[ITEM_COUNT]; //Array for Storing The Values (3 since specified)

        for (int i = 0; i < ITEM_COUNT; i++) 
        {
            System.out.println("\n Enter details for item " + (i + 1));
            items[i] = new Items();
            items[i].inputItems(sc);
        }

        System.out.println("\nItem Details:");
        for (int i = 0; i < 3; i++) 
        {
            items[i].printItemDetail();
        }

        sc.close();
    }
}

