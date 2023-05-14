notes: notes.c
	cc notes.c -o notes
install: notes
	install -Dm 755 notes /bin/notes
uninstall: 
	rm -f /bin/notes
clean: 
	rm -rf notes /bin/notes




