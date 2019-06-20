package com.example.kotlinexample

class trainclas{
    var id : Int = 0
    var passanger : String = ""
    var way : Int = 0
    var train : String = ""
    var departure : Int = 0
    var arrival : Int = 0
    var station : String = ""

    constructor(passanger:String, way:Int, train:String, departure:Int, arrival:Int, station: String){
        this.station = station
        this.passanger = passanger
        this.way = way
        this.train = train
        this.departure = departure
        this.arrival = arrival
    }
    constructor(){

    }
}

class wayclas{
    var id : Int = 0
    var way : Int = 0
    var arrival : Int = 0
    var departure : Int = 0

    constructor(departure: Int,arrival: Int,way: Int){
        this.departure = departure
        this.arrival = arrival
        this.way = way
    }
    constructor(){

    }
}
class staticlas{
    var train : String = ""
    var station : String = ""
    var id : Int = 0
    constructor(train: String, station: String){
        this.station = station
        this.train = train
    }
    constructor(){

    }
}