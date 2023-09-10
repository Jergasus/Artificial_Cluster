OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Cluster.o Area_de_Espera.o Procesador.o Proceso.o
	g++ -o program.exe program.o Cluster.o Area_de_Espera.o Procesador.o Proceso.o

program.o: program.cc BinTree.hh
	g++ -c program.cc $(OPCIONS)

Area_de_Espera.o: Area_de_Espera.cc Area_de_Espera.hh
	g++ -c Area_de_Espera.cc $(OPCIONS)

Cluster.o: Cluster.cc Cluster.hh
	g++ -c Cluster.cc $(OPCIONS)

Procesador.o: Procesador.cc Procesador.hh
	g++ -c Procesador.cc $(OPCIONS)

Proceso.o: Proceso.cc Proceso.hh
	g++ -c Proceso.cc $(OPCIONS)

program.tar: *.hh *.cc Makefile
	tar -cvf program.tar *.hh *.cc Makefile

clean:
	rm -f *.o
	rm -f *.exe
