package com.example.kotlinexample

import android.content.ContentValues
import android.content.Context
import android.database.Cursor
import android.database.sqlite.SQLiteDatabase
import android.database.sqlite.SQLiteOpenHelper
import android.widget.Toast

val DATABASE_NAME ="MyDB"
val TABLE_NAME="Trains"
val COL_PASSANGER = "passanger"
val COL_TRAIN = "train"
val COL_DEPARTURE= "departure"
val COL_ARRIVAL = "arrival"
val COL_WAY = "way"
val COL_ID = "id"

val STATIONTABLE_NAME = "Stations"
val WAYSTABLE_NAME = "Ways"
val COL_STATION_NAME = "station"

class DataBaseHandler (var context: Context): SQLiteOpenHelper(context, DATABASE_NAME,null,1){
    override fun onCreate(db: SQLiteDatabase?) {
        val createTable = "CREATE TABLE " + TABLE_NAME +" (" +
                COL_ID +" INTEGER PRIMARY KEY AUTOINCREMENT," +
                COL_PASSANGER + " VARCHAR(256)," +
                COL_TRAIN + " VARCHAR(256)," +
                COL_DEPARTURE +" INTEGER," +
                COL_ARRIVAL  +" INTEGER," +
                COL_WAY +" INTEGER)"

        val createstation = "CREATE TABLE " + STATIONTABLE_NAME +" (" +
                COL_ID +" INTEGER PRIMARY KEY AUTOINCREMENT," +
                COL_TRAIN + " VARCHAR(256)," +
                COL_STATION_NAME +" VARCHAR(256))"

        val createway = "CREATE TABLE " + WAYSTABLE_NAME +" (" +
                COL_ID +" INTEGER PRIMARY KEY AUTOINCREMENT," +
                COL_DEPARTURE +" INTEGER," +
                COL_ARRIVAL  +" INTEGER," +
                COL_WAY +" INTEGER)"

        db?.execSQL(createstation)
        db?.execSQL(createway)
        db?.execSQL(createTable)
    }

    override fun onUpgrade(db: SQLiteDatabase?, oldVersion: Int, newVersion: Int) {
        TODO("not implemented") //To change body of created functions use File | Settings | File Templates.
    }

    fun insertData(Train: trainclas){
        val kb = this.readableDatabase
        val db = this.writableDatabase

        val query2 = "Select * from " + WAYSTABLE_NAME
        val result2 = kb.rawQuery(query2,null)
        var testy = "false"
        if(result2.moveToFirst()){
            do{
                var checky1 = result2.getString(result2.getColumnIndex(COL_WAY)).toInt()
                var checky2 = result2.getString(result2.getColumnIndex(COL_DEPARTURE)).toInt()
                var checky3 = result2.getString(result2.getColumnIndex(COL_ARRIVAL)).toInt()
                if (checky1==Train.way && checky2==Train.departure && checky3==Train.arrival){

                    testy = "true"
                    break
                }
            }while (result2.moveToNext())
        }
        result2.close()
        if(testy=="false"){
            val kr = ContentValues()
            kr.put(COL_WAY,Train.way)
            kr.put(COL_DEPARTURE,Train.departure)
            kr.put(COL_ARRIVAL,Train.arrival)
            var resulty = db.insert(WAYSTABLE_NAME,null,kr)
        }



        val query1 = "Select * from " + STATIONTABLE_NAME
        val result1 = kb.rawQuery(query1,null)
        var test = "false"
        if(result1.moveToFirst()){
            do{
                var checky1 = result1.getString(result1.getColumnIndex(COL_TRAIN))
                var checky2 = result1.getString(result1.getColumnIndex(COL_STATION_NAME))
                if (checky1==Train.train && checky2==Train.station){

                    test = "true"
                    break
                }
            }while (result1.moveToNext())
        }
        result1.close()
        if(test=="false"){
            val kv = ContentValues()
            kv.put(COL_TRAIN,Train.train)
            kv.put(COL_STATION_NAME,Train.station)
            var resulty = db.insert(STATIONTABLE_NAME,null,kv)
        }



        var cv = ContentValues()
        cv.put(COL_ARRIVAL,Train.arrival)
        cv.put(COL_DEPARTURE,Train.departure)
        cv.put(COL_TRAIN,Train.train)
        cv.put(COL_PASSANGER,Train.passanger)
        cv.put(COL_WAY ,Train.way)
        var result = db.insert(TABLE_NAME,null,cv)
        if(result == -1.toLong())
            Toast.makeText(context, "Failed",Toast.LENGTH_SHORT).show()
        else
            Toast.makeText(context, "Success",Toast.LENGTH_SHORT).show()
    }


    fun readData() : MutableList<trainclas>{
        var list = ArrayList<trainclas>()
        val db = this.readableDatabase
        val query = "Select * from " + TABLE_NAME
        val result = db.rawQuery(query, null)
        if(result.moveToFirst()){
            do{
                var train = trainclas()
                train.id = result.getString(result.getColumnIndex(COL_ID)).toInt()
                train.passanger = result.getString(result.getColumnIndex(COL_PASSANGER))
                train.way = result.getString(result.getColumnIndex(COL_WAY)).toInt()
                train.train = result.getString(result.getColumnIndex(COL_TRAIN))
                train.departure = result.getString(result.getColumnIndex(COL_DEPARTURE)).toInt()
                train.arrival = result.getString(result.getColumnIndex(COL_ARRIVAL)).toInt()
                list.add(train)
            }while (result.moveToNext())
        }

        result.close()
        db.close()
        return list
    }

    fun exea(Train: trainclas) : MutableList<trainclas>{
        var list = ArrayList<trainclas>()
        val db = this.readableDatabase
        val query = "Select * from " + TABLE_NAME
        val result = db.rawQuery(query, null)
        if(result.moveToFirst()){
            do{
                var train = trainclas()
                var check1 = result.getString(result.getColumnIndex(COL_DEPARTURE)).toInt()
                var check2 = result.getString(result.getColumnIndex(COL_ARRIVAL)).toInt()
                if(Train.arrival>=check2 && Train.departure<=check1) {
                    train.id = result.getString(result.getColumnIndex(COL_ID)).toInt()
                    train.passanger = result.getString(result.getColumnIndex(COL_PASSANGER))
                    train.way = result.getString(result.getColumnIndex(COL_WAY)).toInt()
                    train.train = result.getString(result.getColumnIndex(COL_TRAIN))
                    train.departure = result.getString(result.getColumnIndex(COL_DEPARTURE)).toInt()
                    train.arrival = result.getString(result.getColumnIndex(COL_ARRIVAL)).toInt()
                    list.add(train)
                }
            }while (result.moveToNext())
        }

        result.close()
        db.close()
        return list
    }

    fun findstati(Train: trainclas) : MutableList<trainclas>{
        var list = ArrayList<trainclas>()
        val db = this.readableDatabase
        val query = "Select * from " + STATIONTABLE_NAME
        val result = db.rawQuery(query, null)
        if(result.moveToFirst()){
            do{
                var train = trainclas()
                var check1 = result.getString(result.getColumnIndex(COL_TRAIN))
                var check2 = result.getString(result.getColumnIndex(COL_STATION_NAME))
                if(Train.station==check2) {
                    train.id = result.getString(result.getColumnIndex(COL_ID)).toInt()
                    train.passanger = ""
                    train.way = 0
                    train.train = result.getString(result.getColumnIndex(COL_TRAIN))
                    train.departure = 0
                    train.arrival = 0
                    list.add(train)
                }
            }while (result.moveToNext())
        }

        result.close()
        db.close()
        return list
    }

    fun contyway(Train: trainclas) : Int{
        val db = this.readableDatabase
        val query = "Select * from " + WAYSTABLE_NAME
        val result = db.rawQuery(query, null)
        var list = result.count

        result.close()
        db.close()
        return list
    }


}