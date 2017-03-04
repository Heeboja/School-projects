package bst;

import java.util.Scanner; //käytetään scannerluokkaa lukemaan konsolista


/*Testaus ja "käyttöliittymä"*/
class Harkka2b {
	
	private static Scanner scan;
	
	public static void main(String args[]) {
		
		scan = new Scanner(System.in);
		System.out.println("Binary search tree!\n");          
        char ch; //valinta jatkosta
		BinarySearchTree BST = new BinarySearchTree(); // puun alustus
		
		
		do {
			System.out.println("\nAvailable Operations\n");
	        System.out.println("1. Insert");
	        System.out.println("2. Display");
	        System.out.println("Enter operation: \n");
	        
	        int choice = scan.nextInt();   
	        
	        switch (choice) {
	        	
	        	case 1 : // Datan syöttö. Ensin avain, sitten data.
	        			System.out.println("\nInsert key [int] : \n");
	        			int k = scan.nextInt();
	        			System.out.println("\nInsert data [int] : \n");
	        			int d = scan.nextInt();
	        			BST.Insert(k, d);
	        			break;
	        	case 2 : // Datan tulostus avaimien järjestyksessä.
	        			System.out.println("\nComplete tree from left to right: \n");
	        			BST.Print();
	        			break;
	        	default :
	        			System.out.println("Wrong Entry \n "); // Tyhmien käyttäjien varalta.
	        			break;
	        }
	        
	        System.out.println("\nDo you want to continue (Type y or n) \n"); // jatkamisen ohjeistus
            ch = scan.next().charAt(0);  
	            	
		} while (ch == 'Y'|| ch == 'y'); // jatketaan ainoastaan jos jompikumpi noista syötetään.
	}

}
