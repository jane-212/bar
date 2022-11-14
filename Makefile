include config.mk

all: help

help:
	@echo "help for more help"
	@echo "build build the project"
	@echo "run build and run"
	@echo "install install the project"
	@echo "clean clean the project"

build: $(TARGET)

$(TARGET): $(OBJS)
	@$(CC) $(CFLAGS) -o $(OUT)/$@ $(addprefix $(OUT)/, $(OBJS)) $(INCDIR)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $(OUT)/$@ $(INCDIR)

run: build
	@./$(OUT)/$(TARGET)

clean:
	@-rm $(OUT)/*

install: build
	@sudo cp -f ./$(OUT)/$(TARGET) /usr/bin

.PHONY: help build run install clean

