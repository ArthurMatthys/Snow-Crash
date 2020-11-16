With a ls right after connecting as level07, we see a binary file.
As usual, we use ghidra.
We witness the use of `getenv` on the variable `LOGNAME`.
And after this, the program with execute this command : 
"""
/bin/echo %s # %s is the content of `LOGNAME`
"""
Our first idea is to set `LOGNAME` to "`whoami`" :
"""
LOGNAME=`whoami`
"""
Obviously, this doesn't work, as shown by using this simple command :
`env | grep LOGNAME`.
We can see that we just put the result of `whoami` inside LOGNAME.
Let's try to escape the backquotes :
"""
LOGNAME="\`whoami\`"; ./level07
"""
And, as expected, we have this result : `flag07`.
So let's swap `whoami` by `getflag` and we are done !
```
su level08
fiumuikeil55xe9cu4dood66h
```

