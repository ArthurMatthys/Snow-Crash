Same a usual, we use ghidra on the binary file.
The program will read and write the content of `argv[1]`.
But, `argv[1]` cannot contain `"token"` otherwise it won't read the file.
First idea : Create a symbolic link to `token` so we won't have to actualy put `token` in `argv[1]` :
`ln -s token /tmp/text; ./level08 /tmp/text`
This is not working, and looking into the documentation of ln, we understand why :
"""
ln -s SOURCE TARGET
[...]
If SOURCE is a relative path (that is, it does not start with /), then it is interpreted relative to the directory that TARGET is in.
"""
So we just have to put the absolute path like so :
`ln -s /home/user/level08/token /tmp/sol; ./level08 /tmp/sol`
It ouputs `quif5eloekouj29ke0vouxean`.
Now we just have to connect to flag08 with this password
```
su level09
25749xKZ8L7DkSCwJkT9dyv6f
```
