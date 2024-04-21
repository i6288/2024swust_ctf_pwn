from pwn import *
context.log_level = "debug"

p_a = process('./a', stdout=PIPE)
output = p_a.recvall()
p_a.close()

p = process('./num')

p.recvuntil("=")
p.sendline(output)
p.interactive()

