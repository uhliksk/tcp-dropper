**Simple TCP connection dropper**

Listen on port 443 and drop every connection immediately.

**Make:**

gcc -o dropper dropper.c

**Usage:**

./dropper [port_number]
