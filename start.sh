#!/bin/bash

FILENAME=learn_lang
BIN_FILE=.bin/$FILENAME

gcc -o $BIN_FILE $FILENAME.c && $BIN_FILE
