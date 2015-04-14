#include "galileogpio.h"
#include <unistd.h>

int main(int argc, char ** argv)
{
    // Controlling Digital IO 8  
    exportIO(IO8);

    // IO 8 is output
    direction(IO8,OUT);

    // IO 8 drive is strong
    drive(IO8,STRONG);

    int i;
    for (i=1; i<11; i++)
    {
        // IO 8 is high.	
	setDigital(IO8,HIGH);
	 
        // Wait 500ms.
        usleep(500000);
	
	// IO 8 is low.
	setDigital(IO8,LOW);

	// Wait 500ms.
        usleep(500000);
    }
	
    // Finish controlling digital IO 8.
    unexportIO(IO8);

    return 0;
}
