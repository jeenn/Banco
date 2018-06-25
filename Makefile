cliente: Cliente.o Solicitud.o
	g++ Cliente.cpp Solicitud.o PaqueteDatagrama.o SocketDatagrama.o -o Cliente
servidor: Servidor.o Respuesta.o
	g++ Servidor.cpp Respuesta.o PaqueteDatagrama.o SocketDatagrama.o -o Servidor

Respuesta.o: Respuesta.cpp Respuesta.h SocketDatagrama.o PaqueteDatagrama.o
	g++ Respuesta.cpp -c
Solicitud.o: Solicitud.cpp Solicitud.h SocketDatagrama.o PaqueteDatagrama.o
	g++ Solicitud.cpp -c	

PaqueteDatagrama.o: PaqueteDatagrama.cpp SocketDatagrama.o PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
SocketDatagrama.o: SocketDatagrama.cpp SocketDatagrama.h
	g++ SocketDatagrama.cpp -c 
