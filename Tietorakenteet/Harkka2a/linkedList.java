package harkka2a;

public class linkedList
{
    protected Node start;
    public int size;
 
    /* Constructor */
    public linkedList()
    {
        start = null;
        size = 0;
    }
    /* Function to check if list is empty */
    public boolean isEmpty()
    {
        return start == null;
    }
    /* Function to get size of list */
    public int getSize()
    {
        return size;
    }
    /* Function to insert element */
    public void insert(int val)
    {
    	if(search(val)== true) {
    		System.out.println("Integer already exists, pick a new one.\n");
    		return; 
    	}
    	
    	Node nptr = new Node(val, null, null);
        Node tmp, ptr;        
        boolean ins = false;
        if(start == null)
            start = nptr;
        else if (val <= start.getData())
        {
            nptr.setLinkNext(start);
            start.setLinkPrev(nptr);
            start = nptr;
        }
        else
        {
            tmp = start;
            ptr = start.getLinkNext();
            while(ptr != null)
            {
                if(val >= tmp.getData() && val <= ptr.getData())
                {
                    tmp.setLinkNext(nptr);
                    nptr.setLinkPrev(tmp);
                    nptr.setLinkNext(ptr);
                    ptr.setLinkPrev(nptr);
                    ins = true;
                    break;
                }
                else
                {
                    tmp = ptr;
                    ptr = ptr.getLinkNext();
                }
            }
            if(!ins)
            {
                tmp.setLinkNext(nptr);
                nptr.setLinkPrev(tmp);
 
            }
        }
        size++;
    }
    /* Function to delete node at position */
    public void deleteAtPos(int pos)
    {        
        if (pos == 1) 
        {
            if (size == 1)
            {
                start = null;
                size = 0;
                return; 
            }
            start = start.getLinkNext();
            start.setLinkPrev(null);
            size--; 
            return ;
        }
        if (pos == size) 
        {
            Node ptr = start;
 
            for (int i = 1; i < size - 1; i++)
                ptr = ptr.getLinkNext();
            ptr.setLinkNext(null);            
            size --;
            return;
        }
        Node ptr = start.getLinkNext();
        for (int i = 2; i <= size; i++)
        {
            if (i == pos)
            {
                Node p = ptr.getLinkPrev();
                Node n = ptr.getLinkNext();
 
                p.setLinkNext(n);
                n.setLinkPrev(p);
                size-- ;
                return;
            }
            ptr = ptr.getLinkNext();
        }        
    }
    
    public void delete(int delete)
    {   
    	int pos = 1;
    	Node ptr = start;
    	for( ; ptr != null; ptr = ptr.getLinkNext())	{
    		if(ptr.getData() == delete) {
    			deleteAtPos(pos);
    		}
    		pos++;
    	}
    	        
    }
    /* Function to display status of list */
    public void display()
    {
        System.out.print("List = ");
        if (size == 0) 
        {
            System.out.print("empty\n");
            return;
        }
        if (start.getLinkNext() == null) 
        {
            System.out.println(start.getData() );
            return;
        }
        Node ptr = start;
        System.out.print(start.getData()+ " , ");
        ptr = start.getLinkNext();
        while (ptr.getLinkNext() != null)
        {
            System.out.print(ptr.getData()+ " , ");
            ptr = ptr.getLinkNext();
        }
        System.out.print(ptr.getData()+ "\n");
    }
    
    public void display_backwards()
    {
        System.out.print("List = ");
        if (size == 0) 
        {
            System.out.print("empty\n");
            return;
        }
        if (size == 1) 
        {
            System.out.println(start.getData() );
            return;
        }
        Node ptr = start;
        while (ptr.getLinkNext() != null)
        {
            ptr = ptr.getLinkNext();
        }
        while (ptr.getLinkPrev() != null) {
        	System.out.print(ptr.getData()+ " , ");
        	ptr = ptr.getLinkPrev();
        }
        System.out.print(ptr.getData()+ "\n");
    }
 
    public boolean search(int search) {
    	Node ptr = start;
    	for( ; ptr != null; ptr = ptr.getLinkNext())	{
    		if(ptr.getData() == search) {
    			return true;
    		}
    	}
    	return false;
    }
}
