# Hostapd Makefile

HOSTAPD_NAME = hostapd
INCLUDE_PATH = -I./AC/include/common \
			   -I./AC/include/net80211 \
			   -I./AC/include/sys \
			   -I./head/ \

SOURCES_PATH = ./AC/source: \

CC = gcc
OBJ_DIR = ./obj
vpath %.c $(SOURCES_PATH)
SOURCES = $(wildcard $(subst :,/*.c,$(SOURCES_PATH)))
SOURCES_NODIR = $(notdir $(SOURCES))
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SOURCES_NODIR))

all : $(HOSTAPD_NAME) $(OBJ_DIR)

$(HOSTAPD_NAME) : $(OBJS) $(OBJ_DIR)
	$(CC) -o $(INCLUDE_PATH) $@ $(OBJS)

$(OBJ_DIR) :
	mkdir $@

$(OBJ_DIR)/%.o : %.c
	$(CC) $(INCLUDE_PATH) -o $@ $<

.PHONY : clean install

clean:
	rm -f $(OBJ_DIR)/*.o  
