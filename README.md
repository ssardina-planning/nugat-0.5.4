# NuGAT Game Solver (for NuSMV 2.5.4) #

This is the NuGAT game solver compatible with new NuSMV 2.5.4.

Develped by Nitin Yadav and Sebastian Sardina (2015).

## OVERVIEW ##

NuGAT (https://es.fbk.eu/technologies/NuGAT-game-solver) was developed at [FBK-ES](https://es.fbk.eu/)
group. The last version was 0.5.0 which worked with NuSMV 2.5.0 (but not with newer versions). 

NuSMV had an important upgrade to [version 2.5.4]([NuSMV 2.6.0 release news](http://nusmv.fbk.eu/announce-NuSMV-2.5.4.txt)). In June 2015, NuGAT 0.5.0 was ported 0.5.4 to work with NuSMV 2.5.4 by 
Nitin Yadav and Sebastian Sardina. This is such version.

**Obs:** NuSMV later had a major upgrade to [version 2.6.0]([NuSMV 2.6.0 release news](http://nusmv.fbk.eu/announce-NuSMV-2.6.0.txt)), with a versy different architecture. A port of NuGAT compatible
with such version can be found at [NuGAT 0.6.0 repo](https://bitbucket.org/nugaton/nugat-0.6.0)


## INSTALLATION INSTRUCTIONS ##

1. Make sure you have compiled and installed NuSMV 2.5.4 and then set
the following environmet variables:

        export NUSMV_BUILD_DIR=/opt/NuSMV-2.5.4/
        export NUSMV_SOURCE_DIR=~/src/NuSMV/NuSMV-2.5.4/NuSMV/
        
    Remember you can install NuSMV in your own directory:

        ./configure --prefix=/home/ssardina/opt/nusmv-2.5.4
        make
        make install

    See extras/NuSMV-2.5.5/ for NuSMV package and install instructions for this version.

2. Some of the packages needed:

        sudo apt-get install libc6-dev g++ pkg-config automake pkgconf icu-config
        sudo apt-get install flex bison 
        sudo apt-get install libreadline5 libreadline6
        sudo apt-get install libexpat1 libexpat1-dev libxml2-dev liblzma-dev libicu-dev
        sudo apt-get install ruby-libxml 
        sudo apt-get install libncurses5:amd64 libncurses5:i386 libncurses5-dev:amd64 libncurses5-dev:i386

Note: 

- pkgconf is a program which helps to configure compiler and linker flags for development frameworks. It is similar to pkg-config from freedesktop.org. libpkgconf is a library which provides access to most of pkgconf's functionality, to allow other tooling such as compilers and IDEs to discover and use frameworks configured by pkgconf.
 
- icu-config simplifies the task of building and linking against ICU as compared to manually configuring user makefiles or equivalent. Because icu-config is an executable script, it also solves the problem of locating the ICU libraries and headers, by allowing the system PATH to locate it.


3. BUILD and INSTALL with make:

         ./configure --prefix=/home/ssardina/opt/nugat-0.5.4 --with-nusmv-dir=/home/ssardina/src/NuSMV/NuSMV-2.5.4/nusmv/
        make
        make install
        
    This should finish a ./NuGAT executable:
        
          [ssardina@Thinkpad-X1 nugat-0.5.4.git]$ ./NuGaT 
          *** This is NuGaT 0.5.4 (compiled on Thu Nov 30 11:52:20 UTC 2017)
          *** Enabled addons are: game 
          *** For more information on NuGaT see <http://es.fbk.eu/tools/nugat>
          *** or email to <nugat-users@list.fbk.eu>.
          *** Please report bugs to <nugat@list.fbk.eu>.
          *** Copyright (c) 2010, Fondazione Bruno Kessler
          
          *** This version of NuGAT-0.5.4 is linked to NuSMV 2.5.4.
          *** For more information on NuSMV see <http://nusmv.fbk.eu>
          *** or email to <nusmv-users@list.fbk.eu>.
          *** Copyright (C) 2010 by Fondazione Bruno Kessler
          
          *** This version of NuGAT-0.5.4 is linked to the CUDD library version 2.4.1
          *** Copyright (c) 1995-2004, Regents of the University of Colorado
  




## USAGE

It is assumed that the reader is familiar with concepts of two player games.

Games are implemented as a special mode of NuGAT which is entered when
a source file containing a game is given either as input file when
calling NuGAT or when using the "read_model" or the "read_rat_file"
commands in the NuGAT shell. The mode is left when the "reset" command
is used in the NuGAT shell. While in game mode the NuGAT shell command
help provides an overview of the available commands. Calling a NuGAT
shell command with argument "-h" prints a brief usage message.

NuGAT 0.5.4 uses the same language as NuGAT 0.5.0. See examples in examples/

The port of the original NuGAT example (gets same results):
    
    ./NuGAT ../examples/NuGAT/simple.smv

    An example to solve a planning program:

    ./NuGAT -dynamic ../examples/NuGAT/test-NuGAT.smv

    An example of GR(1) formula:
    
    ./NuGaT ../examples/simple-genreac.smv
    
    *** WARNING: Game addon does not support properties COI size sorting.  ***
    *** WARNING: Properties COI size sorting will be disabled.             ***
    --   GenReactivity PLAYER_2 (i0.v) -> (o0.v, i1)  : the strategy has been found

... or interactively:

    [ssardina@Thinkpad-X1 build]$ ./NuGAT -int
    *** This is NuGaT 0.6.0 (compiled on Sun Nov 26 14:34:01 2017)
    *** Enabled addons are: game 
    *** For more information on NuGaT see <http://es.fbk.eu/tools/nugat>
    *** or email to <nugat-users@list.fbk.eu>.
    *** Please report bugs to <Please report bugs to <nusmv-users@fbk.eu>>.
    *** Copyright (c) 2010, Fondazione Bruno Kessler
    
    *** This version of NuGAT-0.6.0 is linked to NuSMV 2.6.0.
    *** For more information on NuSMV see <http://nusmv.fbk.eu>
    *** or email to <nusmv-users@list.fbk.eu>.
    *** Copyright (C) 2010-2014, Fondazione Bruno Kessler
    
    *** This version of NuGAT-0.6.0 is linked to the CUDD library version 2.4.1
    *** Copyright (c) 1995-2004, Regents of the University of Colorado
    
    *** This version of NuGAT-0.6.0 is linked to the MiniSat SAT solver. 
    *** See http://minisat.se/MiniSat.html
    *** Copyright (c) 2003-2006, Niklas Een, Niklas Sorensson
    *** Copyright (c) 2007-2010, Niklas Sorensson
    
    NuSMV > read_model -i ../examples/simple-genreac.smv
    Entering game mode...
    Done entering game mode.
    Note that now game commands apply.
    NuSMV > go
    *** WARNING: Game addon does not support properties COI size sorting.  ***
    *** WARNING: Properties COI size sorting will be disabled.             ***
    NuSMV > build_boolean_model 
    NuSMV > check_
    check_avoid_deadlock  check_buchi_game      check_ltlgame_sf07    check_reach_deadlock  
    check_avoid_target    check_gen_reactivity  check_property        check_reach_target    
    NuSMV > check_gen_reactivity 
    --   GenReactivity PLAYER_2 (i0.v) -> (o0.v, i1)  : the strategy has been found
    
    NuSMV > quit
    Exiting game mode...
    Done exiting game mode.
    Note that now the commands from before entering game mode apply.



##### USEFUL INFO

A file that has useful information on what NuGAT can do is:

src/addons/game/gameCmd.c

One can run NuGAT directly from the command line or via a script file. In both
cases, the most improtant option seems to be "--dynamic", which speeds up NuGAT
by a lot.

1) Command line run:

        $ NuGaT -dynamic <smv file>

2) Script run:

        $ NuGaT -source <.script file>

The script should do some steps before solving the game and can do other extra
things that cannot be done with the command line (like simulating or printing
the strategy). My script contains this:

        set on_failure_script_quits 1
        read_model -i flip-coin-NUGAT-v01.smv
        flatten_hierarchy
        set dynamic_reorder 1
        encode_variables
        set conj_part_threshold 10000
        set partition_method Threshold
        build_model
        check_gen_reactivity -e
        check_reach_target  -e
        quit
        
        compute_reachable
        print_reachable_states
        check_fsm
        check_ctlspec
        pick_state
        simulate -v -r
        quit
 

The -e option in the check statements states to print the controller that solves
the problem (if any).


##### EXAMPLES

Three file examples on how to use NuGAT for planning:

- flip-coin-NUGAT-v01.smv: 
		flip is deterministic; strong planning has solution
- flip-coin-NUGAT-v02.smv: 
		flip is non-deterministic; no strong plan; cannot express fairness
- flip-coin-NUGAT-v03.smv: 
		same as 02 but with modules for Player 1

File flip-coin-NUGAT-v01.script is a script file for runnig v01 smv file

	$ NuGaT -source flip-coin-NUGAT-v01.script 


You will see that because the script has -e in the checking steps:

check_gen_reactivity -e
check_reach_target  -e


the strategy found, if any, will be printed.

## COPYRIGHT ##

NuGaT version is licensed under the GNU Lesser General Public License (LGPL in short) as published by the Free Software Foundation; either version 2.1 of the License, or (at your option) any later version. File LGPL-2.1 contains a copy of the License.
For license information on Lily see its documentation.

## CONTACT ##

This port of NuGAT compatible with NuSMV 2.5.4 was done by:  

* [Sebastian Sardina](https://sites.google.com/site/ssardina/) <ssardina@gmail.com> 
* Nitin Yadav <kyadav.nitin@gmail.com>

For the original authors of NuGAT refer to the [AUTHORS](https://bitbucket.org/nugaton/nugat-0.5.4/src/284c8be1dcad8695484157562e35b4fb3161a73f/AUTHORS?at=master&fileviewer=file-view-default) file in the distribution.
