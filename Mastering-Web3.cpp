#include <iostream>
#include <cmath>
using namespace std;

class Car{
    private:
        string make;
        string model;
        int year;
        double speed;
        double x;
        double y;
        double z;
    public:
    Car(string make1,string model1,int year1,double speed1,double x1,double y1,double z1){
        make=make1;
        model=model1;
        year=year1;
        speed=speed1;
        x=x1;
        y=y1;
        z=z1;
    }
    
    void accelerate(float speed_increment){
        speed=speed+speed_increment;
    }
    
    void brake(float speed_decrement){
        speed=speed-speed_decrement;
        if(speed<0) speed=0;
    }
    
    void move(){
        x=x+speed;
        y=y+speed;
        z=z+speed;
    }
    
    int detect_collision(Car car2){
        int distance=sqrt(pow(x-car2.x,2)+pow(y-car2.y,2)+pow(z-car2.z,2));
        if(distance<=5) return 1;
        else return 0;
    }
    
    float time_to_collision(Car car2){
        float relative_speed=abs(speed-car2.speed);
        if(relative_speed == 0) return INFINITY;
        else{
            float distance=sqrt(pow(x-car2.x,2)+pow(y-car2.y,2)+pow(z-car2.z,2));
            return (distance/relative_speed);
        }
    }
};

int main(){
    Car car1=Car("Hyundai", "Creta", 2022, 50, 0, 0,0);
    Car car2=Car("Maruti", "Alto", 2021, 40, 50, 50,0);
    car1.accelerate(10);
    car2.brake(20);
    car1.move();
    car2.move();
    
    if (car1.detect_collision(car2))
        cout << "Collision detected between car1 and car2" << endl;
    else
        cout << "No collision detected between car1 and car2" << endl;
    
    cout << "Time to collision between car1 and car2: " << car1.time_to_collision(car2) << " seconds" << endl;
    return 0;
}
