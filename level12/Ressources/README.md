Same as level04, but this time, we have to exploit `egrep` to execute our command instead of `echo`.
Furthemore, we have some regex that will try to ruin our input.
The regexes will put every char to uppercase and delete everything from the first space encountered.
Our first idea was to use `|sh` with the `egrep` which would have execute every command found with `egrep` in `/tmp/xd`, knowing that we had a `SH` file in `/tmp` and we had changed the `PATH` variable to include the `/tmp` directory.
It couldn't work since the use of `curl` doesn't keep the change of env variable.
So, we tried, instead of executing a command found in `/tmp/xd`, to execute `getflag` directly :

```
echo "getflag > /tmp/res" > /tmp/SH; chmod +x /tmp/SH
curl 'localhost:4646/?x="`/*/sh`"&y=' ; echo ""; cat /tmp/res
```
And it will output the flag.
```
su level13
g1qKMiRpXf53AWhDaU7FEkczr
```
