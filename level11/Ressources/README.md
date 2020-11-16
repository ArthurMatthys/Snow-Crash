We can see a .lua file. We guess that there is a server running with this script.
So we try to connect with nc with the elements we got in the file:
`nc 127.0.0.1 5151`
It works but it's asking us a password.
We first try to dehash the password in the .lua file, `NotSoEasy` but it didn't work.
We asked ourself why there was no output on our side regarding the :
```
      print("trying " .. l)
```
And in fact, it was printing something, but not on our side, but on the server side.
So we tried to redirect the output to a file in the `tmp` directory. And we tried to execute the command `getflag`. We did it by doing so :
```
echo \`getflag\` \>/tmp/yop\ | nc 127.0.0.1 5151; cat /tmp/yop
```
That's how we got the flag.

```
su level12
fa6v5ateaw21peobuub8ipe6s
```
