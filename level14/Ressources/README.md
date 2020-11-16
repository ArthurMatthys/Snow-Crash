We tried to find anything related to `level14` or `flag14` but nothing came.
So we tried to `gdb` our way inside `getflag`.
We see that there is two things we have to change.
First, we have to bypass the check of `ptrace` with our first breakpoint :
`b *0x0804898e`
We will also have to change the value of `getuid` with the second breakpoint :
`b *0x08048b0a`
To bypass the ptrace, with then have to do :
```
run
set $eax=0
```
Then, we go to our second breakpoint :
```
continue
set $eax=0xbc6
continue
```
And we get the flag
