### Τι περιέχει αυτός ο φάκελος:
Περιέχει ένα απλό παράδειγμα δημιουργίας, επεξεργασίας και καταστροφής ενός ακέραιου πίνακα δύο διστάσεων στον σωρό, μεγέθους <b>N * M</b>.

Ο πίνακας <b>ΔΕΝ</b> αποδεσμεύεται πλήρως. Πως μπορούμε να το διαπιστώσουμε αυτό;

Υπάρχει ένα απίστευτα ισχυρό εργαλείο προγραμματισμού που λέγεται <b>valgrind</b>. Μέσω αυτού μπορούμε να βρίσκουμε εύκολα και γρήγορα τα memory leaks.

### Πως φτιάχνουμε το πρόγραμμα:
Στο αρχείο <b>heap.c</b> δημιουργείται ο πίνακας N * M και εκτυπώνεται. Η επεξεργασία όμως; Όπως βλέπεις, υπάρχει μια δήλωση συνάρτησης add_data που περιγράφει τι κάνει. Που είναι η υλοποίηση της όμως; Έχει "κρυφτεί" στο αρχείο <b>hidden_file.o</b> το οποίο θα ενώσουμε με το heap.c για να φτιάξουμε το εκτελέσιμο. Τα βήματα είναι τα παρακάτω:
>gcc -c heap.c

>gcc -o exec heap.o hidden_file.o 

### Ένα παράδειγμα εκτέλεσης:
    04:12:35 dimskomex@Jim-Ubuntu memory ±|main ✗|→ gcc -c heap.c
    04:12:40 dimskomex@Jim-Ubuntu memory ±|main ✗|→ gcc -o exec heap.o hidden_file.o
    04:12:45 dimskomex@Jim-Ubuntu memory ±|main ✗|→ time ./exec 
    1702044772      1702044773
    1702044774      1702044775
    1702044776      1702044777
    1702044778      1702044779
    1702044780      1702044781

    real    0m10.007s
    user    0m0.005s
    sys     0m0.001s

### Χρήση του valgrind:
τρέχουμε το πρόγραμμα γράφοντας:
>valgrind ./exec

Το output είναι το παρακάτω:

    ==41760== Memcheck, a memory error detector
    ==41760== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
    ==41760== Using Valgrind-3.19.0 and LibVEX; rerun with -h for copyright info
    ==41760== Command: ./exec
    ==41760== 
    1702044895      1702044896
    1702044897      1702044898
    1702044899      1702044900
    1702044901      1702044902
    1702044903      1702044904
    ==41760== 
    ==41760== HEAP SUMMARY:
    ==41760==     in use at exit: 40 bytes in 5 blocks
    ==41760==   total heap usage: 7 allocs, 2 frees, 1,104 bytes allocated
    ==41760== 
    ==41760== LEAK SUMMARY:
    ==41760==    definitely lost: 40 bytes in 5 blocks
    ==41760==    indirectly lost: 0 bytes in 0 blocks
    ==41760==      possibly lost: 0 bytes in 0 blocks
    ==41760==    still reachable: 0 bytes in 0 blocks
    ==41760==         suppressed: 0 bytes in 0 blocks
    ==41760== Rerun with --leak-check=full to see details of leaked memory
    ==41760== 
    ==41760== For lists of detected and suppressed errors, rerun with: -s
    ==41760== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

μας βγάζει μία περίληψη του τι έγινε στον σωρό από την αρχή μέχρι και το τέλος του προγράμματος. Παρατηρούμε ότι μας γράφει πως υπάρχουν memory leaks (δηλαδή δεν κάναμε παντού free) τα οποία πρέπει να αντιμετωπίσουμε.

### TODO:
* Διόρθωσε τα memory leaks. Ενδεικτικά πρέπει να σου λέει αυτό:

        ==42318== HEAP SUMMARY:
        ==42318==     in use at exit: 0 bytes in 0 blocks
        ==42318==   total heap usage: 7 allocs, 7 frees, 1,104 bytes allocated
        ==42318== 
        ==42318== All heap blocks were freed -- no leaks are possible

* Προσπάθησε να φτιάξεις μια υλοποίηση της συνάρτησης add_data χρησιμοποιόντας τη documentation που υπάρχει πάνω από την δήλωση της. Το κάθε τι περίεργο υπάρχει σε βιβλιοθήκες της C. Google is your friend!