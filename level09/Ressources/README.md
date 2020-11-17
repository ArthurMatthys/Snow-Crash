There are 2 files, one binary and one named `token`.
We can see what's inside `token` : 
"""
f4kmm6p|=pnDBDu{
"""
It looks encrypted.
We tried to run `level09` on `token`, without any luck.
So we tried to "bruteforce" our way to the encoded password, because we thought that `level09` has to be use to encrypt, and not a hint to decrypt.
We tried char by char until we realized the encryption looked like a Caesar wheel, but each char if shifted one more than the precedent, starting with no shift.
So, we wrote a python script to decrypt the password and it gave us a result :
`f3iji1ju5yuevaus41q1afiuq`
We can now connect as flag09 and use `getflag`
```
su level10
s5cAJpM8ev6XHw998pRWG728z
```
