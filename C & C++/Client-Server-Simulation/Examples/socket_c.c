#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>


/* Run as:  client host port
 *
 * where host is the machine to connect to and port is its port number */
#define BUFSIZE     80       /* anything large enough for your messages */

int main(int argc, char *argv[])
{
   char hostname[100];
   char buf[BUFSIZE];
   char name[100];
   int sd;
   int port;
   int count;
   struct sockaddr_in pin;
   struct hostent *hp;

   /* check for command line arguments */
   if (argc != 3)
   {
      printf("Usage: client host port\n");
      exit(1);
   }

   /* get hostname and port from argv */
   strcpy(hostname, argv[1]);
   port = atoi(argv[2]);

   /* create an Internet domain stream socket */
   if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
      perror("Error creating socket");
      exit(1);
   }

   /* lookup host machine information */
   if ((hp = gethostbyname(hostname)) == 0) {
      perror("Error on gethostbyname call");
      exit(1);
   }

   /* fill in the socket address structure with host information */
   memset(&pin, 0, sizeof(pin));
   pin.sin_family = AF_INET;
   pin.sin_addr.s_addr = ((struct in_addr *)(hp->h_addr))->s_addr;
   pin.sin_port = htons(port); /* convert to network byte order */


   printf("Connecting to %s:%d\n\n", hostname, port); 

   /* connect to port on host */
   if (connect(sd,(struct sockaddr *)  &pin, sizeof(pin)) == -1) {
      perror("Error on connect call");
      exit(1);
   }

   /* ask user for name */
   printf("Enter your name: ");
   scanf("%s", name);

   /* send the name to the server */ 
   if ( (count = write(sd, name, strlen(name)+1)) == -1) {
      perror("Error on write call");
      exit(1);
   }
   printf("Client sent %d bytes\n", count);

   /* wait for a message to come back from the server */
   if ( (count = read(sd, buf, BUFSIZE)) == -1) {
      perror("Error on read call");
      exit(1);
   }
   printf("Client read %d bytes\n", count);


   /* print the received message */
   printf("\n\n%s\n\n", buf);


   /* close the socket */
   close(sd);
}

