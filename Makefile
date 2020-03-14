PROGRAM_Driver=huffencode
PREFILE1=HuffmanTree
PREFILE2=HuffmanNode
TEST_DRIVER=UnitTests

CC=g++
COMPILE=-c -o
LINK=-o

FLAGS=-std=c++11 -g

$(PROGRAM_Driver): $(PROGRAM_Driver).o
	$(CC) $(FLAGS) $(LINK) $(PROGRAM_Driver) $(PROGRAM_Driver).o $(PREFILE1).o $(PREFILE2).o

$(PROGRAM_Driver).o: $(PREFILE1).o $(PREFILE1).h $(PREFILE2).o $(PREFILE2).h
	$(CC) $(FLAGS) $(COMPILE) $(PROGRAM_Driver).o $(PROGRAM_Driver).cpp

$(PREFILE1).o: $(PREFILE1).h $(PREFILE2).o $(PREFILE2).h
	$(CC) $(FLAGS) $(COMPILE) $(PREFILE1).o $(PREFILE1).cpp

$(PREFILE2).o: $(PREFILE2).h
	$(CC) $(FLAGS) $(COMPILE) $(PREFILE2).o $(PREFILE2).cpp


clean:
	rm -f *.o
	rm -f $(PROGRAM_Driver)
	rm -f $(TEST_DRIVER)

test:
	$(CC) $(FLAGS) $(COMPILE) $(TEST_DRIVER).o $(TEST_DRIVER).cpp
	$(CC) $(FLAGS) $(LINK) $(TEST_DRIVER) $(TEST_DRIVER).o $(PREFILE1).o $(PREFILE2).o
	@./UnitTests
