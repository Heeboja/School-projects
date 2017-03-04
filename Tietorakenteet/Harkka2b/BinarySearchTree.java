package bst;
/*Pääluokka käyttää TNode luokkaa.*/
public class BinarySearchTree {
		
	protected TNode Root;
	protected TNode LastFound;
	public BinarySearchTree() {
		Root = null;
		LastFound = null;
	}

	/*Lisäys. Tehdään uusi juuri. Jos tyhjä niin uusi juuri on samalla edellinen.*/
	public void Insert(int X, int D) {
		if (Root == null) {
			Root = new TNode(X, D, null, null);
			LastFound = Root;
		}
		else {
			LastFound = Root.Insert(X, D);
		}
	}
	
	/*Tulostaa puun pienimmästä suurimpaan.*/
	public void Print() {
		Root.Print(Root);
	}
}
		

