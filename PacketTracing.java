import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Packet{
	
	long arrival;
	long time;
	static long time_check=0;
	Packet(long a,long b) throws Exception
	{
		arrival=a;
		time=b;
		timeCheck();
		time_check=arrival;
	}
	// Checks whether the arrival time of the new packets is given a past time than of the last packet..."time never goes back"
	void timeCheck() throws Exception{
		if(arrival<time_check)
		throw new Exception("Arrival time should be non-descending");
	}
	
	static public  void dropPacket(Packet p)
	{
		System.out.println("Arrived At :"+p.arrival+" -- Dropped --"); 
	}

	static public void processPacket(long curr,Packet p)
	{
		System.out.println("Arrived At :"+p.arrival+" Started at:"+curr+"  Finished at:"+(p.time+curr));
	}
}
  
class PacketTracing{

	static public void main(String...strings){
		
		try{
		 long buf=0;
		 System.out.println("Enter The Buffer Size : ");
		 Scanner in=new Scanner(System.in);
		 buf=in.nextLong();
		 
		 LinkedList<Packet> buffer=new LinkedList(); // for buffer
		 LinkedList<Packet>waitlist =new LinkedList(); // for waitlist new packets after buffer size
		 
		 System.out.println("How many Packets You have" );
		 long num=in.nextLong();
		 
		 System.out.println("Enter The Packets  arrivial & processing time");
		 while(num!=0)
		 {
			waitlist.add(new Packet(in.nextLong(),in.nextLong()));
			--num;
		 }
		 
		 while(buffer.size()<buf)
		 {
			 buffer.add(waitlist.removeFirst());
		 }
		 
	     long current_time=buffer.getFirst().arrival;
		 long end_time = current_time;
		 
		 // 1.Fills the buffer (above)
		 // 2.Process the packets in the buffer
		 // 3.Refills the Buffer and drops the packets that came before processing the buffer
		 // 4.continue 2 , until no more packets in the queue
		 
		 while(true)
		 {
			 while(!buffer.isEmpty()){
				
			 // if any packet arrive after finishing the previous process in the buffer
			 if(buffer.getFirst().arrival>end_time)
			 {
				 System.out.println("System wait for :"+(buffer.getFirst().arrival-end_time));
				 end_time=buffer.getFirst().arrival+buffer.getFirst().time;
				 current_time=buffer.getFirst().arrival;
			 }
			 else
				 end_time+=buffer.getFirst().time; // time after process
			 
			 Packet.processPacket(current_time,buffer.removeFirst()); // go to process
			 current_time=end_time;		// after processing,current time becomes the end time
			 
			 }
			 
			 if(waitlist.isEmpty())
				 break;
			 
			 while(!waitlist.isEmpty() )
			 {
				 if(waitlist.getFirst().arrival<current_time){  
					// System.out.println(waitlist.getFirst().arrival+"  "+current_time);
					 Packet.dropPacket(waitlist.removeFirst());
				 }
				 else{
					// System.out.println(waitlist.getFirst().arrival+"  "+current_time);
					 buffer.add(waitlist.removeFirst());
					 if(buffer.size()>=buf) // refilling buffer
						 break;
				 }
			 }
		 }
		 
		 
		 
		}
		catch(Exception e)
		{
			System.out.println(e.getMessage());
		}
	}
}
