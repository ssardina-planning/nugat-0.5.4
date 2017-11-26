## NuGAT Game Solver (for NuSMV 2.5.4)

NuGaT is a game solver built on top of the NuSMV model checker.

This is the release based on the original 0.5.0 version so as to make
it compatible with the latest NuSMV 2.5.4 which introduced many changes.

See `doc/MIGRATION-0.5.4` for summary of changes done. **Port done on June 2015.**

The original NuGAT 0.5.0 can only be used with NuSMV 2.5.0.

**NOTE:** Please refer to README-0.5.0 for original README file.


### COPYRIGHT

NuGaT version is licensed under the GNU Lesser General Public
License (LGPL in short) as published by the Free Software Foundation;
either version 2.1 of the License, or (at your option) any later
version. File LGPL-2.1 contains a copy of the License.

For license information on Lily see its documentation.


### BUILD INSTRUCTIONS

1. NuGaT uses NuSMV 2.5.4 as its backend. Hence, in order to build and use
NuGaT you should first obtain and build NuSMV 2.5.4. 

    Please refer to doc/INSTALL-NuSMV-2.5.4.md for some instructions on this.

2. If one compiles right away, you would get this error:

        make[2]: *** No rule to make target '/home/ssardina/src/NuSMV/NuSMV-2.5.4/nusmv/librbcdag.la', needed by 'NuGaT'.  Stop.

    To avoid this, when you installed nusmv, it created an extra library librbcdag  in <nusmv-build-dir>/lib/ 
    Please copy files that have "rbc" in their name from <nusmv-build-dir>/lib to nusmv source folder.
  
3. Compile NuGAT using the **source** dir of NuSMV 2.5.0 (not its installation):

        $ ./configure --prefix=/opt/NuGAT-0.5.4/ --with-nusmv-dir=/home/ssardina/src/NuSMV/NuSMV-2.5.4/nusmv/
        $ make
        $ sudo make install 

   This builds an executable "NuGaT" in the current directory.



#### LTL GAME


Checking LTLGAME properties currently requires a slightly modified version of the LTL to B\"uchi translator available in Lily.

   1. Download lily-2008-06-19.tar.gz from the following URL:
      http://www.iaik.tugraz.at/content/research/design_verification/lily/lily-2008-06-19.tar.gz
      into a convenient directory, e.g., /tmp.

   2. Move to the directory where you would like Lily to reside, e.g.,
      /usr/local/src and unpack Lily:

        % cd /usr/local/src
        % tar -xvzf /tmp/lily-2008-06-19.tar.gz

   3. Move into the Lily directory and apply the patch provided in
      NuGaT-0.5.0/contrib:

        % cd Lily-1.0.2
        % patch -p1 < NuGaT-0.5.0/contrib/Lily-1.0.2.patch

   4. Make lily.pl known to NuGaT by either creating a symbolic link
      in a directory in the search path:

        % ln -s /usr/local/src/Lily-1.0.2/lily.pl /usr/local/bin/lily.pl

      or by setting the NuSMV shell variable
      game_sf07_gba_wring_binary to the full path of lily.pl (see the
      NuSMV documentation for details).

### Usage

This section contains some hints on how to use NuGaT.

It is assumed that the reader is familiar with concepts of two player
games.

Games are implemented as a special mode of NuGaT which is entered when
a source file containing a game is given either as input file when
calling NuGaT or when using the "read_model" or the "read_rat_file"
commands in the NuGaT shell. The mode is left when the "reset" command
is used in the NuGaT shell. While in game mode the NuGaT shell command
help provides an overview of the available commands. Calling a NuGaT
shell command with argument "-h" prints a brief usage message.

For an example on how to write games in NuGaT see
examples/simple.smv. It can be invoked either in batch mode:

        % ./NuGaT examples/simple.smv

or interactively:

        % ./NuGaT -int
        [...banner...]
        NuGaT > read_model -i examples/simple.smv
        Entering game mode...
        Done entering game mode.
        Note that now game commands apply.
        NuGaT > go
        *** WARNING: Game addon does not support properties COI size sorting.  ***
        *** WARNING: Properties COI size sorting will be disabled.             ***
        NuGaT > build_boolean_model
        NuGaT > check_property
        --   ReachTarget PLAYER_1 o0.v  : the strategy has been found

        --   AvoidTarget PLAYER_2 o0.v  : no strategy exists

        --   ReachDeadlock PLAYER_1   : no strategy exists

        --   AvoidDeadlock PLAYER_2   : the strategy has been found

        --   BuchiGame PLAYER_2 (i1, o1)  : the strategy has been found

        --   LtlGame PLAYER_1  F ( G i1)  : no strategy exists

        --   GenReactivity PLAYER_2 (i0.v) -> (o0.v, i1)  : the strategy has been found

        NuGaT > quit
        Exiting game mode...
        Done exiting game mode.
        Note that now the commands from before entering game mode apply.
        %


## KNOWN ISSUES

Currently, not all features of the NuSMV language (see the NuSMV 2.5
documentation) are supported in games. Notable examples of unsupported
constructs are assignments (ASSIGN), invariants (INVAR), and
processes.

Also, there is an unresolved issued in the BDD encoder of NuSMV 2.5. If you
see assertion violations of the following kind

NuGaT: bdd/BddEnc.c:4025: bdd_enc_shuffle_variables_order: Assertion `res == 1' failed.
Aborted

then please apply the patch provided in NuGaT-0.5.0/contrib to
$(nusmv_dir)/nusmv/src/enc/bdd/BddEnc.c and recompile first NuSMV and
then NuGaT:

        % cd $(nusmv_dir)/src/enc/bdd/
        % patch BddEnc.c < $(nugat_dir)/contrib/BddEnc.c.patch
        % cd ../../..
        % make
        % cd $(nugat_dir)
        % make


### CONTACT

Migration from NuSMV 2.5.0 to 2.5.4 for NuGAT has been done by:

* Nitin Yadav (<kyadav.nitin@gmail.com>)
* Sebastian Sardina (ssardina@gmail.com) 


### EOF
