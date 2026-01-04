#include <A_Event.h> 
#include <packet.h>
#include <Cframe.h>
#include <framePackets.h>
#include <dataBlock.h>
#include <frameRoutines.h>
#include <frameHdr.h>


#include <iostream.h>
#include <stdlib.h>
#include <unistd.h>
#include <fileEventiterator.h>
#include <phenixTypes.h>
#include <oBuffer.h>
#include <oEvent.h>
#include <stdio.h>

// The global pointer to the Eventiterator (we must be able to 
// get at it in the signal handler) 
Eventiterator *it;
oBuffer *ob;

class X_Event : public A_Event 
{

public:
  // constructors and destructors
  X_Event( DWORD *);
  X_Event( int *);
  ~X_Event();

  DWORD* getFrameListPointer(const int fi);

};

X_Event::X_Event (DWORD *data)
  : A_Event(data)
{ }

X_Event::X_Event (int *data)
  : A_Event(data)
{ }

X_Event::~X_Event ()
{ }

DWORD* X_Event::getFrameListPointer(const int fi)
{  
  return framelist[fi];
}



int 
main(int argc, char *argv[])
{
  int c;
  int status;

  int verbose = 0;
  int identify = 0;
  int maxevents = 0;
  int eventnr = 0;
  int eventnumber =0;
  int countnumber =0;

  DWORD  *buffer;
  FILE *filep;
  int buffer_size = 256*1024*16;  // makes 16MB (specifies how many dwords, so *4)

  // see if we can open the file
  it = new fileEventiterator(argv[2], status);

  if (status)
    {
      delete it;
      cout << "Could not open input stream" << endl;
      exit(1);
    }

  // now we'll see where the data go to
  
  filep = fopen (argv[1], "w");
  if (!filep) 
    {
      cout << "Could not open file: " <<  argv[optind+1] << endl;
      exit (1);
    }

  buffer = new DWORD [buffer_size];
  
  ob = new oBuffer (filep, buffer, buffer_size);

  cout << "starting " << endl;
  // ok. now go through the events
  Event *evt;

  X_Event *nevt;
  X_Event *fevt;
  int *eb;
  int nw;
  int j;
  int *fb;
  int framelen;

  int run;
  int count = 0;
  int i = 0;
  int cntr;
  DWORD *fp ;
  DWORD *fp2 ;
  DWORD *pp;
  DWORD *c_w_p;                         // current write pointer
  int ev_l;                           // initial write pointer ( points to end of real event )
  int fr_l;
  int eofe;
  int new_ev_l;
  int dc_pid,old_pid,new_pid;
  int cnt = 2;
  Packet* pack;
 
  while (count<1000000)
    {
      evt = it->getNextEvent();
      if (!evt&&cnt<argc)
	{
	  cnt++;
	  cout<<"New file opened "<<argv[cnt]<<endl;
	  delete it;
	  it = new fileEventiterator(argv[cnt], status);
	  if (status)
	    {
	      delete it;
	      cout << "End of the file list" << endl;
	      goto End;
	    }
	  
	  evt = it->getNextEvent();

	}

      if (!(pack = evt->getPacket(3001)))
	{ 
	  cout<<"Fuck this event"<<endl;
	  continue;
	}

      count++;                                       // Event counter
 
      if (count%1000==1)    {
	cout<<count<<" ";evt->identify();                               // Print event info
      }
      ev_l = evt->getEvtLength();
      eb = new int [ev_l+100];                      // create event buffer to store one event + fake packets
      fb = new int [ev_l+100];                      // create temporary buffer to modify frames;
          
      evt->Copy (eb, ev_l+100, &nw);                // Copy evt to input event buffer
      evt->Copy (fb, ev_l+100, &nw);                // Copy evt to output event buffer
    
      delete evt;                                    // Do not need evt anymore, use eb instead;
      
      nevt = new X_Event(eb);                        // create A_Event to get access to frame pointer list
      fevt = new X_Event(fb);
      
      new_ev_l = 8;
      cntr = 0;                                      // frame counter
          
      while (fp = nevt->getFrameListPointer(cntr++))                          // pointer to the frame
	{	
	  new_ev_l += 8;
	  fp2 = fevt->getFrameListPointer(cntr-1);
	  c_w_p = fp2+8;
	  fr_l = 8;
	 
//  	  for (dc_pid = 14001; dc_pid<14003; dc_pid++) 
//  	    {
//  	      if ( ( pp = findFramePacketId (fp, dc_pid) ) !=  ptrFailure) 
//  		{
//  		  framelen = pp[0];
//  		  if (framelen==0) cout<<"________________________________"<<endl;
//  		  memcpy(c_w_p,pp,4*framelen);
//  		  c_w_p+= framelen;
//  		  new_ev_l  += framelen;
//  		  fr_l +=framelen;
//  		  *fp2 += framelen;
//  		}
//  	    }
	  
//  	  if ( ( pp = findFramePacketId (fp, 1001) ) !=  ptrFailure) 
//  	    {
//  	      framelen = pp[0]; 
//  	      memcpy(c_w_p,pp,4*framelen);
//  	      c_w_p+= framelen;
//  	      new_ev_l  += framelen;
//  	      fr_l +=framelen;
//  	      *fp2 += framelen;
//  	    }

//  	  if ( ( pp = findFramePacketId (fp, 13001) ) !=  ptrFailure) 
//  	    {
//  	      framelen = pp[0]; 
//  	      memcpy(c_w_p,pp,4*framelen);
//  	      c_w_p+= framelen;
//  	      new_ev_l  += framelen;
//  	      fr_l +=framelen;
//  	      *fp2 += framelen;
//  	    }
	 
	   for (dc_pid = 3001; dc_pid<3161; dc_pid++) 
	     {
	       if ( ( pp = findFramePacketId (fp, dc_pid) ) !=  ptrFailure) 
		 {
		   framelen = pp[0];
		   if (framelen>27&& framelen<200) 
		     {
		       //		       cout<<framelen<<endl;
		       memcpy(c_w_p,pp,4*framelen);
		       c_w_p+= framelen;
		       new_ev_l  += framelen;
		       fr_l +=framelen;
		       *fp2 += framelen;
		     }
		   else if (framelen>1000) cout<<dc_pid<<"\t"<<framelen<<endl;
		 }
	     }
	   *fp2=fr_l;
	}

      *fb = new_ev_l;                                    //  update event length 
      
      // *c_w_p= eofe;                              //  restore eof_event word

      delete nevt;                                   //  delete event 
      delete fevt;
      nevt = new X_Event(fb);                        //  and try to decode it from the modified event buffer
      //nevt->identify();                              //  Second print-out of modified event 
      ob->addEvent(nevt);	                         //  Save it to the file
      
      delete [] eb;
      delete [] fb;
      
      delete nevt;
    }

  delete it;
 End:
  delete ob;
  fclose(filep);
  
  return 0;
}



  






