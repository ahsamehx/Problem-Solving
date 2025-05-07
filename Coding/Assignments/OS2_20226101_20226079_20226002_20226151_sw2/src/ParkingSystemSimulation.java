import java.io.*;
import java.util.*;

public class ParkingSystemSimulation {
    public static void main(String[] args) throws InterruptedException {
        ParkingLot parkingLot = new ParkingLot(3, 4);  // Gate capacities
        List<Car> cars = new ArrayList<>();

        File file = new File("X:\\Cpp\\Coding\\Assignments\\OS2_20226101_20226079_20226002_20226151_sw2\\src\\input.TXT");
        if (!file.exists()) {
            System.err.println("Error: input.txt file not found!");
            return;
        }

        try (BufferedReader br = new BufferedReader(new FileReader(file))) {
            String line;
            while ((line = br.readLine()) != null) {
                if (line.trim().isEmpty()) continue;

                try {
                    String[] parts = line.split(",");
                    if (parts.length == 4) {
                        int gateID = Integer.parseInt(parts[0].trim().split(" ")[1]) - 1;
                        int carID = Integer.parseInt(parts[1].trim().split(" ")[1]);
                        int arriveTime = Integer.parseInt(parts[2].trim().split(" ")[1]);
                        int parkDuration = Integer.parseInt(parts[3].trim().split(" ")[1]);

                        cars.add(new Car(carID, gateID, arriveTime, parkDuration, parkingLot));
                    } else {
                        System.err.println("Invalid line format: " + line);
                    }
                } catch (NumberFormatException e) {
                    System.err.println("Invalid data format in line: " + line);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        Thread[] threads = new Thread[cars.size()];
        for (int i = 0; i < cars.size(); i++) {
            threads[i] = new Thread(cars.get(i));
            threads[i].start();
        }

        for (Thread thread : threads) {
            thread.join();
        }

        System.out.println("\nTotal Cars Served: " + parkingLot.getTotalCarsServed());
        System.out.println("Current Cars in Parking: " + parkingLot.getCurrentCarsInParking());
        for (int i = 0; i < parkingLot.getGates().length; i++) {
            System.out.println("Gate " + (i + 1) + " served " + parkingLot.getGates()[i].getTotalCarsServed() + " cars. (Currently " + parkingLot.getGates()[i].getCurrentOccupiedSpots() + " spots occupied)");
        }
    }
}
