CC			= g++
TARGET	= MathGame
SRC			= mathGame.cpp mathGameMain.cpp


$(TARGET): $(SRC)
	$(CC) -o $(TARGET) $(SRC)


.PHONY: clean
clean:
	rm -f $(TARGET)