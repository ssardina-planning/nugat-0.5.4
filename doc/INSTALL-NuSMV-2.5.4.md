## HOW TO INSTALL NuSMV 2.5.4 ##


1. Make sure you have flex, bison, pkg-config, and all libexpat libs installed:

        sudo apt-get install libc6-dev g++ pkg-config 
        sudo apt-get install flex bison 
        
        sudo apt-get install libreadline5 libreadline6
        sudo apt-get install libexpat1 libxml-parser-ruby libxml-parser-ruby1.9.1
        sudo apt-get install libxml-parser-ruby1.8 libexpat1-dev
        
        sudo apt-get install libncurses5-dev libncurses5-dev:i386

    or in one shot run this:

        sudo apt-get install flex bison pkg-config libreadline5 libreadline6 libexpat1
                libxml-parser-ruby libxml-parser-ruby1.9.1 libxml-parser-ruby1.8 libexpat1-dev
                libncurses5-dev libncurses5-dev:i386

    All these are required or you will get compile errors at some point! If for some
    reason, you need to install some dependencies, you may need to do make clean and
    ./configure again.


3. Get NuSMV 2.5.4 from http://nusmv.fbk.eu/

4. First let's compile the CUDD library for BDDs that comes with the in NuSMV package. 
    (the CUDD library has been modified for NuSMV)
    
    Use -f \<architecture\>:

        $ cd cudd-2.4.1.1
        $ make -f Makefile_64bit	 

5. Compile and install NuSMV:

			 ./configure --prefix=<nusmv-build-dir> 
			 make
			 sudo make install   

    * It requires g++ as the C++ compiler (otherwise get error):

		      C++ preprocessor "/lib/cpp" fails sanity check
    * This should find the compiled cudd lib automatically.
    * One can also compile NuSMV with other optional modules (e.g., MiniSAT, Lily, etc). Unfortunately, I was not able 
    to build the MiniSAT system that comes with NuSMV.
    * It requires g++ as the C++ compiler (otherwise get error):

6. When you install nusmv it creates an extra library librbcdag  in <nusmv-build-dir>/lib/ 
Please copy files that have "rbc" in their name from <nusmv-build-dir>/lib to nusmv source folder.

7. Make sure NuSMV and NuGAT are in your paths, e.g., symblink into
/usr/local/bin to <nusmv-build-dir>/bin/


### USAGE ###

There are some examples/ in source tree.

**NOTE:** From NuSMV-2.5.1 onwards Boolean and Integer are treated differently. So, one
cannot write last = 0 if last is a boolean, but should instead write last =
FALSE.



## EOF ##