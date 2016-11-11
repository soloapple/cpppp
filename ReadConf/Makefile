# $Id: Makefile,v 1.2 2002/01/05 16:29:36 venglin Exp $

BASENAME= /usr/local

CFLAGS	=  -Wall -pipe -I/usr/local/include -DPATH=\"/storage/gard_file\" -g
LDFLAGS =  -L. -L/lib64 -lmysqlclient -lpthread
SRC = ConvertUTF.c readconf.cc
#-L/usr/local/lib/mysql
O=o
CC = g++

BINDIR=$(BASENAME)/sbin

INSTALL=install -o root -m
BINPERM=0555 -s

#OBJS=sqlsyslogd.$(O)

BINS=readconf

.PHONY: $(BINS)
all: $(BINS)

readconf: 
	$(CC) $(SRC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS) $(LIBS)

install: $(BINS)
	$(INSTALL) $(BINPERM) $(BINS) $(BINDIR)
	@for a in $(BINS); do ls -l $(BINDIR)/$$a; done

deinstall:
	cd $(BINDIR) && $(RM) $(BINS)

clean:
	rm -f *.$(O) $(BINS) *core*
