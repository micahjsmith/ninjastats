/*
 * ninjas.c
 * 
 * Parse the Columbia University IT page that shows the status of all printers
 * on campus, and output the number of printers functioning out of total
 * printers. With a large enough time series, we can do some analysis to figure
 * out the optimal printer to use at a certain time...but really, we want to
 * quantify how awful CUIT is at maintaining their printers.
 *
 * Micah Smith <micahjsmith@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]){
   
    //First 5 lines are headers
    //Lines 6 until end are formatted:
    //<tr><td [color info]>[printer name]</td><td> [last printed]</td><td>
    //    [status]</td></tr>
    //Acceptable statuses include "Ready" and "Idle"

    int printercount=0;
    int workingcount=0;

    int i;
    for (i=1; i<argc; i++){
        //If line contains "-ninja." there is a printer
        if(strstr(argv[i],"-ninja."))
            printercount++;
        else
            continue;
        
        //If line contains "Ready" or "Idle", printer is working
        if (strstr(argv[i],"Ready") || strstr(argv[i],"Idle"))
            workingcount++;
    }

    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo=localtime(&rawtime);
    char buf[32];
    strftime(buf, 32,"%c", timeinfo);
    printf("%s: %d working out of %d total (%.2f percent)\n",
           buf, workingcount, printercount, 
           100.0*workingcount/printercount);

    exit(0);
}
