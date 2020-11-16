With ghidra, we witness a use of getuid().
The program checks if the real user has an id of 4242. If that's the case, it gives the flag of this level.
Our idea was to code our own `getuid()` and make the program call our library instead of the standard one.
So, in the `tmp` directory, we create a file named `getuid.c` where we write :
```
#include<unistd.h>
uid_t getuid(void)
{
    return 4242;
}
```
Then, we create our dynamic library : `gcc -fPIC -shared -o lib.so getuid.c`
We then export `/tmp/lib.so` as an environment variable : `export LD_PRELOAD="/tmp/lib.so"`.
We then tried to run `./level13` from the original directory, without any luck.
So we made a copy into the `/tmp` directory and try again `./level13` :
`your token is 2A31L79asukciNyi8uppkEuSx`

```
su level14
2A31L79asukciNyi8uppkEuSx
```
