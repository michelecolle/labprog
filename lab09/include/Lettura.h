#ifndef Lettura_h
#define Lettura_h
#include <ostream>

class Lettura {
    public:
        Lettura() = default;
        Lettura(double,double,double,double,double,double);
        double getYaw_v()const;
        double getYaw_a() const;
        double getPitch_v()const;
        double getPitch_a() const;
        double getRoll_v()const;
        double getRoll_a() const;

    private:
        // Notare l'uso di _ alla fine, seguendo la convenzione di Google C++ Style Guide 
		// per i nomi delle variabili membro private
        double yaw_v_;
        double yaw_a_;
        double pitch_v_;
        double pitch_a_;
        double roll_v_;
        double roll_a_;
};

std::ostream& operator<<(std::ostream& os, const Lettura& l);
bool operator==(const Lettura& l1, const Lettura& l2);

#endif
