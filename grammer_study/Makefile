CC = g++
SRC_TYPEDEF  = test_typedef.cc
SRC_OVERRIDE = test_override.cc
SRC_FRIEND = test_friend.cc

CFLAG = -g -Wall -o
T_TYPEDEF = test_typedef
T_OVERRIDE = test_override
T_FRIEND = test_friend

all:$(T_TYPEDEF) $(T_OVERRIDE) $(T_FRIEND)
	
test_typedef:
	$(CC) $(SRC_TYPEDEF) $(CFLAG) $(T_TYPEDEF)

test_override:
	$(CC) $(SRC_OVERRIDE) $(CFLAG) $(T_OVERRIDE)

test_friend:
	$(CC) $(SRC_FRIEND) $(CFLAG) $(T_FRIEND)

clean:
	rm -rf $(T_TYPEDEF) $(T_OVERRIDE) $(T_FRIEND)
	rm -rf a.out *.o

