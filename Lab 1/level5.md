### Bandit Level 5 → Level 6: Εύρεση αρχείου με συγκεκριμένες ιδιότητες
1. Συνδεόμαστε στον server μέσω SSH:
```console
ssh bandit5@bandit.labs.overthewire.org -p 2220
```
2. Εισάγουμε τον κωδικό που βρήκαμε στο προηγούμενο επίπεδο.
3. Χρησιμοποιούμε την εντολή `find` για να βρούμε το αρχείο με τις ιδιότητες που ζητούνται (αναγνώσιμο, 1033 bytes σε μέγεθος, μη εκτελέσιμο):
```console
find inhere/ -type f -size 1033c
```
4. Το αρχείο που ταιριάζει με τα κριτήρια είναι `inhere/maybehere07/.file2`.
5. Διαβάζουμε το περιεχόμενο του αρχείου:
```console
cat inhere/maybehere07/.file2
```
6. Ο κωδικός για το επόμενο επίπεδο εμφανίζεται στην οθόνη.