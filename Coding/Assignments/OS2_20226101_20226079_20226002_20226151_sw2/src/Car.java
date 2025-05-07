public class Car implements Runnable {
    private int carID;
    private int gateID;
    private int arriveTime;
    private int parkDuration;
    private int waitTime;
    private ParkingLot parkingLot;

    public Car(int carID, int gateID, int arriveTime, int parkDuration, ParkingLot parkingLot) {
        this.carID = carID;
        this.gateID = gateID;
        this.arriveTime = arriveTime;
        this.parkDuration = parkDuration;
        this.parkingLot = parkingLot;
        this.waitTime = 0;
    }

    public int getCarID() {
        return carID;
    }

    public int getGateID() {
        return gateID;
    }

    public int getArriveTime() {
        return arriveTime;
    }

    public int getParkDuration() {
        return parkDuration;
    }

    public void setWaitTime(int waitTime) {
        this.waitTime = waitTime;
    }

    public int getWaitTime() {
        return waitTime;
    }

    @Override
    public void run() {
        long startTime = System.currentTimeMillis();

        try {
            Thread.sleep(arriveTime * 1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        parkingLot.carArrives(this);

        long waitTimeMillis = System.currentTimeMillis() - startTime;
        setWaitTime((int) (waitTimeMillis / 1000));

        try {
            Thread.sleep(parkDuration * 1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        parkingLot.carLeaves(this);
    }
}
