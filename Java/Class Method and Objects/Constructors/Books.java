class Book 
{
    String title;
    String author;
    double price;

    // Default constructor
    public Book()
     {
        title = "Book Title";
        author = "Author of Book";
        price = 0.00;
    }
    // Parameterized Constructors

    // Constructor with title and author
    public Book(String t, String a)
     {
        title = t;
        author = a;
        //price = 0.00; // default price if not provided
    }

    // Constructor with title, author, and price
    public Book(String t, String a, double p)
     {
        title = t;
        author = a;
        price = p;
    }

    // Method to print book details
    public void printDetails() {
        System.out.println("Title: " + title);
        System.out.println("Author: " + author);
        System.out.println("Price: " + price);
    }
    public static void main(String[] args) {
        
        Book b1 = new Book(); // Using default constructor
        b1.printDetails();

        System.out.println();

        // Using constructor with title and author
        Book b2 = new Book("Java", "James Gosling");
        b2.printDetails();

        System.out.println();

        // Using constructor with title, author, and price
        Book b3 = new Book("OOP", "Alan Kay.", 99.99);
        b3.printDetails();
    }
}
