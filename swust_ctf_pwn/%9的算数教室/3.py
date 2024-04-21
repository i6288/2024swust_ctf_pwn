from pwn import *

import os
context(arch = 'i386',os = 'linux',log_level = 'debug')
result=os.popen('./a').read()
#p=remote('47.109.135.169',20013)
#p=process('./num')
p=remote('127.0.0.1',9999)
for i in range(50):
   payload=result.split('\n')[i]

   p.sendline(result.split('\n')[i])
   p.recvuntil("=")  
p.interactive()

