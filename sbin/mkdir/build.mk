MKDIR_DIR = sbin/mkdir
MKDIR_PROGRAM = sbin/sbin/mkdir 
PROGRAM += $(MKDIR_PROGRAM)

EXTRA_CLEAN += $(MKDIR_PROGRAM) $(MKDIR_DIR)/*.o

$(MKDIR_PROGRAM): $(MKDIR_DIR)/*.c lib/libewok.a
	mkdir -p sbin/sbin
	$(CC) $(CFLAGS) -c -o $(MKDIR_DIR)/mkdir.o $(MKDIR_DIR)/mkdir.c
	$(LD) -Ttext=100 $(MKDIR_DIR)/*.o lib/libewok.a -o $(MKDIR_PROGRAM)
