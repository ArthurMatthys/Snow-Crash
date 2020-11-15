passwd = ""
with open("/home/user/level09/token", 'rb') as f:
    count = 0
    while 1:
        a = f.read(1)
        if a == b'':
            break
        res = ord(a) - count
        if res < 0:
            res += 128
        passwd += str(chr(res))
        count +=1
print(passwd[:-1])
