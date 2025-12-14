NOTE:
    per compilare da terminale: g++ -I include src/*.cpp -o main


Michele Colle:
    Spostamento MyVector.hpp nella cartella include (vedi commento nel file MyVector.h)
    Implementazione metodo di stampa di Lettura per stampare la riga di una tabella
    Implementazione della struct Misura (dentro inertial driver.h) che contiene 17 letture per poter utilizzare MyVector su un c style array (wrapper)
    Implementazione test nel main per la classe lettura, una generica struct che wrappa un array, la classe misura ed un array di misura
    Implementazione e test metodo per stampare una misura con il suo header
    Scartata la classe Misura in favore di Myvector di array C style
    Miglioramento stampa (operatore <<) di intertialDriver
    Test per l'operatore == di lettura, creo due misure uguali e una diversa e verifico che l'operatore == si comporti correttamente
    Test per il buffer ciclico: carico una misura in piu nel buffer in modo da sovrascrivere la misura piu vecchia, poi leggo la misura piu vecchia (tramite metodo pop_front) e la confronto con la seconda misura caricata

Filippo Barban:
    implementato Lettura.h e  parte di Lettura.cpp (tutto tranne operatori)
    implementato funzione clear_buffer 
    implementato maggior parte del main di verifica 
    implementato deep copy in MyVector 

Davide Nincao:
    implementato funzioni push_back, pop_front e get_reading in InertialDriver.cpp
    fornito MyVector.h e MyVector.hpp
    implementato quasi tutto InertialDriver.h
    commentato gran parte del codice