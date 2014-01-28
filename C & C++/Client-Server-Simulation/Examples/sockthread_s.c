#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <pthread.h>

#define BUFSIZE     80       /* anything large enough for your messages */


void* handleClient(void *);

int main(int argc, char *argv[])
{
   char     host[80];
   int      sd, sd_current;
   int      port;
   int      *sd_client;
   int      addrlen;
   struct   sockaddr_in sin;
   struct   sockaddr_in pin;
   pthread_t tid;
   pthread_attr_t attr;

   /* check for command line arguments */
   if (argc != 2)
   {
      printf("Usage: server port\n");
      exit(1);
   }

   /* get port from argv */
   port = atoi(argv[1]);
 
 
   /* create an internet domain stream socket */
   if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
      perror("Error creating socket");
      exit(1);
   }

   /* complete the socket structure */
   memset(&sin, 0, sizeof(sin));
   sin.sin_family = AF_INET;
   sin.sin_addr.s_addr = INADDR_ANY;  /* any address on this host */
   sin.sin_port = htons(port);        /* convert to network byte order */

   /* bind the socket to the address and port number */
   if (bind(sd, (struct sockaddr *) &sin, sizeof(sin)) == -1) {
      perror("Error on bind call");
      exit(1);
   }

   /* set queuesize of pending connections */ 
   if (listen(sd, 5) == -1) {
      perror("Error on listen call");
      exit(1);
   }

   /* announce server is running */
   gethostname(host, 80); 
   printf("Server is running on %s:%d\n", host, port);


   /* wait for a client to connect */
   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED); /* use detached threads */
   addrlen = sizeof(pin);
   while (1)
   {
      if ((sd_current = accept(sd, (struct sockaddr *)  &pin, (socklen_t*)&addrlen)) == -1) 
      {
	 perror("Error on accept call");
	 exit(1);
      }

      sd_client = (int*)(malloc(sizeof(sd_current)));
      *sd_client = sd_current;

      pthread_create(&tid, &attr, handleClient, sd_client);
   }

   /* close socket */
   close(sd);
}


void* handleClient(void *arg)
{
   int count=0;
   char     buf[BUFSIZE];  /* used for incoming string, and outgoing data */
   char     temp[BUFSIZE];  

   int sd = *((int*)arg);  /* get sd from arg */
   free(arg);              /* free malloced arg */

   /* read a message from the client */
   if ( (count = read(sd, buf, sizeof(buf)) ) == -1) {
      perror("read");
      exit(1);
   }
   printf("Server read %d bytes\n", count);

   sprintf(temp, "Hi %s", buf);   

   /* send a string back to client */ 
   if ( (count = write(sd, temp, strlen(temp)+1) ) == -1) {
      perror("write");
      exit(1);
   }
   printf("Server sent %d bytes\n", count);

   /* close socket */
   close(sd); 
}

