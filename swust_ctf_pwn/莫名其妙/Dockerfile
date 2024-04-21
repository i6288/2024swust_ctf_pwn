FROM ubuntu:16.04

RUN apt update
RUN apt install socat -yyq

RUN useradd -M -s /bin/false ctf

WORKDIR /app
COPY pwn flag /app/
COPY flag /
RUN chmod +x /app/pwn
RUN chmod a-w /app/pwn
RUN chmod a-w /app/flag
RUN chmod a-w /flag
USER ctf

CMD ["socat", "TCP-LISTEN:9999,reuseaddr,fork", "EXEC:/app/pwn"]

