notes: notes.c
	cc notes.c -o notes
install: notes
	cp notes /bin/notes
clean: 
	rm -rf notes /bin/notes




