#include <iostream>
#include <string>
#include <vector>

struct Car
{
    int num_of_seats;
    std::string engine;
    std::string trip_computer;
    std::string gps;
};

struct CarManual
{
    std::string info;
};

class Builder
{
public:
    virtual void Reset() = 0;

    virtual void SetSeats(int number) = 0;

    virtual void SetEngine() = 0;

    virtual void SetTripComputer() = 0;

    virtual void SetGPS() = 0;
};

class CarBuilder : public Builder
{
private:
    Car car_;

public:
    void Reset() override
    {
    }

    void SetSeats(int number) override
    {
        car_.num_of_seats = number;
    }

    void SetEngine() override
    {
        car_.engine = "Car Engine";
    }

    void SetTripComputer() override
    {
        car_.trip_computer = "Trip Computer";
    }

    void SetGPS() override
    {
        car_.gps = "GPS";
    }

    Car GetResult()
    {
        return car_;
    }
};

class CarManualBuilder : public Builder
{
private:
    CarManual car_manual_;

public:
    void Reset() override
    {
        car_manual_.info.clear();
    }

    void SetSeats(int number) override
    {
        car_manual_.info += ("Seats: " + std::to_string(number) + "\n");
    }

    void SetEngine() override
    {
        car_manual_.info += "Car Engine\n";
    }

    void SetTripComputer() override
    {
        car_manual_.info += "Trip Computer\n";
    }

    void SetGPS() override
    {
        car_manual_.info += "GPS\n";
    }

    CarManual GetResult()
    {
        return car_manual_;
    }
};

class Director
{
public:
    void MakeCarWithFourSeats(Builder *builder)
    {
        builder->SetSeats(4);
        builder->SetEngine();
        builder->SetTripComputer();
        builder->SetGPS();
    }

    void MakeCarWithSevenSeats(Builder *builder)
    {
        builder->SetSeats(7);
        builder->SetEngine();
        builder->SetTripComputer();
        builder->SetGPS();
    }

    void MakeCarWithFourSeatsManual(Builder *builder)
    {
        builder->SetSeats(4);
        builder->SetEngine();
        builder->SetTripComputer();
        builder->SetGPS();
    }
};

int main(int argc, const char *argv[])
{
    {
        auto builder = new CarBuilder();
        Director dir;
        dir.MakeCarWithFourSeats(builder);
        auto result = builder->GetResult();
    }

    {
        auto builder = new CarManualBuilder();
        Director dir;
        dir.MakeCarWithFourSeatsManual(builder);
        auto result = builder->GetResult();
        std::cout << result.info << std::endl;
    }

    return 0;
}