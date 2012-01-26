-----------------------------------------
UCPP for FIRST Instructions
-----------------------------------------

The ucpp_ project allows compilation of code for FRC on any platform
without proprietary software.

To download, you can clone the git repository.  Alternatively, you can just
download a .tar.gz snapshot.

Installation Dependencies (Linux/Unix)
-----------------------------------------

Installation on Unix-like OSes has a few dependencies:
 - A normal collection of command-line tools:
    - bash
    - GNU *utils, etc
    - wget
    - Your distribution most likely installs these by default.  If you
      don't have them, chances are you did that on purpose and can
      deal with the errors.
 - tclsh (also pulled in on many distributions)
 - wine (for running the windows version of the compiler)
 - python (used to simplify scripting)
 - wput (to deploy code to the robot)

Installation Directions (Linux/Unix)
-----------------------------------------

 - Download ucpp.  This can be done through a clone of the git repo
   or through a download of a .tar.gz snapshot.
 - Add the ucpp folder to your path.  For example, I put ucpp in
   /usr/local/share, so I have this at the END of my /etc/profile::
         # This can go in either /etc/profile or ~/.profile
         # UCPP PATH - ucpp is located at /usr/local/share/ucpp in this case
         # and the scripts are located in the ucpp subdirectory of *that*
         PATH="$PATH:/usr/local/share/ucpp/ucpp"
         export PATH
 - Be EXTREMELY CAREFUL editing any configuration files and always have a known
   working copy.  If you screw it up your OS *WILL NOT BOOT*.
 - As your user (not root) run::
         $ ucpp setup -t team_number       # NOTE: our team number is 612
 - Once ucpp has installed, you need to make a workspace folder.  Mine
   is ~/robo_wkspc
 - Put your code repository in the workspace folder - so in my case
   ~/robo_wkspc/612-code

Installation (win32)
-----------------------------------------

This section is not completed.  I can't provide a detailed walkthrough,
as I have no experience getting everything to work together on windows.
I can, however, give a little bit of information.

First, there are two options for installation currently.  One relies on
WindRiver and MSYSGit (I guess if you don't want to work through WR),
and the other relies on CYGWIN.  Once CYGWIN is set up with all of the
proper dependencies (I would highly recommend the apt-cyg script for
this), the install process should be *similar* to the *N?X install.


Running
-----------------------------------------

 - To initialize the project, run in the project's root directory::
         $ ucpp init
 - Every time you add or remove a .cpp file, you must regenerate the
   makefile with::
         $ ucpp configure
    - Note that the above command only looks in the project's root
      directory - so for now no putting .cpp files in subdirectories.
 - You can now make the project with::
         $ make                  # for debug builds
         $ make DEBUG_MODE=0     # for release builds
         $ make clean            # clean to force recompile
 - You can deploy the code with::
         $ make deploy           # deploy code - only debug builds
         $ make undeploy         # remove code from robot
 - The object files are in PPC603gnu/[Non]Debug/612-code.out
    - These can be deployed to the robot manually by renaming the file
      FRC_UserProgram.out and putting it in the /ni-rt/system directory
      of the cRIO.  The cRIO runs an anonymous FTP server for this
      purpose.      

.. _ucpp: https://github.com/nikitakit/ucpp
