+README for getting Z3 working on your windows machine
 
 Step 1:
 +  Navigate your browser to
 +    https://github.com/Z3Prover/z3/wiki/Using-Z3Py-on-Windows  
 
 +This is the precompiled binaries to run z3 from CMD.exe in Windows
   I am reasonably sure you need some form of Python installed on your machine,
   similar to how you need to have a JRE installed on your machine to use a Java IDE
 
 Step 2 (if you dont have it already): Get Python
 +  Navigate your browser to:
 +    https://www.python.org/downloads/
   
 +Grab the latest version and install somewhere
 
 Step 3: Place your file
 +  Presumably you want to run z3 on a file, put that file in the same directory that you downloaded the binaries to
     in Step 1.  
 +This is so that when you run z3, it can find the file
 
 +Once you have both of these installed, and a file ready for test, go to your search bar (bottom left)
 
 +Type CMD.exe in the search bar, and open CMD.exe
 +This gets you a command prompt in windows
 
 +Open the directory you downloaded the z3 binaries too in Step 1, and copy the address bar
 +Paste the address bar into the command prompt, 
 this navigates you to the directory of your z3 install
 
 +Now you can actually tell z3 to Operate on your input file (which should be in this directory as well)
 
 +In the prompt, input z3 -h
 
 +This will display a bunch of the options for input parameters
 +To point z3 at your file, input z3 (filename), use the -h information to help you decide what parameters you want set

 +Thats it!  Good job
