all: notes

config.h:
	cp config.def.h $@
notes: notes.c config.h
	cc notes.c -o notes
install: notes
	install -Dm 755 notes /bin/notes
uninstall: 
	rm -f /bin/notes
clean: 
	rm -f config.h
