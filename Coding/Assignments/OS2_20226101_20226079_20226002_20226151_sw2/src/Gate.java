import java.util.*;

public class Gate {
    private int capacity;
    private List<Car> parkedCars;
    private int totalCarsServed;

    public Gate(int capacity) {
        this.capacity = capacity;
        this.parkedCars = new ArrayList<>();
        this.totalCarsServed = 0;
    }

    public int getTotalCarsServed() {
        return totalCarsServed;
    }

    public synchronized void parkCar(Car car) {
        if (parkedCars.size() >= capacity) {
            try {
                System.out.println("Car " + car.getCarID() + " from Gate " + (car.getGateID() + 1) + " is waiting for a spot.");
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    
        parkedCars.add(car);
        totalCarsServed++;
        System.out.println("Car " + car.getCarID() + " from Gate " + (car.getGateID() + 1) + " parked. (Parking Status: " + parkedCars.size() + " spots occupied)");
    }
    
    public synchronized void removeCar(Car car, int parkDuration) {
        parkedCars.remove(car);
        System.out.println("Car " + car.getCarID() + " from Gate " + (car.getGateID() + 1) + " left after " + parkDuration + " units of time. (Parking Status: " + parkedCars.size() + " spots occupied)");
        notify();
    }

    public int getCurrentOccupiedSpots() {
        return parkedCars.size();
    }
}
