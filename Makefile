SRC=./src/
BIN=./bin/
run: build
	$(BIN)main

build: 
	cc $(SRC)main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o $(BIN)main

clean:
	rm -rf $(BIN)*