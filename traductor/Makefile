SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
LIB = lib
CPPFLAGS = -Wall -g  -I$(INC) -c

#Rellenad el makefile para compilar el proyecto
all: $(BIN)/pruebatrad_test
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************

lib/libformas.a: $(OBJ)/conjuntofrases.o $(OBJ)/frase.o
		ar rsv $(LIB)/libformas.a $(OBJ)/conjuntofrases.o $(OBJ)/frase.o

obj/conjuntofrases.o : $(SRC)/conjuntofrases.cpp $(INC)/conjuntofrases.h $(INC)/frase.h
	$(CXX) $(CPPFLAGS)  $(SRC)/conjuntofrases.cpp  -o $(OBJ)/conjuntofrases.o

obj/frase.o: $(SRC)/frase.cpp $(INC)/frase.h
	$(CXX) $(CPPFLAGS)  $(SRC)/frase.cpp  -o $(OBJ)/frase.o

obj/pruebatrad_test.o: $(SRC)/pruebatrad_test.cpp $(INC)/conjuntofrases.h $(INC)/frase.h
	$(CXX) $(CPPFLAGS) $(SRC)/pruebatrad_test.cpp  -o $(OBJ)/pruebatrad_test.o

bin/pruebatrad_test: $(OBJ)/pruebatrad_test.o $(LIB)/libformas.a
	$(CXX) -o $(BIN)/prueba $(OBJ)/pruebatrad_test.o -I$(INC) -L$(LIB) -lformas



# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
