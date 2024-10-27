### Bandit Level 4 → Level 5: Εύρεση αναγνώσιμου αρχείου
1. Συνδεόμαστε στον server μέσω SSH:
```console
ssh bandit4@bandit.labs.overthewire.org -p 2220
```
2. Εισάγουμε τον κωδικό που βρήκαμε στο προηγούμενο επίπεδο.
3. Ελέγχουμε τα περιεχόμενα του καταλόγου:
```console
ls
```
Βρίσκουμε τον φάκελο `inhere`.
4. Μεταβαίνουμε στον φάκελο `inhere`:
```console
cd inhere/
```
5. Χρησιμοποιούμε την εντολή `file` για να δούμε τον τύπο των αρχείων:
```console
file ./*
```
6. Βρίσκουμε ότι το αρχείο `-file07` είναι το μόνο αναγνώσιμο (ASCII text).
```console
./-file00: data
./-file01: data
./-file02: data
./-file03: data
./-file04: data
./-file05: data
./-file06: data
./-file07: ASCII text
./-file08: data
./-file09: data
```
7. Διαβάζουμε το περιεχόμενο του αρχείου με την εντολή:
```console
cat ./-file07
```
8. Ο κωδικός για το επόμενο επίπεδο εμφανίζεται στην οθόνη.