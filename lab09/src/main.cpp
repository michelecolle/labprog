#include <InertialDriver.h>
#include <Lettura.h>
#include <iostream>

int main()
{
    std::cout << "Main started:" << std::endl;
    InertialDriver driver;
    // prova push_back con 3 misure
    Lettura misura[NUM_READINGS_PER_MEASURE];
    Lettura misura2[NUM_READINGS_PER_MEASURE];
    Lettura misura3[NUM_READINGS_PER_MEASURE];
    for (int i = 0; i < NUM_READINGS_PER_MEASURE; i++)
    {
        misura[i] = Lettura(i * 1.0, i * 1.1, i * 1.2, i * 1.3, i * 1.4, i * 1.5);
        misura2[i] = Lettura(i * 2.0, i * 9, i * 1.7, i * 1.6, i * 1.2, i * 1.9);
        misura3[i] = Lettura(i * 3.0, i * 6, i * 5, i * 2, i * 1.8, i * 1.9);
    }
    driver.push_back(misura);
    std::cout << "fatto push numero 1" << std::endl;
    std::cout << driver << std::endl;
    driver.push_back(misura2);
    std::cout << "fatto push numero 2" << std::endl;
    std::cout << driver << std::endl;
    driver.push_back(misura3);
    std::cout << "fatto push numero 3" << std::endl;
    std::cout << driver << std::endl; // fine prova push_back di 3 misure con successo
    // provo per ogni misura getReading e stampo la lettura
    for (int i = 0; i < NUM_READINGS_PER_MEASURE; i++)
    {
        try
        {
            Lettura l = driver.get_reading(i);
            std::cout << i << " lettura della misura più recente: " << l << std::endl;
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Errore: " << e.what() << std::endl;
        }
    } // fine prova getReading con successo
    // prova di pop_front
    try
    {
        Lettura output[NUM_READINGS_PER_MEASURE];
        driver.pop_front(output);
        std::cout << "fatto pop front \n";
        for (int i = 0; i < NUM_READINGS_PER_MEASURE; ++i)
        {
            std::cout << "Lettura " << i << ": " << output[i] << std::endl;
        }
        std::cout << "prova ultimo elemento dopo pop " << std::endl;
        std::cout << driver << std::endl;
        Lettura output2[NUM_READINGS_PER_MEASURE];
        driver.pop_front(output2);
        std::cout << "fatto pop front \n";
        for (int i = 0; i < NUM_READINGS_PER_MEASURE; ++i)
        {
            std::cout << "Lettura " << i << ": " << output2[i] << std::endl;
        }
        std::cout << "prova ultimo elemento secondo pop " << std::endl;
        std::cout << driver << std::endl;
        Lettura output3[NUM_READINGS_PER_MEASURE];
        driver.pop_front(output3);
        std::cout << "fatto pop front \n";
        for (int i = 0; i < NUM_READINGS_PER_MEASURE; ++i)
        {
            std::cout << "Lettura " << i << ": " << output3[i] << std::endl;
        }
        std::cout << "prova ultimo elemento terzo ed ultimo pop " << std::endl;
        std::cout << driver << std::endl;
    }
    catch (std::out_of_range &e)
    {
        std::cout << e.what() << std::endl;
    } // fine prova di pop_front con successo
    std::cout << std::endl;
    // aggiungo altri 2 elementi al driver visto che lo ho svuotato per provare il clearBuffer
    Lettura misura4[NUM_READINGS_PER_MEASURE];
    Lettura misura5[NUM_READINGS_PER_MEASURE];
    for (int i = 0; i < NUM_READINGS_PER_MEASURE; i++)
    {
        misura4[i] = Lettura(i * 1.0, i * 1.1, i * 1.2, i * 1.3, i * 1.4, i * 1.5);
        misura5[i] = Lettura(i * 2.0, i * 9, i * 1.7, i * 1.6, i * 1.2, i * 1.9);
    }
    driver.push_back(misura4);
    std::cout << "fatto push numero 1" << std::endl;
    std::cout << driver << std::endl;
    driver.push_back(misura5);
    std::cout << "fatto push numero 2" << std::endl;
    std::cout << driver << std::endl;
    std::cout << std::endl;





// --- CREO 18 MISURE PER IL TEST POP ---
std::cout << "\n=== INSERIMENTO DI 18 MISURE ===" << std::endl;

for (int m = 0; m < 20; ++m)
{
    Lettura misuraPop[NUM_READINGS_PER_MEASURE];
    for (int i = 0; i < NUM_READINGS_PER_MEASURE; ++i)
    {
        // valori diversi per riconoscere ogni misura
        misuraPop[i] = Lettura(
            m * 1.0 + i, 
            m * 1.1 + i,
            m * 1.2 + i,
            m * 1.3 + i,
            m * 1.4 + i,
            m * 1.5 + i
        );
    }

    driver.push_back(misuraPop);
    std::cout << "Push #" << (m+1) << " eseguito" << std::endl;
}

// --- TEST: 18 POP_FRONT ---
std::cout << "\n=== TEST 18 POP_FRONT ===" << std::endl;

for (int k = 0; k < 20; ++k)
{
    try
    {
        Lettura out[NUM_READINGS_PER_MEASURE];   // <-- questo è l'array di output
        driver.pop_front(out);

        std::cout << "Pop #" << k+1 << " eseguito" << std::endl;
        for (int i = 0; i < NUM_READINGS_PER_MEASURE; ++i)
        {
            std::cout << "  Lettura " << i << ": " << out[i] << std::endl;
        }
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Pop #" << k+1 << " fallito: " << e.what() << std::endl;
        break;
    }
}

std::cout << "=== FINE TEST POP ===\n" << std::endl;

std::cout<<"ultimo elemento "<<driver<<std::endl;



    // prova clearBuffer
    try {
        driver.clear_buffer();
        std::cout << "dopo il clear_buffer " << driver << std::endl;
    }
    catch (std::out_of_range &e)
    {
        std::cout << e.what() << std::endl;
    }
    // fine prova clearBuffer con successo

    //test per l'opertatore == di Lettura
    Lettura l1(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
    Lettura l2(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
    Lettura l3(1.0, 2.0, 3.0, 4.0, 5.0, 7.0);   
    if (l1 == l2) {
        std::cout << "Test operatore == superato: l1 e l2 sono uguali." << std::endl;
    } else {
        std::cout << "Test operatore == fallito: l1 e l2 dovrebbero essere uguali." << std::endl;
    }
    if (l1 == l3) {
        std::cout << "Test operatore == fallito: l1 e l3 dovrebbero essere diversi." << std::endl;
    } else {
        std::cout << "Test operatore == superato: l1 e l3 sono diversi." << std::endl;
    }

    //test per riempimento buffer ciclico, carico 1 misura in piu del buffer e verifico che la misura piu vecchia sia stata sovrascritta
    std::cout << "Test buffer ciclico: carico 17 misure in un buffer di 16 posizioni" << std::endl;
    Lettura misura_test[NUM_READINGS_PER_MEASURE];

    for (int j = 0; j < 17; j++) {
        Lettura misura_temp[NUM_READINGS_PER_MEASURE];
        for (int i = 0; i < NUM_READINGS_PER_MEASURE; i++)
        {
            misura_temp[i] = Lettura(j * 1.0, j * 1.1, j * 1.2, j * 1.3, j * 1.4, j * 1.5);
        }
        driver.push_back(misura_temp);
        //salvo la seconda misura caricata per confrontarla dopo il ciclo
        if (j==1) {
            for (int i = 0; i < NUM_READINGS_PER_MEASURE; i++) {
                misura_test[i] = misura_temp[i];
            }
        }
    }
    //ora faccio pop_front per leggere la misura piu vecchia
    Lettura output_test[NUM_READINGS_PER_MEASURE];
    driver.pop_front(output_test);
    bool isEqual = true;
    for (int i = 0; i < NUM_READINGS_PER_MEASURE; i++) {
        if (!(output_test[i] == misura_test[i])) {
            isEqual = false;
            break;
        }
    }
    
    if (isEqual) {
        std::cout << "Test superato: la misura piu vecchia e' stata sovrascritta correttamente." << std::endl;
    } else {
        std::cout << "Test fallito: la misura piu vecchia non corrisponde alla seconda misura caricata." << std::endl;
    }
    std::cout << "finito" << std::endl; 
    return 0;
}