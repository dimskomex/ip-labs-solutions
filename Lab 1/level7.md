### Bandit Level 7 → Level 8: Εύρεση κωδικού δίπλα από τη λέξη "millionth"
1. Συνδεόμαστε στον server μέσω SSH:
```console
ssh bandit7@bandit.labs.overthewire.org -p 2220
```
2. Εισάγουμε τον κωδικό που βρήκαμε στο προηγούμενο επίπεδο.
3. Ελέγχουμε τα περιεχόμενα του καταλόγου:
```console
ls
```
Βρίσκουμε το αρχείο data.txt.
4. Χρησιμοποιούμε την εντολή `grep` για να βρούμε τη γραμμή που περιέχει τη λέξη "millionth":
```console
grep "millionth" data.txt
```
5. Στην έξοδο εμφανίζεται ο κωδικός δίπλα από τη λέξη "millionth":
```console
millionth       ................................
```