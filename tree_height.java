import java.util.Scanner;

class Tree{
	
	private static class Node{
		public Node left;
		public Node right;
		public int value;
		public Node(){
			left=null;
			right=null;
			value=0;
		}
		public Node(int v){
			value=v;
			left=null;
			right=null;
	}
	}
	Node head;
	public Tree(){
		head=null;
	}
	public Tree(int a)
	{
		head=new Node(a);
	}
	
	void insert(int a){
		
		if(head==null)
		{
			head=new Node(a);
		}
		else {
			Node temp=new Node(a);
			Node driver=head;
			
			while(true)
			{
				if(a<driver.value)
				{
					if(driver.left==null)
					{
						driver.left=temp;
						break;
					}
					else
						
						driver=driver.left;
				}
				else {
					
					if(driver.right==null)
					{
						driver.right=temp;
						break;
					}
					else
						
					driver=driver.right;
				}
				
				
			}
		}
	}
	
	private int findH(Node node){
		
		if(node==null)
			return 0;
		
		int left=1+findH(node.left);
		int right=1+findH(node.right);
		
		return left<right?right:left;
	}
	
	public int height(){
		
		Node driver=head;
		
		if(driver==null)
		return 0;
		
		else
		{
			return findH(driver);
		}
	}
}

class tree_height{

	public static void main(String...strings){
		
		int num=0;
		
		Scanner input=new Scanner(System.in);
		System.out.println("Enter Integer Data one-by-one, press -1 to finish");
		
		int i=0;
		Tree tree=new Tree();
		while(true)
		{
			num=input.nextInt();
			if(num==-1)
				break;
			tree.insert(num);
		}
		System.out.println("Height OF the Tree : "+   tree.height());
	}
}
