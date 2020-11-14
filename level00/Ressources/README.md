Looking into the /etc/group file. We can see each groupe on the VM.
So we try to find every file belonging to the groupe `flag00` with this command : `find / -group flag00 2>/dev/null`.
We find 2 files with the same content : `cdiiddwpgswtgt`.
This is the hash password to connect to flag00. It is a simple Caesar cipher.
One of the 26 decode looks like a simple sentence : `nottoohardhere`.
So we try to connect with this password, and it works !
```
su level01
x24ti5gi3x0ol2eh4esiuxias
```
