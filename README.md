ninjastats
==========

Columbia students - how often have you been screwed over by a CUIT Ninja
printer not working when you were rushing to print out a paper or assignment
before class? Ever think that for a school of such resources, the printers
could be better maintained? Well, with data about this issue you could begin to
answer the question/smolder in self-righteous fury.

ninjastats is a tool that determines the number of printers working on campus,
out of the total connected to the network, at any one time. It is a shell
script that drives a very simple C program that I wrote while taking Jae Lee's
Advanced Programming. The output can be regularly appended to a text file to
(slowly) create a time series of printer functionality.

To use, compile the C program,
```
gcc -o ninjas.out ninjas.c
```

Then, by running,
```
./ninjas.sh
```
you will append a line to the file `ninjastats.txt`.

You can also use a utility like `crontab` to execute this task regularly. 

To help you get started on your quest to analyze this data, I have also
uploaded a file `ninjastats\_hist.txt` that has data at (somewhat) hourly
intervals between December 2013 and December 2014. Enjoy. Please cite this
project if you do anything cool with it!

Contact: Micah Smith <micahjsmith@gmail.com>
