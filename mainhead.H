class jobs{
	    public:
	    char avail[80];
	    char details[100];
	    void jobs_feed();
	    void jobs_view();
	  }jo;

class recent{
	       public:
	       char date[10];
	       char strrecent[200];
	       void recent_feed();
	       void recent_view();
	     }re,re2;

class device{
	       public:
	       char device[80];
	       char devices_details[80];
	       void devices_feed();
	       void devices_view();
	    }de;
class os{
	   public:
	    char dateos[10];
	    char newos[30];
	    char whatsnewos[200];
	    void os_feed();
	    void os_view();
	 }os;

class dloads{
	      public:
	      char newdload[30];
	      char datedload[10];
	      char whatsnewdload[100];
	      void dloads_feed();
	      void dloads_view();
	    }dl;

class email{
	      public:
	      char emailsub[40];
	      char emailcontent[200];
	      void email_feed();
	      void email_view();
	    }em;



