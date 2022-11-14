CC = g++
CFLAGS = -Wall -o3 -std=c++17

TARGET = bar
SRC_DIR = src
INCDIR = -Isrc
OUT = out

VPATH = $(SRC_DIR)
vpath %.o $(OUT)

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,%.o,$(SRCS))

