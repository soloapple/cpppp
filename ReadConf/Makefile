# $Id: Makefile,v 1.2 2002/01/05 16:29:36 venglin Exp $

BASENAME= /usr/local

GCH_P=.
GCH_H=headers.h
GCH=$(GCH_H).gch

CFLAGS	=  -Wall -pipe -I/usr/local/include -DPATH=\"/storage/gard_file\" -g
LDFLAGS =  -L. -L/lib64 -lmysqlclient -lpthread
LIBS = ConvertUTF.c 

SRC_R = read_conf.cc
SRC_G = get_conf.cc

O=o
CC = g++

BINDIR=$(BASENAME)/sbin

INSTALL=install -o root -m
BINPERM=0555 -s

BINS = read_conf get_conf

.PHONY: $(BINS)
all: $(BINS)

$(GCH):
	$(CC) $(GCH_H)

############################################################
#    
# 
#
#
############################################################
read_conf: $(GCH_P)/$(GCH)
	$(CC) $(SRC_R) $(CFLAGS) -o $@ $(LDFLAGS) $(LIBS)


############################################################
# Line Style(two kinds):
#	key = value   
#	key=value
############################################################
get_conf: $(GCH_P)/$(GCH)
	$(CC) $(SRC_G) $(CFLAGS) -o $@ $(LDFLAGS) $(LIBS)


install: $(BINS)
	$(INSTALL) $(BINPERM) $(BINS) $(BINDIR)
	@for a in $(BINS); do ls -l $(BINDIR)/$$a; done

deinstall:
	cd $(BINDIR) && $(RM) $(BINS)

clean:
	rm -f *.$(O) $(BINS) *core* *.gch a.out
