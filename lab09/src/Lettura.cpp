#include "Lettura.h"
#include <iostream>
#include <iomanip>

Lettura::Lettura(double yaw_v, double yaw_a, double pitch_v, double pitch_a, double roll_v, double roll_a)
    : yaw_v_(yaw_v), yaw_a_(yaw_a), pitch_v_(pitch_v), pitch_a_(pitch_a), roll_v_(roll_v), roll_a_(roll_a) {};

double Lettura::getPitch_a() const{
    return pitch_a_;
}
double Lettura::getPitch_v() const{
    return pitch_v_;
}
double Lettura::getYaw_v() const{
    return yaw_v_;
}
double Lettura::getYaw_a() const{
    return yaw_a_;
}
double Lettura::getRoll_v()const{
    return roll_v_;
}
double Lettura::getRoll_a() const{
    return roll_a_;
}
/// @brief Operatore di confronto tra due oggetti di tipo Lettura, bitwise.
/// utilizzato per testare l'uguaglianza tra due letture.
/// @param l1 Lettura 1
/// @param l2 Lettura 2
/// @return 
bool operator==(const Lettura& l1, const Lettura& l2)
{
    bool isEqual = (l1.getYaw_v() == l2.getYaw_v()) && (l1.getYaw_a() == l2.getYaw_a()) &&
                (l1.getPitch_v() == l2.getPitch_v()) && (l1.getPitch_a() == l2.getPitch_a()) &&
                (l1.getRoll_v() == l2.getRoll_v()) && (l1.getRoll_a() == l2.getRoll_a());
    return isEqual;
}

/// @brief Stampa di un oggetto di tipo Lettura con opportuna precisione e spaziatura.
/// tutti i campi vengono stampati come riga di una tabella separati da " | "
/// l'header della tabella non è gestito da questo operatore ed è il seguente:
/// Yaw_v | Yaw_a | Pitch_v | Pitch_a | Roll_v | Roll_a
/// @param os 
/// @param l 
/// @return 
std::ostream& operator<<(std::ostream& os, const Lettura& l)
{
    os << std::setw(10) << std::fixed << std::setprecision(2) << l.getYaw_v() << " | "
        << std::setw(10) << std::fixed << std::setprecision(2) << l.getYaw_a() << " | "
        << std::setw(10) << std::fixed << std::setprecision(2) << l.getPitch_v() << " | "
        << std::setw(10) << std::fixed << std::setprecision(2) << l.getPitch_a() << " | "
        << std::setw(10) << std::fixed << std::setprecision(2) << l.getRoll_v() << " | "
        << std::setw(10) << std::fixed << std::setprecision(2) << l.getRoll_a();
    return os;
}

