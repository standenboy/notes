# Notes
a simple notes taking app

designed for use in your bashrc / zshrc file

install via
```
git clone https://github.com/standenboy/notes
make
make install
```

# usage 
```
notes -s NAME     sets a new note
notes -r NAME     reads a existing note
notes -d NAME     deletes a note
notes -l          lists all notes

replace NAME with your notes name
```
# config.h
A config.h is avalible

it functions just like in other suckless software

it controls the DIR where the notes are stored, this has to be a full DIR 

so no using ``` ~/.cache/notes ``` as this will break it 

by default it is set to ``` /etc/notes ```
