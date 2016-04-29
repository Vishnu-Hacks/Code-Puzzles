import java.util.Scanner;

/*
 Problem Introduction
 ====================
You are given a set of segments on a line and your goal is to mark as few points on a line as possible so that
each segment contains at least one marked point.
Problem Description

Task
====
 Given a set of n segments {[a0, b0], [a1, b1], . . . , [an−1, bn−1]} with integer coordinates on a line, find
the minimum number m of points such that each segment contains at least one point. That is, find a
set of integers X of the minimum size such that for any segment [ai, bi] there is a point x ∈ X such that ai ≤ x ≤ bi.

 */


public class Covering_Line_Segment {

	public static void main(String...strings){
		
		int num;
		Scanner in =new Scanner(System.in);
		System.out.print("Enter The NUmber Of Coordinates : ");
		num=in.nextInt();
		int[]x=new int[num];
		int[]y=new int [num];
		int x2=0;
		int y2=0;
		System.out.println("\nNow Enter the Coordinates " );
		for(int i=0;i<num;++i){
		
			x2=in.nextInt();
			y2=in.nextInt();
			x[i]=x2<y2?x2:y2;
			y[i]=x2>y2?x2:y2;
		}
		
		findSegments(x,y,num);
		
	}
	// Defect segments with 2 more same lowest x , makes soome problem
	// ex: 1,3  1,10 1,6 etc   //TODO later
	
	//Other repeating points are okay unless it is not lowest
	//ex : 1,3   2,4    2,6   2,7    3,1    3,6  etc are okay
	public static void findSegments(int[]x,int[]y,int num){

		sort(x,y,num);
		boolean disjoint=false; 
		
		int from=0;int to=0;
		int m=0;
		int limit=y[from];
		int i=0;
		int min=0;
		do{
			 disjoint=false; 
			 limit=y[to];
			// cheking for disjoint segments
			for( i=from;i<num;++i){
				if(x[i]>limit){
					disjoint=true;
					break;
				}
			}
			to=i;
			
			// finding the common point untill the disjoint part or till the end
			for(int j=from;j<to-1;++j){
				
	            System.out.println(x[j]+ " "+ y[j]);
				if(y[j]<y[j+1])
					min=y[j];
				else
					min=y[j+1];
			
			}
			   System.out.println(x[to-1]+ " "+ y[to-1]);
			   
				System.out.println("\nNO: of Points Are : "+(min-x[to-1]+1));
				while(min>=x[to-1]){
					System.out.print(min-- +" ");
				}
			System.out.println("\n");
			from=to;		
			
		}while(disjoint==true && from<num);
		
	}
	
	public static void sort(int[]x,int[]y,int num){
		int temp=0;
		
		for(int i=0;i<num-1;++i){
			for(int j=1+i;j<num;++j){
				if(x[i]>x[i+1])
				{
					temp=x[i];
					x[i]=x[i+1];
					x[i+1]=temp;
					
					temp=y[i];
					y[i]=y[i+1];
					y[i+1]=temp;
				}
			}
		}
	}
}
