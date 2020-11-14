Using ghidra, we can see that there is a call to echo in the program.
Furthermore, the owner of the executable is flag03.
So if we can execute `getflag` within the program, we will get the flag needed to log as level04.
We can do this by creating our own "echo" in the tmp directory, and adding `/tmp` in our path environment variable.
Our echo is quite simple :
"""
#!/bin/bash
getflag
"""
Don't forget to allow this new `echo` file to be executed. (chmod +x /tmp/echo)
And to change the path variable, we can do like so : PATH=/tmp:$PATH.
Now, if we execute the program, we get the flag.
```
su level04
qi0maab88jeaj46qoumi7maus
```
