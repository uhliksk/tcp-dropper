#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <unistd.h>

#define MYPORT 443
#define BACKLOG 1

int main (void)
{
  int server_sockfd, client_sockfd, client_len;
  struct sockaddr_in addr_s, addr_c;

  server_sockfd = socket (AF_INET, SOCK_STREAM, 0);
  addr_s.sin_family = AF_INET;
  addr_s.sin_addr.s_addr = INADDR_ANY;
  addr_s.sin_port = htons (MYPORT);
  bzero (&(addr_s.sin_zero), 8);

  bind(server_sockfd, (struct sockaddr *) &addr_s, sizeof (addr_s));
  listen (server_sockfd, BACKLOG);

  printf("dropped connections:\n0");
  fflush(stdout);
  int i = 1;
  while (i)
    {
      client_len = sizeof (struct sockaddr);
      client_sockfd = accept (server_sockfd, (struct sockaddr *) &addr_c, &client_len);
      close (client_sockfd);
      printf("\r%d", i);
      fflush(stdout);
      i++;
    }
  close(server_sockfd);
  return 0;
}
