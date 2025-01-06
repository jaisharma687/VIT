class Car {
    String carName;
    String carType;
    public Car(String name, String type){
        this.carName = name;
        this.carType = type;
    }
    private String getCarName(){
        return this.carName;
    }
    class Engine{
        String EngineType;
        void setEngine(){
            if(Car.this.carType.equals("4WD")){
                if(Car.this.getCarName().equals("Crysler")){
                    this.EngineType = "Smaller";
                }
                else{
                    this.EngineType = "Bigger";
                }
            }
            else{
                this.EngineType = "Bigger";
            }
        }
        String getEngineType(){
            return this.EngineType;
        }
    }
}
