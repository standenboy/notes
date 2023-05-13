# Notes
a simple notes taking app

designed for use in your bashrc / zshrc file

install via
```
git clone https://github.com/standenboy/notes
make
make install
```

# Usage 
```
notes -s NAME     sets a new note
notes -r NAME     reads a existing note
notes -d NAME     deletes a note
notes -l          lists all notes

replace NAME with your notes name
```
you most likely want to use ``` notes -l ``` in your rc file

so then you get a reminder to do stuff whenever you open your terminal

# config.h
A config.h is avalible

it functions just like in other suckless software

it controls the DIR where the notes are stored, this has to be a full DIR 

so no using ``` ~/ ``` as this will break it 

by default it is set to ``` /etc/notes ```

id recomend you use ``` chmod -R a+wr /etc/notes ``` so you can edit this without root
