public class ParkingLot {
    private Gate[] gates;

    public ParkingLot(int numGates, int spotsPerGate) {
        gates = new Gate[numGates];
        for (int i = 0; i < numGates; i++) {
            gates[i] = new Gate(spotsPerGate);
        }
    }

    public void carArrives(Car car) {
        Gate gate = gates[car.getGateID()];
        gate.parkCar(car);
    }

    public void carLeaves(Car car) {
        Gate gate = gates[car.getGateID()];
        gate.removeCar(car, car.getParkDuration());
    }

    public int getTotalCarsServed() {
        int total = 0;
        for (Gate gate : gates) {
            total += gate.getTotalCarsServed();
        }
        return total;
    }

    public int getCurrentCarsInParking() {
        int total = 0;
        for (Gate gate : gates) {
            total += gate.getCurrentOccupiedSpots();
        }
        return total;
    }

    public Gate[] getGates() {
        return gates;
    }
}
