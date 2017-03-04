package harkka2a;

/*
 *  Java Program to Implement Sorted Doubly Linked List
 */
 
import java.util.Scanner;
 
/* Class SortedDoublyLinkedList */
public class Harkka2a
{
    private static Scanner scan;

	public static void main(String[] args)
    {             
        scan = new Scanner(System.in);
        linkedList list = new linkedList(); 
        System.out.println("Sorted double linked list ring\n");          
        char ch;
        /*  Perform list operations  */
        do
        {
            System.out.println("\nSorted Doubly Linked List Operations\n");
            System.out.println("1. insert");
            System.out.println("2. delete certain integer");
            System.out.println("3. search");
            System.out.println("4. display");
            System.out.println("5. display backwards");
            
            int choice = scan.nextInt
            		();            
            switch (choice)
            {
            case 1 : 
                System.out.println("Enter integer to insert. Do not insert characters or otherwise it will crash!\n");
                list.insert( scan.nextInt() );                     
                break;                          
            case 2 :
            	System.out.println("Enter integer to be deleted\n");
                int t = scan.nextInt() ;
                if (list.search(t)==false) {
                	System.out.println("No such integer!\n");
                	break;
                }
                list.delete(t);
            	break;                   
            case 3 : 
            	System.out.println("Search for integer: \n");
            	if(list.size == 0)	{
            		System.out.print("\nEmpty List");
            		break;
            	}
            	t = scan.nextInt() ;
            	if(list.search(t)== true)
            		System.out.println( t + " found!\n");
            	else 
            		System.out.println(t + " not found!\n");
                break;  
            case 4 : 
            	list.display();
            	break;
            case 5 : 
                list.display_backwards();
                break;
            default : 
                System.out.println("Wrong Entry \n ");
                break;   
            }
            
            System.out.println("\nDo you want to continue (Type y or n) \n");
            ch = scan.next().charAt(0);            
        } while (ch == 'Y'|| ch == 'y');               
    }    
