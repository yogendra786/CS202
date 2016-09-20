
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include<string>


namespace pratap{

template < class Item > class graph{
   private :
       string filename;
 
  public:

     void plot(string filename);
    
 
      
  };

template < class Item >
void graph < Item >:: plot (string filename){

char * commandsForGnuplot1[] = {"set term x11 1","set title \"Impedance vs
frequency\"", "set key outside", "plot ’data.temp’ with line"};
char * commandsForGnuplot[] = {"set term x11 0", "set title \"Voltage waveforms\"",
"set key outside", "plot for [col=2:4] ’filename’ using 0:col with line"};
FILE * temp = fopen(filename, "w");

FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
for (ind=0;ind<i;ind++)
fprintf(temp, "%lf %lf %lf %lf\n", time[ind],
cimag(VR[ind]),cimag(VL[ind]),cimag(VC[ind]) );
for (ind=0;ind<4;ind++)
fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[ind]);
fclose(temp);
pclose(gnuplotPipe);

}






























}
#endif
