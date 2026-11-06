SHELL := cmd.exe
.SHELLFLAGS := /C

CC = gcc
CFLAGS = -Wall -Wextra -std=c11
INCLUDES = -Iinclude
SRC = src/main.c src/sorting.c src/utils.c
OUT = build/app.exe

.PHONY: all run clean

all:
	if not exist build mkdir build
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC) -o $(OUT)

run: all
	.\build\app.exe

clean:
	if exist build rmdir /s /q build
