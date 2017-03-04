package bst;
/*Treenode luokka*/
public class TNode {
	/*Sisältää nyt kaksi inttiä: element(avain) ja data*/
	protected int Element;
	protected int Data;
	protected TNode Left;
	protected TNode Right;
	
	public TNode (int O, int D , TNode NewL, TNode NewR) {
		this.Element = O; 
		this.Data = D;
		this.Left = NewL; 
		this.Right = NewR;
	}

	/* Lisäys. Ensin tarkistetaan avaimen suuruus nykyiseen, jos   *
	 * alkio on ensimmäinen, tehdään siitä juuri                   */
	public TNode Insert(int X, int D) {
		/*Onko avaimeltaan pienempi?*/
		if ( X < Element ) {
			
			if (Left == null) {
				Left = new TNode(X, D, null, null);
				return Left;
			}
			else
				return Left.Insert(X, D);	 // rekursiolla eteenpäin		
		}
		/*Onko avaimeltaan suurempi?*/
		else if ( X > Element ) {
				if (Right == null) {
					Right = new TNode(X, D, null, null);
					return Right;
				}
			else
				return Right.Insert(X, D);	// rekursiolla eteenpäin
			
		}
		else
			return this;	
	}
	
	/*Monisteen Print-luokka ei toiminut, joten aikalailla erillainen toteutus järjestyksessä tulostamiseen.*/
	public void Print(TNode node) {
		if (node != null) {
			Print(node.Left);
			System.out.print(node.Data + ", ");
			Print(node.Right);
			
		}
	}
}	
