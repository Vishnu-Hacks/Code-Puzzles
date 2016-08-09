import java.io.*;
import java.util.Stack;

class Char{
	
	char ch;
	int pos;
	Char(char a,int i){
		ch=a;
		pos=i;
	}
}

class check_brackets{
	
	public static void main(String...strings)
	{
		 try {
		 
			 InputStreamReader input_stream = new InputStreamReader(System.in);
	     
			 BufferedReader reader = new BufferedReader(input_stream);
	        
			 
			 String text = reader.readLine();
			 Stack<Char> s1=new Stack();
			 Boolean error=false;
			 char ch;
			 for(int i=0;i<text.length();++i)
			 {
				 ch=text.charAt(i);
				 if(ch=='(' || ch=='{'|| ch=='[')
				 {
					 s1.push(new Char(ch,i));
					
				 }
				 else if(ch==')' || ch=='}'|| ch==']')
				 {
					 if(!s1.empty())
					 {
						 Char a=s1.pop();
						 if(a.ch=='('&&ch!=')')
						 {
							 System.out.println("Mismathcing in "+i);error=true;
							 break;
						 }
						 if(a.ch=='{'&&ch!='}')
						 {
							 System.out.println("Mismathcing in "+i);error=true;
							 break;
						 }
						 if(a.ch=='['&&ch!=']')
						 {
							 System.out.println("Mismathcing in "+i);error=true;
							 break;
						 }
						 
					 } // end of s1.empty()
					 else{
						 System.out.println("No opening for "+ch+" at " +i);error=true;
						 break;
					 }
				 }// end of else
			 }// end 4 loop
			 if(!s1.empty() && !error)
			 {
				 System.out.println("No Sufficent Closinig bracekts");error=true;
				 
			 }
			 
			 if(!error)
				 System.out.println("Sucess");
			 }
		 
			 catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		
	}
}
