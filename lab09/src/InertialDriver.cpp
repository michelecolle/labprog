#include "InertialDriver.h"
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <vector>

// Costruttore di default
InertialDriver::InertialDriver() : start_index_(0), count_(0), misure_(BUFFER_SIZE) {}

// accetta un array stile C contenente una misura e la memorizza nel buffer (sovrascrivendo la misura meno recente se il buffer è pieno)
// NOTA: è stato scelto di implementare il buffer circolare tramite operator[] di MyVector
//       in quanto push_back e pop_front di MyVector non sono adatti a questo scopo.
//       In questo modo size di MyVector non viene aggioranto, ma non è un problema in quanto
//       InertialDriver gestisce questa situazione e il MyVector e membro privato e
//       quindi non accessibile dall'esterno della classe.
void InertialDriver::push_back(const Lettura (&misura)[NUM_READINGS_PER_MEASURE])
{

    if (count_ < BUFFER_SIZE)
    {
        // aggiungo una nuova misura
        unsigned int index = (start_index_ + count_) % BUFFER_SIZE;
        for (int i = 0; i < NUM_READINGS_PER_MEASURE; i++)
        {
            misure_[index][i] = misura[i];
        }
        count_++;
    }
    else
    {
        // sovrascrivo la misura più vecchia
        for (int i = 0; i < NUM_READINGS_PER_MEASURE; i++)
        {
            misure_[start_index_][i] = misura[i];
        }
        start_index_ = (start_index_ + 1) % BUFFER_SIZE;
    }
}

// fornisce in output un array stile C contenente la misura più vecchia e la rimuove dal buffer
void InertialDriver::pop_front(Lettura (&misura)[NUM_READINGS_PER_MEASURE])
{
    if (count_ == 0)
    {
        throw std::out_of_range("Buffer vuoto, impossibile eseguire pop_front");
    }
    else
    {
        for (int i = 0; i < NUM_READINGS_PER_MEASURE; i++)
        {
            misura[i] = misure_[start_index_][i];
        }
        start_index_ = (start_index_ + 1) % BUFFER_SIZE;
        count_--;
    }
}

// elimina (senza restituirle) tutte le misure salvate
void InertialDriver::clear_buffer()
{
    start_index_ = 0;
    count_ = 0;
}

// accetta un numero tra 0 e 16 e ritorna la corrispondente lettura della misura più recente, senza cancellarla dal buffer
Lettura InertialDriver::get_reading(int index) const
{
    if (index < 0 || index >= NUM_READINGS_PER_MEASURE)
    {
        throw std::out_of_range("Indice lettura fuori range (0-16)");
    }
    if (count_ == 0)
    {
        throw std::out_of_range("Buffer vuoto, impossibile eseguire get_reading");
    }
    unsigned int index_misura = (start_index_ + count_ - 1) % BUFFER_SIZE;
    return misure_[index_misura][index];
}

unsigned int InertialDriver::get_count() const
{
    return count_;
}

bool InertialDriver::is_empty() const
{
    return count_ == 0;
}

bool InertialDriver::is_full() const
{
    return count_ == BUFFER_SIZE;
}

// Intestazione della tabella per la stampa (come costante)
const std::vector<std::string> HEADER_TITLES = {
    "n:", "Yaw_v", "Yaw_a", "Pitch_v", "Pitch_a", "Roll_v", "Roll_a"};

const int WIDTH = 90; // Larghezza della linea separatrice

// Operatore di stampa per InertialDriver, stampa la misura più recente come tabella senza rimuoverla dal buffer
std::ostream &operator<<(std::ostream &os, const InertialDriver &driver)
{
    // Verifica che ci sia almeno una misura
    if (driver.is_empty())
    {
        os << "InertialDriver buffer is empty." << std::endl;
        return os;
    }
    os << "InertialDriver last measure is: " << std::endl;
    // Stampa l'header della tabella
    for (size_t i = 0; i < HEADER_TITLES.size(); i++)
    {
        if (i == 0)
            os << std::setw(11) << std::right << HEADER_TITLES[i] << " ";
        else
            os << std::setw(10) << std::right << HEADER_TITLES[i] << " | ";
    }
    os << std::endl;
    os << std::string(WIDTH, '-') << std::endl;
    for (int i = 0; i < NUM_READINGS_PER_MEASURE; i++)
    {
        // Stampa il numero della lettura allineato
        os << "Lettura " << std::setw(2) << std::right << i << ": ";
        // Chiama l'operatore<< già definito per la singola Lettura
        os << driver.get_reading(i) << std::endl;
    }
    os << std::string(WIDTH, '-') << std::endl;
    return os;
}
