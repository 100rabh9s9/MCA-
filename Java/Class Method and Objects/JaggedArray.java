import java.util.Scanner;

public class JaggedArray {
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);

        // number of rows in the jagged array
        System.out.print("Enter the number of rows in the jagged array: ");
        int rows = scanner.nextInt();

        // jagged array
        int[][] jaggedArray = new int[rows][];

        // Populate the jagged array
        for (int i = 0; i < rows; i++) 
        {
            System.out.print("Enter the number of elements in row " + (i + 1) + ": ");
            int columns = scanner.nextInt();

            // Create the sub-array with the user-defined number of columns
            jaggedArray[i] = new int[columns];

        
            System.out.println("Enter " + columns + " elements for row " + (i + 1) + ":");
            for (int j = 0; j < columns; j++) 
            {
                System.out.print("Element " + (j + 1) + ": ");
                jaggedArray[i][j] = scanner.nextInt();
            }
        }
        System.out.println("\nThe elements of the jagged array are:");
        for (int i = 0; i < rows; i++) 
        {
            System.out.print("Row " + (i + 1) + ": ");
            for (int j = 0; j < jaggedArray[i].length; j++) 
            {
                System.out.print(jaggedArray[i][j] + " ");
            }
            System.out.println();
        }

        // Close the scanner
        scanner.close();
    }
}