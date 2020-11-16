As we connect as level05, we recieve a notification showing us we have a mail.
If we go to /var/mail, the file `level05` contain :
`*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05`
It looks like a crontab that is scheduled every 2 minutes.
Looking to the file `/usr/sbin/openarenaserver`, we can see that it adds execution permission to every file in a directory and then execute them.
So, in that same folder, we create a file and put a script that will write the flag:
```
#!/bin/bash
getflag > /tmp/flag
```
We just have to wait for 2 minutes now.
To connect to level 6:
```
su level06
viuaaale9huek52boumoomioc
```
