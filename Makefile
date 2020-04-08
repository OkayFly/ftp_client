CC = gcc
CFLAGS = -g -I./
SRCCLEINT = .
BINCLIENT = bin
OBJCLIENT = obj
OBJECTSCLIENT = ${OBJCLIENT}/client_ftp.o
EXECUTABLECLIENT = ${BINCLIENT}/client_ftp.out

all: clean client

client: ${OBJECTSCLIENT}
	${CC} ${CFLAGS} $^ -o ${EXECUTABLECLIENT}

${OBJCLIENT}/%.o: ${SRCCLEINT}/%.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJCLIENT}/*.o
	rm -fr ${BINCLIENT}/*.out