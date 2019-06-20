package com.example.kotlinexample

import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.widget.Toast
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val context = this
        var db = DataBaseHandler(context)
        button1.setOnClickListener {
            if(editText1.text.toString().length > 0 &&
                editText2.text.toString().length > 0 &&
                editText3.text.toString().length > 0 &&
                editText4.text.toString().length > 0 &&
                editText5.text.toString().length > 0 &&
                editText6.text.toString().length > 0){
                var Train = trainclas(editText6.text.toString(), editText2.text.toString().toInt(),editText1.text.toString(),editText3.text.toString().toInt(), editText4.text.toString().toInt(), editText5.text.toString())
                var db = DataBaseHandler(context)
                db.insertData(Train)
            } else{
                Toast.makeText(context,"please fill the data",Toast.LENGTH_SHORT).show()
            }
        }

        button5.setOnClickListener{
            var data = db.readData()
            textView.text = ""
            for (i in 0..(data.size-1))
                textView.append(data.get(i).id.toString() + " " + data.get(i).passanger.toString() + " " +data.get(i).way.toString() + " " +data.get(i).train.toString() + " " +data.get(i).departure.toString() + " " +data.get(i).arrival.toString()+ "\n")
        }
        button2.setOnClickListener{
            textView.text = ""
            if(editText3.text.toString().length > 0 &&
                editText4.text.toString().length > 0) {
                var Train = trainclas(
                    "",
                    0,
                    "",
                    editText3.text.toString().toInt(),
                    editText4.text.toString().toInt(),
                    ""
                )
                var db = DataBaseHandler(context)
                var data = db.exea(Train)
                for (i in 0..(data.size - 1))
                    textView.append(data.get(i).passanger.toString() + "\n")
            }

        }

        button4.setOnClickListener{
            textView.text = ""
            if(editText5.text.toString().length > 0) {
                var Train = trainclas(
                    "",
                    0,
                    "",
                    0,
                    0,
                    editText5.text.toString()
                )
                var db = DataBaseHandler(context)
                var data = db.findstati(Train)
                for (i in 0..(data.size - 1))
                    textView.append(data.get(i).train.toString() + "\n")
            }

        }

        button3.setOnClickListener{
            textView.text = ""
            if(editText2.text.toString().length > 0) {
                var Train = trainclas(
                    "",
                    editText2.text.toString().toInt(),
                    "",
                    0,
                    0,
                    ""
                )
                var db = DataBaseHandler(context)
                var data = db.contyway(Train)
                textView.append(data.toString() + "\n")
            }

        }


    }


}
