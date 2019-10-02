#include <arpa/inet.h>
#include <string.h>

// Utliser 
// >telnet 127.0.0.1 30000
// pour se connecter au server et l'écouter
// nb. Parfois, le serveur ne démarre pas correctement!
// > error on bind --> + setsockopt REUSEADDR pour réutiliser le port

int main(){
	
//Socket	
	int listener_d = socket(AF_INET,SOCK_STREAM,0);
	if(listener_d == -1 )
		perror("Can't open socket...");
	
// Bind
	struct sockaddr_in name;
	name.sin_family = AF_INET;
	name.sin_port = (in_port_t)htons(30000); // htons pour se comprendre entre machine
	name.sin_addr.s_addr = htonl(INADDR_ANY);
	int c = bind (listener_d, (struct sockaddr *) &name, sizeof(name));
	if (c == -1)
		perror("Can't bind to socket");
		
// Listen
if (listen(listener_d, 10) == -1) // Le 11ème client indiquera au server qu'il est busy
	perror("Can't listen");

	puts("Waiting for connection...");

	while(1){
		// Accept a connection 
		struct sockaddr_storage client_addr;
		unsigned int addresse_size = sizeof(client_addr);
		int connect_d = accept(listener_d, (struct sockaddr *) &client_addr, &addresse_size);
		if(connect_d == -1)
			perror("Can't connect open secondary socket");
		
		// Send something !
		char msg[] = " - BlahBlah Blah \n - ...\n - Goood bye ! \n";
		send(connect_d, msg, strlen(msg), 0);

		close(connect_d);
	}
	return 0;
}

